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

// C++
#include <iomanip>

// GRINS
#include "grins/catalytic_wall.h"
#include "grins/cantera_mixture.h"

// libMesh
#include "libmesh/getpot.h"

template<typename ChemicalMixture>
int test( ChemicalMixture& chem_mixture )
{
  const unsigned int N_index = chem_mixture.species_index("N");

  const GRINS::VariableIndex T_var_dummy = 5;

  const double gamma = 0.03;

  GRINS::CatalyticWall<ChemicalMixture> wall_N( chem_mixture, N_index, T_var_dummy, gamma );
  GRINS::CatalyticWall<ChemicalMixture> wall_N2( chem_mixture, N_index, T_var_dummy, -gamma );

  const double w_s = 0.2;

  const double rho = 1.0e-3;
  const double rho_s = rho*w_s;

  const double T = 620.1;
  const double R_N = chem_mixture.R( chem_mixture.species_index("N") );
  const double M_N = chem_mixture.M( chem_mixture.species_index("N") );
  const double R = 30.1;

  const double omega_dot_exact = rho_s*gamma*std::sqrt( R_N*T/(GRINS::Constants::two_pi*M_N) );
  const double domega_dot_dT_exact = -0.5*rho_s*gamma*std::sqrt( R_N/(T*GRINS::Constants::two_pi*M_N) );
  const double drho_dws = -rho*rho_s/R;
  const double domega_dot_dws_exact = drho_dws*w_s*gamma*std::sqrt( R_N*T/(GRINS::Constants::two_pi*M_N) )
                                    + rho*gamma*std::sqrt( R_N*T/(GRINS::Constants::two_pi*M_N) );

  int return_flag = 0;

  const double omega_dot_N = wall_N.omega_dot( rho_s, T );
  const double omega_dot_N2 = wall_N2.omega_dot( rho_s, T );

  const double domega_dot_dT_N = wall_N.domega_dot_dT( rho_s, T );
  const double domega_dot_dT_N2 = wall_N2.domega_dot_dT( rho_s, T );

  const double domega_dot_dws_N = wall_N.domega_dot_dws( rho_s, w_s, T, R );
  const double domega_dot_dws_N2 = wall_N2.domega_dot_dws( rho_s, w_s, T, R );

  const double tol = 1.0e-15;

  /* omega_dot tests */
  {
    double rel_error = std::fabs( (omega_dot_N - omega_dot_exact)/omega_dot_exact );

    if( rel_error > tol )
      {
	std::cerr << "Mismatch in omega_dot_N!" << std::endl
		  << "omega_dot_N = " << omega_dot_N << std::endl
		  << "omega_dot_exact = " << omega_dot_exact << std::endl
		  << "rel error = " << rel_error << std::endl;

	return_flag = 1;
      }
  }

  {
    double rel_error = std::fabs( (omega_dot_N2 + omega_dot_exact)/omega_dot_exact );

    if( rel_error > tol )
      {
	std::cerr << "Mismatch in omega_dot_N2!" << std::endl
		  << "omega_dot_N2    = " << omega_dot_N2 << std::endl
		  << "omega_dot_exact = " << omega_dot_exact << std::endl
		  << "rel error = " << rel_error << std::endl;

	return_flag = 1;
      }
  }

  /* domega_dot_dT tests */
  {
    double rel_error = std::fabs( (domega_dot_dT_N - domega_dot_dT_exact)/domega_dot_dT_exact );

    if( rel_error > tol )
      {
	std::cerr << "Mismatch in domega_dot_dT_N!" << std::endl
		  << "domega_dot_dT_N = " << domega_dot_dT_N << std::endl
		  << "domega_dot_dT_exact = " << domega_dot_dT_exact << std::endl
		  << "rel error = " << rel_error << std::endl;

	return_flag = 1;
      }
  }

  {
    double rel_error = std::fabs( (domega_dot_dT_N2 + domega_dot_dT_exact)/domega_dot_dT_exact );

    if( rel_error > tol )
      {
	std::cerr << "Mismatch in domega_dot_dT_N2!" << std::endl
		  << "domega_dot_dT_N2    = " << domega_dot_dT_N2 << std::endl
		  << "domega_dot_dT_exact = " << domega_dot_dT_exact << std::endl
		  << "rel error = " << rel_error << std::endl;

	return_flag = 1;
      }
  }

  /* domega_dot_dws tests */
  {
    double rel_error = std::fabs( (domega_dot_dws_N - domega_dot_dws_exact)/domega_dot_dws_exact );

    if( rel_error > tol )
      {
	std::cerr << "Mismatch in domega_dot_dws_N!" << std::endl
		  << "domega_dot_dws_N = " << domega_dot_dws_N << std::endl
		  << "domega_dot_dws_exact = " << domega_dot_dws_exact << std::endl
		  << "rel error = " << rel_error << std::endl;

	return_flag = 1;
      }
  }

  {
    double rel_error = std::fabs( (domega_dot_dws_N2 + domega_dot_dws_exact)/domega_dot_dws_exact );

    if( rel_error > tol )
      {
	std::cerr << "Mismatch in domega_dot_dws_N2!" << std::endl
		  << "domega_dot_dws_N2    = " << domega_dot_dws_N2 << std::endl
		  << "domega_dot_dws_exact = " << domega_dot_dws_exact << std::endl
		  << "rel error = " << rel_error << std::endl;

	return_flag = 1;
      }
  }
    
  return return_flag;
}


int main(int argc, char* argv[])
{
  std::string test_type = argv[1];

  GetPot input( argv[2] );

  int return_flag = 0;

  if( test_type == "cantera" )
    {
#ifdef GRINS_HAVE_CANTERA
      GRINS::CanteraMixture chem_mixture( input );
      return_flag = test<GRINS::CanteraMixture>( chem_mixture );
#else
      return_flag = 77;
#endif
    }
  else
    {
      std::cerr << "Invalid test type " << test_type << std::endl;
      return_flag = 1;
    }

  return return_flag;
}
