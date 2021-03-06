
.. Documentation for the header file dolfin/la/MTL4Vector.h

.. _programmers_reference_cpp_la_mtl4vector:

MTL4Vector.h
============

.. note::
    
    The documentation on this page was automatically extracted from the
    DOLFIN C++ code and may need to be edited or expanded.
    

.. cpp:class:: MTL4Vector

    *Parent class(es)*
    
        * :cpp:class:`GenericVector`
        
    .. cpp:function:: MTL4Vector()
    
        Create empty vector


    .. cpp:function:: explicit MTL4Vector(uint N)
    
        Create vector of size N


    .. cpp:function:: MTL4Vector(const MTL4Vector& x)
    
        Copy constructor


    .. cpp:function:: MTL4Vector* copy() const
    
        Return copy of tensor


    .. cpp:function:: void zero()
    
        Set all entries to zero and keep any sparse structure


    .. cpp:function:: void apply(std::string mode)
    
        Finalize assembly of tensor


    .. cpp:function:: std::string str(bool verbose) const
    
        Return informal string representation (pretty-print)


    .. cpp:function:: void resize(uint N)
    
        Resize vector to size N


    .. cpp:function:: void resize(std::pair<uint, uint> range)
    
        Resize vector with given ownership range


    .. cpp:function:: void resize(std::pair<uint, uint> range, const std::vector<uint>& ghost_indices)
    
        Resize vector with given ownership range and with ghost values


    .. cpp:function:: uint size() const
    
        Return size of vector


    .. cpp:function:: uint local_size() const
    
        Return local size of vector


    .. cpp:function:: std::pair<uint, uint> local_range() const
    
        Return local ownership range of a vector


    .. cpp:function:: bool owns_index(uint i) const
    
        Determine whether global vector index is owned by this process


    .. cpp:function:: void get_local(double* block, uint m, const uint* rows) const
    
        Get block of values


    .. cpp:function:: void set(const double* block, uint m, const uint* rows)
    
        Set block of values


    .. cpp:function:: void add(const double* block, uint m, const uint* rows)
    
        Add block of values


    .. cpp:function:: void get_local(Array<double>& values) const
    
        Get all values on local process


    .. cpp:function:: void set_local(const Array<double>& values)
    
        Set all values on local process


    .. cpp:function:: void add_local(const Array<double>& values)
    
        Add all values to each entry on local process


    .. cpp:function:: void gather(GenericVector& x, const Array<uint>& indices) const
    
        Gather entries into local vector x


    .. cpp:function:: void gather_on_zero(Array<double>& x) const
    
        Gather all entries into Array x on process 0


    .. cpp:function:: void axpy(double a, const GenericVector& x)
    
        Add multiple of given vector (AXPY operation)


    .. cpp:function:: void abs()
    
        Replace all entries in the vector by their absolute values


    .. cpp:function:: double inner(const GenericVector& vector) const
    
        Return inner product with given vector


    .. cpp:function:: double norm(std::string norm_type) const
    
        Return norm of vector


    .. cpp:function:: double min() const
    
        Return minimum value of vector


    .. cpp:function:: double max() const
    
        Return maximum value of vector


    .. cpp:function:: double sum() const
    
        Return sum of values of vector


    .. cpp:function:: double sum(const Array<uint>& rows) const
    
        Return sum of selected rows in vector. Repeated entries are only summed once.


    .. cpp:function:: const MTL4Vector& operator*= (double a)
    
        Multiply vector by given number


    .. cpp:function:: const MTL4Vector& operator*= (const GenericVector& x)
    
        Multiply vector by another vector pointwise


    .. cpp:function:: const MTL4Vector& operator/= (double a)
    
        Divide vector by given number


    .. cpp:function:: const MTL4Vector& operator= (double a)
    
        Assignment operator


    .. cpp:function:: const MTL4Vector& operator+= (const GenericVector& x)
    
        Add given vector


    .. cpp:function:: const MTL4Vector& operator-= (const GenericVector& x)
    
        Subtract given vector


    .. cpp:function:: const GenericVector& operator= (const GenericVector& x)
    
        Assignment operator


    .. cpp:function:: const double* data() const
    
        Return pointer to underlying data (const version)


    .. cpp:function:: double* data()
    
        Return pointer to underlying data (non-const version)


    .. cpp:function:: const mtl4_vector& vec() const
    
        Return const mtl4_vector reference


    .. cpp:function:: mtl4_vector& vec()
    
        Return mtl4_vector reference


    .. cpp:function:: const MTL4Vector& operator= (const MTL4Vector& x)
    
        Assignment operator


