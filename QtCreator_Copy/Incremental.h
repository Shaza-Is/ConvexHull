#ifndef INCREMENTAL_H
#define INCREMENTAL_H
// -------------------- C++ 
#include <iostream>
#include "HullAlgorithm.h"
// -------------------- OpenMesh
#include <OpenMesh/Core/Mesh/TriMesh_ArrayKernelT.hh>
#include <OpenMesh/Core/Mesh/TriConnectivity.hh>

typedef OpenMesh::TriMesh_ArrayKernelT<> MyMesh;

class Incremental : public HullAlgorithm 
{
public:
	Incremental();
	MyMesh* calculateConvHull(MyMesh* mesh);
        
};

#endif //INCREMENTAL_H
