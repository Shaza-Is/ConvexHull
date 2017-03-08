#ifndef HULLALGORITHM_H
#define HULLALGORITHM_H
// -------------------- OpenMesh
#include <OpenMesh/Core/Mesh/TriMesh_ArrayKernelT.hh>
typedef OpenMesh::TriMesh_ArrayKernelT<> MyMesh;



class HullAlgorithm
{
public:
    virtual  MyMesh calculateConvHull(const MyMesh& mesh)=0;


};

#endif //HULLALGORITHM_H
