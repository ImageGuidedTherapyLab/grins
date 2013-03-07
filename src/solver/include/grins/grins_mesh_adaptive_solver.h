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

#ifndef GRINS_MESH_ADAPTIVE_SOLVER_H
#define GRINS_MESH_ADAPTIVE_SOLVER_H

// C++
#include <string>

// GRINS
#include "grins/grins_solver.h"

//libMesh
#include "libmesh/libmesh.h"
#include "libmesh/auto_ptr.h"
#include "libmesh/mesh_refinement.h"

// libMesh forward declarations
class GetPot;
namespace libMesh
{
  class MeshBase;
}

namespace GRINS
{
  // Forward declartions
  class SolverContext;
  class MultiphysicsSystem;

  class MeshAdaptiveSolver : public Solver
  {
  public:

    MeshAdaptiveSolver( const GetPot& input );

    virtual ~MeshAdaptiveSolver();

    virtual void solve( SolverContext& context );

  protected:

    unsigned int _max_r_steps;
    bool _coarsen_by_parents;
    libMesh::Real _absolute_global_tolerance;
    unsigned int _nelem_target;
    libMesh::Real _refine_fraction;
    libMesh::Real _coarsen_fraction;
    libMesh::Real _coarsen_threshold;
    bool _output_adjoint_sol;
    bool _plot_cell_errors;
    std::string _error_plot_prefix;

    libMesh::AutoPtr<libMesh::MeshRefinement> _mesh_refinement;

    virtual void init_time_solver( MultiphysicsSystem* system );

    void build_mesh_refinement( libMesh::MeshBase& mesh );
  };

} // end namespace GRINS
#endif // GRINS_STEADY_SOLVER_H
