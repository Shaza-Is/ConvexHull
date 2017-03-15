// -------------------- C++ 
#include <iostream>
#include "ConvexHull.h"

MyMesh* ConvexHull::getHull(MyMesh* mesh)
{
	return Algorithm->calculateConvHull(mesh);
}