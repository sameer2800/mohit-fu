
.. Documentation for the header file dolfin/adaptivity/marking.h

.. _programmers_reference_cpp_adaptivity_marking:

marking.h
=========

.. note::
    
    The documentation on this page was automatically extracted from the
    DOLFIN C++ code and may need to be edited or expanded.
    



.. cpp:function:: void mark(MeshFunction<bool>& markers, const Vector& indicators, const std::string strategy, const double fraction)

    Mark cells based on indicators and given marking strategy
    
    *Arguments*
        markers (_MeshFunction<bool>_)
            the cell markers (to be computed)
    
        indicators (:cpp:class:`Vector`)
            error indicators (one per cell)
    
        strategy (std::string)
            the marking strategy
    
        fraction (double)
            the marking fraction


.. cpp:function:: void dorfler_mark(MeshFunction<bool>& markers, const Vector& indicators, const double fraction)

    Mark cells using Dorfler marking
    
    *Arguments*
        markers (_MeshFunction<bool>_)
            the cell markers (to be computed)
    
        indicators (:cpp:class:`Vector`)
            error indicators (one per cell)
    
        fraction (double)
            the marking fraction


