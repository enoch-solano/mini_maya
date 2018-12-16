#ifndef MYGL_H
#define MYGL_H

#include <glwidget277.h>
#include <utils.h>
#include <shaderprogram.h>

#include <scene/cylinder.h>
#include <scene/sphere.h>

#include "camera.h"

#include <mesh.h>
#include "drawablecomponents.h"
#include "joint.h"

#include <QOpenGLVertexArrayObject>
#include <QOpenGLShaderProgram>

#include <la.h>

#include <iostream>
#include <QApplication>
#include <QKeyEvent>

#include <QFileDialog>
#include <QMessageBox>

#include <QMap>
#include <QPair>
#include <iterator>

#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

// enums to help determine the type of component selected on mainwindow
enum TypeSelected { EDGE, FACE, VERT, NONE };

class MyGL : public GLWidget277 {
    Q_OBJECT
    // don't forget to run qmake afterwards

private:
    Cylinder m_geomCylinder;        // The instance of a unit cylinder we can use to render any cylinder
    Sphere m_geomSphere;            // The instance of a unit sphere we can use to render any sphere
    ShaderProgram m_progLambert;    // A shader program that uses lambertian reflection
    ShaderProgram m_progFlat;       // A shader program that uses "flat" reflection (no shadowing at all)
    ShaderProgram m_progSkeleton;   // A shader program that transform vertices based on the joints that influence them

    ShaderProgram *mp_currMeshShader;   // shader to draw the mesh with
    ShaderProgram *mp_currCompShader;   // shader to draw the joints/components

    Mesh m_mesh;
    Joint *mp_root_joint;       // root of skeleton
    Joint *mp_selected_joint;   // currently selected joint

    float joint_amt = glm::radians(10.f);  // degrees rotated about axis (upon button click)

    TypeSelected m_type_selected;   // type of component selected
    Component *mp_selected_comp;    // pointer to selected component

    DrawableVertex m_selected_vert;     // drawable selected Vertex
    DrawableHalfEdge m_selected_edge;   // drawable selected Edge
    DrawableFace m_selected_face;       // drawable selected Face

    GLuint vao; // A handle for our vertex array object. This will store the VBOs created in our geometry classes.
                // Don't worry too much about this. Just know it is necessary in order to render geometry.

    Camera m_glCamera;

public:
    explicit MyGL(QWidget *parent = 0);
    ~MyGL();

    void initializeGL();
    void resizeGL(int w, int h);
    void paintGL();

protected:
    void keyPressEvent(QKeyEvent *e);
    void wheelEvent(QWheelEvent* e);

    void send_components();

    void set_default_shaders();
    void set_skeleton_shaders();

    // destroys drawables
    void destroy_drawable_comp();

    // updates drawables
    void update_mesh();
    void update_drawable_edge(HalfEdge *edge);
    void update_drawable_face(HalfEdge *edge, glm::vec3 color);
    void update_drawable_vert(Vertex *v);

    // generates a joint from JSON data
    Joint *generate_joint(Joint *parent, QJsonObject child);

    // generates children of joint from JSON file
    void generate_children(Joint *parent, QJsonArray j_children);

    void draw_skeleton(Joint *j);

    void get_joints(std::vector<Joint*> &joints, Joint *joint);
    void find_closest_joints(std::vector<Joint*> &joints, Vertex *v);

    void skin_mesh();

public slots:
    void slot_get_selected_list_item(QListWidgetItem *item);

    void slot_update_face_r_col(double r);
    void slot_update_face_g_col(double g);
    void slot_update_face_b_col(double b);

    void slot_update_vert_x_pos(double x);
    void slot_update_vert_y_pos(double y);
    void slot_update_vert_z_pos(double z);

    void slot_add_midpoint();
    void slot_triangulate_face();
    void slot_extrude_face();
    void slot_subdivide_poly();

    void slot_import_mesh();

    void slot_import_skeleton();
    void slot_get_selected_joint(QTreeWidgetItem *item);

    void slot_simple_skin_mesh();

    void slot_add_rotate_joint_x();
    void slot_sub_rotate_joint_x();
    void slot_add_rotate_joint_y();
    void slot_sub_rotate_joint_y();
    void slot_add_rotate_joint_z();
    void slot_sub_rotate_joint_z();

    void slot_update_joint_x(double);
    void slot_update_joint_y(double);
    void slot_update_joint_z(double);

signals:
    void send_edges(QVector<HalfEdge*>);
    void send_faces(QVector<Face*>);
    void send_verts(QVector<Vertex*>);

    void send_vert_x_pos(double);
    void send_vert_y_pos(double);
    void send_vert_z_pos(double);

    void send_face_r_col(double);
    void send_face_g_col(double);
    void send_face_b_col(double);

    void send_joint_x(double);
    void send_joint_y(double);
    void send_joint_z(double);

    void send_mesh(Mesh&);

    void send_root_joint(Joint*);
    void clear_joint_tree();

    void send_joint_info(Joint*);
    void clear_joint_info();

    void clear_lists();
};


#endif // MYGL_H
