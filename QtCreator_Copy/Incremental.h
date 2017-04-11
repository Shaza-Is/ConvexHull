#ifndef INCREMENTAL_H
#define INCREMENTAL_H
// -------------------- OpenMesh
#include "meshtype.h"
#include <OpenMesh/Core/Mesh/PolyConnectivity.hh>
#include <OpenMesh/Core/Mesh/TriConnectivity.hh>
#include "HullAlgorithm.h"

class Incremental final : public HullAlgorithm
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
