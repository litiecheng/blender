/*
 * ***** BEGIN GPL LICENSE BLOCK *****
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 *
 * The Original Code is Copyright (C) 2001-2002 by NaN Holding BV.
 * All rights reserved.
 *
 * The Original Code is: all of this file.
 *
 * Contributor(s): none yet.
 *
 * ***** END GPL LICENSE BLOCK *****
 */

/** \file KX_ReplaceMeshActuator.h
 *  \ingroup ketsji
 *  \brief Add object to the game world on action of this actuator
 *  \attention Previously existed as: source/gameengine/GameLogic/SCA_ReplaceMeshActuator.h
 *  Please look here for revision history.
 */

#ifndef __KX_REPLACEMESHACTUATOR_H__
#define __KX_REPLACEMESHACTUATOR_H__

#include "SCA_IActuator.h"
#include "SCA_PropertyActuator.h"
#include "SCA_LogicManager.h"

class KX_Mesh;
class KX_GameObject;

class KX_ReplaceMeshActuator : public SCA_IActuator
{
	Py_Header

	// mesh reference (mesh to replace)
	KX_Mesh *m_mesh;
	bool m_use_gfx; 
	bool m_use_phys;

 public:
	KX_ReplaceMeshActuator(
		KX_GameObject *gameobj, 
		KX_Mesh *mesh, 
		bool use_gfx,
		bool use_phys
	);

	~KX_ReplaceMeshActuator(
	);

		EXP_Value* 
	GetReplica(
	);

	virtual bool 
	Update();

	void	InstantReplaceMesh();

#ifdef WITH_PYTHON

	/* --------------------------------------------------------------------- */
	/* Python interface ---------------------------------------------------- */
	/* --------------------------------------------------------------------- */

	static PyObject *pyattr_get_mesh(EXP_PyObjectPlus *self, const struct EXP_PYATTRIBUTE_DEF *attrdef);
	static int pyattr_set_mesh(EXP_PyObjectPlus *self, const struct EXP_PYATTRIBUTE_DEF *attrdef, PyObject *value);

	EXP_PYMETHOD_DOC(KX_ReplaceMeshActuator,instantReplaceMesh);

#endif  /* WITH_PYTHON */

}; 

#endif  /* __KX_REPLACEMESHACTUATOR_H__ */
