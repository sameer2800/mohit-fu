
.. Documentation for the header file dolfin/fem/solve.h

.. _programmers_reference_cpp_fem_solve:

solve.h
=======

.. note::
    
    The documentation on this page was automatically extracted from the
    DOLFIN C++ code and may need to be edited or expanded.
    



.. cpp:function:: void solve(const Equation& equation, Function& u, Parameters params=empty_parameters)

    Solve linear variational problem a(u, v) == L(v) or nonlinear
    variational problem F(u; v) = 0 without boundary conditions
    Parameters to the Linear/Nonlinear VariationalSolver can be passed
    using params


.. cpp:function:: void solve(const Equation& equation, Function& u, const BoundaryCondition& bc, Parameters params=empty_parameters)

    Solve linear variational problem a(u, v) == L(v) or nonlinear
    variational problem F(u; v) = 0 with a single boundary condition
    Parameters to the Linear/Nonlinear VariationalSolver can be passed
    using params


.. cpp:function:: void solve(const Equation& equation, Function& u, std::vector<const BoundaryCondition*> bcs, Parameters params=empty_parameters)

    Solve linear variational problem a(u, v) == L(v) or nonlinear
    variational problem F(u; v) = 0 with a list of boundary conditions
    Parameters to the Linear/Nonlinear VariationalSolver can be passed
    using params


.. cpp:function:: void solve(const Equation& equation, Function& u, const Form& J, Parameters params=empty_parameters)

    Solve nonlinear variational problem F(u; v) == 0 without boundary
    conditions. The argument J should provide the Jacobian bilinear
    form J = dF/du. Parameters to the Nonlinear VariationalSolver
    can be passed using params


.. cpp:function:: void solve(const Equation& equation, Function& u, const BoundaryCondition& bc, const Form& J, Parameters params=empty_parameters)

    Solve nonlinear variational problem F(u; v) == 0 with a single
    boundary condition. The argument J should provide the Jacobian
    bilinear form J = dF/du. Parameters to the Nonlinear
    VariationalSolver can be passed using params


.. cpp:function:: void solve(const Equation& equation, Function& u, std::vector<const BoundaryCondition*> bcs, const Form& J, Parameters params=empty_parameters)

    Solve nonlinear variational problem F(u; v) == 0 with a list of
    boundary conditions. The argument J should provide the Jacobian
    bilinear form J = dF/du. Parameters to the Nonlinear
    VariationalSolver can be passed using params


