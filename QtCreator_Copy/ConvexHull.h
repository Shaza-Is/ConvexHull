#ifndef CONVEXHULL_H
#define CONVEXHULL_H
// -------------------- C++ 
#include <memory>
#include "Incremental.h"
#include "HullAlgorithm.h"

// -------------------- OpenMesh
#include "meshtype.h"

enum class Algorithms
{
    IncrementalAlogrithm
};
class HullAlgorithm;

class ConvexHull
{
public:
    ConvexHull(const TriMesh& _mesh, Algorithms _algorithm=Algorithms::IncrementalAlogrithm);
    TriMesh getHull() const;

private:
    std::unique_ptr<HullAlgorithm> algorithm;
};

#endif //CONVEXHULL_H
