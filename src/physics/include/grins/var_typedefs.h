//-----------------------------------------------------------------------bl-
//--------------------------------------------------------------------------
// 
// GRINS - General Reacting Incompressible Navier-Stokes 
//
// Copyright (C) 2010-2013 The PECOS Development Team
//
// This library is free software; you can redistribute it and/or
// modify it under the terms of the Version 2.1 GNU Lesser General
// Public License as published by the Free Software Foundation.
//
// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
// Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public
// License along with this library; if not, write to the Free Software
// Foundation, Inc. 51 Franklin Street, Fifth Floor,
// Boston, MA  02110-1301  USA
//
//-----------------------------------------------------------------------el-
//
// $Id$
//
//--------------------------------------------------------------------------
//--------------------------------------------------------------------------
#ifndef GRINS_VAR_TYPEDEFS_H
#define GRINS_VAR_TYPEDEFS_H

// C++
#include <string>
#include <map>
#include "boost/tr1/memory.hpp"

// libMesh
#include "libmesh/id_types.h"

namespace GRINS
{
  //! Forward declare Physics class since Physics uses some of these typedefs
  class Physics;

  //! More descriptive name of the type used for variable indices
  typedef unsigned int VariableIndex;

  typedef std::string VariableName;

  //! More descriptive name of the type used for boundary ids
  /*! We make it a short int to be compatible with libMesh */
  typedef libMesh::boundary_id_type BoundaryID;

  //! Container for GRINS::Physics object pointers
  typedef std::map< std::string,std::tr1::shared_ptr<GRINS::Physics> > PhysicsList;

  //! Iterator for PhysicsList
  typedef std::map< std::string,std::tr1::shared_ptr<GRINS::Physics> >::const_iterator PhysicsListIter;

}
#endif //GRINS_VAR_TYPEDEFS_H
