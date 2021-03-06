
.. Documentation for the header file dolfin/la/PETScFactory.h

.. _programmers_reference_cpp_la_petscfactory:

PETScFactory.h
==============

.. note::
    
    The documentation on this page was automatically extracted from the
    DOLFIN C++ code and may need to be edited or expanded.
    

.. cpp:class:: PETScFactory

    *Parent class(es)*
    
        * :cpp:class:`LinearAlgebraFactory`
        
    .. cpp:function:: PETScMatrix* create_matrix() const
    
        Create empty matrix


    .. cpp:function:: PETScVector* create_vector() const
    
        Create empty vector (global)


    .. cpp:function:: PETScVector* create_local_vector() const
    
        Create empty vector (local)


    .. cpp:function:: SparsityPattern* create_pattern() const
    
        Create empty sparsity pattern


    .. cpp:function:: PETScLUSolver* create_lu_solver() const
    
        Create LU solver


    .. cpp:function:: PETScKrylovSolver* create_krylov_solver(std::string method, std::string pc) const
    
        Create Krylov solver


    .. cpp:function:: static PETScFactory& instance()
    
        Return singleton instance


    .. cpp:function:: PETScFactory()
    
        Private constructor


