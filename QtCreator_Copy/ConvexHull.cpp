// -------------------- C++ 
#include <iostream>
#include "ConvexHull.h"

ConvexHull::ConvexHull(Algorithms a)
{
    if(a == IncrementalAlogrithm)
    algorithm = new Incremental();
}

MyMesh ConvexHull::getHull(const MyMesh& mesh)
{
    return algorithm->calculateConvHull(mesh);
}
