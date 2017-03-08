// -------------------- C++
#include <array>
#include <iostream>
#include "Incremental.h"
//#include "MeshProcessing\MeshProcessing.h"
//#include <sMyng>

//sing namespace Symbyo::CG;

TriMesh Incremental::calculateConvHull(const TriMesh& mesh)
{
    TriMesh hull;

    int i = 0;
    int sim = 2;

    //std::vector<TriMesh::FaceHandle> visible_face_handles;

    hull.request_vertex_status();
    hull.request_face_status();
    hull.request_edge_status();

    for (const auto& vh : mesh.vertices())
    {
        int vis_face_count = 0;
        //initial face
        if(i < 3)
        {
            hull.add_vertex(mesh.point(vh));
            i++;
        }
        //incrementing HULL
        else
        {
            if(i == 3)
            {
                hull.add_vertex(mesh.point(vh));
                if(!OpenMesh::is_zero(OpenMesh::dot(hull.point(OpenMesh::VertexHandle(0)),
                OpenMesh::cross(hull.point(OpenMesh::VertexHandle(1)), hull.point(OpenMesh::VertexHandle(sim))))))
                hull.add_face(OpenMesh::VertexHandle(0), OpenMesh::VertexHandle(1), OpenMesh::VertexHandle(sim));
                else
                {
                    sim++;
                    continue;
                }
                i++;
            }

            std::array<OpenMesh::Vec3f, 3> vecs;
            std::vector<TriMesh::FaceHandle> visible_face_handles;

            for(const auto& fh : hull.faces())
            {
                //calculating volume and set it in vol
                int j = 0;
                for(const auto& fvh : hull.fv_range(fh))
                {
                    vecs[j++] = hull.point(fvh) - mesh.point(vh);
                }

                if (OpenMesh::is_gt(OpenMesh::dot(vecs[0], OpenMesh::cross(vecs[1], vecs[2])), 0.0f))
                {
                    visible_face_handles.push_back(fh);
                    vis_face_count++;
                }
            }

            for (const auto&fh : visible_face_handles)
            {
                if (hull.n_faces() > 1)
                {
                    hull.delete_face(fh, false);
                }
            }


            if (vis_face_count > 0)
            {
                //add the point to hull and form cone faces and delete previously visible faces
                auto hull_v = hull.add_vertex(mesh.point(vh));

                int z = 0;
                for(auto he : hull.halfedges())
                {
                    if(hull.is_boundary(he))
                    {
                        auto vh0 = hull.from_vertex_handle(he);
                        auto vh1 = hull.to_vertex_handle(he);
                        //auto fh = hull.add_face(hull_v, vh1, vh0); //to be completed

                        if(!OpenMesh::is_zero(OpenMesh::dot(hull.point(hull_v),
                        OpenMesh::cross(hull.point(vh0), hull.point(vh1)))))
                        hull.add_face(hull_v, vh1, vh0);


                        //MeshProcessing::writeMesh(hull, "D:/test"+ std::to_sMyng(z) +".ply");
                        //if(!fh)
                        //{
                        //    hull.add_face(hull_v, vh0, vh1);
                        //}
                    }
                    z++;
                }
            }
            //vh ----> the point : judge if it's in the hull
            //looping over face handles of hull
            //calculate volume of tetrahedron formed by the point of vh and the face
            //if the volume is +ve --> mark the face visible ##delete it from hull
            //at the end of loop if no faces are visible then the point inside the hull

            //if not in hull add the point to hull and form cone faces
        }
    }

    hull.garbage_collection();

    hull.release_face_status();
    hull.release_vertex_status();
    hull.release_edge_status();

    return hull;
}
