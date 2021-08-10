#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "mesh.h"
#include <iostream>

namespace Ui {
class MainWindow;
}


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

bool m_isDisable = false;

private slots:
    void on_actionQuit_triggered();
    void on_actionCamera_Controls_triggered();
    void slot_show_joint_info();

    void slot_toggle_face_color_sliders(bool);

private:
    Ui::MainWindow *ui;

public slots:

    void slot_add_edges(QVector<HalfEdge*>);
    void slot_add_faces(QVector<Face*>);
    void slot_add_verts(QVector<Vertex*>);

    void slot_clear_lists();

    void slot_add_root_joint(Joint *root);
    void slot_clear_joint_tree();

    void slot_add_joint_info(Joint *joint);
    void slot_clear_joint_info();
};


#endif // MAINWINDOW_H
