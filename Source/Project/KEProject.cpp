/*---------------------------------------------------------------------------*\
 *                             Kabala Engine                                 *
 *                                                                           *
 *                                                                           *
 *   contact: djkabala@gmail.com                                             *
 *                                                                           *
\*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*\
 *                                License                                    *
 *                                                                           *
 * This library is free software; you can redistribute it and/or modify it   *
 * under the terms of the GNU General Public License as published            *
 * by the Free Software Foundation, version 3.                               *
 *                                                                           *
 * This library is distributed in the hope that it will be useful, but       *
 * WITHOUT ANY WARRANTY; without even the implied warranty of                *
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU         *
 * Library General Public License for more details.                          *
 *                                                                           *
 * You should have received a copy of the GNU General Public                 *
 * License along with this library; if not, write to the Free Software       *
 * Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.                 *
 *                                                                           *
\*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*\
 *                                Changes                                    *
 *                                                                           *
 *                                                                           *
 *                                                                           *
 *                                                                           *
 *                                                                           *
 *                                                                           *
\*---------------------------------------------------------------------------*/

//---------------------------------------------------------------------------
//  Includes
//---------------------------------------------------------------------------

#include <stdlib.h>
#include <stdio.h>

#define KE_COMPILEKABALAENGINELIB

#include <OpenSG/OSGConfig.h>

#include "KEProject.h"
#include "KEUtils.h"
#include "Application/KEMainApplication.h"
#include <OpenSG/OSGViewport.h>
#include <OpenSG/OSGTransform.h>
#include <OpenSG/OSGPerspectiveCamera.h>
#include <OpenSG/OSGOrthographicCamera.h>
#include "Project/Scene/KEScene.h"
#include <OpenSG/Input/OSGWindowEventProducer.h>
#include <OpenSG/Toolbox/OSGFCFileHandler.h>
#include "Application/KEMainApplication.h"
#include <OpenSG/Input/OSGWindowEventProducer.h>

#include <OpenSG/Sound/OSGSoundManager.h>
#include <OpenSG/Lua/OSGLuaManager.h>

OSG_BEGIN_NAMESPACE

/***************************************************************************\
 *                            Description                                  *
\***************************************************************************/

/*! \class osg::Project
The Project. 	
*/

/***************************************************************************\
 *                           Class variables                               *
\***************************************************************************/

/***************************************************************************\
 *                           Class methods                                 *
\***************************************************************************/

void Project::initMethod (void)
{
}




ProjectPtr Project::load(const Path& ProjectFile)
{
	return create(ProjectFile);
}

ProjectPtr Project::create(const Path& ProjectFile)
{
	FCFileType::FCPtrStore NewContainers;
	NewContainers = FCFileHandler::the()->read(ProjectFile);

	for(FCFileType::FCPtrStore::iterator Itor(NewContainers.begin()) ; Itor!= NewContainers.end() ; ++Itor)
	{
		if((*Itor)->getType() == Project::getClassType())
		{
			beginEditCP(Project::Ptr::dcast(*Itor), Project::FilePathFieldMask);
				Project::Ptr::dcast(*Itor)->setFilePath(ProjectFile);
			endEditCP(Project::Ptr::dcast(*Itor), Project::FilePathFieldMask);
			Project::Ptr::dcast(*Itor)->attachNames();
			return Project::Ptr::dcast(*Itor);
		}
	}
	return NullFC;
}

/***************************************************************************\
 *                           Instance methods                              *
\***************************************************************************/

WindowEventProducerPtr Project::getEventProducer(void) const
{
	return MainApplication::the()->getMainWindowEventProducer();
}

void Project::save(void)
{
	FCFileType::FCPtrStore Containers;
	Containers.insert(ProjectPtr(this));

	FCFileType::FCTypeVector IgnoreTypes;

	FCFileHandler::the()->write(Containers,getFilePath(),IgnoreTypes);
}

void Project::save(const Path& ProjectFile)
{
	beginEditCP(ProjectPtr(this), Project::FilePathFieldMask);
		setFilePath(ProjectFile);
	endEditCP(ProjectPtr(this), Project::FilePathFieldMask);
	
	save();
}

void Project::start(void)
{
    //Temporarily validate all openGL Objects
    //MainApplication::the()->getMainWindowEventProducer()->getWindow()->validateAllGLObjects();

    //Attach the listeners
    MainApplication::the()->getMainWindowEventProducer()->addUpdateListener(&_ProjectUpdateListener);
    MainApplication::the()->getMainWindowEventProducer()->addMouseListener(&_ProjectUpdateListener);
    MainApplication::the()->getMainWindowEventProducer()->addMouseMotionListener(&_ProjectUpdateListener);
    MainApplication::the()->getMainWindowEventProducer()->addMouseWheelListener(&_ProjectUpdateListener);
    MainApplication::the()->getMainWindowEventProducer()->addKeyListener(&_ProjectUpdateListener);
    MainApplication::the()->getMainWindowEventProducer()->addWindowListener(&_ProjectUpdateListener);
    
    //Attach the SoundManager
    SoundManager::the()->attachUpdateProducer(MainApplication::the()->getMainWindowEventProducer());

    if(_AnimationAdvancer == NullFC)
    {
        _AnimationAdvancer = ElapsedTimeAnimationAdvancer::create();
    }

	//If needed create a default Viewport
	if(getInternalActiveViewport() == NullFC)
	{
		beginEditCP(ProjectPtr(this), InternalActiveViewportFieldMask);
			setInternalActiveViewport(createDefaultViewport());
		endEditCP(ProjectPtr(this), InternalActiveViewportFieldMask);
	}

	//If I have an initial Scene then enter it
	if(getInitialScene() != NullFC)
	{
		setActiveScene(getInitialScene());
	}

	//Attach the viewport to the window
    if(MainApplication::the()->getMainWindowEventProducer()->getWindow() != NullFC && 
       MainApplication::the()->getMainWindowEventProducer()->getWindow()->getPort().size() == 0)
	{
		beginEditCP(MainApplication::the()->getMainWindowEventProducer()->getWindow(), Window::PortFieldMask);
			MainApplication::the()->getMainWindowEventProducer()->getWindow()->addPort(getInternalActiveViewport());
		endEditCP(MainApplication::the()->getMainWindowEventProducer()->getWindow(), Window::PortFieldMask);
	}

    //Hide and dettach Cursor
    //MainApplication::the()->getMainWindowEventProducer()->setShowCursor(false);
    //MainApplication::the()->getMainWindowEventProducer()->setAttachMouseToCursor(false);
    setDefaults();

    //If I have a Lua Module then load it
    if(!getLuaModule().string().empty())
    {
        LuaManager::the()->runScript(getLuaModule());
    }

    produceProjectStarted(ProjectEvent::create(ProjectPtr(this), getTimeStamp()));
}

void Project::reset(void)
{
	//If I have an initial Scene then enter it
	if(getInitialScene() != NullFC)
	{
		setActiveScene(getInitialScene());
	}

    produceProjectReset(ProjectEvent::create(ProjectPtr(this), getTimeStamp()));
}

void Project::stop(void)
{
    produceProjectStopping(ProjectEvent::create(ProjectPtr(this), getTimeStamp()));

	setActiveScene(NullFC);
	if(MainApplication::the()->getMainWindowEventProducer()->getWindow() != NullFC && MainApplication::the()->getMainWindowEventProducer()->getWindow()->getPort().size() == 0)
	{
		beginEditCP(MainApplication::the()->getMainWindowEventProducer()->getWindow(), Window::PortFieldMask);
			MainApplication::the()->getMainWindowEventProducer()->getWindow()->subPort(0);
		endEditCP(MainApplication::the()->getMainWindowEventProducer()->getWindow(), Window::PortFieldMask);
	}
    //Detach the listeners
    MainApplication::the()->getMainWindowEventProducer()->removeUpdateListener(&_ProjectUpdateListener);
    MainApplication::the()->getMainWindowEventProducer()->removeMouseListener(&_ProjectUpdateListener);
    MainApplication::the()->getMainWindowEventProducer()->removeMouseMotionListener(&_ProjectUpdateListener);
    MainApplication::the()->getMainWindowEventProducer()->removeMouseWheelListener(&_ProjectUpdateListener);
    MainApplication::the()->getMainWindowEventProducer()->removeKeyListener(&_ProjectUpdateListener);
    MainApplication::the()->getMainWindowEventProducer()->removeWindowListener(&_ProjectUpdateListener);

    //Detach the SoundManager
    SoundManager::the()->detachUpdateProducer(MainApplication::the()->getMainWindowEventProducer());
    
    //End all Scenes
    for(UInt32 i(0) ; i<getScenes().size(); ++i)
    {
        getScenes(i)->end();
    }

    produceProjectStopped(ProjectEvent::create(ProjectPtr(this), getTimeStamp()));
}

void Project::setActiveScene(ScenePtr TheScene)
{
	if(getInternalActiveScene() != TheScene)
	{
		if(getInternalActiveScene() != NullFC)
		{
			getInternalActiveScene()->exit();
		}

		beginEditCP(ProjectPtr(this), InternalActiveSceneFieldMask);
			setInternalActiveScene(TheScene);
		endEditCP(ProjectPtr(this), InternalActiveSceneFieldMask);
		if(getInternalActiveScene() != NullFC)
		{
            //Start the scene if it hasn't allready
            if(!getInternalActiveScene()->isStarted())
            {    
                getInternalActiveScene()->start();
            }

			getInternalActiveScene()->enter();

            if(_NavigatorAttached)
            {
                updateNavigatorSceneAttachment();
            }
		}

        produceSceneChanged(ProjectEvent::create(ProjectPtr(this), getTimeStamp()));

        //Reset Animation Advancer
        _AnimationAdvancer->reset();
	}
}

ViewportPtr Project::createDefaultViewport(void) const
{
	ViewportPtr DefaultViewport = Viewport::create();
	beginEditCP(DefaultViewport);
		DefaultViewport->setCamera                  (NullFC);
		DefaultViewport->setRoot                    (NullFC);
		DefaultViewport->setSize                    (0.0f,0.0f, 1.0f,1.0f);
		DefaultViewport->setBackground              (NullFC);
	endEditCP(DefaultViewport);

	return DefaultViewport;
}


void Project::setActiveBackground(BackgroundPtr TheBackground)
{
	beginEditCP(getInternalActiveViewport(), Viewport::BackgroundFieldMask);
		getInternalActiveViewport()->setBackground(TheBackground);
	endEditCP(getInternalActiveViewport(), Viewport::BackgroundFieldMask);
}

void Project::setActiveCamera(CameraPtr TheCamera)
{
	if(TheCamera->getType().isDerivedFrom(PerspectiveCamera::getClassType()))
	{
		//Vec2f WindowSize(MainApplication::the()->getMainWindowEventProducer()->getSize());
		beginEditCP(TheCamera, PerspectiveCamera::AspectFieldMask);
			//PerspectiveCamera::Ptr::dcast(TheCamera)->setAspect(WindowSize.y()/WindowSize.x());
			PerspectiveCamera::Ptr::dcast(TheCamera)->setAspect(1.0);
		endEditCP(TheCamera, PerspectiveCamera::AspectFieldMask);
	}
	if(TheCamera->getType().isDerivedFrom(OrthographicCamera::getClassType()))
	{
		//Vec2f WindowSize(MainApplication::the()->getMainWindowEventProducer()->getSize());
		beginEditCP(TheCamera, OrthographicCamera::AspectFieldMask);
			//OrthographicCamera::Ptr::dcast(TheCamera)->setAspect(WindowSize.y()/WindowSize.x());
			OrthographicCamera::Ptr::dcast(TheCamera)->setAspect(1.0);
		endEditCP(TheCamera, OrthographicCamera::AspectFieldMask);
	}
	beginEditCP(getInternalActiveViewport(), Viewport::CameraFieldMask);
		getInternalActiveViewport()->setCamera(TheCamera);
	endEditCP(getInternalActiveViewport(), Viewport::CameraFieldMask);
}

void Project::setActiveNode(NodePtr TheNode)
{
	beginEditCP(getInternalActiveViewport(), Viewport::RootFieldMask);
		getInternalActiveViewport()->setRoot(TheNode);
	endEditCP(getInternalActiveViewport(), Viewport::RootFieldMask);
}

MFForegroundPtr &Project::getActiveForegrounds(void)
{
	return getInternalActiveViewport()->getForegrounds();
}

void Project::attachNames(void)
{
	//Backgrounds
	for(::osg::UInt32 i(0); i<getBackgrounds().size() ; ++i)
	{
		attachName(getBackgrounds(i));
	}

	//Foregrounds
	for(::osg::UInt32 i(0); i<getForegrounds().size() ; ++i)
	{
		attachName(getForegrounds(i));
	}

	//Cameras
	for(::osg::UInt32 i(0); i<getCameras().size() ; ++i)
	{
		attachName(getCameras(i));
	}

	//ModelNodes
	for(::osg::UInt32 i(0); i<getModelNodes().size() ; ++i)
	{
		attachName(getModelNodes(i));
	}

	//Scenes
	for(::osg::UInt32 i(0) ; i<getScenes().size() ; ++i)
	{
		getScenes(i)->attachNames();
	}

}

void Project::addActiveAnimation(AnimationPtr TheAnimation)
{
    if(getActiveAnimations().find(TheAnimation) == getActiveAnimations().end())
    {
        beginEditCP(ProjectPtr(this), ActiveAnimationsFieldMask);
            getActiveAnimations().push_back(TheAnimation);
        endEditCP(ProjectPtr(this), ActiveAnimationsFieldMask);
    }
}

void Project::removeActiveAnimation(AnimationPtr TheAnimation)
{
    if(getActiveAnimations().find(TheAnimation) != getActiveAnimations().end())
    {
        beginEditCP(ProjectPtr(this), ActiveAnimationsFieldMask);
            getActiveAnimations().erase(getActiveAnimations().find(TheAnimation));
        endEditCP(ProjectPtr(this), ActiveAnimationsFieldMask);
    }
}


void Project::addActiveParticleSystem(ParticleSystemPtr TheParticleSystem)
{
    if(getActiveParticleSystems().find(TheParticleSystem) == getActiveParticleSystems().end())
    {
        beginEditCP(ProjectPtr(this), ActiveParticleSystemsFieldMask);
            getActiveParticleSystems().push_back(TheParticleSystem);
        endEditCP(ProjectPtr(this), ActiveParticleSystemsFieldMask);
        TheParticleSystem->attachUpdateListener(MainApplication::the()->getMainWindowEventProducer());
    }
}

void Project::removeActiveParticleSystem(ParticleSystemPtr TheParticleSystem)
{
    if(getActiveParticleSystems().find(TheParticleSystem) != getActiveParticleSystems().end())
    {
        beginEditCP(ProjectPtr(this), ActiveParticleSystemsFieldMask);
            getActiveParticleSystems().erase(getActiveParticleSystems().find(TheParticleSystem));
        endEditCP(ProjectPtr(this), ActiveParticleSystemsFieldMask);
    }
}

void Project::update(const UpdateEventPtr e)
{
    //if(_NavigatorAttached)
    //{
    //    _navigator.idle(_mousebuttons,_lastx, _lasty);
    //    _navigator.updateCameraTransformation();
    //}
    if(!_PauseActiveUpdates)
    {
        _AnimationAdvancer->update(e->getElapsedTime());

        for(UInt32 i(0) ; i<getActiveAnimations().size() ; ++i)
        {
            getActiveAnimations(i)->update(_AnimationAdvancer);
        }
    }

    //Translation
    Matrix m(getInternalActiveViewport()->getCamera()->getBeacon()->getToWorld());
    Vec3f Local_x(1.0,0.0,0.0),Local_z(0.0,0.0,1.0);
    m.multMatrixVec(Local_x);
    m.multMatrixVec(Local_z);

    Vec3f Direction(0.0,0.0,0.0);
    float TranlateSpeed;
    if(_IsShiftKeyDown)
    {
        TranlateSpeed = _ScaledMotionFactor * _FastMotionFactor;
    }
    else
    {
        TranlateSpeed = _ScaledMotionFactor * _MotionFactor;
    }

    if(_IsAKeyDown)
    {
        Direction -= Local_x;
    }
    if(_IsDKeyDown)
    {
        Direction += Local_x;
    }
    if(_IsSKeyDown)
    {
        Direction += Local_z;
    }
    if(_IsWKeyDown)
    {
        Direction -= Local_z;
    }

    if(Direction != Vec2f(0.0,0.0,0.0))
    {
        Direction.normalize();
        Matrix t;
        t.setTranslate(TranlateSpeed*Direction*e->getElapsedTime());
        m.multLeft(t);
        setCameraBeaconMatrix(m);
    }
}

void Project::updateNavigatorSceneAttachment(void)
{
    getInternalActiveViewport()->getRoot()->updateVolume();

    Vec3f min,max;
    getInternalActiveViewport()->getRoot()->getVolume().getBounds( min, max );
    Vec3f d = max - min;

    if(d.length() < Eps) // Nothing loaded? Use a unity box
    {
        min.setValues(-1.f,-1.f,-1.f);
        max.setValues( 1.f, 1.f, 1.f);
        d = max - min;
    }

    // adjust the translation factors so that motions are sort of scaled
    _ScaledMotionFactor = (d[0] + d[1] + d[2]) / 1000.f;
}

void Project::attachFlyNavigation(void)
{


    updateNavigatorSceneAttachment();
    _NavigatorAttached = true;
    

    /*
    _navigator.setMode(Navigator::TRACKBALL);
    _navigator.setViewport(getInternalActiveViewport());

    updateNavigatorSceneAttachment();*/
}

void Project::dettachFlyNavigation(void)
{
    _NavigatorAttached = false;
}

void Project::toggleFlyNavigation(void)
{
    if(_NavigatorAttached)
    {
        dettachFlyNavigation();
    }
    else
    {
        attachFlyNavigation();
    }
}


void Project::mousePressed(const MouseEventPtr e)
{

}

void Project::mouseReleased(const MouseEventPtr e)
{
}

void Project::keyPressed(const KeyEventPtr e)
{
    if(_NavigatorAttached)
    {
       switch(e->getKey())
       {
       case KeyEvent::KEY_A:
           _IsAKeyDown = true;
	       break;
       case KeyEvent::KEY_S:
           _IsSKeyDown = true;
	       break;
       case KeyEvent::KEY_D:
           _IsDKeyDown = true;
	       break;
       case KeyEvent::KEY_W:
           _IsWKeyDown = true;
	       break;
       case KeyEvent::KEY_SHIFT:
           _IsShiftKeyDown = true;
	       break;
       default:
	       break;
       }
   }
}

void Project::keyReleased(const KeyEventPtr e)
{
    if(_NavigatorAttached)
    {
       switch(e->getKey())
       {
       case KeyEvent::KEY_A:
           _IsAKeyDown = false;
	       break;
       case KeyEvent::KEY_S:
           _IsSKeyDown = false;
	       break;
       case KeyEvent::KEY_D:
           _IsDKeyDown = false;
	       break;
       case KeyEvent::KEY_W:
           _IsWKeyDown = false;
	       break;
       case KeyEvent::KEY_SHIFT:
           _IsShiftKeyDown = false;
	       break;
       default:
	       break;
       }
    }
}

void Project::setCameraBeaconMatrix(const Matrix& m)
{
    if(getInternalActiveViewport()->getCamera()->getBeacon()->getCore()->getType().isDerivedFrom(Transform::getClassType()))
    {
        TransformPtr TransCore = Transform::Ptr::dcast(getInternalActiveViewport()->getCamera()->getBeacon()->getCore());
        beginEditCP(TransCore, Transform::MatrixFieldMask);
            TransCore->setMatrix(m);
        endEditCP(TransCore, Transform::MatrixFieldMask);
    }
}

void Project::mouseMoved(const MouseEventPtr e)
{
    if(_NavigatorAttached)
    {
        Matrix m(getInternalActiveViewport()->getCamera()->getBeacon()->getToWorld());
        //Vec3f Local_x(1.0,0.0,0.0),Local_y(0.0,1.0,0.0);
        //m.multMatrixVec(Local_x);
        //m.multMatrixVec(Local_y);

        Quaternion YRot_Quat(Vec3f(0.0,1.0,0.0), -e->getDelta().x() * _YRotMotionFactor);
        Matrix YRot_Mat;
        YRot_Mat.setRotate(YRot_Quat);
        Quaternion XRot_Quat(Vec3f(1.0,0.0,0.0),-e->getDelta().y() * _XRotMotionFactor);
        Matrix XRot_Mat;
        XRot_Mat.setRotate(XRot_Quat);

        m.mult(YRot_Mat);
        m.mult(XRot_Mat);
       // setCameraBeaconMatrix(m);
    }
}

void Project::mouseDragged(const MouseEventPtr e)
{
	if(_NavigatorAttached && e->getButton() == MouseEvent::BUTTON1)
	{
			Matrix m(getInternalActiveViewport()->getCamera()->getBeacon()->getToWorld());
		//Vec3f Local_x(1.0,0.0,0.0),Local_y(0.0,1.0,0.0);
		//m.multMatrixVec(Local_x);
		//m.multMatrixVec(Local_y);

		Quaternion YRot_Quat(Vec3f(0.0,1.0,0.0), -e->getDelta().x() * _YRotMotionFactor);
		Matrix YRot_Mat;
		YRot_Mat.setRotate(YRot_Quat);
		Quaternion XRot_Quat(Vec3f(1.0,0.0,0.0),-e->getDelta().y() * _XRotMotionFactor);
		Matrix XRot_Mat;
		XRot_Mat.setRotate(XRot_Quat);

		m.mult(YRot_Mat);
		m.mult(XRot_Mat);
	    setCameraBeaconMatrix(m);
	}
}

void Project::setDefaults(void)
{
    _YRotMotionFactor = 0.003f;
    _XRotMotionFactor = 0.003f;

    _FastMotionFactor = 200.0f;
    _MotionFactor = 50.0f;
}
/*-------------------------------------------------------------------------*\
 -  private                                                                 -
\*-------------------------------------------------------------------------*/

void Project::produceSceneChanged(const ProjectEventPtr e)
{
    _Producer.produceEvent(SceneChangedMethodId, e);
}

void Project::produceProjectStarted(const ProjectEventPtr e)
{
    _Producer.produceEvent(ProjectStartedMethodId, e);
}

void Project::produceProjectStopping(const ProjectEventPtr e)
{
    _Producer.produceEvent(ProjectStoppingMethodId, e);
}

void Project::produceProjectStopped(const ProjectEventPtr e)
{
    _Producer.produceEvent(ProjectStoppedMethodId, e);
}

void Project::produceProjectReset(const ProjectEventPtr e)
{
    _Producer.produceEvent(ProjectResetMethodId, e);
}
/*----------------------- constructors & destructors ----------------------*/

Project::Project(void) :
    Inherited(),
        _ProjectUpdateListener(ProjectPtr(this)),
        _PauseActiveUpdates(false),
        _NavigatorAttached(false),
        _IsAKeyDown(false),
        _IsSKeyDown(false),
        _IsDKeyDown(false),
        _IsWKeyDown(false),
        _IsShiftKeyDown(false)
{
}

Project::Project(const Project &source) :
    Inherited(source),
        _ProjectUpdateListener(ProjectPtr(this)),
        _PauseActiveUpdates(source._PauseActiveUpdates),
        _NavigatorAttached(false),
        _IsAKeyDown(false),
        _IsSKeyDown(false),
        _IsDKeyDown(false),
        _IsWKeyDown(false),
        _IsShiftKeyDown(false)
{
}

Project::~Project(void)
{
}

/*----------------------------- class specific ----------------------------*/

void Project::changed(BitVector whichField, UInt32 origin)
{
    Inherited::changed(whichField, origin);

	if((whichField & ScenesFieldMask))
	{
		for(::osg::UInt32 i(0) ; i<getScenes().size() ; ++i)
		{
			beginEditCP(getScenes()[i], Scene::InternalParentProjectFieldMask);
				getScenes()[i]->setInternalParentProject(ProjectPtr(this));
			endEditCP(getScenes()[i], Scene::InternalParentProjectFieldMask);
		}
	}
}

void Project::dump(      UInt32    , 
                         const BitVector ) const
{
    SLOG << "Dump Project NI" << std::endl;
}


OSG_END_NAMESPACE

