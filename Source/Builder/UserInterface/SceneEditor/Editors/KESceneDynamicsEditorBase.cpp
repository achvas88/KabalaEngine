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

/*****************************************************************************\
 *****************************************************************************
 **                                                                         **
 **                  This file is automatically generated.                  **
 **                                                                         **
 **          Any changes made to this file WILL be lost when it is          **
 **           regenerated, which can become necessary at any time.          **
 **                                                                         **
 **     Do not change this file, changes should be done in the derived      **
 **     class SceneDynamicsEditor!
 **                                                                         **
 *****************************************************************************
\*****************************************************************************/


#define KE_COMPILESCENEDYNAMICSEDITORINST

#include <stdlib.h>
#include <stdio.h>

#include <OpenSG/OSGConfig.h>

#include "KESceneDynamicsEditorBase.h"
#include "KESceneDynamicsEditor.h"


OSG_BEGIN_NAMESPACE

const OSG::BitVector SceneDynamicsEditorBase::MTInfluenceMask = 
    (Inherited::MTInfluenceMask) | 
    (static_cast<BitVector>(0x0) << Inherited::NextFieldId); 



FieldContainerType SceneDynamicsEditorBase::_type(
    "SceneDynamicsEditor",
    "SceneComponentEditor",
    NULL,
    reinterpret_cast<PrototypeCreateF>(&SceneDynamicsEditorBase::createEmpty),
    SceneDynamicsEditor::initMethod,
    NULL,
    0);

//OSG_FIELD_CONTAINER_DEF(SceneDynamicsEditorBase, SceneDynamicsEditorPtr)

/*------------------------------ get -----------------------------------*/

FieldContainerType &SceneDynamicsEditorBase::getType(void) 
{
    return _type; 
} 

const FieldContainerType &SceneDynamicsEditorBase::getType(void) const 
{
    return _type;
} 


FieldContainerPtr SceneDynamicsEditorBase::shallowCopy(void) const 
{ 
    SceneDynamicsEditorPtr returnValue; 

    newPtr(returnValue, dynamic_cast<const SceneDynamicsEditor *>(this)); 

    return returnValue; 
}

UInt32 SceneDynamicsEditorBase::getContainerSize(void) const 
{ 
    return sizeof(SceneDynamicsEditor); 
}


#if !defined(OSG_FIXED_MFIELDSYNC)
void SceneDynamicsEditorBase::executeSync(      FieldContainer &other,
                                    const BitVector      &whichField)
{
    this->executeSyncImpl(static_cast<SceneDynamicsEditorBase *>(&other),
                          whichField);
}
#else
void SceneDynamicsEditorBase::executeSync(      FieldContainer &other,
                                    const BitVector      &whichField,                                    const SyncInfo       &sInfo     )
{
    this->executeSyncImpl((SceneDynamicsEditorBase *) &other, whichField, sInfo);
}
void SceneDynamicsEditorBase::execBeginEdit(const BitVector &whichField, 
                                            UInt32     uiAspect,
                                            UInt32     uiContainerSize) 
{
    this->execBeginEditImpl(whichField, uiAspect, uiContainerSize);
}

void SceneDynamicsEditorBase::onDestroyAspect(UInt32 uiId, UInt32 uiAspect)
{
    Inherited::onDestroyAspect(uiId, uiAspect);

}
#endif

/*------------------------- constructors ----------------------------------*/

#ifdef OSG_WIN32_ICL
#pragma warning (disable : 383)
#endif

SceneDynamicsEditorBase::SceneDynamicsEditorBase(void) :
    Inherited() 
{
}

#ifdef OSG_WIN32_ICL
#pragma warning (default : 383)
#endif

SceneDynamicsEditorBase::SceneDynamicsEditorBase(const SceneDynamicsEditorBase &source) :
    Inherited                 (source)
{
}

/*-------------------------- destructors ----------------------------------*/

SceneDynamicsEditorBase::~SceneDynamicsEditorBase(void)
{
}

/*------------------------------ access -----------------------------------*/

UInt32 SceneDynamicsEditorBase::getBinSize(const BitVector &whichField)
{
    UInt32 returnValue = Inherited::getBinSize(whichField);


    return returnValue;
}

void SceneDynamicsEditorBase::copyToBin(      BinaryDataHandler &pMem,
                                  const BitVector         &whichField)
{
    Inherited::copyToBin(pMem, whichField);


}

void SceneDynamicsEditorBase::copyFromBin(      BinaryDataHandler &pMem,
                                    const BitVector    &whichField)
{
    Inherited::copyFromBin(pMem, whichField);


}

#if !defined(OSG_FIXED_MFIELDSYNC)
void SceneDynamicsEditorBase::executeSyncImpl(      SceneDynamicsEditorBase *pOther,
                                        const BitVector         &whichField)
{

    Inherited::executeSyncImpl(pOther, whichField);


}
#else
void SceneDynamicsEditorBase::executeSyncImpl(      SceneDynamicsEditorBase *pOther,
                                        const BitVector         &whichField,
                                        const SyncInfo          &sInfo      )
{

    Inherited::executeSyncImpl(pOther, whichField, sInfo);



}

void SceneDynamicsEditorBase::execBeginEditImpl (const BitVector &whichField, 
                                                 UInt32     uiAspect,
                                                 UInt32     uiContainerSize)
{
    Inherited::execBeginEditImpl(whichField, uiAspect, uiContainerSize);

}
#endif



OSG_END_NAMESPACE

#include <OpenSG/OSGSFieldTypeDef.inl>
#include <OpenSG/OSGMFieldTypeDef.inl>

OSG_BEGIN_NAMESPACE

#if !defined(OSG_DO_DOC) || defined(OSG_DOC_DEV)
DataType FieldDataTraits<SceneDynamicsEditorPtr>::_type("SceneDynamicsEditorPtr", "SceneComponentEditorPtr");
#endif

OSG_DLLEXPORT_SFIELD_DEF1(SceneDynamicsEditorPtr, KE_KABALAENGINELIB_DLLTMPLMAPPING);
OSG_DLLEXPORT_MFIELD_DEF1(SceneDynamicsEditorPtr, KE_KABALAENGINELIB_DLLTMPLMAPPING);

OSG_END_NAMESPACE

