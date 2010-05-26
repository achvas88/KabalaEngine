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
 **     class BackgroundsListComponentGenerator!
 **                                                                         **
 *****************************************************************************
\*****************************************************************************/

#include <OpenSG/OSGConfig.h>

OSG_BEGIN_NAMESPACE


//! access the type of the class
inline
OSG::FieldContainerType &BackgroundsListComponentGeneratorBase::getClassType(void)
{
    return _type; 
} 

//! access the numerical type of the class
inline
OSG::UInt32 BackgroundsListComponentGeneratorBase::getClassTypeId(void) 
{
    return _type.getId(); 
} 

//! create a new instance of the class
inline
BackgroundsListComponentGeneratorPtr BackgroundsListComponentGeneratorBase::create(void) 
{
    BackgroundsListComponentGeneratorPtr fc; 

    if(getClassType().getPrototype() != OSG::NullFC) 
    {
        fc = BackgroundsListComponentGeneratorPtr::dcast(
            getClassType().getPrototype()-> shallowCopy()); 
    }
    
    return fc; 
}

//! create an empty new instance of the class, do not copy the prototype
inline
BackgroundsListComponentGeneratorPtr BackgroundsListComponentGeneratorBase::createEmpty(void) 
{ 
    BackgroundsListComponentGeneratorPtr returnValue; 
    
    newPtr(returnValue); 

    return returnValue; 
}


/*------------------------------ get -----------------------------------*/

//! Get the BackgroundsListComponentGenerator::_sfIconSize field.
inline
const SFVec2f *BackgroundsListComponentGeneratorBase::getSFIconSize(void) const
{
    return &_sfIconSize;
}

//! Get the BackgroundsListComponentGenerator::_sfIconSize field.
inline
SFVec2f *BackgroundsListComponentGeneratorBase::editSFIconSize(void)
{
    return &_sfIconSize;
}

#ifndef OSG_2_PREP
//! Get the BackgroundsListComponentGenerator::_sfIconSize field.
inline
SFVec2f *BackgroundsListComponentGeneratorBase::getSFIconSize(void)
{
    return &_sfIconSize;
}
#endif


//! Get the value of the BackgroundsListComponentGenerator::_sfIconSize field.
inline
Vec2f &BackgroundsListComponentGeneratorBase::editIconSize(void)
{
    return _sfIconSize.getValue();
}

//! Get the value of the BackgroundsListComponentGenerator::_sfIconSize field.
inline
const Vec2f &BackgroundsListComponentGeneratorBase::getIconSize(void) const
{
    return _sfIconSize.getValue();
}

#ifndef OSG_2_PREP
//! Get the value of the BackgroundsListComponentGenerator::_sfIconSize field.
inline
Vec2f &BackgroundsListComponentGeneratorBase::getIconSize(void)
{
    return _sfIconSize.getValue();
}
#endif

//! Set the value of the BackgroundsListComponentGenerator::_sfIconSize field.
inline
void BackgroundsListComponentGeneratorBase::setIconSize(const Vec2f &value)
{
    _sfIconSize.setValue(value);
}


OSG_END_NAMESPACE

