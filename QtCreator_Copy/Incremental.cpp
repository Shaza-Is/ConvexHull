// -------------------- C++ 
#include <array>
#include <iostream>
#include "Incremental.h"
//#include "MeshProcessing\MeshProcessing.h"


Incremental::Incremental( const TriMesh& _mesh )
    :mInputMesh(_mesh)
{
	incremental();
}

TriMesh Incremental::getResult() const
{
    return mHullMesh;
}

Incremental::~Incremental()
{

}

void Incremental::createInitialTetrahedron()
{
	// create the initial hull (the processed point will be marked as tagged)

    for (const auto& vh : mInputMesh.fv_range(OpenMesh::FaceHandle(0)))
	{
        mInputMesh.status(vh).set_tagged(true);
		mHullMesh.add_vertex(mInputMesh.point(vh));
	}

    auto normal = mInputMesh.calc_face_normal(OpenMesh::FaceHandle(0));
    auto d = -OpenMesh::dot(normal, mHullMesh.point(OpenMesh::VertexHandle(0)));

    OpenMesh::VertexHandle maxVh;
	auto maxDistance = 0.0f;

	for (const auto& vh : mInputMesh.vertices())
	{
		auto distance = std::fabs(OpenMesh::dot(normal, mInputMesh.point(vh)) + d); 
        if (distance > maxDistance)
		{
			maxDistance = distance;
			maxVh = vh;
        }
	}


	mInputMesh.status(maxVh).set_tagged(true);
	mHullMesh.add_vertex(mInputMesh.point(maxVh));

	// triangulate the hull
    mHullMesh.add_face(OpenMesh::VertexHandle(0), OpenMesh::VertexHandle(1), OpenMesh::VertexHandle(2));
    mHullMesh.add_face(OpenMesh::VertexHandle(3), OpenMesh::VertexHandle(0), OpenMesh::VertexHandle(2));
    mHullMesh.add_face(OpenMesh::VertexHandle(2), OpenMesh::VertexHandle(1), OpenMesh::VertexHandle(3));
    mHullMesh.add_face(OpenMesh::VertexHandle(3), OpenMesh::VertexHandle(1), OpenMesh::VertexHandle(0));
}

void Incremental::incremental()
{
	mInputMesh.request_vertex_status();

	createInitialTetrahedron();

	mHullMesh.request_vertex_status();
	mHullMesh.request_face_status();
	mHullMesh.request_edge_status();

	// get a point that doesn't lie on the same plane as the face
	for (const auto& vh : mInputMesh.vertices())
	{
        std::vector<OpenMesh::FaceHandle> visibleFaces;
        visibleFaces.clear();
		if (!mInputMesh.status(vh).tagged())
		{
			mInputMesh.status(vh).set_tagged(true);

			for(const auto& fh : mHullMesh.faces())
			{
				//calculating volume
				std::array<OpenMesh::Vec3f, 3> tetrahedronEdges;
				int j = 0;
				auto point = mInputMesh.point(vh);

				//for(auto itr = hull.fv_ccwbegin(fh); itr != hull.fv_ccwend(fh); ++itr) 
				for (const auto& fvh : mHullMesh.fv_range(fh))
					tetrahedronEdges[j++] = mHullMesh.point(fvh) - point;

                // check if the tetrahedron volume is +ve to make sure it is outside the hull mesh
                if (OpenMesh::dot(tetrahedronEdges[2], OpenMesh::cross(tetrahedronEdges[1], tetrahedronEdges[0])) > (std::numeric_limits<float>::epsilon()))
					visibleFaces.push_back(fh);
			}
            //OpenMesh::IO::write_mesh(mHullMesh, "/home/shaza/Desktop/before_del.ply");


			for (const auto&fh : visibleFaces)
                mHullMesh.delete_face(fh, true);
            mHullMesh.garbage_collection();


			if (!visibleFaces.empty())
			{
				//add the point to hull and form cone faces and delete previously visible faces
				auto hullVh = mHullMesh.add_vertex(mInputMesh.point(vh));

				for(auto heh : mHullMesh.halfedges())
				{
					if(mHullMesh.is_boundary(heh))
					{
						auto fromVh = mHullMesh.from_vertex_handle(heh);
						auto toVh = mHullMesh.to_vertex_handle(heh);
                        //mHullMesh.add_face(fromVh, toVh, hullVh);
                        if(!mHullMesh.add_face(fromVh, toVh, hullVh).is_valid())
                        {
                            //OpenMesh::IO::write_mesh(mHullMesh, "/home/shaza/Desktop/adding_problem.ply");

                            std::cout << "beta3" << std::endl;
                            break;

                        }
					}
				}
			}
			//		MeshProcessing::writeMesh(hull, "D:/test.ply");
		}
	}

	mInputMesh.release_vertex_status();

	mHullMesh.release_face_status();
	mHullMesh.release_vertex_status();
	mHullMesh.release_edge_status();

    //flipHullMesh();
}

void Incremental::flipHullMesh()
{
	TriMesh flippedHull;

	for (const auto& vh : mHullMesh.vertices())
		flippedHull.add_vertex(mHullMesh.point(vh));

    std::array<OpenMesh::VertexHandle, 3> flippedFaceVhs;
	for (const auto& fh : mHullMesh.faces())
	{
		int i = 0;
		for (const auto& fvh : mHullMesh.fv_range(fh))
			flippedFaceVhs[i++] = fvh;

		flippedHull.add_face(flippedFaceVhs[2], flippedFaceVhs[1], flippedFaceVhs[0]);
	}

	mHullMesh = flippedHull;
}
