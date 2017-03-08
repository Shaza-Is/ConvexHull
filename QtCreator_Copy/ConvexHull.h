#ifndef ONVEXHULL_H
#define CONVEXHULL_H
// -------------------- C++ 
#include <iostream>
#include "HullAlgorithm.h"
#include "Incremental.h"
// -------------------- OpenMesh
#include <OpenMesh/Core/Mesh/TriMesh_ArrayKernelT.hh>
typedef OpenMesh::TriMesh_ArrayKernelT<> MyMesh;

enum Algorithms
{
    IncrementalAlogrithm
};

class ConvexHull
{
public:
    ConvexHull(Algorithms a=IncrementalAlogrithm);
    MyMesh getHull(const MyMesh &mesh);

private:
	HullAlgorithm * algorithm;        
};

#endif //CONVEXHULL_H
