// -------------------- C++ 
#include <iostream>
#include "Incremental.h"

MyMesh* Incremental::calculateConvHull(MyMesh* mesh)
{
	MyMesh* hull;
	int i = 0;
	float vol = 0;
	std::vector<MyMesh::FaceHandle> visible_face_handles;
	for (MyMesh::VertexHandle vh : mesh.vertices())
	{
	    //initial face
	    if(i < 3)
	    {
	        hull.add_vertex(mesh.point(vh))
	        i++;
	    }
	    else if(i == 3)
	    {
	        vhh = hull.vertices();
	        //    VertexVertexCCWIter vvccwit = hull.vv_ccwiter(vhh);
	        hull.add_face(vhh[0], vhh[1], vhh[2]);
	        i++;
	    }
	    //incrementing HULL
	    else
	    {
	    	
	    	visible_face_handles.clear();
	    	for(MyMesh::FaceHandle facehandle : hull.faces())
	    	{	    		
	    		//calculating volume and set it in vol
	    		MyMesh::FaceVertexIter fv_it = hull.fv_iter(facehandle)

				for(; fv_it.is_valid(); ++fv_it) {
					auto vec = *fv_it - mesh.point(vh);
					float ax = vec[0];
					float ay = vec[1];
					float az = vec[2];
				} 

	    	}
	    //vh ----> the point : judge if it's in the hull
	    	//looping over face handles of hull 
	    	//calculate volume of tetrahedron formed by the point of vh and the face
	    	//if the volume is +ve --> mark the face visible
	    	//at the end of loop if no faces are visible then the point inside the hull

	    //if in hull skip

	    //else add the point to hull and form cone faces and delete previously visible faces
	    } 
	}

}