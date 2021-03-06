
.. Documentation for the header file dolfin/mesh/MeshFunction.h

.. _programmers_reference_cpp_mesh_meshfunction:

MeshFunction.h
==============

.. note::
    
    The documentation on this page was automatically extracted from the
    DOLFIN C++ code and may need to be edited or expanded.
    

.. cpp:class:: MeshFunction

    *Parent class(es)*
    
        * :cpp:class:`Variable`
        
    A MeshFunction is a function that can be evaluated at a set of
    mesh entities. A MeshFunction is discrete and is only defined
    at the set of mesh entities of a fixed topological dimension.
    A MeshFunction may for example be used to store a global
    numbering scheme for the entities of a (parallel) mesh, marking
    sub domains or boolean markers for mesh refinement.


    .. cpp:function:: MeshFunction()
    
        Create empty mesh function


    .. cpp:function:: explicit MeshFunction(const Mesh& mesh)
    
        Create empty mesh function on given mesh
        
        *Arguments*
            mesh (:cpp:class:`Mesh`)
                The mesh to create mesh function on.


    .. cpp:function:: MeshFunction(const Mesh& mesh, uint dim)
    
        Create mesh function of given dimension on given mesh
        
        *Arguments*
            mesh (:cpp:class:`Mesh`)
                The mesh to create mesh function on.
            dim (uint)
                The mesh entity dimension for the mesh function.


    .. cpp:function:: MeshFunction(const Mesh& mesh, uint dim, const T& value)
    
        Create mesh of given dimension on given mesh and initialize
        to a value
        
        *Arguments*
            mesh (:cpp:class:`Mesh`)
                The mesh to create mesh function on.
            dim (uint)
                The mesh entity dimension.
            value (T)
                The value.


    .. cpp:function:: MeshFunction(const Mesh& mesh, const std::string filename)
    
        Create function from data file
        
        *Arguments*
            mesh (:cpp:class:`Mesh`)
                The mesh to create mesh function on.
            filename (std::string)
                The filename to create mesh function from.


    .. cpp:function:: MeshFunction(const Mesh& mesh, const MeshValueCollection<T>& value_collection)
    
        Create function from a MeshValueCollecion
        
        *Arguments*
            mesh (:cpp:class:`Mesh`)
                The mesh to create mesh function on.
            value_collection (:cpp:class:`MeshValueCollection` <T>)
                The mesh value collection for the mesh function data.


    .. cpp:function:: MeshFunction(const MeshFunction<T>& f)
    
        Copy constructor
        
        *Arguments*
            f (:cpp:class:`MeshFunction` <T>)
                The object to be copied.


    .. cpp:function:: MeshFunction<T>& operator= (const MeshFunction<T>& f)
    
        Assign mesh function to other mesh function
        Assignment operator
        
        *Arguments*
            f (:cpp:class:`MeshFunction` <T>)
                A :cpp:class:`MeshFunction` object to asssign to another MeshFunction.


    .. cpp:function:: MeshFunction<T>& operator=(const MeshValueCollection<T>& mesh)
    
        Assignment operator
        
        *Arguments*
            mesh (:cpp:class:`MeshValueCollection`)
                A :cpp:class:`MeshValueCollection` object used to construct a MeshFunction.


    .. cpp:function:: const Mesh& mesh() const
    
        Return mesh associated with mesh function
        
        *Returns*
            :cpp:class:`Mesh`
                The mesh.


    .. cpp:function:: uint dim() const
    
        Return topological dimension
        
        *Returns*
            uint
                The dimension.


    .. cpp:function:: uint size() const
    
        Return size (number of entities)
        
        *Returns*
            uint
                The size.


    .. cpp:function:: const T* values() const
    
        Return array of values (const. version)
        
        *Returns*
            T
                The values.


    .. cpp:function:: T* values()
    
        Return array of values
        
        *Returns*
            T
                The values.


    .. cpp:function:: T& operator[] (const MeshEntity& entity)
    
        Return value at given mesh entity
        
        *Arguments*
            entity (:cpp:class:`MeshEntity`)
                The mesh entity.
        
        *Returns*
            T
                The value at the given entity.


    .. cpp:function:: const T& operator[] (const MeshEntity& entity) const
    
        Return value at given mesh entity (const version)
        
        *Arguments*
            entity (:cpp:class:`MeshEntity`)
                The mesh entity.
        
        *Returns*
            T
                The value at the given entity.


    .. cpp:function:: T& operator[] (uint index)
    
        Return value at given index
        
        *Arguments*
            index (uint)
                The index.
        
        *Returns*
            T
                The value at the given index.


    .. cpp:function:: const T& operator[] (uint index) const
    
        Return value at given index  (const version)
        
        *Arguments*
            index (uint)
                The index.
        
        *Returns*
            T
                The value at the given index.


    .. cpp:function:: const MeshFunction<T>& operator= (const T& value)
    
        Set all values to given value


    .. cpp:function:: void init(uint dim)
    
        Initialize mesh function for given topological dimension
        
        *Arguments*
            dim (uint)
                The dimension.


    .. cpp:function:: void init(uint dim, uint size)
    
        Initialize mesh function for given topological dimension of
        given size
        
        *Arguments*
            dim (uint)
                The dimension.
            size (uint)
                The size.


    .. cpp:function:: void init(const Mesh& mesh, uint dim)
    
        Initialize mesh function for given topological dimension
        
        *Arguments*
            mesh (:cpp:class:`Mesh`)
                The mesh.
            dim (uint)
                The dimension.


    .. cpp:function:: void init(const Mesh& mesh, uint dim, uint size)
    
        Initialize mesh function for given topological dimension of
        given size
        
        *Arguments*
            mesh (:cpp:class:`Mesh`)
                The mesh.
            dim (uint)
                The dimension.
            size (uint)
                The size.


    .. cpp:function:: void set_value(uint index, const T& value)
    
        Set value at given index
        
        *Arguments*
            index (uint)
                The index.
            value (T)
                The value.


    .. cpp:function:: void set_value(uint index, const T& value, const Mesh& mesh)
    
        Compatibility function for use in SubDomains


    .. cpp:function:: void set_values(const std::vector<T>& values)
    
        Set values
        
        *Arguments*
            values (std::vector<T>)
                The values.


    .. cpp:function:: void set_all(const T& value)
    
        Set all values to given value
        
        *Arguments*
            value (T)
                The value to set all values to.


    .. cpp:function:: std::string str(bool verbose) const
    
        Return informal string representation (pretty-print)
        
        *Arguments*
            verbose (bool)
                Flag to turn on additional output.
        
        *Returns*
            std::string
                An informal representation.


