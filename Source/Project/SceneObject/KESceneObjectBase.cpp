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

/*****************************************************************************\
 *****************************************************************************
 **                                                                         **
 **                  This file is automatically generated.                  **
 **                                                                         **
 **          Any changes made to this file WILL be lost when it is          **
 **           regenerated, which can become necessary at any time.          **
 **                                                                         **
 **     Do not change this file, changes should be done in the derived      **
 **     class SceneObject!
 **                                                                         **
 *****************************************************************************
\*****************************************************************************/

#include <cstdlib>
#include <cstdio>
#include <boost/assign/list_of.hpp>

#include <OpenSG/OSGConfig.h>



#include "Project/SceneObject/KEBehavior.h" // Behaviors Class
#include "Project/Effect/KEEffect.h"    // AttachedEffects Class
#include <OpenSG/OSGNode.h>             // Node Class
#include "Project/Scene/KEScene.h"      // Scene Class

#include "KESceneObjectBase.h"
#include "KESceneObject.h"

#include <boost/bind.hpp>

#ifdef WIN32 // turn off 'this' : used in base member initializer list warning
#pragma warning(disable:4355)
#endif

OSG_BEGIN_NAMESPACE

/***************************************************************************\
 *                            Description                                  *
\***************************************************************************/

/*! \class OSG::SceneObject
    The SceneObject.
 */

/***************************************************************************\
 *                        Field Documentation                              *
\***************************************************************************/

/*! \var Behavior *      SceneObjectBase::_mfBehaviors
    
*/

/*! \var Effect *        SceneObjectBase::_mfAttachedEffects
    
*/

/*! \var Node *          SceneObjectBase::_sfNode
    
*/

/*! \var Scene *         SceneObjectBase::_sfScene
    
*/


/***************************************************************************\
 *                      FieldType/FieldTrait Instantiation                 *
\***************************************************************************/

#if !defined(OSG_DO_DOC) || defined(OSG_DOC_DEV)
DataType FieldTraits<SceneObject *>::_type("SceneObjectPtr", "AttachmentContainerPtr");
#endif

OSG_FIELDTRAITS_GETTYPE(SceneObject *)

OSG_EXPORT_PTR_SFIELD_FULL(PointerSField,
                           SceneObject *,
                           0);

OSG_EXPORT_PTR_MFIELD_FULL(PointerMField,
                           SceneObject *,
                           0);

/***************************************************************************\
 *                         Field Description                               *
\***************************************************************************/

void SceneObjectBase::classDescInserter(TypeObject &oType)
{
    FieldDescriptionBase *pDesc = NULL;


    pDesc = new MFUnrecChildBehaviorPtr::Description(
        MFUnrecChildBehaviorPtr::getClassType(),
        "Behaviors",
        "",
        BehaviorsFieldId, BehaviorsFieldMask,
        false,
        (Field::MFDefaultFlags | Field::FStdAccess),
        static_cast<FieldEditMethodSig>(&SceneObject::editHandleBehaviors),
        static_cast<FieldGetMethodSig >(&SceneObject::getHandleBehaviors));

    oType.addInitialDesc(pDesc);

    pDesc = new MFUnrecChildEffectPtr::Description(
        MFUnrecChildEffectPtr::getClassType(),
        "AttachedEffects",
        "",
        AttachedEffectsFieldId, AttachedEffectsFieldMask,
        false,
        (Field::MFDefaultFlags | Field::FStdAccess),
        static_cast<FieldEditMethodSig>(&SceneObject::editHandleAttachedEffects),
        static_cast<FieldGetMethodSig >(&SceneObject::getHandleAttachedEffects));

    oType.addInitialDesc(pDesc);

    pDesc = new SFUnrecNodePtr::Description(
        SFUnrecNodePtr::getClassType(),
        "Node",
        "",
        NodeFieldId, NodeFieldMask,
        false,
        (Field::SFDefaultFlags | Field::FStdAccess),
        static_cast<FieldEditMethodSig>(&SceneObject::editHandleNode),
        static_cast<FieldGetMethodSig >(&SceneObject::getHandleNode));

    oType.addInitialDesc(pDesc);

    pDesc = new SFUnrecScenePtr::Description(
        SFUnrecScenePtr::getClassType(),
        "Scene",
        "",
        SceneFieldId, SceneFieldMask,
        false,
        (Field::SFDefaultFlags | Field::FStdAccess),
        static_cast<FieldEditMethodSig>(&SceneObject::editHandleScene),
        static_cast<FieldGetMethodSig >(&SceneObject::getHandleScene));

    oType.addInitialDesc(pDesc);
}


SceneObjectBase::TypeObject SceneObjectBase::_type(
    SceneObjectBase::getClassname(),
    Inherited::getClassname(),
    "NULL",
    0,
    reinterpret_cast<PrototypeCreateF>(&SceneObjectBase::createEmptyLocal),
    SceneObject::initMethod,
    SceneObject::exitMethod,
    reinterpret_cast<InitalInsertDescFunc>(&SceneObject::classDescInserter),
    false,
    0,
    "<?xml version=\"1.0\"?>\n"
    "\n"
    "<FieldContainer\n"
    "\tname=\"SceneObject\"\n"
    "\tparent=\"AttachmentContainer\"\n"
    "\tlibrary=\"KabalaEngine\"\n"
    "\tpointerfieldtypes=\"both\"\n"
    "\tstructure=\"concrete\"\n"
    "\tsystemcomponent=\"false\"\n"
    "\tparentsystemcomponent=\"true\"\n"
    "\tdecoratable=\"false\"\n"
    "\tuseLocalIncludes=\"false\"\n"
    "\tlibnamespace=\"KE\"\n"
    "    authors=\"David Kabala (djkabala@gmail.com)                             \"\n"
    ">\n"
    "The SceneObject.\n"
    "    <Field\n"
    "\t\tname=\"Behaviors\"\n"
    "\t\ttype=\"Behavior\"\n"
    "        childParentType=\"FieldContainer\"\n"
    "\t\tcategory=\"childpointer\"\n"
    "\t\tcardinality=\"multi\"\n"
    "\t\tvisibility=\"external\"\n"
    "\t\tfieldHeader=\"Project/SceneObject/KEBehaviorFields.h\"\n"
    "\t\ttypeHeader=\"Project/SceneObject/KEBehavior.h\"\n"
    "\t\taccess=\"public\"\n"
    "        linkParentField=\"SceneObject\"\n"
    "\t>\n"
    "\t</Field>\n"
    "    <Field\n"
    "\t\tname=\"AttachedEffects\"\n"
    "\t\ttype=\"Effect\"\n"
    "        childParentType=\"FieldContainer\"\n"
    "\t\tcategory=\"childpointer\"\n"
    "\t\tcardinality=\"multi\"\n"
    "\t\tvisibility=\"external\"\n"
    "\t\tfieldHeader=\"Project/Effect/KEEffectFields.h\"\n"
    "\t\ttypeHeader=\"Project/Effect/KEEffect.h\"\n"
    "\t\taccess=\"public\"\n"
    "        linkParentField=\"ParentSceneObject\"\n"
    "\t>\n"
    "\t</Field>\n"
    "    <Field\n"
    "\t\tname=\"Node\"\n"
    "\t\ttype=\"Node\"\n"
    "\t\tcategory=\"pointer\"\n"
    "\t\tcardinality=\"single\"\n"
    "\t\tvisibility=\"external\"\n"
    "\t\taccess=\"public\"\n"
    "\t\tdefaultValue=\"NULL\"\n"
    "\t>\n"
    "\t</Field>\n"
    "    <Field\n"
    "\t\tname=\"Scene\"\n"
    "\t\ttype=\"Scene\"\n"
    "\t\tcategory=\"pointer\"\n"
    "\t\tcardinality=\"single\"\n"
    "\t\tvisibility=\"external\"\n"
    "        fieldHeader=\"Project/Scene/KEScene.h\"\n"
    "\t\ttypeHeader=\"Project/Scene/KEScene.h\"\n"
    "\t\taccess=\"public\"\n"
    "\t\tdefaultValue=\"NULL\"\n"
    "\t>\n"
    "\t</Field>\n"
    "</FieldContainer>\n",
    "The SceneObject.\n"
    );

/*------------------------------ get -----------------------------------*/

FieldContainerType &SceneObjectBase::getType(void)
{
    return _type;
}

const FieldContainerType &SceneObjectBase::getType(void) const
{
    return _type;
}

UInt32 SceneObjectBase::getContainerSize(void) const
{
    return sizeof(SceneObject);
}

/*------------------------- decorator get ------------------------------*/


//! Get the SceneObject::_mfBehaviors field.
const MFUnrecChildBehaviorPtr *SceneObjectBase::getMFBehaviors(void) const
{
    return &_mfBehaviors;
}

MFUnrecChildBehaviorPtr *SceneObjectBase::editMFBehaviors      (void)
{
    editMField(BehaviorsFieldMask, _mfBehaviors);

    return &_mfBehaviors;
}

//! Get the SceneObject::_mfAttachedEffects field.
const MFUnrecChildEffectPtr *SceneObjectBase::getMFAttachedEffects(void) const
{
    return &_mfAttachedEffects;
}

MFUnrecChildEffectPtr *SceneObjectBase::editMFAttachedEffects(void)
{
    editMField(AttachedEffectsFieldMask, _mfAttachedEffects);

    return &_mfAttachedEffects;
}

//! Get the SceneObject::_sfNode field.
const SFUnrecNodePtr *SceneObjectBase::getSFNode(void) const
{
    return &_sfNode;
}

SFUnrecNodePtr      *SceneObjectBase::editSFNode           (void)
{
    editSField(NodeFieldMask);

    return &_sfNode;
}

//! Get the SceneObject::_sfScene field.
const SFUnrecScenePtr *SceneObjectBase::getSFScene(void) const
{
    return &_sfScene;
}

SFUnrecScenePtr     *SceneObjectBase::editSFScene          (void)
{
    editSField(SceneFieldMask);

    return &_sfScene;
}



void SceneObjectBase::pushToBehaviors(Behavior * const value)
{
    editMField(BehaviorsFieldMask, _mfBehaviors);

    _mfBehaviors.push_back(value);
}

void SceneObjectBase::assignBehaviors(const MFUnrecChildBehaviorPtr &value)
{
    MFUnrecChildBehaviorPtr::const_iterator elemIt  =
        value.begin();
    MFUnrecChildBehaviorPtr::const_iterator elemEnd =
        value.end  ();

    static_cast<SceneObject *>(this)->clearBehaviors();

    while(elemIt != elemEnd)
    {
        this->pushToBehaviors(*elemIt);

        ++elemIt;
    }
}

void SceneObjectBase::removeFromBehaviors(UInt32 uiIndex)
{
    if(uiIndex < _mfBehaviors.size())
    {
        editMField(BehaviorsFieldMask, _mfBehaviors);

        _mfBehaviors.erase(uiIndex);
    }
}

void SceneObjectBase::removeObjFromBehaviors(Behavior * const value)
{
    Int32 iElemIdx = _mfBehaviors.findIndex(value);

    if(iElemIdx != -1)
    {
        editMField(BehaviorsFieldMask, _mfBehaviors);

        _mfBehaviors.erase(iElemIdx);
    }
}
void SceneObjectBase::clearBehaviors(void)
{
    editMField(BehaviorsFieldMask, _mfBehaviors);


    _mfBehaviors.clear();
}

void SceneObjectBase::pushToAttachedEffects(Effect * const value)
{
    editMField(AttachedEffectsFieldMask, _mfAttachedEffects);

    _mfAttachedEffects.push_back(value);
}

void SceneObjectBase::assignAttachedEffects(const MFUnrecChildEffectPtr &value)
{
    MFUnrecChildEffectPtr::const_iterator elemIt  =
        value.begin();
    MFUnrecChildEffectPtr::const_iterator elemEnd =
        value.end  ();

    static_cast<SceneObject *>(this)->clearAttachedEffects();

    while(elemIt != elemEnd)
    {
        this->pushToAttachedEffects(*elemIt);

        ++elemIt;
    }
}

void SceneObjectBase::removeFromAttachedEffects(UInt32 uiIndex)
{
    if(uiIndex < _mfAttachedEffects.size())
    {
        editMField(AttachedEffectsFieldMask, _mfAttachedEffects);

        _mfAttachedEffects.erase(uiIndex);
    }
}

void SceneObjectBase::removeObjFromAttachedEffects(Effect * const value)
{
    Int32 iElemIdx = _mfAttachedEffects.findIndex(value);

    if(iElemIdx != -1)
    {
        editMField(AttachedEffectsFieldMask, _mfAttachedEffects);

        _mfAttachedEffects.erase(iElemIdx);
    }
}
void SceneObjectBase::clearAttachedEffects(void)
{
    editMField(AttachedEffectsFieldMask, _mfAttachedEffects);


    _mfAttachedEffects.clear();
}



/*------------------------------ access -----------------------------------*/

UInt32 SceneObjectBase::getBinSize(ConstFieldMaskArg whichField)
{
    UInt32 returnValue = Inherited::getBinSize(whichField);

    if(FieldBits::NoField != (BehaviorsFieldMask & whichField))
    {
        returnValue += _mfBehaviors.getBinSize();
    }
    if(FieldBits::NoField != (AttachedEffectsFieldMask & whichField))
    {
        returnValue += _mfAttachedEffects.getBinSize();
    }
    if(FieldBits::NoField != (NodeFieldMask & whichField))
    {
        returnValue += _sfNode.getBinSize();
    }
    if(FieldBits::NoField != (SceneFieldMask & whichField))
    {
        returnValue += _sfScene.getBinSize();
    }

    return returnValue;
}

void SceneObjectBase::copyToBin(BinaryDataHandler &pMem,
                                  ConstFieldMaskArg  whichField)
{
    Inherited::copyToBin(pMem, whichField);

    if(FieldBits::NoField != (BehaviorsFieldMask & whichField))
    {
        _mfBehaviors.copyToBin(pMem);
    }
    if(FieldBits::NoField != (AttachedEffectsFieldMask & whichField))
    {
        _mfAttachedEffects.copyToBin(pMem);
    }
    if(FieldBits::NoField != (NodeFieldMask & whichField))
    {
        _sfNode.copyToBin(pMem);
    }
    if(FieldBits::NoField != (SceneFieldMask & whichField))
    {
        _sfScene.copyToBin(pMem);
    }
}

void SceneObjectBase::copyFromBin(BinaryDataHandler &pMem,
                                    ConstFieldMaskArg  whichField)
{
    Inherited::copyFromBin(pMem, whichField);

    if(FieldBits::NoField != (BehaviorsFieldMask & whichField))
    {
        _mfBehaviors.copyFromBin(pMem);
    }
    if(FieldBits::NoField != (AttachedEffectsFieldMask & whichField))
    {
        _mfAttachedEffects.copyFromBin(pMem);
    }
    if(FieldBits::NoField != (NodeFieldMask & whichField))
    {
        _sfNode.copyFromBin(pMem);
    }
    if(FieldBits::NoField != (SceneFieldMask & whichField))
    {
        _sfScene.copyFromBin(pMem);
    }
}

//! create a new instance of the class
SceneObjectTransitPtr SceneObjectBase::createLocal(BitVector bFlags)
{
    SceneObjectTransitPtr fc;

    if(getClassType().getPrototype() != NULL)
    {
        FieldContainerTransitPtr tmpPtr =
            getClassType().getPrototype()-> shallowCopyLocal(bFlags);

        fc = dynamic_pointer_cast<SceneObject>(tmpPtr);
    }

    return fc;
}

//! create a new instance of the class, copy the container flags
SceneObjectTransitPtr SceneObjectBase::createDependent(BitVector bFlags)
{
    SceneObjectTransitPtr fc;

    if(getClassType().getPrototype() != NULL)
    {
        FieldContainerTransitPtr tmpPtr =
            getClassType().getPrototype()-> shallowCopyDependent(bFlags);

        fc = dynamic_pointer_cast<SceneObject>(tmpPtr);
    }

    return fc;
}

//! create a new instance of the class
SceneObjectTransitPtr SceneObjectBase::create(void)
{
    SceneObjectTransitPtr fc;

    if(getClassType().getPrototype() != NULL)
    {
        FieldContainerTransitPtr tmpPtr =
            getClassType().getPrototype()-> shallowCopy();

        fc = dynamic_pointer_cast<SceneObject>(tmpPtr);
    }

    return fc;
}

SceneObject *SceneObjectBase::createEmptyLocal(BitVector bFlags)
{
    SceneObject *returnValue;

    newPtr<SceneObject>(returnValue, bFlags);

    returnValue->_pFieldFlags->_bNamespaceMask &= ~bFlags;

    return returnValue;
}

//! create an empty new instance of the class, do not copy the prototype
SceneObject *SceneObjectBase::createEmpty(void)
{
    SceneObject *returnValue;

    newPtr<SceneObject>(returnValue, Thread::getCurrentLocalFlags());

    returnValue->_pFieldFlags->_bNamespaceMask &=
        ~Thread::getCurrentLocalFlags();

    return returnValue;
}


FieldContainerTransitPtr SceneObjectBase::shallowCopyLocal(
    BitVector bFlags) const
{
    SceneObject *tmpPtr;

    newPtr(tmpPtr, dynamic_cast<const SceneObject *>(this), bFlags);

    FieldContainerTransitPtr returnValue(tmpPtr);

    tmpPtr->_pFieldFlags->_bNamespaceMask &= ~bFlags;

    return returnValue;
}

FieldContainerTransitPtr SceneObjectBase::shallowCopyDependent(
    BitVector bFlags) const
{
    SceneObject *tmpPtr;

    newPtr(tmpPtr, dynamic_cast<const SceneObject *>(this), ~bFlags);

    FieldContainerTransitPtr returnValue(tmpPtr);

    tmpPtr->_pFieldFlags->_bNamespaceMask = bFlags;

    return returnValue;
}

FieldContainerTransitPtr SceneObjectBase::shallowCopy(void) const
{
    SceneObject *tmpPtr;

    newPtr(tmpPtr,
           dynamic_cast<const SceneObject *>(this),
           Thread::getCurrentLocalFlags());

    tmpPtr->_pFieldFlags->_bNamespaceMask &= ~Thread::getCurrentLocalFlags();

    FieldContainerTransitPtr returnValue(tmpPtr);

    return returnValue;
}




/*------------------------- constructors ----------------------------------*/

SceneObjectBase::SceneObjectBase(void) :
    Inherited(),
    _mfBehaviors              (this,
                          BehaviorsFieldId,
                          Behavior::SceneObjectFieldId),
    _mfAttachedEffects        (this,
                          AttachedEffectsFieldId,
                          Effect::ParentSceneObjectFieldId),
    _sfNode                   (NULL),
    _sfScene                  (NULL)
{
}

SceneObjectBase::SceneObjectBase(const SceneObjectBase &source) :
    Inherited(source),
    _mfBehaviors              (this,
                          BehaviorsFieldId,
                          Behavior::SceneObjectFieldId),
    _mfAttachedEffects        (this,
                          AttachedEffectsFieldId,
                          Effect::ParentSceneObjectFieldId),
    _sfNode                   (NULL),
    _sfScene                  (NULL)
{
}


/*-------------------------- destructors ----------------------------------*/

SceneObjectBase::~SceneObjectBase(void)
{
}

/*-------------------------------------------------------------------------*/
/* Child linking                                                           */

bool SceneObjectBase::unlinkChild(
    FieldContainer * const pChild,
    UInt16           const childFieldId)
{
    if(childFieldId == BehaviorsFieldId)
    {
        Behavior * pTypedChild =
            dynamic_cast<Behavior *>(pChild);

        if(pTypedChild != NULL)
        {
            Int32 iChildIdx = _mfBehaviors.findIndex(pTypedChild);

            if(iChildIdx != -1)
            {
                editMField(BehaviorsFieldMask, _mfBehaviors);

                _mfBehaviors.erase(iChildIdx);

                return true;
            }

            FWARNING(("SceneObjectBase::unlinkParent: Child <-> "
                      "Parent link inconsistent.\n"));

            return false;
        }

        return false;
    }

    if(childFieldId == AttachedEffectsFieldId)
    {
        Effect * pTypedChild =
            dynamic_cast<Effect *>(pChild);

        if(pTypedChild != NULL)
        {
            Int32 iChildIdx = _mfAttachedEffects.findIndex(pTypedChild);

            if(iChildIdx != -1)
            {
                editMField(AttachedEffectsFieldMask, _mfAttachedEffects);

                _mfAttachedEffects.erase(iChildIdx);

                return true;
            }

            FWARNING(("SceneObjectBase::unlinkParent: Child <-> "
                      "Parent link inconsistent.\n"));

            return false;
        }

        return false;
    }


    return Inherited::unlinkChild(pChild, childFieldId);
}

void SceneObjectBase::onCreate(const SceneObject *source)
{
    Inherited::onCreate(source);

    if(source != NULL)
    {
        SceneObject *pThis = static_cast<SceneObject *>(this);

        MFUnrecChildBehaviorPtr::const_iterator BehaviorsIt  =
            source->_mfBehaviors.begin();
        MFUnrecChildBehaviorPtr::const_iterator BehaviorsEnd =
            source->_mfBehaviors.end  ();

        while(BehaviorsIt != BehaviorsEnd)
        {
            pThis->pushToBehaviors(*BehaviorsIt);

            ++BehaviorsIt;
        }

        MFUnrecChildEffectPtr::const_iterator AttachedEffectsIt  =
            source->_mfAttachedEffects.begin();
        MFUnrecChildEffectPtr::const_iterator AttachedEffectsEnd =
            source->_mfAttachedEffects.end  ();

        while(AttachedEffectsIt != AttachedEffectsEnd)
        {
            pThis->pushToAttachedEffects(*AttachedEffectsIt);

            ++AttachedEffectsIt;
        }

        pThis->setNode(source->getNode());

        pThis->setScene(source->getScene());
    }
}

GetFieldHandlePtr SceneObjectBase::getHandleBehaviors       (void) const
{
    MFUnrecChildBehaviorPtr::GetHandlePtr returnValue(
        new  MFUnrecChildBehaviorPtr::GetHandle(
             &_mfBehaviors,
             this->getType().getFieldDesc(BehaviorsFieldId),
             const_cast<SceneObjectBase *>(this)));

    return returnValue;
}

EditFieldHandlePtr SceneObjectBase::editHandleBehaviors      (void)
{
    MFUnrecChildBehaviorPtr::EditHandlePtr returnValue(
        new  MFUnrecChildBehaviorPtr::EditHandle(
             &_mfBehaviors,
             this->getType().getFieldDesc(BehaviorsFieldId),
             this));

    returnValue->setAddMethod(
        boost::bind(&SceneObject::pushToBehaviors,
                    static_cast<SceneObject *>(this), _1));
    returnValue->setRemoveMethod(
        boost::bind(&SceneObject::removeFromBehaviors,
                    static_cast<SceneObject *>(this), _1));
    returnValue->setRemoveObjMethod(
        boost::bind(&SceneObject::removeObjFromBehaviors,
                    static_cast<SceneObject *>(this), _1));
    returnValue->setClearMethod(
        boost::bind(&SceneObject::clearBehaviors,
                    static_cast<SceneObject *>(this)));

    editMField(BehaviorsFieldMask, _mfBehaviors);

    return returnValue;
}

GetFieldHandlePtr SceneObjectBase::getHandleAttachedEffects (void) const
{
    MFUnrecChildEffectPtr::GetHandlePtr returnValue(
        new  MFUnrecChildEffectPtr::GetHandle(
             &_mfAttachedEffects,
             this->getType().getFieldDesc(AttachedEffectsFieldId),
             const_cast<SceneObjectBase *>(this)));

    return returnValue;
}

EditFieldHandlePtr SceneObjectBase::editHandleAttachedEffects(void)
{
    MFUnrecChildEffectPtr::EditHandlePtr returnValue(
        new  MFUnrecChildEffectPtr::EditHandle(
             &_mfAttachedEffects,
             this->getType().getFieldDesc(AttachedEffectsFieldId),
             this));

    returnValue->setAddMethod(
        boost::bind(&SceneObject::pushToAttachedEffects,
                    static_cast<SceneObject *>(this), _1));
    returnValue->setRemoveMethod(
        boost::bind(&SceneObject::removeFromAttachedEffects,
                    static_cast<SceneObject *>(this), _1));
    returnValue->setRemoveObjMethod(
        boost::bind(&SceneObject::removeObjFromAttachedEffects,
                    static_cast<SceneObject *>(this), _1));
    returnValue->setClearMethod(
        boost::bind(&SceneObject::clearAttachedEffects,
                    static_cast<SceneObject *>(this)));

    editMField(AttachedEffectsFieldMask, _mfAttachedEffects);

    return returnValue;
}

GetFieldHandlePtr SceneObjectBase::getHandleNode            (void) const
{
    SFUnrecNodePtr::GetHandlePtr returnValue(
        new  SFUnrecNodePtr::GetHandle(
             &_sfNode,
             this->getType().getFieldDesc(NodeFieldId),
             const_cast<SceneObjectBase *>(this)));

    return returnValue;
}

EditFieldHandlePtr SceneObjectBase::editHandleNode           (void)
{
    SFUnrecNodePtr::EditHandlePtr returnValue(
        new  SFUnrecNodePtr::EditHandle(
             &_sfNode,
             this->getType().getFieldDesc(NodeFieldId),
             this));

    returnValue->setSetMethod(
        boost::bind(&SceneObject::setNode,
                    static_cast<SceneObject *>(this), _1));

    editSField(NodeFieldMask);

    return returnValue;
}

GetFieldHandlePtr SceneObjectBase::getHandleScene           (void) const
{
    SFUnrecScenePtr::GetHandlePtr returnValue(
        new  SFUnrecScenePtr::GetHandle(
             &_sfScene,
             this->getType().getFieldDesc(SceneFieldId),
             const_cast<SceneObjectBase *>(this)));

    return returnValue;
}

EditFieldHandlePtr SceneObjectBase::editHandleScene          (void)
{
    SFUnrecScenePtr::EditHandlePtr returnValue(
        new  SFUnrecScenePtr::EditHandle(
             &_sfScene,
             this->getType().getFieldDesc(SceneFieldId),
             this));

    returnValue->setSetMethod(
        boost::bind(&SceneObject::setScene,
                    static_cast<SceneObject *>(this), _1));

    editSField(SceneFieldMask);

    return returnValue;
}


#ifdef OSG_MT_CPTR_ASPECT
void SceneObjectBase::execSyncV(      FieldContainer    &oFrom,
                                        ConstFieldMaskArg  whichField,
                                        AspectOffsetStore &oOffsets,
                                        ConstFieldMaskArg  syncMode,
                                  const UInt32             uiSyncInfo)
{
    SceneObject *pThis = static_cast<SceneObject *>(this);

    pThis->execSync(static_cast<SceneObject *>(&oFrom),
                    whichField,
                    oOffsets,
                    syncMode,
                    uiSyncInfo);
}
#endif


#ifdef OSG_MT_CPTR_ASPECT
FieldContainer *SceneObjectBase::createAspectCopy(
    const FieldContainer *pRefAspect) const
{
    SceneObject *returnValue;

    newAspectCopy(returnValue,
                  dynamic_cast<const SceneObject *>(pRefAspect),
                  dynamic_cast<const SceneObject *>(this));

    return returnValue;
}
#endif

void SceneObjectBase::resolveLinks(void)
{
    Inherited::resolveLinks();

    static_cast<SceneObject *>(this)->clearBehaviors();

    static_cast<SceneObject *>(this)->clearAttachedEffects();

    static_cast<SceneObject *>(this)->setNode(NULL);

    static_cast<SceneObject *>(this)->setScene(NULL);


}


OSG_END_NAMESPACE
