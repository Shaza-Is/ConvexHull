#ifndef HULLALGORITHM_H
#define HULLALGORITHM_H
// -------------------- OpenMesh
#include <OpenMesh/Core/Mesh/TriMesh_ArrayKernelT.hh>
typedef OpenMesh::TriMesh_ArrayKernelT<> TriMesh;



class HullAlgorithm
{
public:
    virtual TriMesh getResult() const=0;
    virtual ~HullAlgorithm();
};

#endif //HULLALGORITHM_H
