/*---------------------------------------------------------------------------*\
 *                             Kabala Engine                                 *
 *                                                                           *
 *               Copyright (C) 2009-2010 by David Kabala                     *
 *                                                                           *
 *   authors:  David Kabala (djkabala@gmail.com)                             *
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

#define KE_COMPILEKABALAENGINELIB

#include <OpenSG/OSGConfig.h>

#include "KEImportModelCommand.h"
#include <OpenSG/OSGSceneFileHandler.h>
#include <OpenSG/OSGFCFileHandler.h>
#include <OpenSG/OSGWindowEventProducer.h>
#include "Application/KEMainApplication.h"
#include "Project/Scene/KEScene.h"
#include <OpenSG/OSGSceneGraphTreeModel.h>
#include <OpenSG/OSGTravMaskGraphOp.h>
#include <OpenSG/OSGImageFileHandler.h>
#include <OpenSG/OSGFilePathAttachment.h>
#include <OpenSG/OSGAnimation.h>

OSG_USING_NAMESPACE

/***************************************************************************\
 *                            Description                                  *
\***************************************************************************/

/*! \class ImportModelCommand
A ImportModelCommand. 
*/

/***************************************************************************\
 *                           Class variables                               *
\***************************************************************************/

CommandType ImportModelCommand::_Type("ImportModelCommand", "UndoableCommand");

/***************************************************************************\
 *                           Class methods                                 *
\***************************************************************************/

ImportModelCommandPtr ImportModelCommand::create(HierarchyPanel* const HierarchyPanel,
                                                 Node* const NodeToAddTo,
                                                 Scene* const SceneToAddTo)
{
	return RefPtr(new ImportModelCommand(HierarchyPanel, NodeToAddTo, SceneToAddTo));
}

/***************************************************************************\
 *                           Instance methods                              *
\***************************************************************************/

void ImportModelCommand::execute(void)
{
    //Have the user select the file to import
    std::vector<WindowEventProducer::FileDialogFilter> Filters;
    std::list< const Char8 * > ReadableModelSuff;
    SceneFileHandler::the()->getSuffixList(ReadableModelSuff, SceneFileType::OSG_READ_SUPPORTED);
    //Determine all of the readable model filetypes
    Filters.push_back(WindowEventProducer::FileDialogFilter("All Model filetypes",""));
    std::string AllModelSuffixes;
    std::string AllModelSuffixesDesc("All Model filetypes (");
    for(std::list<const Char8*>::const_iterator SuffixItor(ReadableModelSuff.begin()) ; SuffixItor != ReadableModelSuff.end() ; ++SuffixItor)
    {
        if(!AllModelSuffixes.empty())
        {
            AllModelSuffixes += ",";
            AllModelSuffixesDesc += ", ";
        }
        AllModelSuffixes += *SuffixItor;
        AllModelSuffixesDesc = AllModelSuffixesDesc + "*." + *SuffixItor;
        Filters.push_back(WindowEventProducer::FileDialogFilter(std::string(SceneFileHandler::the()->getFileType(*SuffixItor)->getName()) +  " (*." + *SuffixItor + ")",*SuffixItor));
    }
    AllModelSuffixesDesc += ")";
    Filters[0] = WindowEventProducer::FileDialogFilter(AllModelSuffixesDesc,AllModelSuffixes);
    Filters.push_back(WindowEventProducer::FileDialogFilter("All (*.*)","*"));

	std::vector<BoostPath> FilesToOpen;
    FilesToOpen = MainApplication::the()->getMainWindow()->openFileDialog("Import a model file.",
                                                                          Filters,
                                                                          BoostPath(".."),
                                                                          false);

	_NewNode = NULL;

    if(FilesToOpen.size() > 0)
    {
        //Try loading the file using the FC file handler
        FCFileType::FCPtrStore NewContainers;
        NewContainers = FCFileHandler::the()->read(FilesToOpen[0]);

        FCFileType::FCPtrStore::iterator Itor;
        for(Itor = NewContainers.begin() ; Itor != NewContainers.end() ; ++Itor)
        {
            //Grab the root node
            if( (*Itor)->getType() == (Node::getClassType()) && 
                (dynamic_pointer_cast<Node>(*Itor)->getParent() == NULL))
            {
                _NewNode = (dynamic_pointer_cast<Node>(*Itor));
            }

            //Grab all of the animations
            else if( (*Itor)->getType().isDerivedFrom(Animation::getClassType()) )
            {
                _NewAnimations.push_back(dynamic_pointer_cast<Animation>(*Itor));
            }
        }

        if(_NewNode == NULL)
        {
            //Try loading the file using the SceneFileHandler
            _NewNode = SceneFileHandler::the()->read(FilesToOpen[0].string().c_str(), NULL);
        }
   } 
	
	if(_NewNode != NULL)
    {
        FilePathAttachment::setFilePath(_NewNode,FilesToOpen[0]);
	    if(MainApplication::the()->getSettings().get<bool>("player.debugger.model_import.trav_mask_graph_op.enabled"))
	    {
		    TravMaskGraphOpRefPtr colMeshGrOp = TravMaskGraphOp::create();
		    
            colMeshGrOp->setMatchName(MainApplication::the()->getSettings().get<bool>("player.debugger.trav_mask_graph_op.match_name"));
		    colMeshGrOp->setMatchRegex(MainApplication::the()->getSettings().get<std::string>("player.debugger.trav_mask_graph_op.search_regex"));
            colMeshGrOp->setMatchWholeName(MainApplication::the()->getSettings().get<bool>("player.debugger.trav_mask_graph_op.match_whole_name"));
            colMeshGrOp->setMatchNodeCoreType(MainApplication::the()->getSettings().get<bool>("player.debugger.trav_mask_graph_op.match_node_core_type"));
            colMeshGrOp->setNodeCoreType(MainApplication::the()->getSettings().get<std::string>("player.debugger.trav_mask_graph_op.node_core_typename"));
            colMeshGrOp->setMatchDerivedCoreTypes(MainApplication::the()->getSettings().get<bool>("player.debugger.trav_mask_graph_op.match_derived_core_types"));
            colMeshGrOp->setMatchCurrentTravMask(MainApplication::the()->getSettings().get<bool>("player.debugger.trav_mask_graph_op.match_trav_mask"));
            colMeshGrOp->setCurrentTravMaskValue(MainApplication::the()->getSettings().get<UInt32>("player.debugger.trav_mask_graph_op.match_trav_mask_value"));
            colMeshGrOp->setMatchMaskCondition(MainApplication::the()->getSettings().get<UInt8>("player.debugger.trav_mask_graph_op.match_mask_condition"));
            colMeshGrOp->setApplyMaskToAllDecendents(MainApplication::the()->getSettings().get<bool>("player.debugger.trav_mask_graph_op.apply_mask_to_decendents"));
            colMeshGrOp->setApplyToNonMatching(MainApplication::the()->getSettings().get<bool>("player.debugger.trav_mask_graph_op.apply_to_non_matching"));
            colMeshGrOp->setNewTravMask(MainApplication::the()->getSettings().get<UInt32>("player.debugger.trav_mask_graph_op.applied_trav_mask"));
            colMeshGrOp->setNewTravMaskOperation(MainApplication::the()->getSettings().get<UInt8>("player.debugger.trav_mask_graph_op.apply_trav_mask_operation"));
		    
            // default values for this graph op will do fine.
		    if(colMeshGrOp->traverse(_NewNode))
		    {
			    SLOG << "Number of nodes hidden: " << colMeshGrOp->getNumChanged() << std::endl;
		    }
	    }

        if(_NodeToAddTo!=NULL)
	    {
	        _HierarchyPanel->getSceneGraphTreeModel()->addNode(_NodeToAddTo,_NewNode);
        }
    }

    //Add the animations
    for(std::vector<AnimationRefPtr>::iterator AnimItor(_NewAnimations.begin()) ; AnimItor != _NewAnimations.end() ; ++AnimItor)
    {
        _SceneAddedTo->pushToAnimations(*AnimItor);
    }

	
	_HasBeenDone = true;
}

std::string ImportModelCommand::getCommandDescription(void) const
{
	std::string Description("Imported Model");
	
	return Description;
}

std::string ImportModelCommand::getPresentationName(void) const
{
	return getCommandDescription();
}

void ImportModelCommand::redo(void)
{
    Inherited::redo();

    //Add the node
	if(_NewNode!=NULL)
	{
		_HierarchyPanel->getSceneGraphTreeModel()->addNode(_NodeToAddTo,_NewNode);
	}

    //Add the animations
    for(std::vector<AnimationRefPtr>::iterator AnimItor(_NewAnimations.begin()) ; AnimItor != _NewAnimations.end() ; ++AnimItor)
    {
        _SceneAddedTo->pushToAnimations(*AnimItor);
    }

}

void ImportModelCommand::undo(void)
{
    Inherited::undo();

    //Remove the node
	if(_NewNode!=NULL)
	{
		_HierarchyPanel->getSceneGraphTreeModel()->removeNode(_NewNode);
	}

    //Remove the animations
    for(std::vector<AnimationRefPtr>::iterator AnimItor(_NewAnimations.begin()) ; AnimItor != _NewAnimations.end() ; ++AnimItor)
    {
        _SceneAddedTo->removeObjFromAnimations(*AnimItor);
    }

}

const CommandType &ImportModelCommand::getType(void) const
{
	return _Type;
}
/*-------------------------------------------------------------------------*\
 -  private                                                                 -
\*-------------------------------------------------------------------------*/

/*----------------------- constructors & destructors ----------------------*/

ImportModelCommand::~ImportModelCommand(void)
{
}

/*----------------------------- class specific ----------------------------*/

void ImportModelCommand::operator =(const ImportModelCommand& source)
{
}

