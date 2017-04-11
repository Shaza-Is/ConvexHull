#ifndef HULLALGORITHM_H
#define HULLALGORITHM_H
// -------------------- OpenMesh
#include "meshtype.h"

class HullAlgorithm
{
public:
    virtual TriMesh getResult() const=0;
    virtual ~HullAlgorithm(){}
};

#endif //HULLALGORITHM_H
