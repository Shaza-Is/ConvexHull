// -------------------- C++ 
#include <iostream>
#include "ConvexHull.h"
// -------------------- OpenMesh
#include <OpenMesh/Core/IO/MeshIO.hh>
#include <OpenMesh/Core/Mesh/TriMesh_ArrayKernelT.hh>
typedef OpenMesh::TriMesh_ArrayKernelT<> MyMesh;

int main()
{
	MyMesh mesh;
	MyMesh* hull;
	ConvexHull cHull;

/*reader*/
	if (!OpenMesh::IO::read_mesh(mesh, "input.off")) 
	{
  		std::cerr << "read error\n";
  		exit(1);
	}

/*algorithm*/
	hull = cHull.getHull(&mesh);

/*writer*/
	if (!OpenMesh::IO::write_mesh(hull, "ConvexHull.off")) 
	{
  		std::cerr << "write error\n";
  		exit(1);
	}
}