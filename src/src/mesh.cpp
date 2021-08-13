#include "mesh.h"
#include <iostream>

Mesh::Mesh(GLWidget277 *context)
    : Drawable(context), m_is_skinned(false) {}

glm::vec4 Mesh::get_nor(std::vector<glm::vec4> vert_pos, int i, int offset) {
    int prev_idx = ((vert_pos.size() + i) - 1) % vert_pos.size();
    int next_idx = (i + 1 + offset) % vert_pos.size();

    glm::vec4 v1 = vert_pos[prev_idx];
    glm::vec4 v2 = vert_pos[i];
    glm::vec4 v3 = vert_pos[next_idx];

    glm::vec4 d1 = v3 - v2;
    glm::vec4 d2 = v1 - v2;

    glm::vec3 nor = glm::cross(glm::vec3(d1.x, d1.y, d1.z),
                               glm::vec3(d2.x, d2.y, d2.z));

    // gets the next vertex if the length of the norm is zero (i.e. parallel edges)
//    if (glm::length(nor) < 1e-6) {
//        return get_nor(vert_pos, i, offset + 1);
//    }

    nor = glm::normalize(nor);

    return glm::vec4(nor, 0.0);
}

glm::vec4 Mesh::get_nor(std::vector<glm::vec4> vert_pos, int i) {
    return get_nor(vert_pos, i, 0);
}

void Mesh::create() {
    std::vector<glm::vec4> vert_pos;
    std::vector<glm::vec4> vert_nor;
    std::vector<glm::vec4> vert_col;

    std::vector<glm::ivec2> joint_ids;
    std::vector<glm::vec2> joint_weights;

    std::vector<GLuint> idx;

    GLuint prev_num_vert = 0;

    // set up face-by-face
    for (Face *f : m_faces) {
        // container for curr face vertices
        std::vector<glm::vec4> face_vert_pos;

        // starting edge
        HalfEdge *start = f->get_edge();

        // traverse circumferernce of face to collection vertex pos
        face_vert_pos.push_back(start->get_vert()->get_pos4());
        vert_pos.push_back(start->get_vert()->get_pos4());

        if (this->is_skinned()) {
            joint_ids.push_back(start->get_vert()->get_joint_ids());
            joint_weights.push_back(start->get_vert()->get_weights());
        }

        // gives vertex color of face
        vert_col.push_back(glm::vec4(f->get_color(), 0));

        GLuint num_vert = 1;

        for (HalfEdge *curr = start->get_next(); curr != start; curr = curr->get_next()) {
            face_vert_pos.push_back(curr->get_vert()->get_pos4());
            vert_pos.push_back(curr->get_vert()->get_pos4());

            if (this->is_skinned()) {
                joint_ids.push_back(curr->get_vert()->get_joint_ids());
                joint_weights.push_back(curr->get_vert()->get_weights());
            }

            vert_col.push_back(glm::vec4(f->get_color(), 0));
            num_vert++;
        }

        // gets corresponding normal
        for (int i = 0; i < num_vert; i++) {
            vert_nor.push_back(get_nor(face_vert_pos, i));
        }

        // triangulates face polygon
        for (int i = 0; i < num_vert - 2; i++) {
            idx.push_back(prev_num_vert);
            idx.push_back(prev_num_vert + i + 1);
            idx.push_back(prev_num_vert + i + 2);
        }

        prev_num_vert += face_vert_pos.size();
    }

    // updates number of indices
    count = idx.size();

    // Create a VBO on GPU and store its handle in bufIdx
    generateIdx();
    // Tell OpenGL that we want to perform subsequent operations on the VBO referred to by bufIdx
    // and that it will be treated as an element array buffer (since it will contain triangle indices)
    mp_context->glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, bufIdx);
    // Pass the data stored in cyl_idx into the bound buffer, reading a number of bytes equal to
    // CYL_IDX_COUNT multiplied by the size of a GLuint. This data is sent to the GPU to be read by shader programs.
    mp_context->glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(GLuint), idx.data(), GL_STATIC_DRAW);

    generatePos();
    mp_context->glBindBuffer(GL_ARRAY_BUFFER, bufPos);
    mp_context->glBufferData(GL_ARRAY_BUFFER, vert_pos.size() * sizeof(glm::vec4), vert_pos.data(), GL_STATIC_DRAW);

    generateNor();
    mp_context->glBindBuffer(GL_ARRAY_BUFFER, bufNor);
    mp_context->glBufferData(GL_ARRAY_BUFFER, vert_nor.size() * sizeof(glm::vec4), vert_nor.data(), GL_STATIC_DRAW);

    generateCol();
    mp_context->glBindBuffer(GL_ARRAY_BUFFER, bufCol);
    mp_context->glBufferData(GL_ARRAY_BUFFER, vert_col.size() * sizeof(glm::vec4), vert_col.data(), GL_STATIC_DRAW);

    if (this->is_skinned()) {
        generateJointIDs();
        mp_context->glBindBuffer(GL_ARRAY_BUFFER, bufJointID);
        mp_context->glBufferData(GL_ARRAY_BUFFER, joint_ids.size() * sizeof(glm::ivec2), joint_ids.data(), GL_STATIC_DRAW);

        generateJointWeights();
        mp_context->glBindBuffer(GL_ARRAY_BUFFER, bufJointWeight);
        mp_context->glBufferData(GL_ARRAY_BUFFER, joint_weights.size() * sizeof(glm::vec2), joint_weights.data(), GL_STATIC_DRAW);
    }
}


void Mesh::split(HalfEdge *he1) {
    HalfEdge *he2 = he1->get_sym();
    Vertex *v1 = he1->get_vert();
    Vertex *v2 = he2->get_vert();

    glm::vec4 avg = v1->get_pos4() + v2->get_pos4();
    avg /= 2;

    Vertex *v3 = new Vertex(nullptr, glm::vec3(avg.x, avg.y, avg.z));

    HalfEdge *he1b = new HalfEdge(he1->get_next(), nullptr, he1->get_face(), he1->get_vert());
    HalfEdge *he2b = new HalfEdge(he2->get_next(), nullptr, he2->get_face(), he2->get_vert());

    he2->set_next(he2b);
    he2->set_vert(v3, false);
    he2->set_sym(he1b, false);

    he1->set_next(he1b);
    he1->set_vert(v3, false);
    he1->set_sym(he2b, false);

    // new edges points of original vertices
    v1->set_edge(he1b, false);
    v2->set_edge(he2b, false);

    // updates the mesh data
    m_edges.push_back(he1b);
    m_edges.push_back(he2b);
    m_verts.push_back(v3);
}

bool is_triangulated(Face *face) {
    HalfEdge *start = face->get_edge();
    int num_vert = 1;

    for (HalfEdge *curr = start->get_next(); curr != start; curr = curr->get_next()) {
        num_vert++;

        if (num_vert > 3) {
            return false;
        }
    }

    return true;
}

void Mesh::triangulate(Face *face_1) {
    while(!is_triangulated(face_1)) {
        HalfEdge *he_0 = face_1->get_edge();

        HalfEdge *he_a = new HalfEdge(nullptr, nullptr, nullptr, he_0->get_vert());
        HalfEdge *he_b = new HalfEdge(nullptr, nullptr, nullptr, he_0->get_next()->get_next()->get_vert());

        he_a->set_sym(he_b, false);

        Face *face_2 = new Face(he_a, face_1->get_color());
        he_a->set_face(face_2);
        he_0->get_next()->set_face(face_2);
        he_0->get_next()->get_next()->set_face(face_2);

        he_b->set_face(face_1);

        he_b->set_next(he_0->get_next()->get_next()->get_next());
        he_0->get_next()->get_next()->set_next(he_a);
        he_a->set_next(he_0->get_next());
        he_0->set_next(he_b);

        m_edges.push_back(he_a);
        m_edges.push_back(he_b);
        m_faces.push_back(face_2);
    }
}

// Generates and returns a face of the mesh given the vertex indices of the face
Face *Mesh::generate_face(std::vector<int> vert_idx) {
    // creates new face
    Face *face = new Face();
    m_faces.push_back(face);

    HalfEdge *first_edge = new HalfEdge(nullptr, nullptr, face, m_verts[vert_idx.back()]);
    HalfEdge *next = first_edge;

    for (int i = vert_idx.size() - 2; i >= 0; i--) {
        Vertex *vert =  m_verts[vert_idx[i]];
        HalfEdge *edge = new HalfEdge(next, nullptr, face, vert);

        m_edges.push_back(edge);

        vert->set_edge(edge, false);
        next = edge;
    }

    first_edge->set_next(next);
    m_edges.push_back(first_edge);
    face->set_edge(first_edge);

    return face;
}

void Mesh::extrude(Face *face) {
    if (face == nullptr) {
        return;
    }

    glm::vec3 offset;
    {
        // calculate normal
        glm::vec3 posvert1 = face->mp_edge->mp_vert->m_pos;
        glm::vec3 posvert2 = face->mp_edge->mp_next->mp_vert->m_pos;
        glm::vec3 posvert3 = face->mp_edge->mp_next->mp_next->mp_vert->m_pos;
        glm::vec3 normal = glm::cross(posvert2 - posvert1, posvert3 - posvert2);
        offset = float(0.5) * glm::normalize(normal);
    }

    std::vector<Vertex*> facevertex;
    std::vector<HalfEdge*> newhalfedge;
    HalfEdge *currentedge;
    currentedge = face->mp_edge;

    // first pass, set new vertex and update the link in this face
    std::map<std::pair<int, int>, HalfEdge*> halfedgemap;
    do
    {
        auto vertex = new Vertex(currentedge->mp_vert->m_pos + offset);

        facevertex.push_back(currentedge->mp_vert); // record old vertex
        currentedge->set_vert(vertex, false);
        newhalfedge.push_back(currentedge); // record halfedge loop
        m_verts.push_back(vertex);
        currentedge = currentedge->mp_next;
    }
    while(currentedge != face->mp_edge);

    // second pass, add new faces
    int len = newhalfedge.size();
    for(int i = 0; i < len; i ++)
    {
        currentedge = newhalfedge[i];

        HalfEdge *edge = currentedge->mp_sym;
        HalfEdge* newedge1 = new HalfEdge();
        HalfEdge* newedge2 = new HalfEdge();
        HalfEdge* newedge3 = new HalfEdge();
        HalfEdge* newedge4 = new HalfEdge();

        // set halfedge -> next
        newedge1->mp_next = newedge2;
        newedge2->mp_next = newedge3;
        newedge3->mp_next = newedge4;
        newedge4->mp_next = newedge1;

        // set halfedge -> vertex
        newedge1->set_vert(newhalfedge[(len + i - 1) % len]->mp_vert);
        newedge2->set_vert(edge->mp_vert);
        newedge3->set_vert(facevertex[i]);
        newedge4->set_vert(currentedge->mp_vert);

        // set halfedge -> sym
        newedge1->set_sym(currentedge);
        newedge3->set_sym(edge);
        {
            int index1 = newedge1->mp_vert->m_id;
            int index2 = newedge2->mp_vert->m_id;
            if(halfedgemap.find({index2, index1}) == halfedgemap.end())
            {
                halfedgemap[std::make_pair(index1, index2)] = newedge2;
            }
            else
            {
                halfedgemap[std::make_pair(index2, index1)]->set_sym(newedge2);
            }
        }
        {
            int index1 = newedge3->mp_vert->m_id;
            int index2 = newedge4->mp_vert->m_id;
            if(halfedgemap.find({index2, index1}) == halfedgemap.end())
            {
                halfedgemap[std::make_pair(index1, index2)] = newedge4;
            }
            else
            {
                halfedgemap[std::make_pair(index2, index1)]->set_sym(newedge4);
            }
        }

        // set face
        auto face = new Face();
        face->set_edge(newedge1);
        face->set_edge(newedge2);
        face->set_edge(newedge3);
        face->set_edge(newedge4);

        // put everything in the array
        m_faces.push_back(std::move(face));
        m_edges.push_back(std::move(newedge1));
        m_edges.push_back(std::move(newedge2));
        m_edges.push_back(std::move(newedge3));
        m_edges.push_back(std::move(newedge4));
        currentedge = currentedge->mp_next;
    }

}

Vertex *Mesh::get_centroid(Face *f) {
    HalfEdge *start = f->get_edge();
    glm::vec4 centroid = start->get_vert()->get_pos4();
    int num_vert = 1;

    for (HalfEdge *curr = start->get_next(); curr != start; curr = curr->get_next()) {
        centroid += curr->get_vert()->get_pos4();
        num_vert++;
    }

    centroid /= num_vert;
    return new Vertex(nullptr, glm::vec3(centroid.x, centroid.y, centroid.z));
}

void Mesh::smooth_split(HalfEdge *he1, QMap<Face*, Vertex*> face_centroids) {
    // this assumes the mesh is closed and bounded
    HalfEdge *he2 = he1->get_sym();
    Vertex *v1 = he1->get_vert();
    Vertex *v2 = he2->get_vert();

    Vertex *f1 = face_centroids.value(he1->get_face());
    Vertex *f2 = face_centroids.value(he2->get_face());

    // smooth midpoint position
    glm::vec4 mid = v1->get_pos4() + v2->get_pos4() + f1->get_pos4() + f2->get_pos4();
    mid /= 4;

    Vertex *e = new Vertex(nullptr, glm::vec3(mid.x, mid.y, mid.z));

    HalfEdge *he1b = new HalfEdge(he1->get_next(), nullptr, he1->get_face(), he1->get_vert());
    HalfEdge *he2b = new HalfEdge(he2->get_next(), nullptr, he2->get_face(), he2->get_vert());

    he2->set_next(he2b);
    he2->set_vert(e, false);
    he2->set_sym(he1b, false);

    he1->set_next(he1b);
    he1->set_vert(e, false);
    he1->set_sym(he2b, false);

    // new edges points of original vertices
    v1->set_edge(he1b, false);
    v2->set_edge(he2b, false);

    // updates the mesh data
    m_edges.push_back(he1b);
    m_edges.push_back(he2b);
    m_verts.push_back(e);
}

void Mesh::smooth_vert(Vertex *vert, QMap<Face*, Vertex*> face_centroids) {
    glm::vec4 v = vert->get_pos4();

    HalfEdge *start = vert->get_edge()->get_sym(); // first edge that points away from vert

    glm::vec4 e = start->get_vert()->get_pos4();
    glm::vec4 f = face_centroids.value(start->get_face())->get_pos4();

    float n = 1; // number of adjacent midpoints

    // iterates through adjacent vertices
    HalfEdge *curr = start->get_sym()->get_next();
    while (curr != start) {
        e += curr->get_vert()->get_pos4();
        f += face_centroids.value(curr->get_face())->get_pos4();
        n++;

        curr = curr->get_sym()->get_next();
    }

    glm::vec4 smooth_v = (n - 2) * v / n;
    smooth_v += e / (n * n);
    smooth_v += f / (n * n);

    vert->set_pos(smooth_v);
}

void Mesh::quadrangulate(Face *f, QMap<Face *, Vertex *> face_centroids) {
    // begins with edge that points to original vertex
    HalfEdge *start = f->get_edge()->get_next();

    HalfEdge *curr = start;
    HalfEdge *temp = curr->get_next()->get_next();

    Vertex *centroid = face_centroids.value(f);

    std::vector<HalfEdge*> to;      // stores edges that point to centroid
    std::vector<HalfEdge*> from;    // stores edges that point from centroid

    do {
        Face *face = new Face(curr, f->get_color());
        curr->set_face(face);
        HalfEdge *next = curr->get_next();
        next->set_face(face);

        m_faces.push_back(face);

        HalfEdge *b = new HalfEdge(curr, nullptr, face, curr->get_sym()->get_vert());
        from.push_back(b);

        HalfEdge *a = new HalfEdge(b, nullptr, face, centroid);
        to.push_back(a);

        next->set_next(a);
        centroid->set_edge(a, false);

        m_edges.push_back(a);
        m_edges.push_back(b);

        curr = temp;
        temp = curr->get_next()->get_next();
    } while (curr != start);

    // handles the sym of the new edges
    for (int i = 0; i < to.size(); i++) {
        to[i]->set_sym(from[(i + 1) % from.size()], false);
    }
}

// Performs Catmull-Clark Subdivsion on Mesh
void Mesh::subdivide() {
    // original number of verts, edges, faces
    int num_edges = m_edges.size();
    int num_verts = m_verts.size();
    int num_faces = m_faces.size();

    // creates face-to-centroid mapping
    QMap<Face*, Vertex*> face_centroids;

    for (Face *f : m_faces) {
        Vertex *centroid = get_centroid(f);
        m_verts.push_back(centroid);
        face_centroids.insert(f, centroid);
    }

    QSet<HalfEdge*> visited; // set to keep track of split edges

    // splits every edge (once)
    for (int i = 0; i < num_edges; i++) {
        if (!visited.contains(m_edges[i])) {
            // adds edge and sym so that we don't split edge twice
            visited.insert(m_edges[i]);
            visited.insert(m_edges[i]->get_sym());

            smooth_split(m_edges[i], face_centroids);
        }
    }

    // smoothens original vertices
    for (int i = 0; i < num_verts; i++) {
        smooth_vert(m_verts[i], face_centroids);
    }

    Face::reset_count();

    std::vector<Face *> orig_faces = m_faces;
    m_faces = std::vector<Face*>();

    // quadrangulates the original faces
    for (int i = 0; i < num_faces; i++) {
        quadrangulate(orig_faces[i], face_centroids);
    }

    // cleans up original faces
    for (Face *f : orig_faces) {
        delete f;
        f = nullptr;
    }

    orig_faces.clear();
}

// Given two faces, finds the commonly bounded edges and sets them to be sym-edges
void Mesh::set_sym_edges(Face *f1, Face *f2, Vertex *v1, Vertex *v2) {
    HalfEdge *e1 = f1->get_edge();

    while (e1->get_vert() != v2) {
        e1 = e1->get_next();
    }

    HalfEdge *e2 = f2->get_edge();

    while(e2->get_vert() != v1) {
        e2 = e2->get_next();
    }

    e1->set_sym(e2, false);
}

void Mesh::set_up_cube() {
    /************************ LEGEND ************************
     * SINGLE PREFIXES:
     *  t,b,r,l,f,e -- top, bottom, right, left, front, end
     *
     * COMBINED PREFIXES:
     *  rtf -- right-top-front
     *  le  -- left-end
     ********************************************************/

    /////////////////////////////////////////////////////////////////////////
    /////////////////////////////// TOP FACE ////////////////////////////////
    /////////////////////////////////////////////////////////////////////////

    Face *t_face = new Face(nullptr, glm::vec3(0,1,0));

    // top vertices
    Vertex *ltf_vert = new Vertex(nullptr, glm::vec3(-0.5, 0.5,  0.5));
    Vertex *rtf_vert = new Vertex(nullptr, glm::vec3( 0.5, 0.5,  0.5));
    Vertex *rte_vert = new Vertex(nullptr, glm::vec3( 0.5, 0.5, -0.5));
    Vertex *lte_vert = new Vertex(nullptr, glm::vec3(-0.5, 0.5, -0.5));

    // top edges (in clockwise order)
    HalfEdge *tf_edge_0 = new HalfEdge(nullptr, nullptr, t_face, rtf_vert);
    HalfEdge *lt_edge_0 = new HalfEdge(tf_edge_0, nullptr, t_face, ltf_vert);
    HalfEdge *te_edge_0 = new HalfEdge(lt_edge_0, nullptr, t_face, lte_vert);
    HalfEdge *rt_edge_0 = new HalfEdge(te_edge_0, nullptr, t_face, rte_vert);

    tf_edge_0->set_next(rt_edge_0);
    t_face->set_edge(tf_edge_0);

    ltf_vert->set_edge(lt_edge_0, false);
    rtf_vert->set_edge(tf_edge_0, false);
    rte_vert->set_edge(rt_edge_0, false);
    lte_vert->set_edge(te_edge_0, false);

    m_faces.push_back(t_face);

    m_verts.push_back(ltf_vert);
    m_verts.push_back(rtf_vert);
    m_verts.push_back(rte_vert);
    m_verts.push_back(lte_vert);

    m_edges.push_back(tf_edge_0);
    m_edges.push_back(lt_edge_0);
    m_edges.push_back(te_edge_0);
    m_edges.push_back(rt_edge_0);

    /////////////////////////////////////////////////////////////////////////
    ////////////////////////////// BOTTOM FACE //////////////////////////////
    /////////////////////////////////////////////////////////////////////////

    Face *b_face = new Face(nullptr, glm::vec3(0,1,0));

    // bottom vertices
    Vertex *lbf_vert = new Vertex(nullptr, glm::vec3(-0.5, -0.5,  0.5));
    Vertex *lbe_vert = new Vertex(nullptr, glm::vec3(-0.5, -0.5, -0.5));
    Vertex *rbe_vert = new Vertex(nullptr, glm::vec3( 0.5, -0.5, -0.5));
    Vertex *rbf_vert = new Vertex(nullptr, glm::vec3( 0.5, -0.5,  0.5));

    // bottom edges (in clockwise order)
    HalfEdge *bf_edge_1 = new HalfEdge(nullptr, nullptr, b_face, lbf_vert);
    HalfEdge *rb_edge_1 = new HalfEdge(bf_edge_1, nullptr, b_face, rbf_vert);
    HalfEdge *be_edge_1 = new HalfEdge(rb_edge_1, nullptr, b_face, rbe_vert);
    HalfEdge *lb_edge_1 = new HalfEdge(be_edge_1, nullptr, b_face, lbe_vert);

    bf_edge_1->set_next(lb_edge_1);
    b_face->set_edge(bf_edge_1);

    lbf_vert->set_edge(bf_edge_1, false);
    rbf_vert->set_edge(rb_edge_1, false);
    rbe_vert->set_edge(be_edge_1, false);
    lbe_vert->set_edge(lb_edge_1, false);

    m_faces.push_back(b_face);

    m_verts.push_back(lbf_vert);
    m_verts.push_back(rbf_vert);
    m_verts.push_back(rbe_vert);
    m_verts.push_back(lbe_vert);

    m_edges.push_back(bf_edge_1);
    m_edges.push_back(rb_edge_1);
    m_edges.push_back(be_edge_1);
    m_edges.push_back(lb_edge_1);

    /////////////////////////////////////////////////////////////////////////
    ////////////////////////////// FRONT FACE ///////////////////////////////
    /////////////////////////////////////////////////////////////////////////

    Face *f_face = new Face(nullptr, glm::vec3(0,0,1));

    HalfEdge *tf_edge_2 = new HalfEdge(nullptr, nullptr, f_face, ltf_vert);
    HalfEdge *rf_edge_2 = new HalfEdge(tf_edge_2, nullptr, f_face, rtf_vert);
    HalfEdge *bf_edge_2 = new HalfEdge(rf_edge_2, nullptr, f_face, rbf_vert);
    HalfEdge *lf_edge_2 = new HalfEdge(bf_edge_2, nullptr, f_face, lbf_vert);

    tf_edge_2->set_next(lf_edge_2);
    f_face->set_edge(tf_edge_2);

    ltf_vert->set_edge(tf_edge_2, false);
    lbf_vert->set_edge(lf_edge_2, false);
    rbf_vert->set_edge(bf_edge_2, false);
    rtf_vert->set_edge(rf_edge_2, false);

    tf_edge_2->set_sym(tf_edge_0, false);
    bf_edge_2->set_sym(bf_edge_1, false);

    m_faces.push_back(f_face);

    m_edges.push_back(tf_edge_2);
    m_edges.push_back(rf_edge_2);
    m_edges.push_back(bf_edge_2);
    m_edges.push_back(lf_edge_2);

    /////////////////////////////////////////////////////////////////////////
    ////////////////////////////// RIGHT FACE ///////////////////////////////
    /////////////////////////////////////////////////////////////////////////

    Face *r_face = new Face(nullptr, glm::vec3(1,0,0));

    HalfEdge *rt_edge_3 = new HalfEdge(nullptr, nullptr, r_face, rtf_vert);
    HalfEdge *re_edge_3 = new HalfEdge(rt_edge_3, nullptr, r_face, rte_vert);
    HalfEdge *rb_edge_3 = new HalfEdge(re_edge_3, nullptr, r_face, rbe_vert);
    HalfEdge *rf_edge_3 = new HalfEdge(rb_edge_3, nullptr, r_face, rbf_vert);

    rt_edge_3->set_next(rf_edge_3);
    r_face->set_edge(rt_edge_3);

    rtf_vert->set_edge(rt_edge_3, false);
    rte_vert->set_edge(re_edge_3, false);
    rbe_vert->set_edge(rb_edge_3, false);
    rbf_vert->set_edge(rf_edge_3, false);

    rt_edge_3->set_sym(rt_edge_0, false);
    rf_edge_3->set_sym(rf_edge_2, false);
    rb_edge_3->set_sym(rb_edge_1, false);

    m_faces.push_back(r_face);

    m_edges.push_back(rt_edge_3);
    m_edges.push_back(re_edge_3);
    m_edges.push_back(rb_edge_3);
    m_edges.push_back(rf_edge_3);

    ///////////////////////////////////////////////////////////////////////
    ////////////////////////////// END FACE ///////////////////////////////
    ///////////////////////////////////////////////////////////////////////

    Face *e_face = new Face(nullptr, glm::vec3(0,0,1));

    HalfEdge *te_edge_4 = new HalfEdge(nullptr, nullptr, e_face, rte_vert);
    HalfEdge *le_edge_4 = new HalfEdge(te_edge_4, nullptr, e_face, lte_vert);
    HalfEdge *be_edge_4 = new HalfEdge(le_edge_4, nullptr, e_face, lbe_vert);
    HalfEdge *re_edge_4 = new HalfEdge(be_edge_4, nullptr, e_face, rbe_vert);

    te_edge_4->set_next(re_edge_4);
    e_face->set_edge(te_edge_4);

    rte_vert->set_edge(te_edge_4, false);
    lte_vert->set_edge(le_edge_4, false);
    lbe_vert->set_edge(be_edge_4, false);
    rbe_vert->set_edge(re_edge_4, false);

    te_edge_4->set_sym(te_edge_0, false);
    be_edge_4->set_sym(be_edge_1, false);
    re_edge_4->set_sym(re_edge_3, false);

    m_faces.push_back(e_face);

    m_edges.push_back(te_edge_4);
    m_edges.push_back(le_edge_4);
    m_edges.push_back(be_edge_4);
    m_edges.push_back(re_edge_4);

    ////////////////////////////////////////////////////////////////////////
    ////////////////////////////// LEFT FACE ///////////////////////////////
    ////////////////////////////////////////////////////////////////////////

    Face *l_face = new Face(nullptr, glm::vec3(1,0,0));

    HalfEdge *lt_edge_5 = new HalfEdge(nullptr, nullptr, l_face, lte_vert);
    HalfEdge *lf_edge_5 = new HalfEdge(lt_edge_5, nullptr, l_face, ltf_vert);
    HalfEdge *lb_edge_5 = new HalfEdge(lf_edge_5, nullptr, l_face, lbf_vert);
    HalfEdge *le_edge_5 = new HalfEdge(lb_edge_5, nullptr, l_face, lbe_vert);

    lt_edge_5->set_next(le_edge_5);
    l_face->set_edge(lt_edge_5);

    lte_vert->set_edge(lt_edge_5, false);
    ltf_vert->set_edge(lf_edge_5, false);
    lbf_vert->set_edge(lb_edge_5, false);
    lbe_vert->set_edge(le_edge_5, false);

    lt_edge_5->set_sym(lt_edge_0, false);
    lf_edge_5->set_sym(lf_edge_2, false);
    lb_edge_5->set_sym(lb_edge_1, false);
    le_edge_5->set_sym(le_edge_4, false);

    m_faces.push_back(l_face);

    m_edges.push_back(lt_edge_5);
    m_edges.push_back(lf_edge_5);
    m_edges.push_back(lb_edge_5);
    m_edges.push_back(le_edge_5);
}

void Mesh::clean_up_mesh() {
    destroy();

    for (Face *f : m_faces) {
        delete f;
        f = nullptr;
    }

    for (HalfEdge *e : m_edges) {
        delete e;
        e = nullptr;
    }

    for (Vertex *v : m_verts) {
        delete v;
        v = nullptr;
    }

    m_faces.clear();
    m_verts.clear();
    m_edges.clear();

    Face::reset_count();
    HalfEdge::reset_count();
    Vertex::reset_count();

    m_is_skinned = false;
}

Mesh::~Mesh() {
    this->clean_up_mesh();
}

/////////////////////////////////////////////////////////////////////////////////////////

void Mesh::set_is_skinned(bool is_skinned) {
    m_is_skinned = is_skinned;

    for (Vertex *v : m_verts) {
        v->set_is_skinned(is_skinned);
    }
}

bool Mesh::is_skinned() {
    return m_is_skinned;
}
