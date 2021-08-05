#include "mygl.h"

MyGL::MyGL(QWidget *parent)
    : GLWidget277(parent),
      m_geomCylinder(this), m_geomSphere(this),
      m_progLambert(this), m_progFlat(this), m_progSkeleton(this),
      m_glCamera(), m_mesh(this), m_type_selected(NONE),
      mp_selected_comp(nullptr), m_selected_vert(this),
      m_selected_edge(this), m_selected_face(this), mp_root_joint(nullptr),
      mp_currMeshShader(nullptr), mp_currCompShader(nullptr)
{
    this->setFocusPolicy(Qt::StrongFocus);
}

MyGL::~MyGL() {
    makeCurrent();
    glDeleteVertexArrays(1, &vao);
    m_geomCylinder.destroy();
    m_geomSphere.destroy();

    delete mp_root_joint;

    m_mesh.~Mesh();
    this->destroy_drawable_comp();
}

void MyGL::initializeGL() {
    // Create an OpenGL context using Qt's QOpenGLFunctions_3_2_Core class
    // If you were programming in a non-Qt context you might use GLEW (GL Extension Wrangler)instead
    initializeOpenGLFunctions();
    // Print out some information about the current OpenGL context
    debugContextVersion();

    // Set a few settings/modes in OpenGL rendering
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LINE_SMOOTH);
    glEnable(GL_POLYGON_SMOOTH);
    glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);
    glHint(GL_POLYGON_SMOOTH_HINT, GL_NICEST);
    // Set the size with which points should be rendered
    glPointSize(5);
    // Set the color with which the screen is filled at the start of each render call.
    glClearColor(0.5, 0.5, 0.5, 1);

    printGLErrorLog();

    // Create a Vertex Attribute Object
    glGenVertexArrays(1, &vao);

    //Create the instances of Cylinder and Sphere.
    // m_geomCylinder.create();
    // m_geomSphere.create();

    m_mesh.set_up_cube();
    m_mesh.create();

    ///////////////////////////// COMPILES the SHADERS /////////////////////////////
    // Create and set up the diffuse shader
    m_progLambert.create(":/glsl/lambert.vert.glsl", ":/glsl/lambert.frag.glsl");
    // Create and set up the flat lighting shader
    m_progFlat.create(":/glsl/flat.vert.glsl", ":/glsl/flat.frag.glsl");
    // Create and set up the skeleton shader
    m_progSkeleton.create(":/glsl/skeleton.vert.glsl", ":/glsl/skeleton.frag.glsl");
    ////////////////////////////////////////////////////////////////////////////////

    this->set_default_shaders();

    // Set a color with which to draw geometry since you won't have one
    // defined until you implement the Node classes.
    // This makes your geometry render green.
    m_progLambert.setGeometryColor(glm::vec4(1,0,0,1));

    // We have to have a VAO bound in OpenGL 3.2 Core. But if we're not
    // using multiple VAOs, we can just bind one once.
    glBindVertexArray(vao);

    // sends edges, vertices, faces to mainwindow
    this->send_components();
}

void MyGL::resizeGL(int w, int h) {
    //This code sets the concatenated view and perspective projection matrices used for
    //our scene's camera view.
    m_glCamera = Camera(w, h);
    glm::mat4 viewproj = m_glCamera.getViewProj();

    // Upload the view-projection matrix to our shaders (i.e. onto the graphics card)

    m_progLambert.setViewProjMatrix(viewproj);
    m_progFlat.setViewProjMatrix(viewproj);
    m_progSkeleton.setViewProjMatrix(viewproj);

    printGLErrorLog();
}

//This function is called by Qt any time your GL window is supposed to update
//For example, when the function update() is called, paintGL is called implicitly.
void MyGL::paintGL() {
    this->setFocus();

    // Clear the screen so that we only see newly drawn images
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    m_progFlat.setViewProjMatrix(m_glCamera.getViewProj());
    m_progLambert.setViewProjMatrix(m_glCamera.getViewProj());
    m_progSkeleton.setViewProjMatrix(m_glCamera.getViewProj());

    if (m_mesh.is_skinned()) {
        std::vector<glm::mat4> bind_mats;
        std::vector<glm::mat4> overall_trans;

        std::vector<Joint*> joints;
        get_joints(joints, mp_root_joint);

        for (Joint *j : joints) {
            bind_mats.push_back(j->get_bind_mat());
            overall_trans.push_back(j->get_overall_transformation());
        }

        m_progSkeleton.set_bind_mats(bind_mats);
        m_progSkeleton.set_overall_trans(overall_trans);
    }

    //#define NOPE
#ifndef NOPE
    // model matrix to be used in shader
    glm::mat4 model = glm::mat4(1.f);

    // draws the mesh
    mp_currMeshShader->setModelMatrix(model);
    mp_currMeshShader->draw(m_mesh);

    glDisable(GL_DEPTH_TEST);

    // draws the joints and selected component
    mp_currCompShader->setModelMatrix(model);

    switch(m_type_selected) {
    case (VERT):
        mp_currCompShader->draw(m_selected_vert);
        break;

    case (EDGE):
        mp_currCompShader->draw(m_selected_edge);
        break;

    case (FACE):
        mp_currCompShader->draw(m_selected_face);
        break;
    }

    if (mp_root_joint != nullptr) {
        this->draw_skeleton(mp_root_joint);
    }

    glEnable(GL_DEPTH_TEST);
#endif
}

void MyGL::set_default_shaders() {
    mp_currMeshShader = &m_progLambert;
    mp_currCompShader = &m_progFlat;
}

void MyGL::set_skeleton_shaders() {
    mp_currCompShader = &m_progSkeleton;
    mp_currMeshShader = &m_progSkeleton;
}

void MyGL::keyPressEvent(QKeyEvent *e) {
    float amount = 2.0f;
    if(e->modifiers() & Qt::ShiftModifier){
        amount = 10.0f;
    }

    switch(e->key()) {
    case (Qt::Key_Escape):
        QApplication::quit();
        break;

    case (Qt::Key_Right):
        m_glCamera.RotateAboutUp(-amount);
        break;
    case (Qt::Key_Left):
        m_glCamera.RotateAboutUp(amount);
        break;
    case (Qt::Key_Up):
        m_glCamera.RotateAboutRight(-amount);
        break;
    case (Qt::Key_Down):
        m_glCamera.RotateAboutRight(amount);
        break;

    case (Qt::Key_1):
        m_glCamera.fovy += amount;
        break;
    case (Qt::Key_2):
        m_glCamera.fovy -= amount;
        break;

    case (Qt::Key_W):
        m_glCamera.TranslateAlongLook(amount);
        break;
    case (Qt::Key_S):
        m_glCamera.TranslateAlongLook(-amount);
        break;
    case (Qt::Key_D):
        m_glCamera.TranslateAlongRight(amount);
        break;
    case (Qt::Key_A):
        m_glCamera.TranslateAlongRight(-amount);
        break;

    case (Qt::Key_Q):
        m_glCamera.TranslateAlongUp(-amount);
        break;
    case (Qt::Key_E):
        m_glCamera.TranslateAlongUp(amount);
        break;

    case (Qt::Key_R):
        m_glCamera = Camera(this->width(), this->height());
        break;

    case (Qt::Key_I):
        m_glCamera.RotatePhi(-amount * .1);
        break;
    case (Qt::Key_K):
        m_glCamera.RotatePhi(amount * .1);
        break;
    case (Qt::Key_J):
        m_glCamera.RotateTheta(amount * .1);
        break;
    case (Qt::Key_L):
        m_glCamera.RotateTheta(-amount * .1);
        break;
    }


    m_glCamera.RecomputeAttributes();

    if (m_type_selected == EDGE) {
        HalfEdge *edge = dynamic_cast<HalfEdge*>(mp_selected_comp);

        if (e->key() == Qt::Key_N) {
            mp_selected_comp = edge->get_next();

            this->destroy_drawable_comp();
            this->update_drawable_edge(edge->get_next());

        } else if (e->key() == Qt::Key_M) {
            mp_selected_comp = edge->get_sym();

            this->destroy_drawable_comp();
            this->update_drawable_edge(edge->get_sym());

        } else if (e->key() == Qt::Key_F) {
            Face *face = edge->get_face();
            mp_selected_comp = face;

            this->destroy_drawable_comp();
            this->update_drawable_face(face->get_edge(), face->get_color());

        } else if (e->key() == Qt::Key_V) {
            Vertex *vert = edge->get_vert();
            mp_selected_comp = vert;

            this->destroy_drawable_comp();
            this->update_drawable_vert(vert);
        }

    } else if (m_type_selected == VERT) {
        if (e->key() == Qt::Key_H) {
            Vertex *vert = dynamic_cast<Vertex*>(mp_selected_comp);
            mp_selected_comp = vert->get_edge();

            this->destroy_drawable_comp();
            this->update_drawable_edge(vert->get_edge());
        }

    } else if (m_type_selected == FACE) {
        if (e->modifiers() & Qt::ShiftModifier) {
            if (e->key() == Qt::Key_H) {
                Face *face = dynamic_cast<Face*>(mp_selected_comp);
                mp_selected_comp = face->get_edge();

                this->destroy_drawable_comp();
                this->update_drawable_edge(face->get_edge());
            }
        }
    }

    update();  // Calls paintGL, among other things
}

void MyGL::wheelEvent(QWheelEvent *e) {
    m_glCamera.Zoom(e->delta() * 0.02f);
    m_glCamera.RecomputeAttributes();

    update();  // Calls paintGL, among other things
}


void MyGL::mousePressEvent(QMouseEvent *e) {
    if (e->buttons() & (Qt::LeftButton | Qt::RightButton))     {
        m_mousePosPrev = glm::vec2(e->x(), e->y());
    }
}

void MyGL::mouseMoveEvent(QMouseEvent* e) {
    glm::vec2 pos(e->x(), e->y());

    if (e->buttons() & Qt::LeftButton) {
        // Rotation
        glm::vec2 diff = 0.01f * (pos - m_mousePosPrev);
        m_mousePosPrev = pos;
        m_glCamera.RotatePhi(-diff.x);
        m_glCamera.RotateTheta(-diff.y);
    } else if (e->buttons() & Qt::RightButton) {
        // Panning
        glm::vec2 diff = 0.05f * (pos - m_mousePosPrev);
        m_mousePosPrev = pos;
        m_glCamera.TranslateAlongRight(-diff.x);
        m_glCamera.TranslateAlongUp(diff.y);
    }

    update();  // Calls paintGL, among other things
}

/*******************************************************************************/
/************************************ MESH *************************************/
/*******************************************************************************/

// reads in obj file, parses file, and sets up mesh
void MyGL::slot_import_mesh() {
    QString filename = QFileDialog::getOpenFileName(this, "Open an obj file!", "/home", tr("Object files (*.obj)"));

    // condition in case user cancels
    if (filename == nullptr) {
        return;
    }

    // cleans up previous mesh
    m_mesh.clean_up_mesh();

    // reverts back to original shaders
    this->set_default_shaders();

    // begins parsing file
    QFile file(filename);

    if (!file.open(QIODevice::ReadOnly)) {
        QMessageBox::information(0, "error", file.errorString());
    }

    // creates mapping between edges to faces (for finding sym edge pairs)
    // where an edge is just the set of vertex indices from obj file
    // (used for finding sym edge pairs)
    QMap<QPair<int,int>, Face*> edge_face_map;

    QTextStream in(&file);

    while (!in.atEnd()) {
        // trims and reads lines of file
        QString line = in.readLine().trimmed();

        // splits line by whitespace
        QStringList token = line.split(QRegExp("\\s+"));

        if (token.at(0) == "v") {
            glm::vec3 pos(token.at(1).toFloat(),
                          token.at(2).toFloat(),
                          token.at(3).toFloat());

            m_mesh.m_verts.push_back(new Vertex(nullptr, pos));

        } else if (token.at(0) == "f") {
            std::vector<int> vert_idx;  // vertex indices of THIS face

            // grabs the vertex position index (which is one-indexed in obj file)
            for (int i = 1; i < token.size(); i++) {
                int idx = token.at(i).split('/').at(0).toInt() - 1;
                vert_idx.push_back(idx);
            }

            // generates face from given vertex indices
            Face *face = m_mesh.generate_face(vert_idx);

            // finds symmetric edge pairs (if they exist)
            for (int i = 0; i < vert_idx.size(); i++) {
                int fir = i;
                int sec = (i + 1) % vert_idx.size();

                QPair<int, int> sym_edge = qMakePair(vert_idx[sec], vert_idx[fir]);
                Face *mapped_face = edge_face_map.value(sym_edge);

                // checks if the sym edge exists in edge-face map
                if (mapped_face == nullptr) {
                    // adds edge-face pair (no sym exists yet)
                    QPair<int, int> edge = qMakePair(vert_idx[fir], vert_idx[sec]);
                    edge_face_map.insert(edge, face);
                } else {
                    // adds connection between syms
                    Vertex *v1 = m_mesh.m_verts[vert_idx[fir]]; // edge in f2 should point to v1
                    Vertex *v2 = m_mesh.m_verts[vert_idx[sec]]; // edge in f1 should point to v2

                    Mesh::set_sym_edges(face, mapped_face, v1, v2);
                }
            }
        }
    }

    file.close();

    // cleans up selected components
    this->destroy_drawable_comp();
    // creates newly uploaded mesh
    this->update_mesh();

    if (mp_root_joint != nullptr) {
        std::vector<Joint*> joints;
        get_joints(joints, mp_root_joint);

        for (Joint *j : joints) {
            j->set_is_skinning(false);
        }
    }

    update();

    emit clear_lists();         // tells mainwindow to clear list of components
    this->send_components();    // updates mainwindow with new list of components
}

// sends edges, vertices, faces to mainwindow
void MyGL::send_components() {
    QVector<Face*> faces = QVector<Face*>::fromStdVector(m_mesh.m_faces);
    QVector<Vertex*> verts = QVector<Vertex*>::fromStdVector(m_mesh.m_verts);
    QVector<HalfEdge*> edges = QVector<HalfEdge*>::fromStdVector(m_mesh.m_edges);

    emit send_faces(faces);
    emit send_verts(verts);
    emit send_edges(edges);
}

// invokes create() among other things
void MyGL::update_mesh() {
    m_mesh.destroy();
    m_mesh.create();
}

/*******************************************************************************/
/******************************* MESH MODIFIERS ********************************/
/*******************************************************************************/

void MyGL::slot_add_midpoint() {
    if (m_type_selected != EDGE) {
        return;
    }

    HalfEdge* edge = dynamic_cast<HalfEdge*>(mp_selected_comp);
    m_mesh.split(edge);

    if (m_mesh.is_skinned()) {
        this->skin_mesh();
    }

    this->update_drawable_edge(edge);
    this->update_mesh();

    update();

    emit clear_lists();
    this->send_components();
}

void MyGL::slot_triangulate_face() {
    if (m_type_selected != FACE) {
        return;
    }

    Face *face = dynamic_cast<Face*>(mp_selected_comp);
    m_mesh.triangulate(face);

    if (m_mesh.is_skinned()) {
        this->skin_mesh();
    }

    this->update_drawable_face(face->get_edge(), face->get_color());
    this->update_mesh();

    update();

    emit clear_lists();
    this->send_components();
}

void MyGL::slot_extrude_face() {
    if (m_type_selected != FACE) {
        return;
    }

    Face *face = dynamic_cast<Face*>(mp_selected_comp);
//    m_mesh.extrude(face);

    this->update_drawable_face(face->get_edge(), face->get_color());
    this->update_mesh();

    update();

    emit clear_lists();
    this->send_components();
}

void MyGL::slot_subdivide_poly() {
    m_mesh.subdivide();

    if (m_mesh.is_skinned()) {
        this->skin_mesh();
    }

    // creates new mesh
    this->update_mesh();

    // cleans up selected components
    this->destroy_drawable_comp();

    update();

    emit clear_lists();
    this->send_components();
}

/*******************************************************************************/
/*************************** SELECTED MESH COMPONENT ***************************/
/*******************************************************************************/


void MyGL::setFaceColorSliders(glm::vec3 col) {
    col *= 255.f;

    this->send_face_red_col(int(col.r));
    this->send_face_green_col(int(col.g));
    this->send_face_blue_col(int(col.b));
}

void MyGL::resetFaceColorSliders() {
    setFaceColorSliders(glm::vec3(0.f));
}

void MyGL::slot_get_selected_list_item(QListWidgetItem *item) {
    // makes sure an item was clicked
    if (item != 0) {
        if (HalfEdge* edge = dynamic_cast<HalfEdge*>(item)) {

            mp_selected_comp = edge;

            this->destroy_drawable_comp();
            this->update_drawable_edge(edge);

            this->resetFaceColorSliders();

            // zeros out positions
            this->send_vert_x_pos(0.0);
            this->send_vert_y_pos(0.0);
            this->send_vert_z_pos(0.0);

        } else if (Face *face = dynamic_cast<Face*>(item)) {

            mp_selected_comp = face;

            this->destroy_drawable_comp();
            this->update_drawable_face(face->get_edge(), face->get_color());

            // sends color to sliders
            glm::vec3 col = face->get_color();
            this->setFaceColorSliders(col);

            // zeros out positions
            this->send_vert_x_pos(0.0);
            this->send_vert_y_pos(0.0);
            this->send_vert_z_pos(0.0);

        } else if (Vertex *vert = dynamic_cast<Vertex*>(item)) {

            mp_selected_comp = vert;

            this->destroy_drawable_comp();
            this->update_drawable_vert(vert);

            // zeros out colors
            this->resetFaceColorSliders();

            // sends position to spinboxes
            glm::vec4 pos = vert->get_pos4();

            this->send_vert_x_pos(pos.x);
            this->send_vert_y_pos(pos.y);
            this->send_vert_z_pos(pos.z);
        }

        update();
    }
}

void MyGL::update_drawable_edge(HalfEdge *edge) {
    m_selected_edge.destroy();
    m_selected_edge.set_verts(edge);
    m_selected_edge.create();

    m_type_selected = EDGE;
}

void MyGL::update_drawable_face(HalfEdge *edge, glm::vec3 color) {
    m_selected_face.destroy();
    m_selected_face.set_verts(edge, color);
    m_selected_face.create();

    m_type_selected = FACE;
}

void MyGL::update_drawable_vert(Vertex *v) {
    m_selected_vert.destroy();
    m_selected_vert.set_vert(v);
    m_selected_vert.create();

    m_type_selected = VERT;
}

// cleans up selected components
void MyGL::destroy_drawable_comp() {
    m_selected_vert.destroy();
    m_selected_edge.destroy();
    m_selected_face.destroy();

    m_type_selected = NONE;
}

/*******************************************************************************/
/************************** MESH COMPONENT MODIFIERS ***************************/
/*******************************************************************************/

void MyGL::update_face_col(ChannelSelected channel, float value) {
    // return if the currently selected structure is not a face
    if (m_type_selected != FACE) {
        return;
    }

    // assuming value is in the range [0,256)
    // need to normalize this range to [0,1)
    value /= 255.f;

    Face *face = dynamic_cast<Face*>(mp_selected_comp);
    glm::vec3 color = face->get_color();

    // update the appropriate channel
    switch(channel) {
    case RED_CH:
        color.r = value;
        break;
    case GREEN_CH:
        color.g = value;
        break;
    case BLUE_CH:
        color.b = value;
        break;
    default:
        color = glm::vec3(0.f);
    }

    face->set_color(color);

    this->update_drawable_face(face->get_edge(), face->get_color());
    this->update_mesh();

    update();
}

void MyGL::slot_update_face_red_col(int r) {
    update_face_col(RED_CH, r);
}

void MyGL::slot_update_face_green_col(int g) {
    update_face_col(GREEN_CH, g);
}

void MyGL::slot_update_face_blue_col(int b) {
    update_face_col(BLUE_CH, b);
}


void MyGL::slot_update_vert_x_pos(double x) {
    if (m_type_selected == VERT) {
        Vertex *vert = dynamic_cast<Vertex*>(mp_selected_comp);

        glm::vec4 pos = vert->get_pos4();
        pos.x = x;
        vert->set_pos(pos);

        this->update_drawable_vert(vert);
        this->update_mesh();

        update();
    }
}

void MyGL::slot_update_vert_y_pos(double y) {
    if (m_type_selected == VERT) {
        Vertex *vert = dynamic_cast<Vertex*>(mp_selected_comp);

        glm::vec4 pos = vert->get_pos4();
        pos.y = y;
        vert->set_pos(pos);

        this->update_drawable_vert(vert);
        this->update_mesh();

        update();
    }
}

void MyGL::slot_update_vert_z_pos(double z) {
    if (m_type_selected == VERT) {
        Vertex *vert = dynamic_cast<Vertex*>(mp_selected_comp);

        glm::vec4 pos = vert->get_pos4();
        pos.z = z;
        vert->set_pos(pos);

        this->update_drawable_vert(vert);
        this->update_mesh();

        update();
    }
}


/*******************************************************************************/
/********************************** SKELETON ***********************************/
/*******************************************************************************/

// imports skeleton from JSON file
void MyGL::slot_import_skeleton() {
    QString filename = QFileDialog::getOpenFileName(this, "Open a json file!", "/home", tr("JSON files (*.json)"));

    // condition in case user cancels
    if (filename == nullptr) {
        return;
    }

    // begins parsing file
    QFile file(filename);

    if (!file.open(QIODevice::ReadOnly)) {
        QMessageBox::information(0, "error", file.errorString());
    }

    QString file_content = file.readAll();
    file.close();

    // reads file as a JSON file
    QJsonDocument doc = QJsonDocument::fromJson(file_content.toUtf8());

    // cleans up mainwindow
    if (mp_root_joint != nullptr) {
        emit clear_joint_tree();
        emit clear_joint_info();
    }

    // cleans up previous skeleton
    delete mp_root_joint;
    Joint::reset_count();

    // cleans up selected joint
    mp_selected_joint = nullptr;

    // gets root from file
    mp_root_joint = generate_joint(nullptr, doc.object().value("root").toObject());

    // updates tree in mainwindow
    emit send_root_joint(mp_root_joint);

    // reverts back to original shaders
    this->set_default_shaders();

    m_mesh.set_is_skinned(false);
    this->update_mesh();

    update();
}

// generates a child Joint object from a Joint parent and JSON info about child
Joint *MyGL::generate_joint(Joint *parent, QJsonObject child) {
    QString j_name = child.value("name").toString();
    QJsonArray j_pos = child.value("pos").toArray();
    QJsonArray j_rot = child.value("rot").toArray();
    QJsonArray j_children = child.value("children").toArray();

    glm::vec3 pos;  // position of joint
    glm::vec3 axis; // axis of rotation

    float angle = j_rot.at(0).toDouble();   // angle to rotate about axis

    for (int i = 0; i < 3; i++) {
        pos[i] = j_pos.at(i).toDouble();
        axis[i] = j_rot.at(i+1).toDouble();
    }

    Joint *joint = new Joint(this, parent, pos, glm::angleAxis(angle, axis), j_name);

    if (!j_children.isEmpty()) {
        generate_children(joint, j_children);
    }

    return joint;
}

// generates the children of a given parent Joint from JSON infor about children
// (adds children in-order traversal)
void MyGL::generate_children(Joint *parent, QJsonArray j_children) {
    for (QJsonValue child : j_children) {
        Joint *j = generate_joint(parent, child.toObject());
        parent->add_child(j);
    }
}


// draws a given skeleton
void MyGL::draw_skeleton(Joint *j) {
    j->create();
    mp_currCompShader->draw(*j);

    for (Joint *child : j->get_children()) {
        draw_skeleton(child);
    }
}


/*******************************************************************************/
/************************** MESH/SKELETON MODIFIERS ****************************/
/*******************************************************************************/

void MyGL::slot_simple_skin_mesh() {
    if (mp_root_joint == nullptr || m_mesh.is_skinned()) {
        return;
    }

    this->skin_mesh();
}


void MyGL::skin_mesh() {
    std::vector<Joint*> joints;
    get_joints(joints, mp_root_joint);

    for (Joint *j : joints) {
        j->set_is_skinning(true);
    }

    for (Vertex *v : m_mesh.m_verts) {
        find_closest_joints(joints, v);
    }

    this->set_skeleton_shaders();

    m_mesh.set_is_skinned(true);

    this->update_mesh();

    update();
}

// gets the joints in-order
void MyGL::get_joints(std::vector<Joint*> &joints, Joint *joint) {
    joints.push_back(joint);

    for (Joint *child : joint->get_children()) {
        get_joints(joints, child);
    }
}

// finds the two closest joint to a given vertex
void MyGL::find_closest_joints(std::vector<Joint*> &joints, Vertex *v) {
    QPair<float, float> closest_dists = qMakePair(HUGE_VALF, HUGE_VALF);
    QPair<Joint*, Joint*> closest_joints = qMakePair(nullptr, nullptr);

    for (Joint *joint : joints) {
        glm::vec3 del = joint->get_pos() - v->get_pos3();
        float dist = glm::length(del);

        if (dist < closest_dists.first) {
            closest_dists.first = dist;
            closest_joints.first = joint;

            // maintains invariant that closest joint is 2nd entry
            if (dist < closest_dists.second) {
                closest_dists.first = closest_dists.second;
                closest_dists.second = dist;

                closest_joints.first = closest_joints.second;
                closest_joints.second = joint;
            }
        }
    }

    v->set_joints(closest_joints, closest_dists);
}

/*******************************************************************************/
/******************************** SELECTED JOINT *******************************/
/*******************************************************************************/

// handles selected joint from tree
void MyGL::slot_get_selected_joint(QTreeWidgetItem *item) {
    // makes sure an item was clicked
    if (item == 0) {
        return;
    }

    if (mp_selected_joint != nullptr) {
        mp_selected_joint->toggle_is_selected();
    }

    mp_selected_joint = dynamic_cast<Joint*>(item);
    mp_selected_joint->toggle_is_selected();

    emit send_joint_info(mp_selected_joint);

    glm::vec3 pos = mp_selected_joint->get_rel_pos();

    emit send_joint_x(pos.x);
    emit send_joint_y(pos.y);
    emit send_joint_z(pos.z);

    update();
}

/*******************************************************************************/
/************************** SELECTED JOINT MODIFIERS ***************************/
/*******************************************************************************/

// signals to selected joint to rotate about x-axis counter-clockwise
void MyGL::slot_add_rotate_joint_x() {
    if (mp_selected_joint == nullptr) {
        return;
    }

    mp_selected_joint->rotate_x(joint_amt);

    emit clear_joint_info();
    emit send_joint_info(mp_selected_joint);

    this->update_mesh();

    update();
}

// signals to selected joint to rotate about x-axis clockwise
void MyGL::slot_sub_rotate_joint_x() {
    if (mp_selected_joint == nullptr) {
        return;
    }

    mp_selected_joint->rotate_x(-joint_amt);

    emit clear_joint_info();
    emit send_joint_info(mp_selected_joint);

    this->update_mesh();

    update();
}

// signals to selected joint to rotate about y-axis counter-clockwise
void MyGL::slot_add_rotate_joint_y() {
    if (mp_selected_joint == nullptr) {
        return;
    }

    mp_selected_joint->rotate_y(joint_amt);

    emit clear_joint_info();
    emit send_joint_info(mp_selected_joint);

    this->update_mesh();

    update();
}

// signals to selected joint to rotate about y-axis clockwise
void MyGL::slot_sub_rotate_joint_y() {
    if (mp_selected_joint == nullptr) {
        return;
    }

    mp_selected_joint->rotate_y(-joint_amt);

    emit clear_joint_info();
    emit send_joint_info(mp_selected_joint);

    this->update_mesh();

    update();
}

// signals to selected joint to rotate about z-axis counter-clockwise
void MyGL::slot_add_rotate_joint_z() {
    if (mp_selected_joint == nullptr) {
        return;
    }

    mp_selected_joint->rotate_z(joint_amt);

    emit clear_joint_info();
    emit send_joint_info(mp_selected_joint);

    this->update_mesh();

    update();
}

// signals to selected joint to rotate about z-axis clockwise
void MyGL::slot_sub_rotate_joint_z() {
    if (mp_selected_joint == nullptr) {
        return;
    }

    mp_selected_joint->rotate_z(-joint_amt);

    emit clear_joint_info();
    emit send_joint_info(mp_selected_joint);

    this->update_mesh();

    update();
}


void MyGL::slot_update_joint_x(double x) {
    if (mp_selected_joint == nullptr) {
        return;
    }

    mp_selected_joint->translate_x(x);

    emit clear_joint_info();
    emit send_joint_info(mp_selected_joint);

    this->update_mesh();

    update();
}


void MyGL::slot_update_joint_y(double y) {
    if (mp_selected_joint == nullptr) {
        return;
    }

    mp_selected_joint->translate_y(y);

    emit clear_joint_info();
    emit send_joint_info(mp_selected_joint);

    this->update_mesh();

    update();
}


void MyGL::slot_update_joint_z(double z) {
    if (mp_selected_joint == nullptr) {
        return;
    }

    mp_selected_joint->translate_z(z);

    emit clear_joint_info();
    emit send_joint_info(mp_selected_joint);

    this->update_mesh();

    update();
}
