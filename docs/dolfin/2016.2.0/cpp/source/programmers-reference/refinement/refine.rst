
.. Documentation for the header file dolfin/refinement/refine.h

.. _programmers_reference_cpp_refinement_refine:

refine.h
========

.. note::
    
    The documentation on this page was automatically extracted from the
    DOLFIN C++ code and may need to be edited or expanded.
    



.. cpp:function:: Mesh refine(const Mesh& mesh, bool redistribute = true)

    Create uniformly refined mesh
    
    *Arguments*
        mesh (:cpp:class:`Mesh`)
            The mesh to refine.
        redistribute (_bool_)
            Optional argument to redistribute the refined mesh if mesh is a
            distributed mesh.
    
    *Returns*
        :cpp:class:`Mesh`
            The refined mesh.
    
    *Example*
        .. code-block:: c++
    
            mesh = refine(mesh);
    


.. cpp:function:: std::shared_ptr<const MeshHierarchy> refine( const MeshHierarchy& hierarchy, const MeshFunction<bool>& markers)

    Refine a MeshHierarchy


.. cpp:function:: void refine(Mesh& refined_mesh, const Mesh& mesh, bool redistribute = true)

    Create uniformly refined mesh
    
    *Arguments*
        refined_mesh (:cpp:class:`Mesh`)
            The mesh that will be the refined mesh.
        mesh (:cpp:class:`Mesh`)
            The original mesh.
        redistribute (_bool_)
            Optional argument to redistribute the refined mesh if mesh is a
            distributed mesh.


.. cpp:function:: Mesh refine(const Mesh& mesh, const MeshFunction<bool>& cell_markers, bool redistribute = true)

    Create locally refined mesh
    
    *Arguments*
        mesh (:cpp:class:`Mesh`)
            The mesh to refine.
        cell_markers (:cpp:class:`MeshFunction` <bool>)
            A mesh function over booleans specifying which cells
            that should be refined (and which should not).
        redistribute (_bool_)
            Optional argument to redistribute the refined mesh if mesh is a
            distributed mesh.
    
    *Returns*
        :cpp:class:`Mesh`
            The locally refined mesh.
    
    *Example*
        .. code-block:: c++
    
            CellFunction<bool> cell_markers(mesh);
            cell_markers.set_all(false);
            Point origin(0.0, 0.0, 0.0);
            for (CellIterator cell(mesh); !cell.end(); ++cell)
            {
                Point p = cell->midpoint();
                if (p.distance(origin) < 0.1)
                    cell_markers[*cell] = true;
            }
            mesh = refine(mesh, cell_markers);
    


.. cpp:function:: void refine(Mesh& refined_mesh, const Mesh& mesh, const MeshFunction<bool>& cell_markers, bool redistribute = true)

    Create locally refined mesh
    
    *Arguments*
        refined_mesh (:cpp:class:`Mesh`)
            The mesh that will be the refined mesh.
        mesh (:cpp:class:`Mesh`)
            The original mesh.
        cell_markers (:cpp:class:`MeshFunction` <bool>)
            A mesh function over booleans specifying which cells
            that should be refined (and which should not).
        redistribute (_bool_)
            Optional argument to redistribute the refined mesh if mesh is a
            distributed mesh.


.. cpp:function:: void p_refine(Mesh& refined_mesh, const Mesh& mesh)

    Increase the polynomial order of the mesh from 1 to 2, i.e. add points
    at the Edge midpoints, to make a quadratic mesh.
    
    *Arguments*
        refined_mesh (:cpp:class:`Mesh`)
            The mesh that will be the quadratic mesh.
        mesh (:cpp:class:`Mesh`)
            The original linear mesh.


.. cpp:function:: Mesh p_refine(const Mesh& mesh)

    Return a p_refined mesh
    Increase the polynomial order of the mesh from 1 to 2, i.e. add points
    at the Edge midpoints, to make a quadratic mesh.
    
    *Arguments*
        mesh (:cpp:class:`Mesh`)
            The original linear mesh.


