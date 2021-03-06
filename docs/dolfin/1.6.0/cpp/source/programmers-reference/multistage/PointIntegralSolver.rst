
.. Documentation for the header file dolfin/multistage/PointIntegralSolver.h

.. _programmers_reference_cpp_multistage_pointintegralsolver:

PointIntegralSolver.h
=====================

.. note::
    
    The documentation on this page was automatically extracted from the
    DOLFIN C++ code and may need to be edited or expanded.
    

.. cpp:class:: PointIntegralSolver

    *Parent class(es)*
    
        * :cpp:class:`Variable`
        
    .. cpp:function:: PointIntegralSolver(std::shared_ptr<MultiStageScheme> scheme)
    
        Constructor
        FIXME: Include version where one can pass a Solver and/or
        Parameters


    .. cpp:function:: void step(double dt)
    
        Step solver with time step dt


    .. cpp:function:: void step_interval(double t0, double t1, double dt)
    
        Step solver an interval using dt as time step


    .. cpp:function:: std::shared_ptr<MultiStageScheme> scheme() const
    
        Return the MultiStageScheme


    .. cpp:function:: static Parameters default_parameters()
    
        Default parameter values


