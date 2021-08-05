/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QVector>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[18];
    char stringdata0[286];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 23), // "on_actionQuit_triggered"
QT_MOC_LITERAL(2, 35, 0), // ""
QT_MOC_LITERAL(3, 36, 34), // "on_actionCamera_Controls_trig..."
QT_MOC_LITERAL(4, 71, 14), // "slot_add_edges"
QT_MOC_LITERAL(5, 86, 18), // "QVector<HalfEdge*>"
QT_MOC_LITERAL(6, 105, 14), // "slot_add_faces"
QT_MOC_LITERAL(7, 120, 14), // "QVector<Face*>"
QT_MOC_LITERAL(8, 135, 14), // "slot_add_verts"
QT_MOC_LITERAL(9, 150, 16), // "QVector<Vertex*>"
QT_MOC_LITERAL(10, 167, 16), // "slot_clear_lists"
QT_MOC_LITERAL(11, 184, 19), // "slot_add_root_joint"
QT_MOC_LITERAL(12, 204, 6), // "Joint*"
QT_MOC_LITERAL(13, 211, 4), // "root"
QT_MOC_LITERAL(14, 216, 21), // "slot_clear_joint_tree"
QT_MOC_LITERAL(15, 238, 19), // "slot_add_joint_info"
QT_MOC_LITERAL(16, 258, 5), // "joint"
QT_MOC_LITERAL(17, 264, 21) // "slot_clear_joint_info"

    },
    "MainWindow\0on_actionQuit_triggered\0\0"
    "on_actionCamera_Controls_triggered\0"
    "slot_add_edges\0QVector<HalfEdge*>\0"
    "slot_add_faces\0QVector<Face*>\0"
    "slot_add_verts\0QVector<Vertex*>\0"
    "slot_clear_lists\0slot_add_root_joint\0"
    "Joint*\0root\0slot_clear_joint_tree\0"
    "slot_add_joint_info\0joint\0"
    "slot_clear_joint_info"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   64,    2, 0x08 /* Private */,
       3,    0,   65,    2, 0x08 /* Private */,
       4,    1,   66,    2, 0x0a /* Public */,
       6,    1,   69,    2, 0x0a /* Public */,
       8,    1,   72,    2, 0x0a /* Public */,
      10,    0,   75,    2, 0x0a /* Public */,
      11,    1,   76,    2, 0x0a /* Public */,
      14,    0,   79,    2, 0x0a /* Public */,
      15,    1,   80,    2, 0x0a /* Public */,
      17,    0,   83,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 5,    2,
    QMetaType::Void, 0x80000000 | 7,    2,
    QMetaType::Void, 0x80000000 | 9,    2,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 12,   13,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 12,   16,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_actionQuit_triggered(); break;
        case 1: _t->on_actionCamera_Controls_triggered(); break;
        case 2: _t->slot_add_edges((*reinterpret_cast< QVector<HalfEdge*>(*)>(_a[1]))); break;
        case 3: _t->slot_add_faces((*reinterpret_cast< QVector<Face*>(*)>(_a[1]))); break;
        case 4: _t->slot_add_verts((*reinterpret_cast< QVector<Vertex*>(*)>(_a[1]))); break;
        case 5: _t->slot_clear_lists(); break;
        case 6: _t->slot_add_root_joint((*reinterpret_cast< Joint*(*)>(_a[1]))); break;
        case 7: _t->slot_clear_joint_tree(); break;
        case 8: _t->slot_add_joint_info((*reinterpret_cast< Joint*(*)>(_a[1]))); break;
        case 9: _t->slot_clear_joint_info(); break;
        default: ;
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
