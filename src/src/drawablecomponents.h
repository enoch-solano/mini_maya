#ifndef DRAWABLECOMPONENTS_H
#define DRAWABLECOMPONENTS_H

#include "drawable.h"
#include "components.h"
#include "la.h"

class DrawableHalfEdge : public Drawable {
    glm::vec4 m_v0;
    glm::vec4 m_v1;

    std::vector<GLuint> m_idx;
    std::vector<glm::vec4> m_vert_col;

    std::vector<glm::ivec2> m_joint_ids;
    std::vector<glm::vec2> m_joint_weights;

public:
    DrawableHalfEdge(GLWidget277 *context);
    ~DrawableHalfEdge();

    GLenum drawMode() override;
    void create() override;

    void set_verts(HalfEdge *edge);
};

class DrawableVertex : public Drawable {
    glm::vec4 m_v;
    glm::vec4 white_col;

    std::vector<glm::ivec2> m_joint_ids;
    std::vector<glm::vec2> m_joint_weights;

public:
    DrawableVertex(GLWidget277 *context);
    ~DrawableVertex();

    GLenum drawMode() override;
    void create() override;

    void set_vert(Vertex* v);
};

class DrawableFace : public Drawable {
    std::vector<glm::vec4> m_vert_pos;
    glm::vec3 m_color;

    std::vector<glm::ivec2> m_joint_ids;
    std::vector<glm::vec2> m_joint_weights;

public:
    DrawableFace(GLWidget277 *context);
    ~DrawableFace();

    GLenum drawMode() override;
    void create() override;

    void set_verts(HalfEdge *edge, glm::vec3 color);
};

#endif // DRAWABLECOMPONENTS_H
