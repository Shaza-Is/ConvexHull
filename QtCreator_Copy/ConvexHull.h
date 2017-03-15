#ifndef ONVEXHULL_H
#define CONVEXHULL_H
// -------------------- C++ 
#include <iostream>
#include "Incremental.h"
#include "HullAlgorithm.h"

// -------------------- OpenMesh
#include <OpenMesh/Core/Mesh/TriMesh_ArrayKernelT.hh>
typedef OpenMesh::TriMesh_ArrayKernelT<> TriMesh;

enum Algorithms
{
    IncrementalAlogrithm
};

class ConvexHull
{
public:
    ConvexHull(const TriMesh& _mesh, Algorithms a=IncrementalAlogrithm);
    TriMesh getHull();
    ~ConvexHull();

private:
	HullAlgorithm * algorithm;        
};

#endif //CONVEXHULL_H
