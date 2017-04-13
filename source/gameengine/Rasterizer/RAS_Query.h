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
 * The Original Code is: all of this file.
 *
 * Contributor(s): Tristan Porteries.
 *
 * ***** END GPL LICENSE BLOCK *****
 */

/** \file RAS_Query.h
 *  \ingroup bgerast
 */

#ifndef __RAS_QUERY_H__
#define __RAS_QUERY_H__

#include <memory>

class RAS_OpenGLQuery;

class RAS_Query
{
private:
	std::unique_ptr<RAS_OpenGLQuery> m_impl;

public:
	enum QueryType {
		SAMPLES = 0,
		ANY_SAMPLES,
		ANY_SAMPLES_CONSERVATIVE,
		PRIMITIVES,
		TIME
	};

	RAS_Query(QueryType type);
	~RAS_Query();

	void Begin();
	void End();

	bool Available();
	int ResultNoWait();
	int Result();
};

#endif  // __RAS_QUERY_H__
