#include "components.h"

// initializes static variables
unsigned int HalfEdge::edge_count = 0;
unsigned int Face::face_count = 0;
unsigned int Vertex::vert_count = 0;

void HalfEdge::reset_count() {
    edge_count = 0;
}

void Face::reset_count() {
    face_count = 0;
}

void Vertex::reset_count() {
    vert_count = 0;
}

/********************************/
/******** HALFEDGE CLASS ********/
/********************************/
HalfEdge::HalfEdge(HalfEdge *next, HalfEdge *sym, Face *face, Vertex *vert)
    : mp_next(next), mp_sym(sym), mp_face(face),
      mp_vert(vert), m_id(edge_count)
{
    edge_count++;
    setText("edge_" + QString::number(m_id));
}

HalfEdge::HalfEdge() : HalfEdge(nullptr, nullptr, nullptr, nullptr) {}

// GETTERs
HalfEdge *HalfEdge::get_next() const {
    return mp_next;
}

HalfEdge *HalfEdge::get_sym() const {
    return mp_sym;
}

Face *HalfEdge::get_face() const {
    return mp_face;
}

Vertex *HalfEdge::get_vert() const {
    return mp_vert;
}

int HalfEdge::get_id() const {
    return m_id;
}

// SETTERs
void HalfEdge::set_next(HalfEdge *next) {
    mp_next = next;
}

void HalfEdge::set_vert(Vertex *vert, bool edge_set) {
    mp_vert = vert;

    // updates edge of reciprocal vert if it's not up-to-date
    if (!edge_set) {
        vert->set_edge(this, true);
    }
}
void HalfEdge::set_sym(HalfEdge *sym, bool sym_set) {
    mp_sym = sym;

    // updates sym of reciprocal edge if it's not up-to-date
    if (!sym_set) {
        sym->set_sym(this, true);
    }
}

void HalfEdge::set_face(Face *face) {
    mp_face = face;
}

/************************************/
/************ FACE CLASS ************/
/************************************/
Face::Face(HalfEdge *edge, glm::vec3 color)
    : mp_edge(edge), m_color(color), m_id(face_count)
{
    face_count++;
    setText("face_" + QString::number(m_id));
}

Face::Face()
    : Face(nullptr,
           glm::vec3((float) std::rand() / (RAND_MAX),
                     (float) std::rand() / (RAND_MAX),
                     (float) std::rand() / (RAND_MAX))) {}

// GETTERs
HalfEdge *Face::get_edge() const {
    return mp_edge;
}

glm::vec3 Face::get_color() const {
    return m_color;
}

int Face::get_id() const {
    return m_id;
}

// SETTERs
void Face::set_edge(HalfEdge *edge) {
    mp_edge = edge;
    edge->set_face(this);
}

void Face::set_color(glm::vec3 color) {
    m_color = color;
}

/**************************************/
/************ VERTEX CLASS ************/
/**************************************/
Vertex::Vertex(HalfEdge *edge, glm::vec3 pos)
    : mp_edge(edge), m_pos(pos), m_id(vert_count),
      m_joints(qMakePair(nullptr, nullptr)),
      m_weights(glm::vec2(HUGE_VALF))
{
    vert_count++;
    setText("vertex_" + QString::number(m_id));
}

Vertex::Vertex(glm::vec3 pos) : Vertex(nullptr, pos) {}

// GETTERs
HalfEdge *Vertex::get_edge() const {
    return mp_edge;
}

// returns position in homogeneous coordinates
glm::vec4 Vertex::get_pos4() const {
    return glm::vec4(m_pos, 1.0);
}

glm::vec3 Vertex::get_pos3() const {
    return m_pos;
}

int Vertex::get_id() const {
    return m_id;
}

glm::ivec2 Vertex::get_joint_ids() const {
    int first_id = m_joints.first->get_id();
    int second_id = m_joints.second->get_id();

    return glm::ivec2(first_id, second_id);
}
glm::vec2 Vertex::get_weights() const {
    return m_weights;
}

bool Vertex::is_skinned() const {
    return m_is_skinned;
}

void Vertex::set_edge(HalfEdge *edge, bool vert_set) {
    mp_edge = edge;

    if (!vert_set) {
        edge->set_vert(this, true);
    }
}

void Vertex::set_pos(glm::vec4 pos) {
    m_pos.x = pos.x;
    m_pos.y = pos.y;
    m_pos.z = pos.z;
}

void Vertex::set_joints(QPair<Joint*, Joint*> joints, QPair<float, float> weights) {
    m_joints.first = joints.first;
    m_joints.second = joints.second;

    float sum = weights.first + weights.second;
    m_weights[0] = 1 - (weights.first / sum);
    m_weights[1] = 1 - (weights.second / sum);
}

void Vertex::set_is_skinned(bool is_skinned) {
    m_is_skinned = is_skinned;
}

void Vertex::clear_joints() {
    m_joints = qMakePair(nullptr, nullptr);
    m_weights = glm::vec2(HUGE_VALF, HUGE_VALF);
}
