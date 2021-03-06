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

#ifndef _KEAPPLICATIONMODE_H_
#define _KEAPPLICATIONMODE_H_
#ifdef __sgi
#pragma once
#endif

#include "KEApplicationModeBase.h"

OSG_BEGIN_NAMESPACE

/*! \brief ApplicationMode class. See \ref
           PageKabalaEngineApplicationMode for a description.
*/

class KE_KABALAENGINE_DLLMAPPING ApplicationMode : public ApplicationModeBase
{
  protected:

    /*==========================  PUBLIC  =================================*/

  public:

    typedef ApplicationModeBase Inherited;
    typedef ApplicationMode     Self;

    /*---------------------------------------------------------------------*/
    /*! \name                      Sync                                    */
    /*! \{                                                                 */

    virtual void changed(ConstFieldMaskArg whichField,
                         UInt32            origin,
                         BitVector         details    );

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                     Output                                   */
    /*! \{                                                                 */

    virtual void dump(      UInt32     uiIndent = 0,
                      const BitVector  bvFlags  = 0) const;

    /*! \}                                                                 */

	virtual void attachApplication(void);
	virtual void dettachApplication(void);
	virtual void start(void) = 0;
	virtual void stop(void) = 0;
    virtual void reset(void) = 0;

    /*=========================  PROTECTED  ===============================*/

  protected:

    // Variables should all be in ApplicationModeBase.

    /*---------------------------------------------------------------------*/
    /*! \name                  Constructors                                */
    /*! \{                                                                 */

    ApplicationMode(void);
    ApplicationMode(const ApplicationMode &source);

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                   Destructors                                */
    /*! \{                                                                 */

    virtual ~ApplicationMode(void);

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                      Init                                    */
    /*! \{                                                                 */

    static void initMethod(InitPhase ePhase);

    /*! \}                                                                 */
    /*==========================  PRIVATE  ================================*/

  private:

    friend class FieldContainer;
    friend class ApplicationModeBase;

    // prohibit default functions (move to 'public' if you need one)
    void operator =(const ApplicationMode &source);
};

typedef ApplicationMode *ApplicationModeP;

OSG_END_NAMESPACE

#include "KEApplicationModeBase.inl"
#include "KEApplicationMode.inl"

#endif /* _KEAPPLICATIONMODE_H_ */
