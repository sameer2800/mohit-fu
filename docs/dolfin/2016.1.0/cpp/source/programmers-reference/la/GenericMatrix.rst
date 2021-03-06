
.. Documentation for the header file dolfin/la/GenericMatrix.h

.. _programmers_reference_cpp_la_genericmatrix:

GenericMatrix.h
===============

.. note::
    
    The documentation on this page was automatically extracted from the
    DOLFIN C++ code and may need to be edited or expanded.
    

.. cpp:class:: GenericMatrix

    *Parent class(es)*
    
        * :cpp:class:`GenericTensor`
        
        * :cpp:class:`GenericLinearOperator`
        
    This class defines a common interface for matrices.


    .. cpp:function:: std::size_t rank() const
    
        Return tensor rank (number of dimensions)


    .. cpp:function:: std::size_t size(std::size_t dim) const = 0
    
        Return size of given dimension


    .. cpp:function:: std::pair<std::int64_t, std::int64_t> local_range(std::size_t dim) const = 0
    
        Return local ownership range


    .. cpp:function:: std::size_t nnz() const = 0
    
        Return number of non-zero entries in matrix (collective)


    .. cpp:function:: void get(double* block, const dolfin::la_index* num_rows, const dolfin::la_index * const * rows) const
    
        Get block of values


    .. cpp:function:: void set(const double* block, const dolfin::la_index* num_rows, const dolfin::la_index * const * rows)
    
        Set block of values using global indices


    .. cpp:function:: void set_local(const double* block, const dolfin::la_index* num_rows, const dolfin::la_index * const * rows)
    
        Set block of values using local indices


    .. cpp:function:: void add(const double* block, const dolfin::la_index* num_rows, const dolfin::la_index * const * rows)
    
        Add block of values using global indices


    .. cpp:function:: void add_local(const double* block, const dolfin::la_index* num_rows, const dolfin::la_index * const * rows)
    
        Add block of values using local indices


    .. cpp:function:: void add(const double* block, const std::vector<ArrayView<const dolfin::la_index>>& rows)
    
        Add block of values using global indices


    .. cpp:function:: void add_local(const double* block, const std::vector<ArrayView<const dolfin::la_index>>& rows)
    
        Add block of values using local indices


    .. cpp:function:: void zero() = 0
    
        Set all entries to zero and keep any sparse structure


    .. cpp:function:: void apply(std::string mode) = 0
    
        Finalize assembly of tensor


    .. cpp:function:: std::string str(bool verbose) const = 0
    
        Return informal string representation (pretty-print)


    .. cpp:function:: std::shared_ptr<GenericMatrix> copy() const = 0
    
        Return copy of matrix


    .. cpp:function:: void init_vector(GenericVector& z, std::size_t dim) const = 0
    
        Initialize vector z to be compatible with the matrix-vector
        product y = Ax. In the parallel case, both size and layout are
        important.
        
        *Arguments*
            dim (std::size_t)
                The dimension (axis): dim = 0 --> z = y, dim = 1 --> z = x


    .. cpp:function:: void get(double* block, std::size_t m, const dolfin::la_index* rows, std::size_t n, const dolfin::la_index* cols) const = 0
    
        Get block of values


    .. cpp:function:: void set(const double* block, std::size_t m, const dolfin::la_index* rows, std::size_t n, const dolfin::la_index* cols) = 0
    
        Set block of values using global indices


    .. cpp:function:: void set_local(const double* block, std::size_t m, const dolfin::la_index* rows, std::size_t n, const dolfin::la_index* cols) = 0
    
        Set block of values using local indices


    .. cpp:function:: void add(const double* block, std::size_t m, const dolfin::la_index* rows, std::size_t n, const dolfin::la_index* cols) = 0
    
        Add block of values using global indices


    .. cpp:function:: void add_local(const double* block, std::size_t m, const dolfin::la_index* rows, std::size_t n, const dolfin::la_index* cols) = 0
    
        Add block of values using local indices


    .. cpp:function:: void axpy(double a, const GenericMatrix& A, bool same_nonzero_pattern) = 0
    
        Add multiple of given matrix (AXPY operation)


    .. cpp:function:: double norm(std::string norm_type) const = 0
    
        Return norm of matrix


    .. cpp:function:: void getrow(std::size_t row, std::vector<std::size_t>& columns, std::vector<double>& values) const = 0
    
        Get non-zero values of given row (global index) on local process


    .. cpp:function:: void setrow(std::size_t row, const std::vector<std::size_t>& columns, const std::vector<double>& values) = 0
    
        Set values for given row (global index) on local process


    .. cpp:function:: void zero(std::size_t m, const dolfin::la_index* rows) = 0
    
        Set given rows (global row indices) to zero


    .. cpp:function:: void zero_local(std::size_t m, const dolfin::la_index* rows) = 0
    
        Set given rows (local row indices) to zero


    .. cpp:function:: void ident(std::size_t m, const dolfin::la_index* rows) = 0
    
        Set given rows (global row indices) to identity matrix


    .. cpp:function:: void ident_local(std::size_t m, const dolfin::la_index* rows) = 0
    
        Set given rows (local row indices) to identity matrix


    .. cpp:function:: void transpmult(const GenericVector& x, GenericVector& y) const = 0
    
        Matrix-vector product, y = A^T x. The y vector must either be
        zero-sized or have correct size and parallel layout.


    .. cpp:function:: void get_diagonal(GenericVector& x) const = 0
    
        Get diagonal of a matrix


    .. cpp:function:: void set_diagonal(const GenericVector& x) = 0
    
        Set diagonal of a matrix


    .. cpp:function:: const GenericMatrix& operator*= (double a) = 0
    
        Multiply matrix by given number


    .. cpp:function:: const GenericMatrix& operator/= (double a) = 0
    
        Divide matrix by given number


    .. cpp:function:: const GenericMatrix& operator+= (const GenericMatrix& A)
    
        Add given matrix


    .. cpp:function:: const GenericMatrix& operator-= (const GenericMatrix& A)
    
        Subtract given matrix


    .. cpp:function:: bool is_symmetric(double tol) const
    
        Test if matrix is symmetric


    .. cpp:function:: const GenericMatrix& operator= (const GenericMatrix& x) = 0
    
        Assignment operator


    .. cpp:function:: double operator() (dolfin::la_index i, dolfin::la_index j) const
    
        Get value of given entry


    .. cpp:function:: double getitem(std::pair<dolfin::la_index, dolfin::la_index> ij) const
    
        Get value of given entry


    .. cpp:function:: void setitem(std::pair<dolfin::la_index, dolfin::la_index> ij, double value)
    
        Set given entry to value. apply("insert") must be called
        before using using the object.


    .. cpp:function:: void ident_zeros()
    
        Insert one on the diagonal for all zero rows


