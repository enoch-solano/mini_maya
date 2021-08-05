/****************************************************************************
** Meta object code from reading C++ file 'mygl.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/mygl.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QVector>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mygl.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MyGL_t {
    QByteArrayData data[58];
    char stringdata0[927];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MyGL_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MyGL_t qt_meta_stringdata_MyGL = {
    {
QT_MOC_LITERAL(0, 0, 4), // "MyGL"
QT_MOC_LITERAL(1, 5, 10), // "send_edges"
QT_MOC_LITERAL(2, 16, 0), // ""
QT_MOC_LITERAL(3, 17, 18), // "QVector<HalfEdge*>"
QT_MOC_LITERAL(4, 36, 10), // "send_faces"
QT_MOC_LITERAL(5, 47, 14), // "QVector<Face*>"
QT_MOC_LITERAL(6, 62, 10), // "send_verts"
QT_MOC_LITERAL(7, 73, 16), // "QVector<Vertex*>"
QT_MOC_LITERAL(8, 90, 15), // "send_vert_x_pos"
QT_MOC_LITERAL(9, 106, 15), // "send_vert_y_pos"
QT_MOC_LITERAL(10, 122, 15), // "send_vert_z_pos"
QT_MOC_LITERAL(11, 138, 17), // "send_face_red_col"
QT_MOC_LITERAL(12, 156, 19), // "send_face_green_col"
QT_MOC_LITERAL(13, 176, 18), // "send_face_blue_col"
QT_MOC_LITERAL(14, 195, 12), // "send_joint_x"
QT_MOC_LITERAL(15, 208, 12), // "send_joint_y"
QT_MOC_LITERAL(16, 221, 12), // "send_joint_z"
QT_MOC_LITERAL(17, 234, 9), // "send_mesh"
QT_MOC_LITERAL(18, 244, 5), // "Mesh&"
QT_MOC_LITERAL(19, 250, 15), // "send_root_joint"
QT_MOC_LITERAL(20, 266, 6), // "Joint*"
QT_MOC_LITERAL(21, 273, 16), // "clear_joint_tree"
QT_MOC_LITERAL(22, 290, 15), // "send_joint_info"
QT_MOC_LITERAL(23, 306, 16), // "clear_joint_info"
QT_MOC_LITERAL(24, 323, 11), // "clear_lists"
QT_MOC_LITERAL(25, 335, 27), // "slot_get_selected_list_item"
QT_MOC_LITERAL(26, 363, 16), // "QListWidgetItem*"
QT_MOC_LITERAL(27, 380, 4), // "item"
QT_MOC_LITERAL(28, 385, 24), // "slot_update_face_red_col"
QT_MOC_LITERAL(29, 410, 1), // "r"
QT_MOC_LITERAL(30, 412, 26), // "slot_update_face_green_col"
QT_MOC_LITERAL(31, 439, 1), // "g"
QT_MOC_LITERAL(32, 441, 25), // "slot_update_face_blue_col"
QT_MOC_LITERAL(33, 467, 1), // "b"
QT_MOC_LITERAL(34, 469, 22), // "slot_update_vert_x_pos"
QT_MOC_LITERAL(35, 492, 1), // "x"
QT_MOC_LITERAL(36, 494, 22), // "slot_update_vert_y_pos"
QT_MOC_LITERAL(37, 517, 1), // "y"
QT_MOC_LITERAL(38, 519, 22), // "slot_update_vert_z_pos"
QT_MOC_LITERAL(39, 542, 1), // "z"
QT_MOC_LITERAL(40, 544, 17), // "slot_add_midpoint"
QT_MOC_LITERAL(41, 562, 21), // "slot_triangulate_face"
QT_MOC_LITERAL(42, 584, 17), // "slot_extrude_face"
QT_MOC_LITERAL(43, 602, 19), // "slot_subdivide_poly"
QT_MOC_LITERAL(44, 622, 16), // "slot_import_mesh"
QT_MOC_LITERAL(45, 639, 20), // "slot_import_skeleton"
QT_MOC_LITERAL(46, 660, 23), // "slot_get_selected_joint"
QT_MOC_LITERAL(47, 684, 16), // "QTreeWidgetItem*"
QT_MOC_LITERAL(48, 701, 21), // "slot_simple_skin_mesh"
QT_MOC_LITERAL(49, 723, 23), // "slot_add_rotate_joint_x"
QT_MOC_LITERAL(50, 747, 23), // "slot_sub_rotate_joint_x"
QT_MOC_LITERAL(51, 771, 23), // "slot_add_rotate_joint_y"
QT_MOC_LITERAL(52, 795, 23), // "slot_sub_rotate_joint_y"
QT_MOC_LITERAL(53, 819, 23), // "slot_add_rotate_joint_z"
QT_MOC_LITERAL(54, 843, 23), // "slot_sub_rotate_joint_z"
QT_MOC_LITERAL(55, 867, 19), // "slot_update_joint_x"
QT_MOC_LITERAL(56, 887, 19), // "slot_update_joint_y"
QT_MOC_LITERAL(57, 907, 19) // "slot_update_joint_z"

    },
    "MyGL\0send_edges\0\0QVector<HalfEdge*>\0"
    "send_faces\0QVector<Face*>\0send_verts\0"
    "QVector<Vertex*>\0send_vert_x_pos\0"
    "send_vert_y_pos\0send_vert_z_pos\0"
    "send_face_red_col\0send_face_green_col\0"
    "send_face_blue_col\0send_joint_x\0"
    "send_joint_y\0send_joint_z\0send_mesh\0"
    "Mesh&\0send_root_joint\0Joint*\0"
    "clear_joint_tree\0send_joint_info\0"
    "clear_joint_info\0clear_lists\0"
    "slot_get_selected_list_item\0"
    "QListWidgetItem*\0item\0slot_update_face_red_col\0"
    "r\0slot_update_face_green_col\0g\0"
    "slot_update_face_blue_col\0b\0"
    "slot_update_vert_x_pos\0x\0"
    "slot_update_vert_y_pos\0y\0"
    "slot_update_vert_z_pos\0z\0slot_add_midpoint\0"
    "slot_triangulate_face\0slot_extrude_face\0"
    "slot_subdivide_poly\0slot_import_mesh\0"
    "slot_import_skeleton\0slot_get_selected_joint\0"
    "QTreeWidgetItem*\0slot_simple_skin_mesh\0"
    "slot_add_rotate_joint_x\0slot_sub_rotate_joint_x\0"
    "slot_add_rotate_joint_y\0slot_sub_rotate_joint_y\0"
    "slot_add_rotate_joint_z\0slot_sub_rotate_joint_z\0"
    "slot_update_joint_x\0slot_update_joint_y\0"
    "slot_update_joint_z"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MyGL[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      42,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      18,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,  224,    2, 0x06 /* Public */,
       4,    1,  227,    2, 0x06 /* Public */,
       6,    1,  230,    2, 0x06 /* Public */,
       8,    1,  233,    2, 0x06 /* Public */,
       9,    1,  236,    2, 0x06 /* Public */,
      10,    1,  239,    2, 0x06 /* Public */,
      11,    1,  242,    2, 0x06 /* Public */,
      12,    1,  245,    2, 0x06 /* Public */,
      13,    1,  248,    2, 0x06 /* Public */,
      14,    1,  251,    2, 0x06 /* Public */,
      15,    1,  254,    2, 0x06 /* Public */,
      16,    1,  257,    2, 0x06 /* Public */,
      17,    1,  260,    2, 0x06 /* Public */,
      19,    1,  263,    2, 0x06 /* Public */,
      21,    0,  266,    2, 0x06 /* Public */,
      22,    1,  267,    2, 0x06 /* Public */,
      23,    0,  270,    2, 0x06 /* Public */,
      24,    0,  271,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      25,    1,  272,    2, 0x0a /* Public */,
      28,    1,  275,    2, 0x0a /* Public */,
      30,    1,  278,    2, 0x0a /* Public */,
      32,    1,  281,    2, 0x0a /* Public */,
      34,    1,  284,    2, 0x0a /* Public */,
      36,    1,  287,    2, 0x0a /* Public */,
      38,    1,  290,    2, 0x0a /* Public */,
      40,    0,  293,    2, 0x0a /* Public */,
      41,    0,  294,    2, 0x0a /* Public */,
      42,    0,  295,    2, 0x0a /* Public */,
      43,    0,  296,    2, 0x0a /* Public */,
      44,    0,  297,    2, 0x0a /* Public */,
      45,    0,  298,    2, 0x0a /* Public */,
      46,    1,  299,    2, 0x0a /* Public */,
      48,    0,  302,    2, 0x0a /* Public */,
      49,    0,  303,    2, 0x0a /* Public */,
      50,    0,  304,    2, 0x0a /* Public */,
      51,    0,  305,    2, 0x0a /* Public */,
      52,    0,  306,    2, 0x0a /* Public */,
      53,    0,  307,    2, 0x0a /* Public */,
      54,    0,  308,    2, 0x0a /* Public */,
      55,    1,  309,    2, 0x0a /* Public */,
      56,    1,  312,    2, 0x0a /* Public */,
      57,    1,  315,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, 0x80000000 | 5,    2,
    QMetaType::Void, 0x80000000 | 7,    2,
    QMetaType::Void, QMetaType::Double,    2,
    QMetaType::Void, QMetaType::Double,    2,
    QMetaType::Void, QMetaType::Double,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Double,    2,
    QMetaType::Void, QMetaType::Double,    2,
    QMetaType::Void, QMetaType::Double,    2,
    QMetaType::Void, 0x80000000 | 18,    2,
    QMetaType::Void, 0x80000000 | 20,    2,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 20,    2,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 26,   27,
    QMetaType::Void, QMetaType::Int,   29,
    QMetaType::Void, QMetaType::Int,   31,
    QMetaType::Void, QMetaType::Int,   33,
    QMetaType::Void, QMetaType::Double,   35,
    QMetaType::Void, QMetaType::Double,   37,
    QMetaType::Void, QMetaType::Double,   39,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 47,   27,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Double,    2,
    QMetaType::Void, QMetaType::Double,    2,
    QMetaType::Void, QMetaType::Double,    2,

       0        // eod
};

void MyGL::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MyGL *_t = static_cast<MyGL *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->send_edges((*reinterpret_cast< QVector<HalfEdge*>(*)>(_a[1]))); break;
        case 1: _t->send_faces((*reinterpret_cast< QVector<Face*>(*)>(_a[1]))); break;
        case 2: _t->send_verts((*reinterpret_cast< QVector<Vertex*>(*)>(_a[1]))); break;
        case 3: _t->send_vert_x_pos((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 4: _t->send_vert_y_pos((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 5: _t->send_vert_z_pos((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 6: _t->send_face_red_col((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->send_face_green_col((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->send_face_blue_col((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->send_joint_x((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 10: _t->send_joint_y((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 11: _t->send_joint_z((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 12: _t->send_mesh((*reinterpret_cast< Mesh(*)>(_a[1]))); break;
        case 13: _t->send_root_joint((*reinterpret_cast< Joint*(*)>(_a[1]))); break;
        case 14: _t->clear_joint_tree(); break;
        case 15: _t->send_joint_info((*reinterpret_cast< Joint*(*)>(_a[1]))); break;
        case 16: _t->clear_joint_info(); break;
        case 17: _t->clear_lists(); break;
        case 18: _t->slot_get_selected_list_item((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 19: _t->slot_update_face_red_col((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 20: _t->slot_update_face_green_col((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 21: _t->slot_update_face_blue_col((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 22: _t->slot_update_vert_x_pos((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 23: _t->slot_update_vert_y_pos((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 24: _t->slot_update_vert_z_pos((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 25: _t->slot_add_midpoint(); break;
        case 26: _t->slot_triangulate_face(); break;
        case 27: _t->slot_extrude_face(); break;
        case 28: _t->slot_subdivide_poly(); break;
        case 29: _t->slot_import_mesh(); break;
        case 30: _t->slot_import_skeleton(); break;
        case 31: _t->slot_get_selected_joint((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1]))); break;
        case 32: _t->slot_simple_skin_mesh(); break;
        case 33: _t->slot_add_rotate_joint_x(); break;
        case 34: _t->slot_sub_rotate_joint_x(); break;
        case 35: _t->slot_add_rotate_joint_y(); break;
        case 36: _t->slot_sub_rotate_joint_y(); break;
        case 37: _t->slot_add_rotate_joint_z(); break;
        case 38: _t->slot_sub_rotate_joint_z(); break;
        case 39: _t->slot_update_joint_x((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 40: _t->slot_update_joint_y((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 41: _t->slot_update_joint_z((*reinterpret_cast< double(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (MyGL::*_t)(QVector<HalfEdge*> );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MyGL::send_edges)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (MyGL::*_t)(QVector<Face*> );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MyGL::send_faces)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (MyGL::*_t)(QVector<Vertex*> );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MyGL::send_verts)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (MyGL::*_t)(double );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MyGL::send_vert_x_pos)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (MyGL::*_t)(double );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MyGL::send_vert_y_pos)) {
                *result = 4;
                return;
            }
        }
        {
            typedef void (MyGL::*_t)(double );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MyGL::send_vert_z_pos)) {
                *result = 5;
                return;
            }
        }
        {
            typedef void (MyGL::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MyGL::send_face_red_col)) {
                *result = 6;
                return;
            }
        }
        {
            typedef void (MyGL::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MyGL::send_face_green_col)) {
                *result = 7;
                return;
            }
        }
        {
            typedef void (MyGL::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MyGL::send_face_blue_col)) {
                *result = 8;
                return;
            }
        }
        {
            typedef void (MyGL::*_t)(double );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MyGL::send_joint_x)) {
                *result = 9;
                return;
            }
        }
        {
            typedef void (MyGL::*_t)(double );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MyGL::send_joint_y)) {
                *result = 10;
                return;
            }
        }
        {
            typedef void (MyGL::*_t)(double );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MyGL::send_joint_z)) {
                *result = 11;
                return;
            }
        }
        {
            typedef void (MyGL::*_t)(Mesh & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MyGL::send_mesh)) {
                *result = 12;
                return;
            }
        }
        {
            typedef void (MyGL::*_t)(Joint * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MyGL::send_root_joint)) {
                *result = 13;
                return;
            }
        }
        {
            typedef void (MyGL::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MyGL::clear_joint_tree)) {
                *result = 14;
                return;
            }
        }
        {
            typedef void (MyGL::*_t)(Joint * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MyGL::send_joint_info)) {
                *result = 15;
                return;
            }
        }
        {
            typedef void (MyGL::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MyGL::clear_joint_info)) {
                *result = 16;
                return;
            }
        }
        {
            typedef void (MyGL::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MyGL::clear_lists)) {
                *result = 17;
                return;
            }
        }
    }
}

const QMetaObject MyGL::staticMetaObject = {
    { &GLWidget277::staticMetaObject, qt_meta_stringdata_MyGL.data,
      qt_meta_data_MyGL,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *MyGL::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MyGL::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MyGL.stringdata0))
        return static_cast<void*>(const_cast< MyGL*>(this));
    return GLWidget277::qt_metacast(_clname);
}

int MyGL::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = GLWidget277::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 42)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 42;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 42)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 42;
    }
    return _id;
}

// SIGNAL 0
void MyGL::send_edges(QVector<HalfEdge*> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MyGL::send_faces(QVector<Face*> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void MyGL::send_verts(QVector<Vertex*> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void MyGL::send_vert_x_pos(double _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void MyGL::send_vert_y_pos(double _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void MyGL::send_vert_z_pos(double _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void MyGL::send_face_red_col(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void MyGL::send_face_green_col(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void MyGL::send_face_blue_col(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void MyGL::send_joint_x(double _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}

// SIGNAL 10
void MyGL::send_joint_y(double _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 10, _a);
}

// SIGNAL 11
void MyGL::send_joint_z(double _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 11, _a);
}

// SIGNAL 12
void MyGL::send_mesh(Mesh & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 12, _a);
}

// SIGNAL 13
void MyGL::send_root_joint(Joint * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 13, _a);
}

// SIGNAL 14
void MyGL::clear_joint_tree()
{
    QMetaObject::activate(this, &staticMetaObject, 14, nullptr);
}

// SIGNAL 15
void MyGL::send_joint_info(Joint * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 15, _a);
}

// SIGNAL 16
void MyGL::clear_joint_info()
{
    QMetaObject::activate(this, &staticMetaObject, 16, nullptr);
}

// SIGNAL 17
void MyGL::clear_lists()
{
    QMetaObject::activate(this, &staticMetaObject, 17, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
