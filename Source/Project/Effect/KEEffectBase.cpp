/*---------------------------------------------------------------------------*\
 *                             Kabala Engine                                 *
 *                                                                           *
 *               Copyright (C) 2009-2010 by David Kabala                     *
 *                                                                           *
 *   authors:  Robert Goetz (rdgoetz@iastate.edu)                            *
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
 **     class Effect!
 **                                                                         **
 *****************************************************************************
\*****************************************************************************/

#include <cstdlib>
#include <cstdio>
#include <boost/assign/list_of.hpp>

#include <OpenSG/OSGConfig.h>



#include <OpenSG/OSGFieldContainer.h>   // ParentSceneObject Class

#include "KEEffectBase.h"
#include "KEEffect.h"

#include <boost/bind.hpp>

#include <OpenSG/OSGEventDetails.h>

#ifdef WIN32 // turn off 'this' : used in base member initializer list warning
#pragma warning(disable:4355)
#endif

OSG_BEGIN_NAMESPACE

/***************************************************************************\
 *                            Description                                  *
\***************************************************************************/

/*! \class OSG::Effect
    The SceneObject.
 */

/***************************************************************************\
 *                        Field Documentation                              *
\***************************************************************************/

/*! \var FieldContainer * EffectBase::_sfParentSceneObject
    
*/


/***************************************************************************\
 *                      FieldType/FieldTrait Instantiation                 *
\***************************************************************************/

#if !defined(OSG_DO_DOC) || defined(OSG_DOC_DEV)
DataType FieldTraits<Effect *>::_type("EffectPtr", "AttachmentContainerPtr");
#endif

OSG_FIELDTRAITS_GETTYPE(Effect *)

OSG_EXPORT_PTR_SFIELD_FULL(PointerSField,
                           Effect *,
                           0);

OSG_EXPORT_PTR_MFIELD_FULL(PointerMField,
                           Effect *,
                           0);

DataType &FieldTraits< Effect *, 1 >::getType(void)
{
    return FieldTraits<Effect *, 0>::getType();
}


OSG_EXPORT_PTR_MFIELD(ChildPointerMField,
                      Effect *,
                      UnrecordedRefCountPolicy,
                      1);


/***************************************************************************\
 *                         Field Description                               *
\***************************************************************************/

void EffectBase::classDescInserter(TypeObject &oType)
{
    FieldDescriptionBase *pDesc = NULL;


    pDesc = new SFParentFieldContainerPtr::Description(
        SFParentFieldContainerPtr::getClassType(),
        "ParentSceneObject",
        "",
        ParentSceneObjectFieldId, ParentSceneObjectFieldMask,
        false,
        (Field::SFDefaultFlags | Field::FStdAccess),
        static_cast     <FieldEditMethodSig>(&Effect::invalidEditField),
        static_cast     <FieldGetMethodSig >(&Effect::invalidGetField));

    oType.addInitialDesc(pDesc);
}


EffectBase::TypeObject EffectBase::_type(
    EffectBase::getClassname(),
    Inherited::getClassname(),
    "NULL",
    0,
    NULL,
    Effect::initMethod,
    Effect::exitMethod,
    reinterpret_cast<InitalInsertDescFunc>(&Effect::classDescInserter),
    false,
    0,
    "<?xml version=\"1.0\"?>\n"
    "\n"
    "<FieldContainer\n"
    "\tname=\"Effect\"\n"
    "\tparent=\"AttachmentContainer\"\n"
    "\tlibrary=\"KabalaEngine\"\n"
    "\tpointerfieldtypes=\"both\"\n"
    "\tstructure=\"abstract\"\n"
    "\tsystemcomponent=\"false\"\n"
    "\tparentsystemcomponent=\"true\"\n"
    "\tdecoratable=\"false\"\n"
    "\tuseLocalIncludes=\"false\"\n"
    "\tlibnamespace=\"KE\"\n"
    "    childFields=\"multi\"\n"
    "    authors=\"Robert Goetz (rdgoetz@iastate.edu)                            \"\n"
    ">\n"
    "The SceneObject.\n"
    "    <Field\n"
    "\t\tname=\"ParentSceneObject\"\n"
    "\t\ttype=\"FieldContainer\"\n"
    "\t\tcategory=\"parentpointer\"\n"
    "\t\tcardinality=\"single\"\n"
    "\t\tvisibility=\"external\"\n"
    "\t\taccess=\"none\"\n"
    "\t\tdefaultValue=\"NULL\"\n"
    "        doRefCount=\"false\"\n"
    "        passFieldMask=\"true\"\n"
    "\t>\n"
    "\t</Field>\n"
    "    <ProducedEvent\n"
    "\t\tname=\"EffectBegan\"\n"
    "\t\tdetailsType=\"EffectEventDetails\"\n"
    "\t\tfieldHeader=\"Project/Effect/KEEffectEventDetailsFields.h\"\n"
    "\t\ttypeHeader=\"Project/Effect/KEEffectEventDetails.h\"\n"
    "\t\tconsumable=\"true\"\n"
    "\t>\n"
    "\t</ProducedEvent>\n"
    "\t<ProducedEvent\n"
    "\t\tname=\"EffectPaused\"\n"
    "\t\tdetailsType=\"EffectEventDetails\"\n"
    "\t\tfieldHeader=\"Project/Effect/KEEffectEventDetailsFields.h\"\n"
    "\t\ttypeHeader=\"Project/Effect/KEEffectEventDetails.h\"\n"
    "\t\tconsumable=\"true\"\n"
    "\t>\n"
    "\t</ProducedEvent>\n"
    "\t<ProducedEvent\n"
    "\t\tname=\"EffectUnpaused\"\n"
    "\t\tdetailsType=\"EffectEventDetails\"\n"
    "\t\tfieldHeader=\"Project/Effect/KEEffectEventDetailsFields.h\"\n"
    "\t\ttypeHeader=\"Project/Effect/KEEffectEventDetails.h\"\n"
    "\t\tconsumable=\"true\"\n"
    "\t>\n"
    "\t</ProducedEvent>\n"
    "\t<ProducedEvent\n"
    "\t\tname=\"EffectFinished\"\n"
    "\t\tdetailsType=\"EffectEventDetails\"\n"
    "\t\tfieldHeader=\"Project/Effect/KEEffectEventDetailsFields.h\"\n"
    "\t\ttypeHeader=\"Project/Effect/KEEffectEventDetails.h\"\n"
    "\t\tconsumable=\"true\"\n"
    "\t>\n"
    "\t</ProducedEvent>\n"
    "\t<ProducedEvent\n"
    "\t\tname=\"EffectStopped\"\n"
    "\t\tdetailsType=\"EffectEventDetails\"\n"
    "\t\tfieldHeader=\"Project/Effect/KEEffectEventDetailsFields.h\"\n"
    "\t\ttypeHeader=\"Project/Effect/KEEffectEventDetails.h\"\n"
    "\t\tconsumable=\"true\"\n"
    "\t>\n"
    "\t</ProducedEvent>\n"
    "</FieldContainer>\n",
    "The SceneObject.\n"
    );

//! Effect Produced Events

EventDescription *EffectBase::_eventDesc[] =
{
    new EventDescription("EffectBegan", 
                          "",
                          EffectBeganEventId, 
                          FieldTraits<EffectEventDetails *>::getType(),
                          true,
                          static_cast<EventGetMethod>(&EffectBase::getHandleEffectBeganSignal)),

    new EventDescription("EffectPaused", 
                          "",
                          EffectPausedEventId, 
                          FieldTraits<EffectEventDetails *>::getType(),
                          true,
                          static_cast<EventGetMethod>(&EffectBase::getHandleEffectPausedSignal)),

    new EventDescription("EffectUnpaused", 
                          "",
                          EffectUnpausedEventId, 
                          FieldTraits<EffectEventDetails *>::getType(),
                          true,
                          static_cast<EventGetMethod>(&EffectBase::getHandleEffectUnpausedSignal)),

    new EventDescription("EffectFinished", 
                          "",
                          EffectFinishedEventId, 
                          FieldTraits<EffectEventDetails *>::getType(),
                          true,
                          static_cast<EventGetMethod>(&EffectBase::getHandleEffectFinishedSignal)),

    new EventDescription("EffectStopped", 
                          "",
                          EffectStoppedEventId, 
                          FieldTraits<EffectEventDetails *>::getType(),
                          true,
                          static_cast<EventGetMethod>(&EffectBase::getHandleEffectStoppedSignal))

};

EventProducerType EffectBase::_producerType(
    "EffectProducerType",
    "EventProducerType",
    "",
    InitEventProducerFunctor(),
    _eventDesc,
    sizeof(_eventDesc));

/*------------------------------ get -----------------------------------*/

FieldContainerType &EffectBase::getType(void)
{
    return _type;
}

const FieldContainerType &EffectBase::getType(void) const
{
    return _type;
}

const EventProducerType &EffectBase::getProducerType(void) const
{
    return _producerType;
}

UInt32 EffectBase::getContainerSize(void) const
{
    return sizeof(Effect);
}

/*------------------------- decorator get ------------------------------*/







/*------------------------------ access -----------------------------------*/

UInt32 EffectBase::getBinSize(ConstFieldMaskArg whichField)
{
    UInt32 returnValue = Inherited::getBinSize(whichField);

    if(FieldBits::NoField != (ParentSceneObjectFieldMask & whichField))
    {
        returnValue += _sfParentSceneObject.getBinSize();
    }

    return returnValue;
}

void EffectBase::copyToBin(BinaryDataHandler &pMem,
                                  ConstFieldMaskArg  whichField)
{
    Inherited::copyToBin(pMem, whichField);

    if(FieldBits::NoField != (ParentSceneObjectFieldMask & whichField))
    {
        _sfParentSceneObject.copyToBin(pMem);
    }
}

void EffectBase::copyFromBin(BinaryDataHandler &pMem,
                                    ConstFieldMaskArg  whichField)
{
    Inherited::copyFromBin(pMem, whichField);

    if(FieldBits::NoField != (ParentSceneObjectFieldMask & whichField))
    {
        _sfParentSceneObject.copyFromBin(pMem);
    }
}



/*------------------------- event producers ----------------------------------*/
void EffectBase::produceEvent(UInt32 eventId, EventDetails* const e)
{
    switch(eventId)
    {
    case EffectBeganEventId:
        OSG_ASSERT(dynamic_cast<EffectBeganEventDetailsType* const>(e));

        _EffectBeganEvent.set_combiner(ConsumableEventCombiner(e));
        _EffectBeganEvent(dynamic_cast<EffectBeganEventDetailsType* const>(e), EffectBeganEventId);
        break;
    case EffectPausedEventId:
        OSG_ASSERT(dynamic_cast<EffectPausedEventDetailsType* const>(e));

        _EffectPausedEvent.set_combiner(ConsumableEventCombiner(e));
        _EffectPausedEvent(dynamic_cast<EffectPausedEventDetailsType* const>(e), EffectPausedEventId);
        break;
    case EffectUnpausedEventId:
        OSG_ASSERT(dynamic_cast<EffectUnpausedEventDetailsType* const>(e));

        _EffectUnpausedEvent.set_combiner(ConsumableEventCombiner(e));
        _EffectUnpausedEvent(dynamic_cast<EffectUnpausedEventDetailsType* const>(e), EffectUnpausedEventId);
        break;
    case EffectFinishedEventId:
        OSG_ASSERT(dynamic_cast<EffectFinishedEventDetailsType* const>(e));

        _EffectFinishedEvent.set_combiner(ConsumableEventCombiner(e));
        _EffectFinishedEvent(dynamic_cast<EffectFinishedEventDetailsType* const>(e), EffectFinishedEventId);
        break;
    case EffectStoppedEventId:
        OSG_ASSERT(dynamic_cast<EffectStoppedEventDetailsType* const>(e));

        _EffectStoppedEvent.set_combiner(ConsumableEventCombiner(e));
        _EffectStoppedEvent(dynamic_cast<EffectStoppedEventDetailsType* const>(e), EffectStoppedEventId);
        break;
    default:
        SWARNING << "No event defined with that ID";
        break;
    }
}

boost::signals2::connection EffectBase::connectEvent(UInt32 eventId, 
                                                             const BaseEventType::slot_type &listener, 
                                                             boost::signals2::connect_position at)
{
    switch(eventId)
    {
    case EffectBeganEventId:
        return _EffectBeganEvent.connect(listener, at);
        break;
    case EffectPausedEventId:
        return _EffectPausedEvent.connect(listener, at);
        break;
    case EffectUnpausedEventId:
        return _EffectUnpausedEvent.connect(listener, at);
        break;
    case EffectFinishedEventId:
        return _EffectFinishedEvent.connect(listener, at);
        break;
    case EffectStoppedEventId:
        return _EffectStoppedEvent.connect(listener, at);
        break;
    default:
        SWARNING << "No event defined with that ID";
        return boost::signals2::connection();
        break;
    }

    return boost::signals2::connection();
}

boost::signals2::connection  EffectBase::connectEvent(UInt32 eventId, 
                                                              const BaseEventType::group_type &group,
                                                              const BaseEventType::slot_type &listener,
                                                              boost::signals2::connect_position at)
{
    switch(eventId)
    {
    case EffectBeganEventId:
        return _EffectBeganEvent.connect(group, listener, at);
        break;
    case EffectPausedEventId:
        return _EffectPausedEvent.connect(group, listener, at);
        break;
    case EffectUnpausedEventId:
        return _EffectUnpausedEvent.connect(group, listener, at);
        break;
    case EffectFinishedEventId:
        return _EffectFinishedEvent.connect(group, listener, at);
        break;
    case EffectStoppedEventId:
        return _EffectStoppedEvent.connect(group, listener, at);
        break;
    default:
        SWARNING << "No event defined with that ID";
        return boost::signals2::connection();
        break;
    }

    return boost::signals2::connection();
}
    
void  EffectBase::disconnectEvent(UInt32 eventId, const BaseEventType::group_type &group)
{
    switch(eventId)
    {
    case EffectBeganEventId:
        _EffectBeganEvent.disconnect(group);
        break;
    case EffectPausedEventId:
        _EffectPausedEvent.disconnect(group);
        break;
    case EffectUnpausedEventId:
        _EffectUnpausedEvent.disconnect(group);
        break;
    case EffectFinishedEventId:
        _EffectFinishedEvent.disconnect(group);
        break;
    case EffectStoppedEventId:
        _EffectStoppedEvent.disconnect(group);
        break;
    default:
        SWARNING << "No event defined with that ID";
        break;
    }
}

void  EffectBase::disconnectAllSlotsEvent(UInt32 eventId)
{
    switch(eventId)
    {
    case EffectBeganEventId:
        _EffectBeganEvent.disconnect_all_slots();
        break;
    case EffectPausedEventId:
        _EffectPausedEvent.disconnect_all_slots();
        break;
    case EffectUnpausedEventId:
        _EffectUnpausedEvent.disconnect_all_slots();
        break;
    case EffectFinishedEventId:
        _EffectFinishedEvent.disconnect_all_slots();
        break;
    case EffectStoppedEventId:
        _EffectStoppedEvent.disconnect_all_slots();
        break;
    default:
        SWARNING << "No event defined with that ID";
        break;
    }
}

bool  EffectBase::isEmptyEvent(UInt32 eventId) const
{
    switch(eventId)
    {
    case EffectBeganEventId:
        return _EffectBeganEvent.empty();
        break;
    case EffectPausedEventId:
        return _EffectPausedEvent.empty();
        break;
    case EffectUnpausedEventId:
        return _EffectUnpausedEvent.empty();
        break;
    case EffectFinishedEventId:
        return _EffectFinishedEvent.empty();
        break;
    case EffectStoppedEventId:
        return _EffectStoppedEvent.empty();
        break;
    default:
        SWARNING << "No event defined with that ID";
        return true;
        break;
    }
}

UInt32  EffectBase::numSlotsEvent(UInt32 eventId) const
{
    switch(eventId)
    {
    case EffectBeganEventId:
        return _EffectBeganEvent.num_slots();
        break;
    case EffectPausedEventId:
        return _EffectPausedEvent.num_slots();
        break;
    case EffectUnpausedEventId:
        return _EffectUnpausedEvent.num_slots();
        break;
    case EffectFinishedEventId:
        return _EffectFinishedEvent.num_slots();
        break;
    case EffectStoppedEventId:
        return _EffectStoppedEvent.num_slots();
        break;
    default:
        SWARNING << "No event defined with that ID";
        return 0;
        break;
    }
}


/*------------------------- constructors ----------------------------------*/

EffectBase::EffectBase(void) :
    Inherited(),
    _sfParentSceneObject      (NULL)
{
}

EffectBase::EffectBase(const EffectBase &source) :
    Inherited(source),
    _sfParentSceneObject      (NULL)
{
}


/*-------------------------- destructors ----------------------------------*/

EffectBase::~EffectBase(void)
{
}
/*-------------------------------------------------------------------------*/
/* Parent linking                                                          */

bool EffectBase::linkParent(
    FieldContainer * const pParent,
    UInt16           const childFieldId,
    UInt16           const parentFieldId )
{
    if(parentFieldId == ParentSceneObjectFieldId)
    {
        FieldContainer * pTypedParent =
            dynamic_cast< FieldContainer * >(pParent);

        if(pTypedParent != NULL)
        {
            FieldContainer *pOldParent =
                _sfParentSceneObject.getValue         ();

            UInt16 oldChildFieldId =
                _sfParentSceneObject.getParentFieldPos();

            if(pOldParent != NULL)
            {
                pOldParent->unlinkChild(this, oldChildFieldId);
            }

            editSField(ParentSceneObjectFieldMask);

            _sfParentSceneObject.setValue(static_cast<FieldContainer *>(pParent), childFieldId);

            return true;
        }

        return false;
    }

    return Inherited::linkParent(pParent, childFieldId, parentFieldId);
}

bool EffectBase::unlinkParent(
    FieldContainer * const pParent,
    UInt16           const parentFieldId)
{
    if(parentFieldId == ParentSceneObjectFieldId)
    {
        FieldContainer * pTypedParent =
            dynamic_cast< FieldContainer * >(pParent);

        if(pTypedParent != NULL)
        {
            if(_sfParentSceneObject.getValue() == pParent)
            {
                editSField(ParentSceneObjectFieldMask);

                _sfParentSceneObject.setValue(NULL, 0xFFFF);

                return true;
            }

            FWARNING(("EffectBase::unlinkParent: "
                      "Child <-> Parent link inconsistent.\n"));

            return false;
        }

        return false;
    }

    return Inherited::unlinkParent(pParent, parentFieldId);
}



GetFieldHandlePtr EffectBase::getHandleParentSceneObject (void) const
{
    SFParentFieldContainerPtr::GetHandlePtr returnValue;

    return returnValue;
}

EditFieldHandlePtr EffectBase::editHandleParentSceneObject(void)
{
    EditFieldHandlePtr returnValue;

    return returnValue;
}


GetEventHandlePtr EffectBase::getHandleEffectBeganSignal(void) const
{
    GetEventHandlePtr returnValue(
        new  GetTypedEventHandle<EffectBeganEventType>(
             const_cast<EffectBeganEventType *>(&_EffectBeganEvent),
             _producerType.getEventDescription(EffectBeganEventId),
             const_cast<EffectBase *>(this)));

    return returnValue;
}

GetEventHandlePtr EffectBase::getHandleEffectPausedSignal(void) const
{
    GetEventHandlePtr returnValue(
        new  GetTypedEventHandle<EffectPausedEventType>(
             const_cast<EffectPausedEventType *>(&_EffectPausedEvent),
             _producerType.getEventDescription(EffectPausedEventId),
             const_cast<EffectBase *>(this)));

    return returnValue;
}

GetEventHandlePtr EffectBase::getHandleEffectUnpausedSignal(void) const
{
    GetEventHandlePtr returnValue(
        new  GetTypedEventHandle<EffectUnpausedEventType>(
             const_cast<EffectUnpausedEventType *>(&_EffectUnpausedEvent),
             _producerType.getEventDescription(EffectUnpausedEventId),
             const_cast<EffectBase *>(this)));

    return returnValue;
}

GetEventHandlePtr EffectBase::getHandleEffectFinishedSignal(void) const
{
    GetEventHandlePtr returnValue(
        new  GetTypedEventHandle<EffectFinishedEventType>(
             const_cast<EffectFinishedEventType *>(&_EffectFinishedEvent),
             _producerType.getEventDescription(EffectFinishedEventId),
             const_cast<EffectBase *>(this)));

    return returnValue;
}

GetEventHandlePtr EffectBase::getHandleEffectStoppedSignal(void) const
{
    GetEventHandlePtr returnValue(
        new  GetTypedEventHandle<EffectStoppedEventType>(
             const_cast<EffectStoppedEventType *>(&_EffectStoppedEvent),
             _producerType.getEventDescription(EffectStoppedEventId),
             const_cast<EffectBase *>(this)));

    return returnValue;
}


#ifdef OSG_MT_CPTR_ASPECT
void EffectBase::execSyncV(      FieldContainer    &oFrom,
                                        ConstFieldMaskArg  whichField,
                                        AspectOffsetStore &oOffsets,
                                        ConstFieldMaskArg  syncMode,
                                  const UInt32             uiSyncInfo)
{
    Effect *pThis = static_cast<Effect *>(this);

    pThis->execSync(static_cast<Effect *>(&oFrom),
                    whichField,
                    oOffsets,
                    syncMode,
                    uiSyncInfo);
}
#endif



void EffectBase::resolveLinks(void)
{
    Inherited::resolveLinks();


}


OSG_END_NAMESPACE
