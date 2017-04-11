// -------------------- C++
#include <iostream>
#include <cstdlib>
// -------------------- OpenMesh
#include <OpenMesh/Core/IO/MeshIO.hh>
#include "meshtype.h"
#include "ConvexHull.h"

using namespace std;

int main()
{
    TriMesh mesh;
    TriMesh hull;

    /*reader*/
    if (!OpenMesh::IO::read_mesh(mesh, "/home/shaza/Desktop/terr.ply"))
    {
        std::cerr << "read error\n";
        exit(EXIT_FAILURE);
    }

    /*algorithm*/
    ConvexHull cHull(mesh);
    hull = cHull.getHull();

    /*writer*/
    if (!OpenMesh::IO::write_mesh(hull, "/home/shaza/Desktop/output.ply"))
    {
        std::cerr << "write error\n";
        exit(EXIT_FAILURE);
    }
    return EXIT_SUCCESS;
}
