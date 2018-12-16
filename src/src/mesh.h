#ifndef MESH_H
#define MESH_H

#include <vector>

#include "drawable.h"
#include "components.h"

class Mesh : public Drawable {
public:
    int IDX_COUNT;
    const float extrusion_length = 1.0;

    std::vector<Face *> m_faces;
    std::vector<Vertex *> m_verts;
    std::vector<HalfEdge *> m_edges;

    bool m_is_skinned;

protected:
    Vertex *get_centroid(Face *f);
    void smooth_split(HalfEdge *he1, QMap<Face*, Vertex*> face_centroids);
    void smooth_vert(Vertex *vert, QMap<Face*, Vertex*> face_centroids);
    void quadrangulate(Face *f, QMap<Face*, Vertex*> face_centroids);

    glm::vec4 get_nor(std::vector<glm::vec4> vert_pos, int i);
    glm::vec4 get_nor(std::vector<glm::vec4> vert_pos, int i, int offset);

public:
    Mesh(GLWidget277 *context);

    ~Mesh();

    void set_up_cube();
    void create() override;

    void split(HalfEdge *he1);
    void triangulate(Face *face_1);
    Face *generate_face(std::vector<int> vert_idx);

    void extrude(Face *face);
    void subdivide();

    void clean_up_mesh();

    static void set_sym_edges(Face *f1, Face *f2, Vertex *v1, Vertex *v2);

    // toggles if mesh is skinned or not
    void set_is_skinned(bool is_skinned);
    bool is_skinned();
};

#endif // MESH_H
