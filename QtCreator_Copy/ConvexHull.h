#ifndef CONVEXHULL_H
#define CONVEXHULL_H
// -------------------- C++ 
#include <memory>
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
    ConvexHull(const TriMesh& _mesh, Algorithms _algorithm=IncrementalAlogrithm);
    TriMesh getHull() const;

private:
    std::unique_ptr<HullAlgorithm> algorithm;
};

#endif //CONVEXHULL_H
