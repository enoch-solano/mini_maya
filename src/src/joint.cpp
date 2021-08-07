#include "joint.h"

// initializes static variables
int Joint::joint_count = 0;

Joint::Joint(GLWidget277 *context, Joint *parent, glm::vec3 pos, glm::quat ori, QString name)
    : Drawable(context), mp_parent(parent), m_pos(pos), m_ori(ori), m_name(name),
      m_bind_mat(glm::inverse(get_overall_transformation())), m_id(joint_count)
{
    setText(0, m_name);
    joint_count++;
}

Joint::~Joint() {
    for (Joint *child : m_children) {
        delete child;
        child = nullptr;
    }
}

/////////////////////////////////////////////////////////
//////////////////////// SETTERS ////////////////////////
/////////////////////////////////////////////////////////

void Joint::set_parent(Joint *parent) {
    mp_parent = parent;
}

void Joint::add_child(Joint *child) {
    m_children.push_back(child);
    QTreeWidgetItem::addChild(child);
}

void Joint::toggle_is_selected() {
    m_is_selected = !m_is_selected;
}

// rotates orientation about x-axis
void Joint::rotate_x(float amt) {
    m_ori = glm::angleAxis(amt, glm::vec3(1, 0, 0)) * m_ori;
}

// rotates orientation about y-axis
void Joint::rotate_y(float amt) {
    m_ori = glm::angleAxis(amt, glm::vec3(0, 1, 0)) * m_ori;
}

// rotates orientation about z-axis
void Joint::rotate_z(float amt) {
    m_ori = glm::angleAxis(amt, glm::vec3(0, 0, 1)) * m_ori;
}

void Joint::translate_x(float x) {
    m_pos.x = x;
}

void Joint::translate_y(float y) {
    m_pos.y = y;
}

void Joint::translate_z(float z) {
    m_pos.z = z;
}

/////////////////////////////////////////////////////////
//////////////////////// GETTERS ////////////////////////
/////////////////////////////////////////////////////////

std::vector<Joint*> Joint::get_children() {
    return m_children;
}

// returns position relative to parent
glm::vec3 Joint::get_rel_pos() {
    return m_pos;
}

// returns position relative to world
glm::vec3 Joint::get_pos() {
    glm::vec4 pos = glm::vec4(m_pos, 1.f);

    if (mp_parent != nullptr) {
        pos = mp_parent->get_overall_transformation() * pos;
    }

    return glm::vec3(pos.x, pos.y, pos.z);
}

glm::vec4 Joint::get_ori() {
    float deg = glm::angle(m_ori);
    glm::vec3 axis = glm::axis(m_ori);

    return glm::vec4(deg, axis);
}

glm::mat4 Joint::get_bind_mat() {
    return m_bind_mat;
}

int Joint::get_id() {
    return m_id;
}

QString Joint::get_name() {
    return m_name;
}

///////////////////////////////////////////////////////////////////////////////

// represents the concatenation of a joint's position and
// rotation, which are in parents' coordinate frame
// (i.e. converts local coordinates -> parents' coordinates)
glm::mat4 Joint::get_local_transformation() {
    return glm::translate(glm::mat4(1.f), m_pos) * glm::mat4_cast(m_ori);
}

// represents the concatentation of this joint's local transformation
// with the transformations of its chain of parent joints
// (i.e. converts local -> world)
glm::mat4 Joint::get_overall_transformation() {
    if (mp_parent == nullptr) {
        return get_local_transformation();
    } else {
        return mp_parent->get_overall_transformation() *  get_local_transformation();
    }
}

void Joint::create() {
    std::vector<glm::vec4> vert_col;
    std::vector<glm::vec4> vert_pos;
    std::vector<GLuint> vert_idx;

    glm::vec4 white(1.f, 1.f, 1.f, 0.f);
    glm::vec4 red(1.f, 0.f, 0.f, 0.f);
    glm::vec4 green(0.f, 1.f, 0.f, 0.f);
    glm::vec4 blue(0.f, 0.f, 1.f, 0.f);
    glm::vec4 orange(1.f, 0.5, 0.f, 0.f);

    // generates the sphere representing joint
    int num_sides = 20;

    glm::mat3 radius(0.5);  // radius of circle
    glm::mat3 axis(1.f);    // axis of rotation

    float deg = glm::radians(360.f / num_sides);

    for (int i = 0; i < 3; i++) {
        glm::vec4 p(radius[(i + 1) % 3], 1.f);

        // generates n-sided polygon positions
        for (int j = 0; j < num_sides; j++) {
            glm::mat4 M = glm::rotate(glm::mat4(), j * deg, axis[i]);
            vert_pos.push_back(get_overall_transformation() * M * p);
        }

        // adds indices of polygon
        for (int j = 0; j < num_sides; j++) {
            vert_idx.push_back(j + (num_sides * i));
            vert_idx.push_back((j + 1) % num_sides + (num_sides * i));
        }
    }

    if (m_is_selected){
        for (int i = 0; i < vert_pos.size(); i++) {
            vert_col.push_back(white);
        }
    } else {
        for (int i = 0; i < vert_pos.size(); i++) {
            if (i < num_sides){
                vert_col.push_back(red);
            } else if (i < 2 * num_sides) {
                vert_col.push_back(green);
            } else {
                vert_col.push_back(blue);
            }
        }
    }

    // draws line from joint to parent joint
    if (mp_parent != nullptr) {
        vert_col.push_back(orange);
        vert_col.push_back(white);

        vert_idx.push_back(vert_pos.size());
        vert_idx.push_back(vert_pos.size() + 1);

        // current joint position relative to world
        glm::vec4 p1 = mp_parent->get_overall_transformation() * glm::vec4(m_pos, 1.f);
        vert_pos.push_back(p1);

        // parent joint's position relative to world
        glm::vec4 p2 = mp_parent->get_overall_transformation() * glm::vec4(0.f, 0.f, 0.f, 1.f);
        vert_pos.push_back(p2);
    }

    count = vert_idx.size();

    generateIdx();
    mp_context->glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, bufIdx);
    mp_context->glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(GLuint), vert_idx.data(), GL_STATIC_DRAW);

    generatePos();
    mp_context->glBindBuffer(GL_ARRAY_BUFFER, bufPos);
    mp_context->glBufferData(GL_ARRAY_BUFFER, vert_pos.size() * sizeof(glm::vec4), vert_pos.data(), GL_STATIC_DRAW);

    generateCol();
    mp_context->glBindBuffer(GL_ARRAY_BUFFER, bufCol);
    mp_context->glBufferData(GL_ARRAY_BUFFER, vert_col.size() * sizeof(glm::vec4), vert_col.data(), GL_STATIC_DRAW);

    glm::ivec2 ids(0, 0);
    glm::vec2 weights(-1.f, -1.f);
    
    std::vector<glm::ivec2> joint_ids (vert_pos.size(), ids);
    std::vector<glm::vec2> joint_weights (vert_pos.size(), weights);
    
    generateJointIDs();
    mp_context->glBindBuffer(GL_ARRAY_BUFFER, bufJointID);
    mp_context->glBufferData(GL_ARRAY_BUFFER, joint_ids.size() * sizeof(glm::ivec2), joint_ids.data(), GL_STATIC_DRAW);
    
    generateJointWeights();
    mp_context->glBindBuffer(GL_ARRAY_BUFFER, bufJointWeight);
    mp_context->glBufferData(GL_ARRAY_BUFFER, joint_weights.size() * sizeof(glm::vec2), joint_weights.data(), GL_STATIC_DRAW);
}

void Joint::set_is_skinning(bool is_skinning) {
    m_is_skinning = is_skinning;
}

bool Joint::is_skinning() {
    return m_is_skinning;
}

GLenum Joint::drawMode() {
    return GL_LINES;
}

void Joint::reset_count() {
    joint_count = 0;
}
