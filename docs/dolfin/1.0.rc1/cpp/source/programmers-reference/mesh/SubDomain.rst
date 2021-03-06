
.. Documentation for the header file dolfin/mesh/SubDomain.h

.. _programmers_reference_cpp_mesh_subdomain:

SubDomain.h
===========

.. note::
    
    The documentation on this page was automatically extracted from the
    DOLFIN C++ code and may need to be edited or expanded.
    

.. cpp:class:: SubDomain

    This class defines the interface for definition of subdomains.
    Alternatively, subdomains may be defined by a :cpp:class:`Mesh` and a
    :cpp:class:`MeshFunction` <uint> over the mesh.


    .. cpp:function:: SubDomain()
    
        Constructor


    .. cpp:function:: bool inside(const Array<double>& x, bool on_boundary) const
    
        Return true for points inside the subdomain
        
        *Arguments*
            x (:cpp:class:`Array` <double>)
                The coordinates of the point.
            on_boundary (bool)
                True for points on the boundary.
        
        *Returns*
            bool
                True for points inside the subdomain.


    .. cpp:function:: void map(const Array<double>& x, Array<double>&) const
    
        Map coordinate x in domain H to coordinate y in domain G (used for
        periodic boundary conditions)
        
        *Arguments*
            x (:cpp:class:`Array` <double>)
                The coordinates in domain H.
            unnamed (:cpp:class:`Array` <double>)
                The coordinates in domain G.


    .. cpp:function:: void snap(Array<double>& x) const
    
        Snap coordinate to boundary of subdomain
        
        *Arguments*
            x (:cpp:class:`Array` <double>)
                The coordinates.


    .. cpp:function:: void mark_cells(Mesh& mesh, unsigned int sub_domain) const
    
        Set subdomain markers (uint) on cells for given subdomain number
        
        *Arguments*
            mesh (:cpp:class:`Mesh`)
                The mesh to be marked.
            sub_domain (unsigned int)
                The subdomain number.


    .. cpp:function:: void mark_facets(Mesh& mesh, unsigned int sub_domain) const
    
        Set subdomain markers (uint) on facets for given subdomain number
        
        *Arguments*
            mesh (:cpp:class:`Mesh`)
                The mesh to be marked.
            sub_domain (unsigned int)
                The subdomain number.


    .. cpp:function:: void mark(Mesh& mesh, unsigned int dim, unsigned int sub_domain) const
    
        Set subdomain markers (uint) for given topological dimension
        and subdomain number
        
        *Arguments*
            mesh (:cpp:class:`Mesh`)
                The mesh to be marked.
            dim (unsigned int)
                The topological dimension of entities to be marked.
            sub_domain (unsigned int)
                The subdomain number.


    .. cpp:function:: void mark(MeshFunction<unsigned int>& sub_domains, unsigned int sub_domain) const
    
        Set subdomain markers (uint) for given subdomain number
        
        *Arguments*
            sub_domains (:cpp:class:`MeshFunction` <unsigned int>)
                The subdomain markers.
            sub_domain (unsigned int)
                The subdomain number.


    .. cpp:function:: void mark(MeshFunction<int>& sub_domains, int sub_domain) const
    
        Set subdomain markers (int) for given subdomain number
        
        *Arguments*
            sub_domains (:cpp:class:`MeshFunction` <int>)
                The subdomain markers.
            sub_domain (int)
                The subdomain number.


    .. cpp:function:: void mark(MeshFunction<double>& sub_domains, double sub_domain) const
    
        Set subdomain markers (double) for given subdomain number
        
        *Arguments*
            sub_domains (:cpp:class:`MeshFunction` <double>)
                The subdomain markers.
            sub_domain (double)
                The subdomain number.


    .. cpp:function:: void mark(MeshFunction<bool>& sub_domains, bool sub_domain) const
    
        Set subdomain markers (bool) for given subdomain
        
        *Arguments*
            sub_domains (:cpp:class:`MeshFunction` <bool>)
                The subdomain markers.
            sub_domain (bool)
                The subdomain number.


    .. cpp:function:: void mark(MeshValueCollection<unsigned int>& sub_domains, unsigned int sub_domain, const Mesh& mesh) const
    
        Set subdomain markers (uint) for given subdomain number
        
        *Arguments*
            sub_domains (:cpp:class:`MeshValueCollection` <unsigned int>)
                The subdomain markers.
            sub_domain (unsigned int)
                The subdomain number.
            mesn (:cpp:class:`Mesh`)
                The mesh.


    .. cpp:function:: void mark(MeshValueCollection<int>& sub_domains, int sub_domain, const Mesh& mesh) const
    
        Set subdomain markers (int) for given subdomain number
        
        *Arguments*
            sub_domains (:cpp:class:`MeshValueCollection` <int>)
                The subdomain markers
            sub_domain (int)
                The subdomain number


    .. cpp:function:: void mark(MeshValueCollection<double>& sub_domains, double sub_domain, const Mesh& mesh) const
    
        Set subdomain markers (double) for given subdomain number
        
        *Arguments*
            sub_domains (:cpp:class:`MeshValueCollection` <double>)
                The subdomain markers.
            sub_domain (double)
                The subdomain number


    .. cpp:function:: void mark(MeshValueCollection<bool>& sub_domains, bool sub_domain, const Mesh& mesh) const
    
        Set subdomain markers (bool) for given subdomain
        
        *Arguments*
            sub_domains (:cpp:class:`MeshValueCollection` <bool>)
                The subdomain markers
            sub_domain (bool)
                The subdomain number


    .. cpp:function:: uint geometric_dimension() const
    
        Return geometric dimension
        
        *Returns*
            uint
                The geometric dimension.


    .. cpp:function:: void apply_markers(S& sub_domains, T sub_domain, const Mesh& mesh) const
    
        Apply marker of type T (most likely an uint) to object of class
        S (most likely MeshFunction or MeshValueCollection)


