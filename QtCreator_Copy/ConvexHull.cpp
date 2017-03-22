// -------------------- C++ 
#include "ConvexHull.h"

ConvexHull::ConvexHull(const TriMesh &_mesh, Algorithms _algorithm)
{
    if(_algorithm == IncrementalAlogrithm)
    algorithm = std::unique_ptr<Incremental>(new Incremental(_mesh));

}

TriMesh ConvexHull::getHull() const
{
    return algorithm->getResult();
}


