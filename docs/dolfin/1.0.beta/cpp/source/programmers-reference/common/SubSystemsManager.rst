
.. Documentation for the header file dolfin/common/SubSystemsManager.h

.. _programmers_reference_cpp_common_subsystemsmanager:

SubSystemsManager.h
===================

.. note::
    
    The documentation on this page was automatically extracted from the
    DOLFIN C++ code and may need to be edited or expanded.
    

.. cpp:class:: SubSystemsManager

    This is a singleton class which manages the initialisation and
    finalisation of various sub systems, such as MPI and PETSc.


    .. cpp:function:: static void init_mpi()
    
        Initialise MPI


    .. cpp:function:: static void init_petsc()
    
        Initialize PETSc without command-line arguments


    .. cpp:function:: static void init_petsc(int argc, char* argv[])
    
        Initialize PETSc with command-line arguments. Note that PETSc
        command-line arguments may also be filtered and sent to PETSc
        by parameters.parse(argc, argv).


    .. cpp:function:: static void finalize()
    
        Finalize subsytems. This will be called by the destructor, but in
        special cases it may be necessary to call finalize() explicitly.


