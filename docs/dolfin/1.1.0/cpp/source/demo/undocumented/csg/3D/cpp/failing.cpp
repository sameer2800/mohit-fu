// Copyright (C) 2012 Benjamin Kehlet
//
// This file is part of DOLFIN.
//
// DOLFIN is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// DOLFIN is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
// GNU Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public License
// along with DOLFIN. If not, see <http://www.gnu.org/licenses/>.
//
// Modified by Benjamin Kehlet, 2012
// Modified by Johannes Ring, 2012
//
// First added:  2012-05-11
// Last changed: 2012-11-12

#include <dolfin.h>

using namespace dolfin;

#ifdef HAS_CGAL

int main()
{
  // Define 3D geometry  
  Cone cone(Point(-1.0, 1.0, 1.0), Point(1.0, -1.0, -1.0), .5, .5);
  //Cone cone2(Point(1.0, 1.0, 1.0), Point(-1.0, -1.0, -1.0), 0, .5);
  Cylinder cyl(Point(1.0, -1.0, 1.0), Point(-1.0, 1.0, -1.0), .5);
  const boost::shared_ptr<CSGGeometry> g3d = cone + cyl;

  // Test printing
  info("\nCompact output of 3D geometry:");
  info(*g3d);
  info("\nVerbose output of 3D geometry:");
  info(*g3d, true);

  // Generate mesh
  Mesh mesh3d(g3d, 64);

  // Plot meshes
  plot(mesh3d, "3D mesh");

  return 0;
}

#else

int main()
{
  info("DOLFIN must be compiled with CGAL to run this demo.");
  return 0;
}
#endif 
