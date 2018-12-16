#include "mainwindow.h"
#include <ui_mainwindow.h>
#include "cameracontrolshelp.h"

#include <iostream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->mygl->setFocus();

    // connects MyGL to lists
    connect(ui->mygl, SIGNAL(send_edges(QVector<HalfEdge*>)), this, SLOT(slot_add_edges(QVector<HalfEdge*>)));
    connect(ui->mygl, SIGNAL(send_verts(QVector<Vertex*>)), this, SLOT(slot_add_verts(QVector<Vertex*>)));
    connect(ui->mygl, SIGNAL(send_faces(QVector<Face*>)), this, SLOT(slot_add_faces(QVector<Face*>)));

    // connects lists to MyGL
    connect(ui->edgeList, SIGNAL(itemClicked(QListWidgetItem*)), ui->mygl, SLOT(slot_get_selected_list_item(QListWidgetItem*)));
    connect(ui->faceList, SIGNAL(itemClicked(QListWidgetItem*)), ui->mygl, SLOT(slot_get_selected_list_item(QListWidgetItem*)));
    connect(ui->vertexList, SIGNAL(itemClicked(QListWidgetItem*)), ui->mygl, SLOT(slot_get_selected_list_item(QListWidgetItem*)));

    // connects spin boxes to MyGL
    connect(ui->redSpin, SIGNAL(valueChanged(double)), ui->mygl, SLOT(slot_update_face_r_col(double)));
    connect(ui->greenSpin, SIGNAL(valueChanged(double)), ui->mygl, SLOT(slot_update_face_g_col(double)));
    connect(ui->blueSpin, SIGNAL(valueChanged(double)), ui->mygl, SLOT(slot_update_face_b_col(double)));

    connect(ui->xSpin, SIGNAL(valueChanged(double)), ui->mygl, SLOT(slot_update_vert_x_pos(double)));
    connect(ui->ySpin, SIGNAL(valueChanged(double)), ui->mygl, SLOT(slot_update_vert_y_pos(double)));
    connect(ui->zSpin, SIGNAL(valueChanged(double)), ui->mygl, SLOT(slot_update_vert_z_pos(double)));

    // connects MyGL to spin boxes
    connect(ui->mygl, SIGNAL(send_vert_x_pos(double)), ui->xSpin, SLOT(setValue(double)));
    connect(ui->mygl, SIGNAL(send_vert_y_pos(double)), ui->ySpin, SLOT(setValue(double)));
    connect(ui->mygl, SIGNAL(send_vert_z_pos(double)), ui->zSpin, SLOT(setValue(double)));

    connect(ui->mygl, SIGNAL(send_face_r_col(double)), ui->redSpin, SLOT(setValue(double)));
    connect(ui->mygl, SIGNAL(send_face_g_col(double)), ui->greenSpin, SLOT(setValue(double)));
    connect(ui->mygl, SIGNAL(send_face_b_col(double)), ui->blueSpin, SLOT(setValue(double)));

    // connects buttons to MyGL
    connect(ui->midButton, SIGNAL(clicked(bool)), ui->mygl, SLOT(slot_add_midpoint()));
    connect(ui->triButton, SIGNAL(clicked(bool)), ui->mygl, SLOT(slot_triangulate_face()));
    connect(ui->extrButton, SIGNAL(clicked(bool)), ui->mygl, SLOT(slot_extrude_face()));
    connect(ui->subdivButton, SIGNAL(clicked(bool)), ui->mygl, SLOT(slot_subdivide_poly()));

    // allows MyGL to clear widget lists
    connect(ui->mygl, SIGNAL(clear_lists()), this, SLOT(slot_clear_lists()));

    // button to import meshes
    connect(ui->importButton, SIGNAL(clicked(bool)), ui->mygl, SLOT(slot_import_mesh()));

    // button to import skeletons
    connect(ui->importSkeletonButton, SIGNAL(clicked(bool)), ui->mygl, SLOT(slot_import_skeleton()));

    // allows MyGL to update tree widget
    connect(ui->mygl, SIGNAL(send_root_joint(Joint*)), this, SLOT(slot_add_root_joint(Joint*)));
    connect(ui->mygl, SIGNAL(clear_joint_tree()), this, SLOT(slot_clear_joint_tree()));

    // connects tree to MyGL (w.r.t. when an item is pressed)
    connect(ui->jointTree, SIGNAL(itemPressed(QTreeWidgetItem*,int)), ui->mygl, SLOT(slot_get_selected_joint(QTreeWidgetItem*)));

    // connects additive/subtractive buttons to MyGL
    connect(ui->plusX, SIGNAL(clicked(bool)), ui->mygl, SLOT(slot_add_rotate_joint_x()));
    connect(ui->minusX, SIGNAL(clicked(bool)), ui->mygl, SLOT(slot_sub_rotate_joint_x()));
    connect(ui->plusY, SIGNAL(clicked(bool)), ui->mygl, SLOT(slot_add_rotate_joint_y()));
    connect(ui->minusY, SIGNAL(clicked(bool)), ui->mygl, SLOT(slot_sub_rotate_joint_y()));
    connect(ui->plusZ, SIGNAL(clicked(bool)), ui->mygl, SLOT(slot_add_rotate_joint_z()));
    connect(ui->minusZ, SIGNAL(clicked(bool)), ui->mygl, SLOT(slot_sub_rotate_joint_z()));

    // connects translate slots to MyGL
    connect(ui->jointXTranslate, SIGNAL(valueChanged(double)), ui->mygl, SLOT(slot_update_joint_x(double)));
    connect(ui->jointYTranslate, SIGNAL(valueChanged(double)), ui->mygl, SLOT(slot_update_joint_y(double)));
    connect(ui->jointZTranslate, SIGNAL(valueChanged(double)), ui->mygl, SLOT(slot_update_joint_z(double)));

    connect(ui->mygl, SIGNAL(send_joint_x(double)), ui->jointXTranslate, SLOT(setValue(double)));
    connect(ui->mygl, SIGNAL(send_joint_y(double)), ui->jointYTranslate, SLOT(setValue(double)));
    connect(ui->mygl, SIGNAL(send_joint_z(double)), ui->jointZTranslate, SLOT(setValue(double)));

    connect(ui->mygl, SIGNAL(send_joint_info(Joint*)), this, SLOT(slot_add_joint_info(Joint*)));
    connect(ui->mygl, SIGNAL(clear_joint_info()), this, SLOT(slot_clear_joint_info()));

    connect(ui->skinButton, SIGNAL(clicked(bool)), ui->mygl, SLOT(slot_simple_skin_mesh()));
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_actionQuit_triggered() {
    QApplication::exit();
}

void MainWindow::on_actionCamera_Controls_triggered() {
    CameraControlsHelp* c = new CameraControlsHelp();
    c->show();
}

void MainWindow::slot_add_edges(QVector<HalfEdge*> edges) {
    for (HalfEdge *e : edges) {
        ui->edgeList->addItem(e);
    }
}

void MainWindow::slot_add_faces(QVector<Face*> faces) {
    for (Face *f : faces) {
        ui->faceList->addItem(f);
    }
}

void MainWindow::slot_add_verts(QVector<Vertex*> verts) {
    for (Vertex *v : verts) {
        ui->vertexList->addItem(v);
    }
}

void MainWindow::slot_add_root_joint(Joint *root) {
    ui->jointTree->addTopLevelItem(root);
}

void MainWindow::slot_add_joint_info(Joint *joint) {
    glm::vec3 pos = joint->get_pos();
    glm::vec4 ori = joint->get_ori();

    QString joint_info = QString("POSITION w.r.t. World:\n");
    joint_info += QString("    x: %1\n").arg(pos.x);
    joint_info += QString("    y: %1\n").arg(pos.y);
    joint_info += QString("    z: %1\n").arg(pos.z);

    joint_info += QString("ORIENTATION:\n");
    joint_info += QString("  axis of rotation, v  \n");
    joint_info += QString("    vx: %1  \n").arg(ori[1]);
    joint_info += QString("    vy: %1  \n").arg(ori[2]);
    joint_info += QString("    vz: %1  \n").arg(ori[3]);
    joint_info += QString("  deg. about axis of rot.  \n");
    joint_info += QString("    deg: %1  \n").arg(glm::degrees(ori[0]));

    joint_info += QString("JOINT ID:\n");
    joint_info += QString("    ID: %1  \n").arg(joint->get_id());

    ui->jointInfo->setText(joint_info);
}

void MainWindow::slot_clear_joint_info() {
    ui->jointInfo->clear();
}

// clears the lists in the widget WITHOUT deleting items
void MainWindow::slot_clear_lists() {
    while (ui->edgeList->count() > 0) {
      ui->edgeList->takeItem(0);
    }

    while (ui->vertexList->count() > 0) {
        ui->vertexList->takeItem(0);
    }

    while (ui->faceList->count() > 0) {
        ui->faceList->takeItem(0);
    }
}

void MainWindow::slot_clear_joint_tree() {
    ui->jointTree->takeTopLevelItem(0);
}
