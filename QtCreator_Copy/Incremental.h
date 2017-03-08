#ifndef INCREMENTAL_H
#define INCREMENTAL_H
// -------------------- C++ 
#include <iostream>
#include "HullAlgorithm.h"
// -------------------- OpenMesh
#include <OpenMesh/Core/Mesh/TriMesh_ArrayKernelT.hh>
#include <OpenMesh/Core/Mesh/PolyConnectivity.hh>
#include <OpenMesh/Core/Mesh/TriConnectivity.hh>

typedef OpenMesh::TriMesh_ArrayKernelT<> TriMesh;

class Incremental //: public HullAlgorithm
{
public:
    Incremental(){}
    TriMesh calculateConvHull(const TriMesh& mesh);
        
};

#endif //INCREMENTAL_H
