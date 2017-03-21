// -------------------- C++ 
#include <iostream>
#include "ConvexHull.h"

ConvexHull::ConvexHull(const TriMesh &_mesh, Algorithms a)
{
    if(a == IncrementalAlogrithm)
    algorithm = new Incremental(_mesh);
}

TriMesh ConvexHull::getHull()
{
    return algorithm->getResult();
}

ConvexHull::~ConvexHull()
{
    delete algorithm;
}
