#include "drawablecomponents.h"
#include <iostream>

using namespace std;

///////////////////////////////////////////////////////////
//////////////////// DRAWABLE VERTICES ////////////////////
///////////////////////////////////////////////////////////
DrawableVertex::DrawableVertex(GLWidget277 *context)
    : Drawable(context) {
    white_col = glm::vec4(1, 1, 1, 0);
    count = 1;  // tells OpenGL number of indices
}

void DrawableVertex::create() {
    glm::ivec2 ids(0, 0);
    glm::vec2 weights(-1.f, -1.f);

    std::vector<glm::ivec2> joint_ids (1, ids);
    std::vector<glm::vec2> joint_weights (1, weights);

    generateJointIDs();
    mp_context->glBindBuffer(GL_ARRAY_BUFFER, bufJointID);
    mp_context->glBufferData(GL_ARRAY_BUFFER, sizeof(glm::ivec2), joint_ids.data(), GL_STATIC_DRAW);

    generateJointWeights();
    mp_context->glBindBuffer(GL_ARRAY_BUFFER, bufJointWeight);
    mp_context->glBufferData(GL_ARRAY_BUFFER, sizeof(glm::vec2), joint_weights.data(), GL_STATIC_DRAW);

    generateIdx();
    mp_context->glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, bufIdx);
    mp_context->glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(GLuint), 0, GL_STATIC_DRAW);

    generatePos();
    mp_context->glBindBuffer(GL_ARRAY_BUFFER, bufPos);
    mp_context->glBufferData(GL_ARRAY_BUFFER, sizeof(glm::vec4), &m_v, GL_STATIC_DRAW);

    generateCol();
    mp_context->glBindBuffer(GL_ARRAY_BUFFER, bufCol);
    mp_context->glBufferData(GL_ARRAY_BUFFER, sizeof(glm::vec4), &white_col, GL_STATIC_DRAW);
}

void DrawableVertex::set_vert(Vertex *v) {
    m_v = v->get_pos4();

    if (v->is_skinned()) {
        m_joint_ids.clear();
        m_joint_weights.clear();

        m_joint_ids.push_back(v->get_joint_ids());
        m_joint_weights.push_back(v->get_weights());
    }
}

GLenum DrawableVertex::drawMode() {
    return GL_POINTS;
}

DrawableVertex::~DrawableVertex() {}

////////////////////////////////////////////////////////
//////////////////// DRAWABLE EDGES ////////////////////
////////////////////////////////////////////////////////
DrawableHalfEdge::DrawableHalfEdge(GLWidget277 *context)
    : Drawable(context) {
    count = 2;  // tells OpenGL number of indices

    m_idx.push_back(0);
    m_idx.push_back(1);

    m_vert_col.push_back(glm::vec4(1,0,0,0));   // one vertex is red
    m_vert_col.push_back(glm::vec4(1,1,0,0));   // other vertex is yellow
}

void DrawableHalfEdge::create() {
    std::vector<glm::vec4> vert_pos;
    vert_pos.push_back(m_v0);
    vert_pos.push_back(m_v1);

    generateJointIDs();
    mp_context->glBindBuffer(GL_ARRAY_BUFFER, bufJointID);
    mp_context->glBufferData(GL_ARRAY_BUFFER, m_joint_ids.size() * sizeof(glm::ivec2), m_joint_ids.data(), GL_STATIC_DRAW);

    generateJointWeights();
    mp_context->glBindBuffer(GL_ARRAY_BUFFER, bufJointWeight);
    mp_context->glBufferData(GL_ARRAY_BUFFER, m_joint_weights.size() * sizeof(glm::vec2), m_joint_weights.data(), GL_STATIC_DRAW);

    generateIdx();
    mp_context->glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, bufIdx);
    mp_context->glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(GLuint), m_idx.data(), GL_STATIC_DRAW);

    generatePos();
    mp_context->glBindBuffer(GL_ARRAY_BUFFER, bufPos);
    mp_context->glBufferData(GL_ARRAY_BUFFER, count * sizeof(glm::vec4), vert_pos.data(), GL_STATIC_DRAW);

    generateCol();
    mp_context->glBindBuffer(GL_ARRAY_BUFFER, bufCol);
    mp_context->glBufferData(GL_ARRAY_BUFFER, count * sizeof(glm::vec4), m_vert_col.data(), GL_STATIC_DRAW);
}

void DrawableHalfEdge::set_verts(HalfEdge *edge) {
    Vertex *v0 = edge->get_vert();
    Vertex *v1 = edge->get_sym()->get_vert();

    m_v0 = v0->get_pos4();
    m_v1 = v1->get_pos4();

    if (v0->is_skinned()) {
        m_joint_ids.clear();
        m_joint_weights.clear();

        m_joint_ids.push_back(v0->get_joint_ids());
        m_joint_ids.push_back(v1->get_joint_ids());

        m_joint_weights.push_back(v0->get_weights());
        m_joint_weights.push_back(v1->get_weights());
    }
}

GLenum DrawableHalfEdge::drawMode() {
    return GL_LINES;
}

DrawableHalfEdge::~DrawableHalfEdge() {}

////////////////////////////////////////////////////////
//////////////////// DRAWABLE FACES ////////////////////
////////////////////////////////////////////////////////
DrawableFace::DrawableFace(GLWidget277 *context)
    : Drawable(context) {}

void DrawableFace::create() {
    // obtains appropriate indices
    std::vector<GLuint> idx;
    idx.push_back(0);

    for (GLuint i = 1; i < m_vert_pos.size(); i++) {
        idx.push_back(i);
        idx.push_back(i);
    }

    idx.push_back(0);

    // creates appropriate color vector
    std::vector<glm::vec4> vert_col;

    for (int i = 0; i < m_vert_pos.size(); i++) {
        vert_col.push_back(glm::vec4(m_color, 0));
    }

    count = idx.size();

    generateJointIDs();
    mp_context->glBindBuffer(GL_ARRAY_BUFFER, bufJointID);
    mp_context->glBufferData(GL_ARRAY_BUFFER, m_joint_ids.size() * sizeof(glm::ivec2), m_joint_ids.data(), GL_STATIC_DRAW);

    generateJointWeights();
    mp_context->glBindBuffer(GL_ARRAY_BUFFER, bufJointWeight);
    mp_context->glBufferData(GL_ARRAY_BUFFER, m_joint_weights.size() * sizeof(glm::vec2), m_joint_weights.data(), GL_STATIC_DRAW);

    generateIdx();
    mp_context->glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, bufIdx);
    mp_context->glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(GLuint), idx.data(), GL_STATIC_DRAW);

    generatePos();
    mp_context->glBindBuffer(GL_ARRAY_BUFFER, bufPos);
    mp_context->glBufferData(GL_ARRAY_BUFFER, m_vert_pos.size() * sizeof(glm::vec4), m_vert_pos.data(), GL_STATIC_DRAW);

    generateCol();
    mp_context->glBindBuffer(GL_ARRAY_BUFFER, bufCol);
    mp_context->glBufferData(GL_ARRAY_BUFFER, vert_col.size() * sizeof(glm::vec4), vert_col.data(), GL_STATIC_DRAW);
}

void DrawableFace::set_verts(HalfEdge *edge, glm::vec3 color) {
    m_vert_pos.clear();

    HalfEdge *start = edge;

    m_vert_pos.push_back(start->get_vert()->get_pos4());

    if (start->get_vert()->is_skinned()) {
        m_joint_ids.clear();
        m_joint_weights.clear();

        m_joint_ids.push_back(start->get_vert()->get_joint_ids());
        m_joint_weights.push_back(start->get_vert()->get_weights());
    }

    for (HalfEdge *curr = start->get_next(); curr != start; curr = curr->get_next()) {
        m_vert_pos.push_back(curr->get_vert()->get_pos4());

        if (start->get_vert()->is_skinned()) {
            m_joint_ids.push_back(start->get_vert()->get_joint_ids());
            m_joint_weights.push_back(start->get_vert()->get_weights());
        }
    }

    m_color = glm::abs(glm::vec3(1) - color);
}

GLenum DrawableFace::drawMode() {
    return GL_LINES;
}

DrawableFace::~DrawableFace() {}
