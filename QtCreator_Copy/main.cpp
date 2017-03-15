// -------------------- C++
#include <iostream>

// -------------------- OpenMesh
#include <OpenMesh/Core/IO/MeshIO.hh>
#include <OpenMesh/Core/Mesh/TriMesh_ArrayKernelT.hh>

#include "ConvexHull.h"
typedef OpenMesh::TriMesh_ArrayKernelT<> TriMesh;
using namespace std;

int main()
{
    TriMesh mesh;
    TriMesh hull;


    /*reader*/
    if (!OpenMesh::IO::read_mesh(mesh, "/home/shaza/Desktop/sphere.ply"))
    {
        std::cerr << "read error\n";
        exit(1);
    }

    /*algorithm*/
    ConvexHull cHull(mesh);
    hull = cHull.getHull();

    /*writer*/
    if (!OpenMesh::IO::write_mesh(hull, "/home/shaza/Desktop/output.ply"))
    {
        std::cerr << "write error\n";
        exit(1);
    }
    return 0;
}

