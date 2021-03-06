
.. Documentation for the header file dolfin/la/EpetraMatrix.h

.. _programmers_reference_cpp_la_epetramatrix:

EpetraMatrix.h
==============

.. note::
    
    The documentation on this page was automatically extracted from the
    DOLFIN C++ code and may need to be edited or expanded.
    

.. cpp:class:: EpetraMatrix

    *Parent class(es)*
    
        * :cpp:class:`GenericMatrix`
        
    This class provides a simple matrix class based on Epetra.
    It is a simple wrapper for an Epetra matrix object (Epetra_FECrsMatrix)
    implementing the GenericMatrix interface.
    
    The interface is intentionally simple. For advanced usage,
    access the Epetra_FECrsMatrix object using the function mat() and
    use the standard Epetra interface.


    .. cpp:function:: EpetraMatrix()
    
        Create empty matrix


    .. cpp:function:: EpetraMatrix(const EpetraMatrix& A)
    
        Copy constuctor


    .. cpp:function:: explicit EpetraMatrix(boost::shared_ptr<Epetra_FECrsMatrix> A)
    
        Create matrix from given Epetra_FECrsMatrix pointer


    .. cpp:function:: explicit EpetraMatrix(const Epetra_CrsGraph& graph)
    
        Create matrix from given Epetra_CrsGraph


    .. cpp:function:: bool distributed() const
    
        Return true if matrix is distributed


    .. cpp:function:: void init(const GenericSparsityPattern& sparsity_pattern)
    
        Initialize zero tensor using sparsity pattern


    .. cpp:function:: EpetraMatrix* copy() const
    
        Return copy of tensor


    .. cpp:function:: uint size(uint dim) const
    
        Return size of given dimension


    .. cpp:function:: std::pair<uint, uint> local_range(uint dim) const
    
        Return local ownership range


    .. cpp:function:: void zero()
    
        Set all entries to zero and keep any sparse structure


    .. cpp:function:: void apply(std::string mode)
    
        Finalize assembly of tensor. The following values are recognized
        for the mode parameter:
        
          add    - corresponding to Epetra GlobalAssemble(Add)
          insert - corresponding to Epetra GlobalAssemble(Insert)


    .. cpp:function:: std::string str(bool verbose) const
    
        Return informal string representation (pretty-print)


    .. cpp:function:: void resize(GenericVector& y, uint dim) const
    
        Resize vector y such that is it compatible with matrix for
        multuplication Ax = b (dim = 0 -> b, dim = 1 -> x) In parallel
        case, size and layout are important.


    .. cpp:function:: void get(double* block, uint m, const uint* rows, uint n, const uint* cols) const
    
        Get block of values


    .. cpp:function:: void set(const double* block, uint m, const uint* rows, uint n, const uint* cols)
    
        Set block of values


    .. cpp:function:: void add(const double* block, uint m, const uint* rows, uint n, const uint* cols)
    
        Add block of values


    .. cpp:function:: void axpy(double a, const GenericMatrix& A, bool same_nonzero_pattern)
    
        Add multiple of given matrix (AXPY operation)


    .. cpp:function:: double norm(std::string norm_type) const
    
        Return norm of matrix


    .. cpp:function:: void getrow(uint row, std::vector<uint>& columns, std::vector<double>& values) const
    
        Get non-zero values of given row


    .. cpp:function:: void setrow(uint row, const std::vector<uint>& columns, const std::vector<double>& values)
    
        Set values for given row


    .. cpp:function:: void zero(uint m, const uint* rows)
    
        Set given rows to zero


    .. cpp:function:: void ident(uint m, const uint* rows)
    
        Set given rows to identity matrix


    .. cpp:function:: const EpetraMatrix& operator*= (double a)
    
        Multiply matrix by given number


    .. cpp:function:: const EpetraMatrix& operator/= (double a)
    
        Divide matrix by given number


    .. cpp:function:: const GenericMatrix& operator= (const GenericMatrix& x)
    
        Assignment operator


    .. cpp:function:: LinearAlgebraFactory& factory() const
    
        Return linear algebra backend factory


    .. cpp:function:: void init(const EpetraSparsityPattern& sparsity_pattern)
    
        Initialize zero tensor using sparsity pattern


    .. cpp:function:: boost::shared_ptr<Epetra_FECrsMatrix> mat() const
    
        Return Epetra_FECrsMatrix pointer


    .. cpp:function:: const EpetraMatrix& operator= (const EpetraMatrix& x)
    
        Assignment operator


