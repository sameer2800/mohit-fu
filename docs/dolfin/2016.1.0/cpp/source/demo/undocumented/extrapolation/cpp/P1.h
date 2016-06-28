// This code conforms with the UFC specification version 2016.1.0
// and was automatically generated by FFC version 2016.1.0.
//
// This code was generated with the option '-l dolfin' and
// contains DOLFIN-specific wrappers that depend on DOLFIN.
// 
// This code was generated with the following parameters:
// 
//   convert_exceptions_to_warnings: False
//   cpp_optimize:                   True
//   cpp_optimize_flags:             '-O2'
//   epsilon:                        1e-14
//   error_control:                  False
//   form_postfix:                   True
//   format:                         'dolfin'
//   optimize:                       True
//   precision:                      15
//   quadrature_degree:              -1
//   quadrature_rule:                'auto'
//   representation:                 'auto'
//   split:                          False

#ifndef __P1_H
#define __P1_H
#include <stdexcept>
#include <ufc.h>

class p1_finite_element_0: public ufc::finite_element
{
public:

  p1_finite_element_0() : ufc::finite_element()
  {
    // Do nothing
  }

  ~p1_finite_element_0() override
  {
    // Do nothing
  }

  const char * signature() const final override
  {
    return "FiniteElement('Lagrange', triangle, 1)";
  }

  ufc::shape cell_shape() const final override
  {
    return ufc::shape::triangle;
  }

  std::size_t topological_dimension() const final override
  {
    return 2;
  }

  std::size_t geometric_dimension() const final override
  {
    return 2;
  }

  std::size_t space_dimension() const final override
  {
    return 3;
  }

  std::size_t value_rank() const final override
  {
    return 0;
  }

  std::size_t value_dimension(std::size_t i) const final override
  {
    return 1;
  }

  std::size_t value_size() const final override
  {
    return 1;
  }

  std::size_t reference_value_rank() const final override
  {
    return 0;
  }

  std::size_t reference_value_dimension(std::size_t i) const final override
  {
    return 1;
  }

  std::size_t reference_value_size() const final override
  {
    return 1;
  }

  std::size_t degree() const final override
  {
    return 1;
  }

  const char * family() const final override
  {
    return "Lagrange";
  }

  static void _evaluate_basis(std::size_t i,
                              double * values,
                              const double * x,
                              const double * coordinate_dofs,
                              int cell_orientation)
  {
    // Compute Jacobian
    double J[4];
    compute_jacobian_triangle_2d(J, coordinate_dofs);
    
    // Compute Jacobian inverse and determinant
    double K[4];
    double detJ;
    compute_jacobian_inverse_triangle_2d(K, detJ, J);
    
    
    // Compute constants
    const double C0 = coordinate_dofs[2] + coordinate_dofs[4];
    const double C1 = coordinate_dofs[3] + coordinate_dofs[5];
    
    // Get coordinates and map to the reference (FIAT) element
    double X = (J[1]*(C1 - 2.0*x[1]) + J[3]*(2.0*x[0] - C0)) / detJ;
    double Y = (J[0]*(2.0*x[1] - C1) + J[2]*(C0 - 2.0*x[0])) / detJ;
    
    // Reset values
    *values = 0.0;
    switch (i)
    {
    case 0:
      {
        
      // Array of basisvalues
      double basisvalues[3] = {0.0, 0.0, 0.0};
      
      // Declare helper variables
      double tmp0 = (1.0 + Y + 2.0*X)/2.0;
      
      // Compute basisvalues
      basisvalues[0] = 1.0;
      basisvalues[1] = tmp0;
      basisvalues[2] = basisvalues[0]*(0.5 + 1.5*Y);
      basisvalues[0] *= std::sqrt(0.5);
      basisvalues[2] *= std::sqrt(1.0);
      basisvalues[1] *= std::sqrt(3.0);
      
      // Table(s) of coefficients
      static const double coefficients0[3] = \
      {0.471404520791032, -0.288675134594813, -0.166666666666667};
      
      // Compute value(s)
      for (unsigned int r = 0; r < 3; r++)
      {
        *values += coefficients0[r]*basisvalues[r];
      } // end loop over 'r'
        break;
      }
    case 1:
      {
        
      // Array of basisvalues
      double basisvalues[3] = {0.0, 0.0, 0.0};
      
      // Declare helper variables
      double tmp0 = (1.0 + Y + 2.0*X)/2.0;
      
      // Compute basisvalues
      basisvalues[0] = 1.0;
      basisvalues[1] = tmp0;
      basisvalues[2] = basisvalues[0]*(0.5 + 1.5*Y);
      basisvalues[0] *= std::sqrt(0.5);
      basisvalues[2] *= std::sqrt(1.0);
      basisvalues[1] *= std::sqrt(3.0);
      
      // Table(s) of coefficients
      static const double coefficients0[3] = \
      {0.471404520791032, 0.288675134594813, -0.166666666666667};
      
      // Compute value(s)
      for (unsigned int r = 0; r < 3; r++)
      {
        *values += coefficients0[r]*basisvalues[r];
      } // end loop over 'r'
        break;
      }
    case 2:
      {
        
      // Array of basisvalues
      double basisvalues[3] = {0.0, 0.0, 0.0};
      
      // Declare helper variables
      double tmp0 = (1.0 + Y + 2.0*X)/2.0;
      
      // Compute basisvalues
      basisvalues[0] = 1.0;
      basisvalues[1] = tmp0;
      basisvalues[2] = basisvalues[0]*(0.5 + 1.5*Y);
      basisvalues[0] *= std::sqrt(0.5);
      basisvalues[2] *= std::sqrt(1.0);
      basisvalues[1] *= std::sqrt(3.0);
      
      // Table(s) of coefficients
      static const double coefficients0[3] = \
      {0.471404520791032, 0.0, 0.333333333333333};
      
      // Compute value(s)
      for (unsigned int r = 0; r < 3; r++)
      {
        *values += coefficients0[r]*basisvalues[r];
      } // end loop over 'r'
        break;
      }
    }
    
  }

  void evaluate_basis(std::size_t i,
                      double * values,
                      const double * x,
                      const double * coordinate_dofs,
                      int cell_orientation) const final override
  {
    _evaluate_basis(i, values, x, coordinate_dofs, cell_orientation);
  }

  static void _evaluate_basis_all(double * values,
                                  const double * x,
                                  const double * coordinate_dofs,
                                  int cell_orientation)
  {
    // Helper variable to hold values of a single dof.
    double dof_values = 0.0;
    
    // Loop dofs and call evaluate_basis
    for (unsigned int r = 0; r < 3; r++)
    {
      _evaluate_basis(r, &dof_values, x, coordinate_dofs, cell_orientation);
      values[r] = dof_values;
    } // end loop over 'r'
  }

  void evaluate_basis_all(double * values,
                          const double * x,
                          const double * coordinate_dofs,
                          int cell_orientation) const final override
  {
    _evaluate_basis_all(values, x, coordinate_dofs, cell_orientation);
  }

  static void _evaluate_basis_derivatives(std::size_t i,
                                          std::size_t n,
                                          double * values,
                                          const double * x,
                                          const double * coordinate_dofs,
                                          int cell_orientation)
  {
    
    // Compute number of derivatives.
    unsigned int num_derivatives = 1;
    for (unsigned int r = 0; r < n; r++)
    {
      num_derivatives *= 2;
    } // end loop over 'r'
    
    // Reset values. Assuming that values is always an array.
    for (unsigned int r = 0; r < num_derivatives; r++)
    {
      values[r] = 0.0;
    } // end loop over 'r'
    
    // Call evaluate_basis if order of derivatives is equal to zero.
    if (n == 0)
    {
      _evaluate_basis(i, values, x, coordinate_dofs, cell_orientation);
      return ;
    }
    
    // If order of derivatives is greater than the maximum polynomial degree, return zeros.
    if (n > 1)
    {
    return ;
    }
    
    // Compute Jacobian
    double J[4];
    compute_jacobian_triangle_2d(J, coordinate_dofs);
    
    // Compute Jacobian inverse and determinant
    double K[4];
    double detJ;
    compute_jacobian_inverse_triangle_2d(K, detJ, J);
    
    
    // Compute constants
    const double C0 = coordinate_dofs[2] + coordinate_dofs[4];
    const double C1 = coordinate_dofs[3] + coordinate_dofs[5];
    
    // Get coordinates and map to the reference (FIAT) element
    double X = (J[1]*(C1 - 2.0*x[1]) + J[3]*(2.0*x[0] - C0)) / detJ;
    double Y = (J[0]*(2.0*x[1] - C1) + J[2]*(C0 - 2.0*x[0])) / detJ;
    
    // Declare two dimensional array that holds combinations of derivatives and initialise
    unsigned int combinations[2][1];
    for (unsigned int row = 0; row < 2; row++)
    {
      for (unsigned int col = 0; col < 1; col++)
        combinations[row][col] = 0;
    }
    
    // Generate combinations of derivatives
    for (unsigned int row = 1; row < num_derivatives; row++)
    {
      for (unsigned int num = 0; num < row; num++)
      {
        for (unsigned int col = n-1; col+1 > 0; col--)
        {
          if (combinations[row][col] + 1 > 1)
            combinations[row][col] = 0;
          else
          {
            combinations[row][col] += 1;
            break;
          }
        }
      }
    }
    
    // Compute inverse of Jacobian
    const double Jinv[2][2] = {{K[0], K[1]}, {K[2], K[3]}};
    
    // Declare transformation matrix
    // Declare pointer to two dimensional array and initialise
    double transform[2][2];
    for (unsigned int j = 0; j < num_derivatives; j++)
    {
      for (unsigned int k = 0; k < num_derivatives; k++)
        transform[j][k] = 1;
    }
    
    // Construct transformation matrix
    for (unsigned int row = 0; row < num_derivatives; row++)
    {
      for (unsigned int col = 0; col < num_derivatives; col++)
      {
        for (unsigned int k = 0; k < n; k++)
          transform[row][col] *= Jinv[combinations[col][k]][combinations[row][k]];
      }
    }
    switch (i)
    {
    case 0:
      {
        
      // Array of basisvalues
      double basisvalues[3] = {0.0, 0.0, 0.0};
      
      // Declare helper variables
      double tmp0 = (1.0 + Y + 2.0*X)/2.0;
      
      // Compute basisvalues
      basisvalues[0] = 1.0;
      basisvalues[1] = tmp0;
      basisvalues[2] = basisvalues[0]*(0.5 + 1.5*Y);
      basisvalues[0] *= std::sqrt(0.5);
      basisvalues[2] *= std::sqrt(1.0);
      basisvalues[1] *= std::sqrt(3.0);
      
      // Table(s) of coefficients
      static const double coefficients0[3] = \
      {0.471404520791032, -0.288675134594813, -0.166666666666667};
      
      // Tables of derivatives of the polynomial base (transpose).
      static const double dmats0[3][3] = \
      {{0.0, 0.0, 0.0},
      {4.89897948556635, 0.0, 0.0},
      {0.0, 0.0, 0.0}};
      
      static const double dmats1[3][3] = \
      {{0.0, 0.0, 0.0},
      {2.44948974278318, 0.0, 0.0},
      {4.24264068711928, 0.0, 0.0}};
      
      // Compute reference derivatives.
      // Declare array of derivatives on FIAT element.
      double derivatives[2];
      for (unsigned int r = 0; r < 2; r++)
      {
        derivatives[r] = 0.0;
      } // end loop over 'r'
      
      // Declare derivative matrix (of polynomial basis).
      double dmats[3][3] = \
      {{1.0, 0.0, 0.0},
      {0.0, 1.0, 0.0},
      {0.0, 0.0, 1.0}};
      
      // Declare (auxiliary) derivative matrix (of polynomial basis).
      double dmats_old[3][3] = \
      {{1.0, 0.0, 0.0},
      {0.0, 1.0, 0.0},
      {0.0, 0.0, 1.0}};
      
      // Loop possible derivatives.
      for (unsigned int r = 0; r < num_derivatives; r++)
      {
        // Resetting dmats values to compute next derivative.
        for (unsigned int t = 0; t < 3; t++)
        {
          for (unsigned int u = 0; u < 3; u++)
          {
            dmats[t][u] = 0.0;
            if (t == u)
            {
            dmats[t][u] = 1.0;
            }
            
          } // end loop over 'u'
        } // end loop over 't'
        
        // Looping derivative order to generate dmats.
        for (unsigned int s = 0; s < n; s++)
        {
          // Updating dmats_old with new values and resetting dmats.
          for (unsigned int t = 0; t < 3; t++)
          {
            for (unsigned int u = 0; u < 3; u++)
            {
              dmats_old[t][u] = dmats[t][u];
              dmats[t][u] = 0.0;
            } // end loop over 'u'
          } // end loop over 't'
          
          // Update dmats using an inner product.
          if (combinations[r][s] == 0)
          {
          for (unsigned int t = 0; t < 3; t++)
          {
            for (unsigned int u = 0; u < 3; u++)
            {
              for (unsigned int tu = 0; tu < 3; tu++)
              {
                dmats[t][u] += dmats0[t][tu]*dmats_old[tu][u];
              } // end loop over 'tu'
            } // end loop over 'u'
          } // end loop over 't'
          }
          
          if (combinations[r][s] == 1)
          {
          for (unsigned int t = 0; t < 3; t++)
          {
            for (unsigned int u = 0; u < 3; u++)
            {
              for (unsigned int tu = 0; tu < 3; tu++)
              {
                dmats[t][u] += dmats1[t][tu]*dmats_old[tu][u];
              } // end loop over 'tu'
            } // end loop over 'u'
          } // end loop over 't'
          }
          
        } // end loop over 's'
        for (unsigned int s = 0; s < 3; s++)
        {
          for (unsigned int t = 0; t < 3; t++)
          {
            derivatives[r] += coefficients0[s]*dmats[s][t]*basisvalues[t];
          } // end loop over 't'
        } // end loop over 's'
      } // end loop over 'r'
      
      // Transform derivatives back to physical element
      for (unsigned int r = 0; r < num_derivatives; r++)
      {
        for (unsigned int s = 0; s < num_derivatives; s++)
        {
          values[r] += transform[r][s]*derivatives[s];
        } // end loop over 's'
      } // end loop over 'r'
        break;
      }
    case 1:
      {
        
      // Array of basisvalues
      double basisvalues[3] = {0.0, 0.0, 0.0};
      
      // Declare helper variables
      double tmp0 = (1.0 + Y + 2.0*X)/2.0;
      
      // Compute basisvalues
      basisvalues[0] = 1.0;
      basisvalues[1] = tmp0;
      basisvalues[2] = basisvalues[0]*(0.5 + 1.5*Y);
      basisvalues[0] *= std::sqrt(0.5);
      basisvalues[2] *= std::sqrt(1.0);
      basisvalues[1] *= std::sqrt(3.0);
      
      // Table(s) of coefficients
      static const double coefficients0[3] = \
      {0.471404520791032, 0.288675134594813, -0.166666666666667};
      
      // Tables of derivatives of the polynomial base (transpose).
      static const double dmats0[3][3] = \
      {{0.0, 0.0, 0.0},
      {4.89897948556635, 0.0, 0.0},
      {0.0, 0.0, 0.0}};
      
      static const double dmats1[3][3] = \
      {{0.0, 0.0, 0.0},
      {2.44948974278318, 0.0, 0.0},
      {4.24264068711928, 0.0, 0.0}};
      
      // Compute reference derivatives.
      // Declare array of derivatives on FIAT element.
      double derivatives[2];
      for (unsigned int r = 0; r < 2; r++)
      {
        derivatives[r] = 0.0;
      } // end loop over 'r'
      
      // Declare derivative matrix (of polynomial basis).
      double dmats[3][3] = \
      {{1.0, 0.0, 0.0},
      {0.0, 1.0, 0.0},
      {0.0, 0.0, 1.0}};
      
      // Declare (auxiliary) derivative matrix (of polynomial basis).
      double dmats_old[3][3] = \
      {{1.0, 0.0, 0.0},
      {0.0, 1.0, 0.0},
      {0.0, 0.0, 1.0}};
      
      // Loop possible derivatives.
      for (unsigned int r = 0; r < num_derivatives; r++)
      {
        // Resetting dmats values to compute next derivative.
        for (unsigned int t = 0; t < 3; t++)
        {
          for (unsigned int u = 0; u < 3; u++)
          {
            dmats[t][u] = 0.0;
            if (t == u)
            {
            dmats[t][u] = 1.0;
            }
            
          } // end loop over 'u'
        } // end loop over 't'
        
        // Looping derivative order to generate dmats.
        for (unsigned int s = 0; s < n; s++)
        {
          // Updating dmats_old with new values and resetting dmats.
          for (unsigned int t = 0; t < 3; t++)
          {
            for (unsigned int u = 0; u < 3; u++)
            {
              dmats_old[t][u] = dmats[t][u];
              dmats[t][u] = 0.0;
            } // end loop over 'u'
          } // end loop over 't'
          
          // Update dmats using an inner product.
          if (combinations[r][s] == 0)
          {
          for (unsigned int t = 0; t < 3; t++)
          {
            for (unsigned int u = 0; u < 3; u++)
            {
              for (unsigned int tu = 0; tu < 3; tu++)
              {
                dmats[t][u] += dmats0[t][tu]*dmats_old[tu][u];
              } // end loop over 'tu'
            } // end loop over 'u'
          } // end loop over 't'
          }
          
          if (combinations[r][s] == 1)
          {
          for (unsigned int t = 0; t < 3; t++)
          {
            for (unsigned int u = 0; u < 3; u++)
            {
              for (unsigned int tu = 0; tu < 3; tu++)
              {
                dmats[t][u] += dmats1[t][tu]*dmats_old[tu][u];
              } // end loop over 'tu'
            } // end loop over 'u'
          } // end loop over 't'
          }
          
        } // end loop over 's'
        for (unsigned int s = 0; s < 3; s++)
        {
          for (unsigned int t = 0; t < 3; t++)
          {
            derivatives[r] += coefficients0[s]*dmats[s][t]*basisvalues[t];
          } // end loop over 't'
        } // end loop over 's'
      } // end loop over 'r'
      
      // Transform derivatives back to physical element
      for (unsigned int r = 0; r < num_derivatives; r++)
      {
        for (unsigned int s = 0; s < num_derivatives; s++)
        {
          values[r] += transform[r][s]*derivatives[s];
        } // end loop over 's'
      } // end loop over 'r'
        break;
      }
    case 2:
      {
        
      // Array of basisvalues
      double basisvalues[3] = {0.0, 0.0, 0.0};
      
      // Declare helper variables
      double tmp0 = (1.0 + Y + 2.0*X)/2.0;
      
      // Compute basisvalues
      basisvalues[0] = 1.0;
      basisvalues[1] = tmp0;
      basisvalues[2] = basisvalues[0]*(0.5 + 1.5*Y);
      basisvalues[0] *= std::sqrt(0.5);
      basisvalues[2] *= std::sqrt(1.0);
      basisvalues[1] *= std::sqrt(3.0);
      
      // Table(s) of coefficients
      static const double coefficients0[3] = \
      {0.471404520791032, 0.0, 0.333333333333333};
      
      // Tables of derivatives of the polynomial base (transpose).
      static const double dmats0[3][3] = \
      {{0.0, 0.0, 0.0},
      {4.89897948556635, 0.0, 0.0},
      {0.0, 0.0, 0.0}};
      
      static const double dmats1[3][3] = \
      {{0.0, 0.0, 0.0},
      {2.44948974278318, 0.0, 0.0},
      {4.24264068711928, 0.0, 0.0}};
      
      // Compute reference derivatives.
      // Declare array of derivatives on FIAT element.
      double derivatives[2];
      for (unsigned int r = 0; r < 2; r++)
      {
        derivatives[r] = 0.0;
      } // end loop over 'r'
      
      // Declare derivative matrix (of polynomial basis).
      double dmats[3][3] = \
      {{1.0, 0.0, 0.0},
      {0.0, 1.0, 0.0},
      {0.0, 0.0, 1.0}};
      
      // Declare (auxiliary) derivative matrix (of polynomial basis).
      double dmats_old[3][3] = \
      {{1.0, 0.0, 0.0},
      {0.0, 1.0, 0.0},
      {0.0, 0.0, 1.0}};
      
      // Loop possible derivatives.
      for (unsigned int r = 0; r < num_derivatives; r++)
      {
        // Resetting dmats values to compute next derivative.
        for (unsigned int t = 0; t < 3; t++)
        {
          for (unsigned int u = 0; u < 3; u++)
          {
            dmats[t][u] = 0.0;
            if (t == u)
            {
            dmats[t][u] = 1.0;
            }
            
          } // end loop over 'u'
        } // end loop over 't'
        
        // Looping derivative order to generate dmats.
        for (unsigned int s = 0; s < n; s++)
        {
          // Updating dmats_old with new values and resetting dmats.
          for (unsigned int t = 0; t < 3; t++)
          {
            for (unsigned int u = 0; u < 3; u++)
            {
              dmats_old[t][u] = dmats[t][u];
              dmats[t][u] = 0.0;
            } // end loop over 'u'
          } // end loop over 't'
          
          // Update dmats using an inner product.
          if (combinations[r][s] == 0)
          {
          for (unsigned int t = 0; t < 3; t++)
          {
            for (unsigned int u = 0; u < 3; u++)
            {
              for (unsigned int tu = 0; tu < 3; tu++)
              {
                dmats[t][u] += dmats0[t][tu]*dmats_old[tu][u];
              } // end loop over 'tu'
            } // end loop over 'u'
          } // end loop over 't'
          }
          
          if (combinations[r][s] == 1)
          {
          for (unsigned int t = 0; t < 3; t++)
          {
            for (unsigned int u = 0; u < 3; u++)
            {
              for (unsigned int tu = 0; tu < 3; tu++)
              {
                dmats[t][u] += dmats1[t][tu]*dmats_old[tu][u];
              } // end loop over 'tu'
            } // end loop over 'u'
          } // end loop over 't'
          }
          
        } // end loop over 's'
        for (unsigned int s = 0; s < 3; s++)
        {
          for (unsigned int t = 0; t < 3; t++)
          {
            derivatives[r] += coefficients0[s]*dmats[s][t]*basisvalues[t];
          } // end loop over 't'
        } // end loop over 's'
      } // end loop over 'r'
      
      // Transform derivatives back to physical element
      for (unsigned int r = 0; r < num_derivatives; r++)
      {
        for (unsigned int s = 0; s < num_derivatives; s++)
        {
          values[r] += transform[r][s]*derivatives[s];
        } // end loop over 's'
      } // end loop over 'r'
        break;
      }
    }
    
  }

  void evaluate_basis_derivatives(std::size_t i,
                                  std::size_t n,
                                  double * values,
                                  const double * x,
                                  const double * coordinate_dofs,
                                  int cell_orientation) const final override
  {
    _evaluate_basis_derivatives(i, n, values, x, coordinate_dofs, cell_orientation);
  }

  static void _evaluate_basis_derivatives_all(std::size_t n,
                                              double * values,
                                              const double * x,
                                              const double * coordinate_dofs,
                                              int cell_orientation)
  {
    // Call evaluate_basis_all if order of derivatives is equal to zero.
    if (n == 0)
    {
      _evaluate_basis_all(values, x, coordinate_dofs, cell_orientation);
      return ;
    }
    
    // Compute number of derivatives.
    unsigned int num_derivatives = 1;
    for (unsigned int r = 0; r < n; r++)
    {
      num_derivatives *= 2;
    } // end loop over 'r'
    
    // Set values equal to zero.
    for (unsigned int r = 0; r < 3; r++)
    {
      for (unsigned int s = 0; s < num_derivatives; s++)
      {
        values[r*num_derivatives + s] = 0.0;
      } // end loop over 's'
    } // end loop over 'r'
    
    // If order of derivatives is greater than the maximum polynomial degree, return zeros.
    if (n > 1)
    {
      return ;
    }
    
    // Helper variable to hold values of a single dof.
    double dof_values[2];
    for (unsigned int r = 0; r < 2; r++)
    {
      dof_values[r] = 0.0;
    } // end loop over 'r'
    
    // Loop dofs and call evaluate_basis_derivatives.
    for (unsigned int r = 0; r < 3; r++)
    {
      _evaluate_basis_derivatives(r, n, dof_values, x, coordinate_dofs, cell_orientation);
      for (unsigned int s = 0; s < num_derivatives; s++)
      {
        values[r*num_derivatives + s] = dof_values[s];
      } // end loop over 's'
    } // end loop over 'r'
  }

  void evaluate_basis_derivatives_all(std::size_t n,
                                      double * values,
                                      const double * x,
                                      const double * coordinate_dofs,
                                      int cell_orientation) const final override
  {
    _evaluate_basis_derivatives_all(n, values, x, coordinate_dofs, cell_orientation);
  }

  double evaluate_dof(std::size_t i,
                      const ufc::function& f,
                      const double * coordinate_dofs,
                      int cell_orientation,
                      const ufc::cell& c) const final override
  {
    // Declare variables for result of evaluation
    double vals[1];
    
    // Declare variable for physical coordinates
    double y[2];
    switch (i)
    {
    case 0:
      {
        y[0] = coordinate_dofs[0];
      y[1] = coordinate_dofs[1];
      f.evaluate(vals, y, c);
      return vals[0];
        break;
      }
    case 1:
      {
        y[0] = coordinate_dofs[2];
      y[1] = coordinate_dofs[3];
      f.evaluate(vals, y, c);
      return vals[0];
        break;
      }
    case 2:
      {
        y[0] = coordinate_dofs[4];
      y[1] = coordinate_dofs[5];
      f.evaluate(vals, y, c);
      return vals[0];
        break;
      }
    }
    
    return 0.0;
  }

  void evaluate_dofs(double * values,
                             const ufc::function& f,
                             const double * coordinate_dofs,
                             int cell_orientation,
                             const ufc::cell& c) const final override
  {
    // Declare variables for result of evaluation
    double vals[1];
    
    // Declare variable for physical coordinates
    double y[2];
    y[0] = coordinate_dofs[0];
    y[1] = coordinate_dofs[1];
    f.evaluate(vals, y, c);
    values[0] = vals[0];
    y[0] = coordinate_dofs[2];
    y[1] = coordinate_dofs[3];
    f.evaluate(vals, y, c);
    values[1] = vals[0];
    y[0] = coordinate_dofs[4];
    y[1] = coordinate_dofs[5];
    f.evaluate(vals, y, c);
    values[2] = vals[0];
  }

  void interpolate_vertex_values(double * vertex_values,
                                 const double * dof_values,
                                 const double * coordinate_dofs,
                                 int cell_orientation,
                                 const ufc::cell& c) const final override
  {
    // Evaluate function and change variables
    vertex_values[0] = dof_values[0];
    vertex_values[1] = dof_values[1];
    vertex_values[2] = dof_values[2];
  }

  void tabulate_dof_coordinates(double * dof_coordinates,
                                const double * coordinate_dofs) const final override
  {
    dof_coordinates[0] = coordinate_dofs[0];
    dof_coordinates[1] = coordinate_dofs[1];
    dof_coordinates[2] = coordinate_dofs[2];
    dof_coordinates[3] = coordinate_dofs[3];
    dof_coordinates[4] = coordinate_dofs[4];
    dof_coordinates[5] = coordinate_dofs[5];
  }

  std::size_t num_sub_elements() const final override
  {
    return 0;
  }

  ufc::finite_element * create_sub_element(std::size_t i) const final override
  {
    return 0;
  }

  ufc::finite_element * create() const final override
  {
    return new p1_finite_element_0();
  }

};


class p1_dofmap_0: public ufc::dofmap
{
public:

  p1_dofmap_0() : ufc::dofmap()
  {
    // Do nothing
  }

  ~p1_dofmap_0() override
  {
    // Do nothing
  }

  const char * signature() const final override
  {
    return "FFC dofmap for FiniteElement('Lagrange', triangle, 1)";
  }

  bool needs_mesh_entities(std::size_t d) const final override
  {
    switch (d)
    {
    case 0:
      {
        return true;
        break;
      }
    case 1:
      {
        return false;
        break;
      }
    case 2:
      {
        return false;
        break;
      }
    }
    
    return false;
  }

  std::size_t topological_dimension() const final override
  {
    return 2;
  }

  std::size_t global_dimension(const std::vector<std::size_t>&
                               num_global_entities) const final override
  {
    return num_global_entities[0];
  }

  std::size_t num_element_dofs() const final override
  {
    return 3;
  }

  std::size_t num_facet_dofs() const final override
  {
    return 2;
  }

  std::size_t num_entity_dofs(std::size_t d) const final override
  {
    switch (d)
    {
    case 0:
      {
        return 1;
        break;
      }
    case 1:
      {
        return 0;
        break;
      }
    case 2:
      {
        return 0;
        break;
      }
    }
    
    return 0;
  }

  void tabulate_dofs(std::size_t * dofs,
                     const std::vector<std::size_t>& num_global_entities,
                     const std::vector<std::vector<std::size_t>>& entity_indices) const final override
  {
    dofs[0] = entity_indices[0][0];
    dofs[1] = entity_indices[0][1];
    dofs[2] = entity_indices[0][2];
  }

  void tabulate_facet_dofs(std::size_t * dofs,
                           std::size_t facet) const final override
  {
    switch (facet)
    {
    case 0:
      {
        dofs[0] = 1;
      dofs[1] = 2;
        break;
      }
    case 1:
      {
        dofs[0] = 0;
      dofs[1] = 2;
        break;
      }
    case 2:
      {
        dofs[0] = 0;
      dofs[1] = 1;
        break;
      }
    }
    
  }

  void tabulate_entity_dofs(std::size_t * dofs,
                            std::size_t d, std::size_t i) const final override
  {
    if (d > 2)
    {
    throw std::runtime_error("d is larger than dimension (2)");
    }
    
    switch (d)
    {
    case 0:
      {
        if (i > 2)
      {
      throw std::runtime_error("i is larger than number of entities (2)");
      }
      
      switch (i)
      {
      case 0:
        {
          dofs[0] = 0;
          break;
        }
      case 1:
        {
          dofs[0] = 1;
          break;
        }
      case 2:
        {
          dofs[0] = 2;
          break;
        }
      }
      
        break;
      }
    case 1:
      {
        
        break;
      }
    case 2:
      {
        
        break;
      }
    }
    
  }


  std::size_t num_sub_dofmaps() const final override
  {
    return 0;
  }

  ufc::dofmap * create_sub_dofmap(std::size_t i) const final override
  {
    return 0;
  }

  ufc::dofmap * create() const final override
  {
    return new p1_dofmap_0();
  }

};

// DOLFIN wrappers

// Standard library includes
#include <string>

// DOLFIN includes
#include <dolfin/common/NoDeleter.h>
#include <dolfin/mesh/Mesh.h>
#include <dolfin/mesh/MultiMesh.h>
#include <dolfin/fem/FiniteElement.h>
#include <dolfin/fem/DofMap.h>
#include <dolfin/fem/Form.h>
#include <dolfin/fem/MultiMeshForm.h>
#include <dolfin/function/FunctionSpace.h>
#include <dolfin/function/MultiMeshFunctionSpace.h>
#include <dolfin/function/GenericFunction.h>
#include <dolfin/function/CoefficientAssigner.h>
#include <dolfin/function/MultiMeshCoefficientAssigner.h>
#include <dolfin/adaptivity/ErrorControl.h>
#include <dolfin/adaptivity/GoalFunctional.h>
#include <dolfin/la/GenericVector.h>

namespace P1
{

class FunctionSpace: public dolfin::FunctionSpace
{
public:

  // Constructor for standard function space
  FunctionSpace(std::shared_ptr<const dolfin::Mesh> mesh):
    dolfin::FunctionSpace(mesh,
                          std::make_shared<const dolfin::FiniteElement>(std::make_shared<p1_finite_element_0>()),
                          std::make_shared<const dolfin::DofMap>(std::make_shared<p1_dofmap_0>(), *mesh))
  {
    // Do nothing
  }

  // Constructor for constrained function space
  FunctionSpace(std::shared_ptr<const dolfin::Mesh> mesh, std::shared_ptr<const dolfin::SubDomain> constrained_domain):
    dolfin::FunctionSpace(mesh,
                          std::make_shared<const dolfin::FiniteElement>(std::make_shared<p1_finite_element_0>()),
                          std::make_shared<const dolfin::DofMap>(std::make_shared<p1_dofmap_0>(), *mesh, constrained_domain))
  {
    // Do nothing
  }

};

}

#endif
