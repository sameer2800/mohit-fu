
.. Documentation for the header file dolfin/mesh/SubMesh.h

.. _programmers_reference_cpp_mesh_submesh:

SubMesh.h
=========

.. note::
    
    The documentation on this page was automatically extracted from the
    DOLFIN C++ code and may need to be edited or expanded.
    

.. cpp:class:: SubMesh

    *Parent class(es)*
    
        * :cpp:class:`Mesh`
        
    A SubMesh is a mesh defined as a subset of a given mesh. It
    provides a convenient way to create matching meshes for
    multiphysics applications by creating meshes for subdomains as
    subsets of a single global mesh.


    .. cpp:function:: SubMesh(const Mesh& mesh, const SubDomain& sub_domain)
    
        Create subset of given mesh marked by sub domain


    .. cpp:function:: SubMesh(const Mesh& mesh, const MeshFunction<unsigned int>& sub_domains, uint sub_domain)
    
        Create subset of given mesh marked by mesh function


    .. cpp:function:: void init(const Mesh& mesh, const MeshFunction<uint>& sub_domains, uint sub_domain)
    
        Create sub mesh


