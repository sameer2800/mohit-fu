
.. Documentation for the header file dolfin/mesh/UnitCube.h

.. _programmers_reference_cpp_mesh_unitcube:

UnitCube.h
==========

.. note::
    
    The documentation on this page was automatically extracted from the
    DOLFIN C++ code and may need to be edited or expanded.
    

.. cpp:class:: UnitCube

    *Parent class(es)*
    
        * :cpp:class:`Mesh`
        
    Tetrahedral mesh of the 3D unit cube [0,1] x [0,1] x [0,1].
    Given the number of cells (nx, ny, nz) in each direction,
    the total number of tetrahedra will be 6*nx*ny*nz and the
    total number of vertices will be (nx + 1)*(ny + 1)*(nz + 1).


    .. cpp:function:: UnitCube(uint nx, uint ny, uint nz)
    
        Define a uniform finite element :cpp:class:`Mesh` over the unit cube
        [0,1] x [0,1] x [0,1].
        
        *Arguments*
            nx (uint)
                Number of cells in :math:`x` direction.
            ny (uint)
                Number of cells in :math:`y` direction.
            nz (uint)
                Number of cells in :math:`z` direction.
        
        *Example*
            .. code-block:: c++
        
                UnitCube mesh(32, 32, 32);
        


