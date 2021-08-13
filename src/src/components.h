#ifndef COMPONENTS_H
#define COMPONENTS_H

#include <glwidget277.h>
#include <la.h>

#include "joint.h"
#include <iostream>

#include <QString>
#include <QListWidgetItem>

class Component : public QListWidgetItem {};

class Face;
class Vertex;

class HalfEdge : public Component {
public:
    static unsigned int edge_count;

    HalfEdge *mp_next;
    HalfEdge *mp_sym;
    Face *mp_face;
    Vertex *mp_vert;

    int m_id;

public:
    HalfEdge(HalfEdge *next, HalfEdge *sym, Face *face, Vertex *vert);

    // GETTERs
    HalfEdge *get_next() const;
    HalfEdge *get_sym() const;
    Face *get_face() const;
    Vertex *get_vert() const;
    int get_id() const;

    // SETTERs
    void set_next(HalfEdge *next);
    void set_vert(Vertex *vert, bool edge_set);
    void set_sym(HalfEdge *sym, bool sym_set);
    void set_face(Face *face);

    static void reset_count();
};

class Face : public Component {
public:
    static unsigned int face_count;

    HalfEdge *mp_edge;
    glm::vec3 m_color;

    int m_id;

public:
    Face(HalfEdge *edge, glm::vec3 color);

    // GETTERs
    HalfEdge *get_edge() const;
    glm::vec3 get_color() const;
    int get_id() const;

    // SETTERs
    void set_edge(HalfEdge *next);
    void set_color(glm::vec3 color);

    static void reset_count();
};

class Vertex : public Component {
public:
    static unsigned int vert_count;

    HalfEdge *mp_edge;
    glm::vec3 m_pos;

    QPair<Joint*, Joint*> m_joints;
    glm::vec2 m_weights;
    bool m_is_skinned = false;

    int m_id;

public:
    Vertex(HalfEdge *edge, glm::vec3 pos);

    // GETTERs
    HalfEdge *get_edge() const;
    glm::vec4 get_pos4() const;
    glm::vec3 get_pos3() const;
    int get_id() const;

    glm::ivec2 get_joint_ids() const;
    glm::vec2 get_weights() const;
    bool is_skinned() const;

    // SETTERs
    void set_edge(HalfEdge *edge, bool vert_set);
    void set_pos(glm::vec4 pos);

    void set_joints(QPair<Joint*, Joint*> joints, QPair<float, float> weights);
    void set_is_skinned(bool is_skinned);

    void clear_joints();

    static void reset_count();
};

#endif // COMPONENTS_H
