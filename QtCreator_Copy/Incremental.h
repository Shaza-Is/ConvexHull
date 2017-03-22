#ifndef INCREMENTAL_H
#define INCREMENTAL_H
// -------------------- OpenMesh
#include <OpenMesh/Core/Mesh/TriMesh_ArrayKernelT.hh>
#include <OpenMesh/Core/Mesh/PolyConnectivity.hh>
#include <OpenMesh/Core/Mesh/TriConnectivity.hh>
#include "HullAlgorithm.h"

typedef OpenMesh::TriMesh_ArrayKernelT<> TriMesh;


class Incremental : public HullAlgorithm
{
public:
    explicit Incremental(const TriMesh& _mesh);

    TriMesh getResult() const;

private:
	void createInitialTetrahedron();
	void incremental();

	TriMesh mHullMesh;
	TriMesh mInputMesh;
};

#endif
