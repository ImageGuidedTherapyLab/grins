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

#ifndef GRINS_SIMULATION_BUILDER_H
#define GRINS_SIMULATION_BUILDER_H

// GRINS
#include "physics_factory.h"
#include "mesh_builder.h"
#include "solver_factory.h"
#include "visualization_factory.h"
#include "bc_factory.h"
#include "qoi_factory.h"
#include "error_estimation_factory.h"

namespace GRINS
{
  class SimulationBuilder
  {
  public:
    
    SimulationBuilder();
    virtual ~SimulationBuilder();

    std::tr1::shared_ptr<libMesh::Mesh> build_mesh( const GetPot& input );

    GRINS::PhysicsList build_physics( const GetPot& input );

    std::tr1::shared_ptr<GRINS::Solver> build_solver( const GetPot& input );

    std::tr1::shared_ptr<GRINS::Visualization> build_vis( const GetPot& input );

    std::multimap< GRINS::PhysicsName, GRINS::DBCContainer > build_dirichlet_bcs();

    std::map< GRINS::PhysicsName, GRINS::NBCContainer > build_neumann_bcs( libMesh::EquationSystems& equation_system );

    std::tr1::shared_ptr<QoIBase> build_qoi( const GetPot& input );

    std::tr1::shared_ptr<libMesh::AdjointRefinementEstimator> build_adjoint_refinement_estimator( const GetPot& input, std::tr1::shared_ptr<QoIBase> qoi );

    std::tr1::shared_ptr<libMesh::ErrorEstimator> build_error_estimator( const GetPot& input, std::tr1::shared_ptr<GRINS::QoIBase> qoi );

    void attach_physics_factory( std::tr1::shared_ptr<PhysicsFactory> physics_factory );

    void attach_solver_factory( std::tr1::shared_ptr<SolverFactory> solver_factory );

    void attach_mesh_builder( std::tr1::shared_ptr<MeshBuilder> mesh_builder );
    
    void attach_vis_factory( std::tr1::shared_ptr<VisualizationFactory> vis_factory );

    void attach_bc_factory( std::tr1::shared_ptr<BoundaryConditionsFactory> bc_factory );

    void attach_qoi_factory( std::tr1::shared_ptr<QoIFactory> qoi_factory );

  void attach_error_estimator_factory( std::tr1::shared_ptr<ErrorEstimatorFactory> error_estimator_factory );

  protected:
    
    std::tr1::shared_ptr<PhysicsFactory> _physics_factory;
    std::tr1::shared_ptr<MeshBuilder> _mesh_builder;
    std::tr1::shared_ptr<SolverFactory> _solver_factory;
    std::tr1::shared_ptr<VisualizationFactory> _vis_factory;
    std::tr1::shared_ptr<BoundaryConditionsFactory> _bc_factory;
    std::tr1::shared_ptr<QoIFactory> _qoi_factory;
    std::tr1::shared_ptr<ErrorEstimatorFactory> _error_estimator_factory;
      
  }; //class SimulationBuilder
} // namespace GRINS

#endif //GRINS_SIMULATION_BUILDER_H
