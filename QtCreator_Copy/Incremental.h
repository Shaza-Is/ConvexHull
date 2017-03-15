#ifndef INCREMENTAL_H
#define INCREMENTAL_H
// -------------------- OpenMesh
#include <OpenMesh/Core/IO/MeshIO.hh>
#include <OpenMesh/Core/Mesh/TriMesh_ArrayKernelT.hh>
#include <OpenMesh/Core/Mesh/PolyConnectivity.hh>
#include <OpenMesh/Core/Mesh/TriConnectivity.hh>


typedef OpenMesh::TriMesh_ArrayKernelT<> TriMesh;
//using namespace OpenMesh;

//#include "MeshProcessing\Mesh\TriMesh.h"

//using namespace Symbyo::CG;

class Incremental
{
public:
	Incremental(const TriMesh& _mesh);

    TriMesh getResult() const;

private:
	void createInitialTetrahedron();
	void incremental();
	void flipHullMesh();

	TriMesh mHullMesh;
	TriMesh mInputMesh;
};

#endif
