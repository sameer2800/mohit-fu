
.. Documentation for the header file dolfin/la/uBLASKrylovSolver.h

.. _programmers_reference_cpp_la_ublaskrylovsolver:

uBLASKrylovSolver.h
===================

.. note::
    
    The documentation on this page was automatically extracted from the
    DOLFIN C++ code and may need to be edited or expanded.
    

.. cpp:class:: uBLASKrylovSolver

    *Parent class(es)*
    
        * :cpp:class:`GenericLinearSolver`
        
    This class implements Krylov methods for linear systems
    of the form Ax = b using uBLAS data types.


    .. cpp:function:: uBLASKrylovSolver(std::string solver_type="default", std::string pc_type="default")
    
        Create Krylov solver for a particular method and preconditioner


    .. cpp:function:: uBLASKrylovSolver(uBLASPreconditioner& pc)
    
        Create Krylov solver for a particular uBLASPreconditioner


    .. cpp:function:: uBLASKrylovSolver(std::string solver_type, uBLASPreconditioner& preconditioner)
    
        Create Krylov solver for a particular method and uBLASPreconditioner


    .. cpp:function:: void set_operator(const boost::shared_ptr<const GenericMatrix> A)
    
        Solve the operator (matrix)


    .. cpp:function:: const GenericMatrix& get_operator() const
    
        Return the operator (matrix)


    .. cpp:function:: uint solve(const GenericMatrix& A, GenericVector& x, const GenericVector& b)
    
        Solve linear system Ax = b and return number of iterations


    .. cpp:function:: uint solve(const uBLASMatrix<ublas_dense_matrix>& A, uBLASVector& x, const uBLASVector& b)
    
        Solve linear system Ax = b and return number of iterations (dense matrix)


    .. cpp:function:: uint solve(const uBLASMatrix<ublas_sparse_matrix>& A, uBLASVector& x, const uBLASVector& b)
    
        Solve linear system Ax = b and return number of iterations (sparse matrix)


    .. cpp:function:: uint solve(const uBLASKrylovMatrix& A, uBLASVector& x, const uBLASVector& b)
    
        Solve linear system Ax = b and return number of iterations (virtual matrix)


    .. cpp:function:: static Parameters default_parameters()
    
        Default parameter values


    .. cpp:function:: uint solve_krylov(const Mat& A, uBLASVector& x, const uBLASVector& b)
    
        Select solver and solve linear system Ax = b and return number of iterations


    .. cpp:function:: uint solveCG(const Mat& A, uBLASVector& x, const uBLASVector& b, bool& converged) const
    
        Solve linear system Ax = b using CG


    .. cpp:function:: uint solveGMRES(const Mat& A, uBLASVector& x, const uBLASVector& b, bool& converged) const
    
        Solve linear system Ax = b using restarted GMRES


    .. cpp:function:: uint solveBiCGStab(const Mat& A, uBLASVector& x, const uBLASVector& b, bool& converged) const
    
        Solve linear system Ax = b using BiCGStab


    .. cpp:function:: void select_preconditioner(std::string pc_type)
    
        Select and create named preconditioner


    .. cpp:function:: void read_parameters()
    
        Read solver parameters


