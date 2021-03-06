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

// This class
#include "grins/heat_transfer_stab_helper.h"

//libMesh
#include "libmesh/getpot.h"

namespace GRINS
{

  HeatTransferStabilizationHelper::HeatTransferStabilizationHelper(const GetPot& input)
    : StabilizationHelper(),
      _C( input("Stabilization/tau_constant", 1 ) ),
      _tau_factor( input("Stabilization/tau_factor", 0.5 ) )
  {
    return;
  }

  HeatTransferStabilizationHelper::~HeatTransferStabilizationHelper()
  {
    return;
  }

} // namespace GRINS
