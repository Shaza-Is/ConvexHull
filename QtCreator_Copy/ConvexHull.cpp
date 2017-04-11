// -------------------- C++ 
#include "ConvexHull.h"

ConvexHull::ConvexHull(const TriMesh &_mesh, Algorithms _algorithm)
{
    switch(_algorithm)
    {
        case Algorithms::IncrementalAlogrithm :
            algorithm = std::unique_ptr<Incremental>(new Incremental(_mesh));
            break;
    }
}

TriMesh ConvexHull::getHull() const
{
    return algorithm->getResult();
}


