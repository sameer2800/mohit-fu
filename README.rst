================================
FEniCS documentation and webpage
================================

The repository contains the source for the pages at
http://www.fenicsproject.org.

* How to: generate web pages
  ::

    make web

  This will read .rst files from the 'source' directory and generate
  .html files in the 'build/html' directory.

* How to: import documentation
  ::

    make import_docs

  This will import documentation input files (.rst) from all projects,
  build .html files and add those to 'build/html'. Running this
  script requires that all projects (currently DOLFIN and UFL) have
  been built and that the environment variables DOLFIN_DIR and UFL_DIR
  have been set.

* How to: publish web pages
  ::

    make publish

  This will upload the generated pages from 'build/html' to
  fenicsproject.org/new, including both the web pages and the
  documentation pages. Running this script requires access to the
  account fenics@fenicsproject.org.

* How to: do it all
  ::

    make all

  This is equivalent to running all of the above targets.
