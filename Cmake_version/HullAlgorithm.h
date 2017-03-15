#ifndef HULLALGORITHM_H
#define HULLALGORITHM_H
// -------------------- OpenMesh
#include <OpenMesh/Core/Mesh/TriMesh_ArrayKernelT.hh>
typedef OpenMesh::TriMesh_ArrayKernelT<> MyMesh;

enum Algorithms
{
	IncrementalAlogrithm	
};

class HullAlgorithm
{
public:
	HullAlgorithm(Algorithms a=IncrementalAlogrithm);
	virtual MyMesh* calculateConvHull(MyMesh* mesh)=0;

private:
	Algorithms algorithm;
};

#endif //HULLALGORITHM_H