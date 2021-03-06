.. Documentation for the Cahn-Hilliard demo from DOLFIN.

.. _demo_pde_cahn_hilliard_cpp_documentation:

Cahn-Hilliard equation
======================

.. include:: ../common.txt

Implementation
--------------

The implementation is split in three files: two form files containing the
definition of the variational forms expressed in UFL and a C++ file
containing the actual solver.

Running this demo requires the files: :download:`main.cpp`,
:download:`CahnHilliard2D.ufl`, :download:`CahnHilliard3D.ufl` and
:download:`CMakeLists.txt`.

UFL form files
^^^^^^^^^^^^^^

The UFL code for this problem in two and three dimensions are in
:download:`CahnHilliard2D.ufl` and :download:`CahnHilliard3D.ufl` respectively.
They differ only in the first line setting the cell:

.. code-block:: python

    cell = triangle

First, a mixed function spaces of linear Lagrange functions on triangles
is created:

.. code-block:: python

    P1 = FiniteElement("Lagrange", cell, 1)
    ME = P1*P1

On the mixed space, trial and test functions are defined:

.. code-block:: python

    du   = TrialFunction(ME)
    q, v = TestFunctions(ME)

The test functions have been split into components.

Coefficient functions are now defined for the current solution (the
most recent guess) and the solution from the beginning of the time
step. Further, these functions (and the trial function) are split into
their components:

.. code-block:: python

    u   = Coefficient(ME)  # current solution
    u0  = Coefficient(ME)  # solution from previous converged step

    # Split mixed functions
    dc, dmu = split(du)
    c,  mu  = split(u)
    c0, mu0 = split(u0)

Various model parameters can be specified using the class
:py:class:`Constant`. This means that their value can be changed
without recompiling the UFL file.  Lastly, the value of
:math:`\mu_{n+\theta}` is computed.

.. code-block:: python

    lmbda    = Constant(cell) # surface energy parameter
    dt       = Constant(cell) # time step
    theta    = Constant(cell) # time stepping parameter

    # mu_(n+theta)
    mu_mid = (1-theta)*mu0 + theta*mu

.. index:: automatic differentiation

The chemical potential :math:`df/dc` will be computed using automated
differentiation:

.. code-block:: python

    # Compute the chemical potential df/dc
    c    = variable(c)
    f    = 100*c**2*(1-c)**2
    dfdc = diff(f, c)

Here, the first line declares that ``c`` is a variable that some
function can be differentiated with respect to. The next line is the
function :math:`f` defined in the problem statement, and the third
line performs the differentiation of ``f`` with respect to the
variable ``c``.

The linear forms for the two equations can be summed into one form
``L``. We wish to drive the residual of this form to zero during the
solution process. The directional derivative of ``L`` can be computed
automatically, by calling ``derivative``, to form the bilinear form
``a`` representing the Jacobian matrix:

.. code-block:: python

    F0 = c*q*dx  - c0*q*dx   + dt*dot(grad(mu_mid), grad(q))*dx
    F1 = mu*v*dx - dfdc*v*dx - lmbda*dot(grad(c), grad(v))*dx
    F = F0 + F1

    J = derivative(F, u, du)

C++ program
^^^^^^^^^^^

The first lines of this solver include the ``DOLFIN`` header files
and the two files generated by the form compiler, and the ``DOLFIN``
namespace is used:

.. code-block:: c++

  #include <dolfin.h>
  #include "CahnHilliard2D.h"
  #include "CahnHilliard3D.h"

  using namespace dolfin;


The class ``InitialConditions`` defines the initial conditions for the
solver.  In the constructor, the random number generator is seeded
using the rank (process number) so that different processes will
generate different sequences when running in parallel. The ``eval``
function evaluates the initial condition. The first value (``[0]``)
corresponds to :math:`c` and the second value (``[1]``) corresponds to
:math:`\mu`:

.. code-block:: c++

   // Initial conditions
   class InitialConditions : public Expression
   {
   public:

     InitialConditions() : Expression(2)
     {
        dolfin::seed(2 + dolfin::MPI::rank(MPI_COMM_WORLD));
     }

     void eval(Array<double>& values, const Array<double>& x) const
     {
       values[0]= 0.63 + 0.02*(0.5 - dolfin::rand());
       values[1]= 0.0;
     }
   };


The next class is a subclass of :cpp:class:`NonlinearProblem`. A
:cpp:class:`NonlinearProblem` object can be passed to a
:cpp:class:`NewtonSolver` to be solved. The requirements of a
:cpp:class:`NonlinearProblem` subclass are that it provides the
function ``void F(GenericVector& b, const GenericVector& x)`` for
computing the residual vector and the function ``void J(GenericMatrix&
A, const GenericVector& x)`` for computing the Jacobian matrix.  The
below class is designed to work for two different generated forms (2D
and 3D), with the appropriate form chosen based on the geometric
dimension of the mesh. The makes the class more complicated than would
be the case if it supported a single form type.  The class is first
declared as a subclass of cpp:class:`NonlinearProblem`:

.. code-block:: c++

  // User defined nonlinear problem
  class CahnHilliardEquation : public NonlinearProblem
  {
    public:

Its constructor takes the various arguments which are required
to create the forms, and it calls a the templated private member
function ``init``:

.. code-block:: c++

    // Constructor
    CahnHilliardEquation(std::shared_ptr<const Mesh> mesh,
                         std::shared_ptr<const Constant> dt,
                         std::shared_ptr<const Constant> theta,
                         std::shared_ptr<const Constant> lambda)
    {
      // Initialize class (depending on geometric dimension of the mesh).
      // Unfortunately C++ does not allow namespaces as template arguments
      dolfin_assert(mesh);
      if (mesh->geometry().dim() == 2)
      {
        init<CahnHilliard2D::FunctionSpace, CahnHilliard2D::JacobianForm,
             CahnHilliard2D::ResidualForm>(mesh, dt, theta, lambda);
      }
      else if (mesh->geometry().dim() == 3)
      {
        init<CahnHilliard3D::FunctionSpace, CahnHilliard3D::JacobianForm,
             CahnHilliard3D::ResidualForm>(mesh, dt, theta, lambda);
      }
      else
        error("Cahn-Hilliard model is programmed for 2D and 3D only.");
    }

The function ``F`` computes the residual vector, which corresponds to
assembly of the form ``L``:

.. code-block:: c++

      // User defined residual vector
      void F(GenericVector& b, const GenericVector& x)
      {
        // Assemble RHS (Neumann boundary conditions)
        Assembler assembler;
        assembler.assemble(b, *L);
      }

The function ``J`` computes the Jacobian matrix, which corresponds to
the assembly of the form ``a``.

.. code-block:: c++

      // User defined assemble of Jacobian
      void J(GenericMatrix& A, const GenericVector& x)
      {
        // Assemble system
        Assembler assembler;
        assembler.assemble(A, *a);
      }

The following two functions are helper functions which allow access to
the solution vectors:

.. code-block:: c++

      // Return solution function
      Function& u()
      { return *_u; }

      // Return solution function
      Function& u0()
      { return *_u0; }

The private ``init`` function is responsible for creating the forms
and functions associated with the problem. It is a templated function
so that the 2D and 3D cases can be handled with the same code.
Firstly, a shared pointer to a :cpp:class:`FunctionSpace` (``X``) is
created. Then two shared pointers ``_u`` and ``_u0`` are set to point
to :cpp:class:`Function` s from the space ``V``.  A shared pointer is
used so that the function space is not destroyed when the constructor
exits. (The function space will not be destroyed until there are no
more Functions or Forms that point to it.)  Using the function space
``V``, bilinear and linear forms are created using ``new``, and the
coefficient functions are attached. These forms are then wrapped in a
shared pointer (using the ``reset`` function) which will take care of
eventually destroying the forms. Finally, ``_u`` is set equal to the
initial condition (by interpolation).

.. code-block:: c++

    private:

      template<class X, class Y, class Z>
      void init(std::shared_ptr<const Mesh> mesh,
                std::shared_ptr<const Constant> dt,
                std::shared_ptr<const Constant> theta,
                std::shared_ptr<const Constant> lambda)
      {
        // Create function space and functions
        std::shared_ptr<X> V(new X(mesh));
        _u.reset(new Function(V));
        _u0.reset(new Function(V));

        // Create forms and attach functions
        Y* _a = new Y(V, V);
        Z* _L = new Z(V);
        _a->u = _u;
        _a->lmbda = lambda; _a->dt = dt; _a->theta = theta;
        _L->u = _u; _L->u0 = _u0;
        _L->lmbda = lambda; _L->dt = dt; _L->theta = theta;

        // Wrap pointers in a smart pointer
        a.reset(_a);
        L.reset(_L);

        // Set solution to intitial condition
        InitialConditions u_initial;
        *_u = u_initial;
      }

The ``CahnHilliardEquation`` class stores the data required for
computing the residual vector and the Jacobian matrix as private data:

.. code-block:: c++

      // Function space, forms and functions
      std::unique_ptr<Form> a;
      std::unique_ptr<Form> L;
      std::shared_ptr<Function> _u;
      std::shared_ptr<Function> _u0;
  };

The main program is started, and declared such that it can accept
command line arguments. Such are parsed to ``init``:

.. code-block:: c++

  int main(int argc, char* argv[])
  {
    init(argc, argv);


A mesh is then created with 97 (96 + 1) vertices in each direction:

.. code-block:: c++

    // Mesh
    auto mesh = std::make_shared<UnitSquareMesh>(96, 96);

A set of constants (required for the assembling of the forms) and two
scalars (to be used in the time stepping) are then declared:

.. code-block:: c++

    // Time stepping and model parameters
    auto dt = std::make_shared<Constant>(5.0e-6);
    auto theta = std::make_shared<Constant>(0.5);
    auto lambda = std::make_shared<Constant>(1.0e-2);

    double t = 0.0;
    double T = 50*(*dt);

A ``CahnHilliardEquation`` object is created, which will be used in conjunction
with a Newton solver, and references to solution functions are
declared:

.. code-block:: c++

    // Create user-defined nonlinear problem
    CahnHilliardEquation cahn_hilliard(mesh, dt, theta, lambda);

    // Solution functions
    Function& u = cahn_hilliard.u();
    Function& u0 = cahn_hilliard.u0();


A Newton solver is created which will use a LU linear solver, and various
solver parameters are set:

.. code-block:: c++

    // Create nonlinear solver and set parameters
    NewtonSolver newton_solver;
    newton_solver.parameters["linear_solver"] = "lu";
    newton_solver.parameters["convergence_criterion"] = "incremental";
    newton_solver.parameters["maximum_iterations"] = 10;
    newton_solver.parameters["relative_tolerance"] = 1e-6;
    newton_solver.parameters["absolute_tolerance"] = 1e-15;

A file is created for saving the solution at each time step in VTK
format. The data will be compressed to reduce the file size.

.. code-block:: c++

    // Save initial condition to file
    File file("cahn_hilliard.pvd", "compressed");
    file << u[0];

The solution process is based on stepping forward in time. At the
beginning of each time step, time is incremented and :math:`u_{n}
\leftarrow u_{n+1}`. The Newton solver is then used to solve the
nonlinear equation and the first component of the solution (``u[0]``)
is saved to a file, along with the time ``t``.

.. code-block:: c++

    // Solve
    while (t < T)
    {
      // Update for next time step
      t += *dt;
      *u0.vector() = *u.vector();

      // Solve
      newton_solver.solve(cahn_hilliard, *u.vector());

      // Save function to file
      file << std::pair<const Function*, double>(&(u[0]), t);
    }

The final result is plotted to the screen and the program is finished.

.. code-block:: c++

    // Plot solution
    plot(u[0]);
    interactive();

    return 0;
  }


Complete code
-------------

Complete UFL files
^^^^^^^^^^^^^^^^^^

.. literalinclude:: CahnHilliard2D.ufl
   :start-after: # Compile
   :language: python

.. literalinclude:: CahnHilliard3D.ufl
   :start-after: # Compile
   :language: python


Complete main file
^^^^^^^^^^^^^^^^^^

.. literalinclude:: main.cpp
   :start-after: // Begin demo
   :language: c++
