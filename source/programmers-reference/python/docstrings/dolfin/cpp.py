"Documentation for all DOLFIN classes which are generated by Swig."

class Variable(object):
    """
    Common base class for DOLFIN variables.

    C++ includes: Variable.h 
    """
    def __init__(self, *args): 
        """
        __init__(self) -> Variable
        __init__(self, string name, string label) -> Variable

        Create variable with given name and label. 
        """
    def rename(self, *args):
        """
        rename(self, string name, string label)

        Rename variable. 
        """

    def name(self):
        """
        name(self) -> string

        Return name. 
        """

    def label(self):
        """
        label(self) -> string

        Return label (description). 
        """

    def str(self, *args):
        """
        str(self, bool verbose) -> string

        Return informal string representation (pretty-print). 
        """

    def disp(self):
        """
        .. warning::

            Deprecated, to be removed.
        """

    def __str__(self):
        """__str__(self) -> string"""

class Point(object):
    """
    A Point represents a point in R^3 with coordinates x, y, z, or,
    alternatively, a vector in R^3, supporting standard operations like
    the norm, distances, scalar and vector products etc.

    C++ includes: Point.h 
    """
    def __init__(self, *args): 
        """
        __init__(self, double x = 0.0, double y = 0.0, double z = 0.0) -> Point
        __init__(self, double x = 0.0, double y = 0.0) -> Point
        __init__(self, double x = 0.0) -> Point
        __init__(self) -> Point
        __init__(self, uint dim, double x) -> Point
        __init__(self, Point p) -> Point

        Copy constructor. 
        """
    def x(self):
        """
        x(self) -> double

        Return x-coordinate. 
        """

    def y(self):
        """
        y(self) -> double

        Return y-coordinate. 
        """

    def z(self):
        """
        z(self) -> double

        Return z-coordinate. 
        """

    def coordinates(self):
        """
        coordinates(self) -> double

        Return coordinate array. 
        """

    def __add__(self, *args):
        """__add__(self, Point p) -> Point"""

    def __sub__(self, *args):
        """__sub__(self, Point p) -> Point"""

    def __iadd__(self, *args):
        """__iadd__(self, Point p) -> Point"""

    def __isub__(self, *args):
        """__isub__(self, Point p) -> Point"""

    def __mul__(self, *args):
        """__mul__(self, double a) -> Point"""

    def __imul__(self, *args):
        """__imul__(self, double a) -> Point"""

    def __div__(self, *args):
        """__div__(self, double a) -> Point"""

    def __idiv__(self, *args):
        """__idiv__(self, double a) -> Point"""

    def distance(self, *args):
        """
        distance(self, Point p) -> double

        Compute distance to given point. 
        """

    def norm(self):
        """
        norm(self) -> double

        Compute norm of point representing a vector from the origin. 
        """

    def cross(self, *args):
        """
        cross(self, Point p) -> Point

        Compute cross product with given vector. 
        """

    def dot(self, *args):
        """
        dot(self, Point p) -> double

        Compute dot product with given vector. 
        """

    def str(self, *args):
        """
        str(self, bool verbose) -> string

        Return informal string representation (pretty-print). 
        """

    def __getitem__(self, *args):
        """__getitem__(self, int i) -> double"""

    def __setitem__(self, *args):
        """__setitem__(self, int i, double val)"""

class Mesh(Variable):
    """
    A Mesh consists of a set of connected and numbered mesh entities.

    Both the representation and the interface are dimension-independent,
    but a concrete interface is also provided for standard named mesh
    entities:

    .. tabularcolumns:: |c|c|c|

    +--------+-----------+-------------+
    | Entity | Dimension | Codimension |
    +========+===========+=============+
    | Vertex |  0        |             |
    +--------+-----------+-------------+
    | Edge   |  1        |             | 
    +--------+-----------+-------------+
    | Face   |  2        |             | 
    +--------+-----------+-------------+
    | Facet  |           |      1      |
    +--------+-----------+-------------+
    | Cell   |           |        0    |
    +--------+-----------+-------------+

    When working with mesh iterators, all entities and connectivity
    are precomputed automatically the first time an iterator is
    created over any given topological dimension or connectivity.

    Note that for efficiency, only entities of dimension zero
    (vertices) and entities of the maximal dimension (cells) exist
    when creating a Mesh. Other entities must be explicitly created
    by calling init().

    For example, all edges in a mesh may be created by a call to mesh.init(1).
    Similarly, connectivities such as all edges connected to a given vertex
    must also be explicitly created (in this case by a call to
    mesh.init(0, 1)).
    """
    def __init__(self, *args):
        """
        **Overloaded versions**

        * Mesh\ **()**

          Create empty mesh.

        * Mesh\ **(mesh)**

          Copy constructor.

          *Arguments*
              mesh : a :py:class:`Mesh` instance.

        * Mesh\ **(filename)**

          Create mesh from data file.

          *Arguments*
              filename : string, name of file to load.
        """
    def num_vertices(self):
        """
        Get number of vertices in mesh.

        *Returns*
            integer : number of vertices.

        *Example*
            >>> mesh = dolfin.UnitSquare(2,2)
            >>> mesh.num_vertices()
            9
        """

    def num_edges(self):
        """
        Get number of edges in mesh.

        *Returns*
            integer : number of edges.


        *Example*
            >>> mesh = dolfin.UnitSquare(2,2)
            >>> mesh.num_edges()
            0
            >>> mesh.init(1)
            16
            >>> mesh.num_edges()
            16
        """

    def num_faces(self):
        """
        Get number of faces in mesh.

        *Returns*
            integer : number of faces.

        *Example*
            >>> mesh = dolfin.UnitSquare(2,2)
            >>> mesh.num_faces()
            8
        """

    def num_facets(self):
        """
        Get number of facets in mesh.

        *Returns*
            integer : number of facets.

        *Example*
            >>> mesh = dolfin.UnitSquare(2,2)
            >>> mesh.num_facets()
            0
            >>> mesh.init(0,1)
            >>> mesh.num_facets()
            16
        """

    def num_cells(self):
        """
        Get number of cells in mesh.

        *Returns*
            integer : number of cells.

        *Example*
            >>> mesh = dolfin.UnitSquare(2,2)
            >>> mesh.num_cells()
            8
        """

    def num_entities(self, d):
        """
        Get number of entities of given topological dimension.

        *Arguments*
            integer : d, topological dimension.

        *Returns*
            integer : number of entities of topological dimension d.

        *Example*
            >>> mesh = dolfin.UnitSquare(2,2)
            >>> mesh.init(0,1)
            >>> mesh.num_entities(0)
            9
            >>> mesh.num_entities(1)
            16
            >>> mesh.num_entities(2)
            8
        """

    def size(self, d):
        """
        Get number of entities of given topological dimension.

        *Arguments*
            integer : d, topological dimension.

        *Returns*
            integer : number of entities of topological dimension d.

        *Example*
            >>> mesh = dolfin.UnitSquare(2,2)
            >>> mesh.init(0,1)
            >>> mesh.num_entities(0)
            9
            >>> mesh.num_entities(1)
            16
            >>> mesh.num_entities(2)
            8
        """

    def topology(self):
        """
        *Returns*
            :py:class:`MeshTopology` : the topology object associated with the\
                                       mesh.
        """

    def geometry(self):
        """
        *Returns*
            :py:class:`MeshGeometry` : the geometry object associated with the\
                                       mesh.
        """

    def intersection_operator(self):
        """
        *Returns*
            :py:class:`IntersectionOperator` : the intersection operator\
                object associated with the mesh.
        """

    def data(self):
        """
        *Returns*
            :py:class:`MeshData` : the mesh data object associated with the\
                                   mesh.
        """

    def type(self):
        """
        *Returns*
            :py:class:`CellType` : the cell type object associated with the\
                                   mesh.
        """

    def init(self, *args):
        """
        Initialise mesh entities and connectivity.

        **Overloaded versions**

        * init\ **()**

          Compute all entities and connectivity.

        * init\ **(d)**

          Compute entities of given topological dimension.

          *Arguments*
              d : integer, topological dimension.

          *Returns*
              integer : number of created entities

        * init\ **(d0, d1)**

          Compute connectivity between given pair of dimensions.

          *Arguments*
              d0 : integer, topological dimension.

              d1 : integer, topological dimension.
        """

    def clear(self):
        """
        Clear all mesh data. 
        """

    def order(self):
        """
        Order all mesh entities (not needed if "mesh order entities" is
        set). 
        """

    def ordered(self):
        """

        *Returns*
            bool : Return true iff topology is ordered according to the UFC\
                   numbering.
        """

    def move(self, *args):
        """
        Move coordinates of Mesh.

        **Overloaded versions**

        * move\ **(boundary, method=hermite)**

          Move coordinates of mesh according to new boundary coordinates.

          *Arguments*
              boundary : a :py:class:`BoundaryMesh` instance.

              method : a :py:class:`ALEType` (enum).\
                       Method which defines how the coordinates should be\
                       moved, default is *hermite*.

        * move\ **(mesh, method=hermite)**

          Move coordinates of mesh according to adjacent mesh with common
          global vertices.

          *Arguments*
              mesh : a :py:class:`Mesh` instance.

              method : a :py:class:`ALEType` (enum).\
                       Method which defines how the coordinates should be\
                       moved, default is *hermite*.

        * move\ **(function)**

          Move coordinates of mesh according to displacement function. 

          *Arguments*
              function : a :py:class:`Function` instance.
        """

    def smooth(self, num_iterations = 1):
        """
        Smooth internal vertices of mesh by local averaging.

        *Arguments*
            num_iterations : integer, number of iterations to perform\
                             smoothing, default value is 1.
        """

    def smooth_boundary(self, num_iterations = 1, harmonic_smoothing = True):
        """
        Smooth boundary vertices of mesh by local averaging.

        *Arguments*
            num_iterations : integer, number of iterations to perform\
                             smoothing, default value is 1.

            harmonic_smoothing : bool, flag to turn on harmonics smoothing,\
                                 default value is True.
        """

    def snap_boundary(self, sub_domain, harmonic_smoothing = True):
        """
        Snap boundary vertices of mesh to match given sub domain.

        *Arguments*
            sub_domain : a :py:class:`SubDomain` instance.

            harmonic_smoothing : bool, a flag to turn on harmonics smoothing,\
                                default value is True.
        """

    def all_intersected_entities(self, *args):
        """
        This function computes the cell ids of all cells of the current mesh
        which intersects with a given mesh entity. The result is stored in
        the last argument to the function which might be a vector or a set
        depending on which version is called.

        **Overloaded versions**

        * all_intersected_entities\ **(point, ids_result)**

          Compute all ids of all cells which are intersected by the given
          point.

          *Arguments*
              point : a :py:class:`Point` instance.

              ids_result : set of integers.\
                           The cell ids which are intersectedare stored in a\
                           set for efficiency reasons, to avoid to sort out\
                           duplicates later on.

        * all_intersected_entities\ **(points, ids_result)**

          Compute all ids of all cells which are intersected by any point in
          points.

          *Arguments*
              point : a :py:class:`Point` instance.

              ids_result : set of integers.\
                           The cell ids which are intersected are stored in a\
                           set for efficiency reasons, to avoid to sort out\
                           duplicates later on.

        * all_intersected_entities\ **(entity, ids_result)**

          Compute all ids of all cells which are intersected by the given
          entity.

          *Arguments*
              entity : a :py:class:`MeshEntity` instance.

              ids_result : list of integers.\
                           The ids of the intersected cells are saved in a\
                           list. This is more efficent than using a set and\
                           allows a map between the (external) cell and the
                           intersected cell of the mesh.

        * all_intersected_entities\ **(entities, ids_result)**

          Compute all id of all cells which are intersects by any entity in the
          list entities.

          *Arguments*
              entities : list of :py:class:`MeshEntity`.

              ids_result : set of integers.\
                           The cell ids which are intersected are stored in a\
                           set for efficiency reasons, to avoid to sort out\
                           duplicates later on.

        * all_intersected_entities\ **(another_mesh, ids_result)**

          Compute all ids of all cells which are intersected by another_mesh.

          *Arguments*
              another_mesh : a :py:class:`Mesh` instance.

              ids_result : set of integers.\
                           The cell ids which are intersected are stored in a\
                           set for efficiency reasons, to avoid to sort out\
                           duplicates later on.
        """

    def any_intersected_entity(self, point):
        """
        Computes only the first id  of the entity, which contains the point.

        *Arguments*
            point : a :py:class:`Point` instance.

        *Returns*
            integer : the first id of the cell, which contains the point,\
                      returns -1 if no cell is intersected.
        """

    def closest_point(self, point):
        """
        Computes the point inside the mesh which is closest to the point query.

        *Arguments*
            point : a :py:class:`Point` instance.

        *Returns*
            :py:class:`Point` : the point inside the mesh which is closest to\
                                the point.
        """

    def closest_cell(self, point):
        """
        Computes the index of the cell in the mesh which is closest to the
        point query.

        *Arguments*
            point : a :py:class:`Point` instance.

        *Returns*
            integer : the index of the cell in the mesh which is closest to\
                      point.

        *Example*
            >>> mesh = dolfin.UnitSquare(1,1)
            >>> point = dolfin.Point(0.0, 2.0)
            >>> mesh.closest_cell(point)
            1
        """

    def closest_point_and_cell(self, point):
        """
        Computes the point inside the mesh and the corresponding cell index
        which are closest to the point query.

        *Arguments*
            point : a :py:class:`Point` instance.

        *Returns*
            ??? : the point inside the mesh and the corresponding cell index\
                  which is closest to the point query.

        std::pair<(dolfin::Point,dolfin::uint)>

        .. warning::

            Incomplete documentation: Don't know what the return value translates into.
        """

    def hmin(self):
        """
        Compute minimum cell diameter.

        *Returns*
            float : the minimum cell diameter, the diameter is computed as\
                    two times the circumradius (http://mathworld.wolfram.com).

        *Example*
            >>> mesh = dolfin.UnitSquare(2,2)
            >>> mesh.hmin()
            0.70710678118654757
        """

    def hmax(self):
        """
        Compute maximum cell diameter.

        *Returns*
            float : the maximum cell diameter, the diameter is computed as\
                    two times the circumradius (http://mathworld.wolfram.com).

        *Example*
            >>> mesh = dolfin.UnitSquare(2,2)
            >>> mesh.hmax()
            0.70710678118654757
        """

    def str(self, verbose):
        """
        Informal string representation.

        *Arguments*
            verbose : bool, a flag to turn on additional output.

        *Returns*
            string : an informal representation of the mesh.

        *Example*
            >>> mesh = dolfin.UnitSquare(2,2)
            >>> mesh.str(False)
            '<Mesh of topological dimension 2 (triangles) with 9 vertices and 8 cells, ordered>'
        """

    def coordinates(self):
        """
        *Returns*
            numpy.ndarray : Coordinates of all vertices.

        *Example*
            >>> mesh = dolfin.UnitSquare(1,1)
            >>> mesh.coordinates()
            array([[ 0.,  0.],
                   [ 1.,  0.],
                   [ 0.,  1.],
                   [ 1.,  1.]])
        """

    def cells(self):
        """
        *Returns*
            numpy.ndarray : Connectivity for all cells.

        *Example*
            >>> mesh = dolfin.UnitSquare(1,1)
            >>> mesh.coordinates()
            array([[0, 1, 3],
                   [0, 2, 3]])
        """
