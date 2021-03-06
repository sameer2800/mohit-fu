
.. Documentation for the header file dolfin/la/LinearSolver.h

.. _programmers_reference_cpp_la_linearsolver:

LinearSolver.h
==============

.. note::
    
    The documentation on this page was automatically extracted from the
    DOLFIN C++ code and may need to be edited or expanded.
    

.. cpp:class:: LinearSolver

    *Parent class(es)*
    
        * :cpp:class:`GenericLinearSolver`
        
    This class provides a general solver for linear systems Ax = b.


    .. cpp:function:: LinearSolver(std::string solver_type = "lu", std::string pc_type = "ilu")
    
        Create linear solver


    .. cpp:function:: void set_operator(const boost::shared_ptr<const GenericMatrix> A)
    
        Set the operator (matrix)


    .. cpp:function:: void set_operators(const boost::shared_ptr<const GenericMatrix> A, const boost::shared_ptr<const GenericMatrix> P)
    
        Set the operator (matrix) and preconitioner matrix


    .. cpp:function:: uint solve(const GenericMatrix& A, GenericVector& x, const GenericVector& b)
    
        Solve linear system Ax = b


    .. cpp:function:: uint solve(GenericVector& x, const GenericVector& b)
    
        Solve linear system Ax = b


    .. cpp:function:: static Parameters default_parameters()
    
        Default parameter values


