
.. Documentation for the header file dolfin/adaptivity/SpecialFacetFunction.h

.. _programmers_reference_cpp_adaptivity_specialfacetfunction:

SpecialFacetFunction.h
======================

.. note::
    
    The documentation on this page was automatically extracted from the
    DOLFIN C++ code and may need to be edited or expanded.
    

.. cpp:class:: SpecialFacetFunction

    *Parent class(es)*
    
        * :cpp:class:`Expression`
        
    .. cpp:function:: SpecialFacetFunction(std::vector<Function>& f_e)
    
        Create (scalar-valued) SpecialFacetFunction
        
        *Arguments*
            f_e (std::vector<:cpp:class:`Function`>)
               Separate _Function_s for each facet


    .. cpp:function:: SpecialFacetFunction(std::vector<Function>& f_e, uint dim)
    
        Create (vector-valued) SpecialFacetFunction
        
        *Arguments*
            f_e (std::vector<:cpp:class:`Function`>)
               Separate _Function_s for each facet
        
            dim (int)
                The value-dimension of the Functions


    .. cpp:function:: void eval(Array<double>& values, const Array<double>& x, const ufc::cell& cell) const
    
        Evaluate SpecialFacetFunction (cf :cpp:class:`Expression`.eval)
        Evaluate function for given cell


    .. cpp:function:: Function& operator[] (uint i) const
    
        Extract sub-function i
        
        *Arguments*
            i (int)
               component
        
        *Returns*
            :cpp:class:`Function`


