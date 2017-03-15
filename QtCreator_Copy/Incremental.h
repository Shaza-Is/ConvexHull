#ifndef INCREMENTAL_H
#define INCREMENTAL_H
// -------------------- OpenMesh
#include <OpenMesh/Core/IO/MeshIO.hh>
#include <OpenMesh/Core/Mesh/TriMesh_ArrayKernelT.hh>
#include <OpenMesh/Core/Mesh/PolyConnectivity.hh>
#include <OpenMesh/Core/Mesh/TriConnectivity.hh>
#include "HullAlgorithm.h"

typedef OpenMesh::TriMesh_ArrayKernelT<> TriMesh;
//using namespace OpenMesh;

//#include "MeshProcessing\Mesh\TriMesh.h"

//using namespace Symbyo::CG;

class Incremental : public HullAlgorithm
{
public:
	Incremental(const TriMesh& _mesh);

    TriMesh getResult() const;
    ~Incremental();
private:
	void createInitialTetrahedron();
	void incremental();
	void flipHullMesh();

	TriMesh mHullMesh;
	TriMesh mInputMesh;
};

#endif
