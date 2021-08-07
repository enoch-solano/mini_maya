#ifndef JOINT_H
#define JOINT_H

#include "drawable.h"
#include "la.h"

#include <iostream>
#include <algorithm>
#include <vector>

#include <QTreeWidgetItem>

class Joint : public QTreeWidgetItem, public Drawable {
protected:
    static int joint_count;

    QString m_name;
    Joint *mp_parent;
    std::vector<Joint*> m_children;

    glm::vec3 m_pos;    // position relative to parent
    glm::quat m_ori;    // joint's current orientation
    glm::mat4 m_bind_mat;   // converts world->local

    int m_id;

    bool m_is_selected = false;
    bool m_is_skinning = false;

public:
    Joint(GLWidget277 *context, Joint *parent, glm::vec3 pos, glm::quat ori, QString name);

    ~Joint();

    //////////////////////// SETTERS ////////////////////////
    void toggle_is_selected();

    void set_parent(Joint *parent);
    void add_child(Joint *child);

    void rotate_x(float amt);
    void rotate_y(float amt);
    void rotate_z(float amt);

    void translate_x(float x);
    void translate_y(float y);
    void translate_z(float z);

    void set_is_skinning(bool is_skinning);

    //////////////////////// GETTERS ////////////////////////
    std::vector<Joint*> get_children();

    // gets position relative to parent
    glm::vec3 get_rel_pos();
    // gets position in world frame
    glm::vec3 get_pos();

    glm::vec4 get_ori();
    glm::mat4 get_bind_mat();

    bool is_skinning();

    int get_id();
    QString get_name();


    // represents the concatenation of a joint's position and
    // rotation, which are in parents' coordinate frame
    // (i.e. converts local coordinates -> parents' coordinates)
    glm::mat4 get_local_transformation();

    // represents the concatentation of this joint's local transformation
    // with the transformations of its chain of parent joints
    // (i.e. converts local -> world)
    glm::mat4 get_overall_transformation();

    static void reset_count();

    void create() override;
    GLenum drawMode() override;
};

#endif // JOINT_H
