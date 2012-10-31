//-----------------------------------------------------------------------bl-
//--------------------------------------------------------------------------
// 
// GRINS - General Reacting Incompressible Navier-Stokes 
//
// Copyright (C) 2010-2012 The PECOS Development Team
//
// This program is free software; you can redistribute it and/or
// modify it under the terms of the Version 2 GNU General
// Public License as published by the Free Software Foundation.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
// General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this library; if not, write to the Free Software
// Foundation, Inc. 51 Franklin Street, Fifth Floor, Boston, MA
// 02110-1301 USA
//
//-----------------------------------------------------------------------el-
//
// $Id$
//
//--------------------------------------------------------------------------
//--------------------------------------------------------------------------

#ifndef SOLVER_FACTORY_H
#define SOLVER_FACTORY_H

//libMesh
#include "getpot.h"

//GRINS
#include "grins_solver.h"
#include "grins_steady_solver.h"
#include "grins_unsteady_solver.h"
#include "grins_mesh_adaptive_solver.h"

namespace GRINS
{
  //! This object handles constructing the solver to be used.
  /*! To allow the user to easily extend the (limited) available solvers,
      the solver construction is handled in this object. */
  class SolverFactory
  {
  public:

    SolverFactory();
    virtual ~SolverFactory();

    //! Builds GRINS::Solver object.
    /*! Users should override this method to construct 
        their own solvers. */
    virtual std::tr1::shared_ptr<GRINS::Solver> build(const GetPot& input);

  };
}
#endif //SOLVER_FACTORY_H
