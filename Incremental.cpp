// -------------------- C++ 
#include <iostream>
#include "Incremental.h"

MyMesh* Incremental::calculateConvHull(MyMesh* mesh)
{
	int i = 0;
	for (auto vh : mesh.vertices())
	{
	    //initial tetrahedron
	    if(i < 4)
	    {
	        hull.add_vertex(mesh.point(vh))
	        i++;
	    }
	    else if(i == 4)
	    {
	        for(OpenMesh::VertexHandle vhh : hull.vertices())
	        {
	            VertexVertexCCWIter vvccwit = hull.vv_ccwiter(vhh);
	            hull.add_face(vhh, vvccwit[0], vvccwit[1]);
	        }
	        i++;
	    }
	    //incrementing HULL
	    else
	    {
	    //vh ----> the point : judge if it's in the hull

	    //if in hull skip

	    //else add to hull and form corresponding faces and delete previously visible
	    }
	}

}