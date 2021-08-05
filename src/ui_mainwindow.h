/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QWidget>
#include "mygl.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionQuit;
    QAction *actionCamera_Controls;
    QAction *importMeshAction;
    QAction *importSkeletonAction;
    QAction *actionTriangulate_Face;
    QAction *actionExtrude_Face;
    QAction *actionSubdivide_Mesh;
    QAction *actionAdd_Midpoint;
    QAction *actionSkin_Mesh;
    QWidget *centralWidget;
    MyGL *mygl;
    QListWidget *vertexList;
    QListWidget *edgeList;
    QListWidget *faceList;
    QTextEdit *textEdit;
    QTextEdit *textEdit_2;
    QTextEdit *textEdit_3;
    QTextEdit *textEdit_4;
    QTextEdit *textEdit_5;
    QTextEdit *textEdit_6;
    QTextEdit *textEdit_7;
    QTextEdit *textEdit_8;
    QDoubleSpinBox *ySpin;
    QTextEdit *textEdit_9;
    QTextEdit *textEdit_10;
    QDoubleSpinBox *zSpin;
    QTextEdit *textEdit_11;
    QDoubleSpinBox *xSpin;
    QTextEdit *textEdit_12;
    QTextEdit *textEdit_14;
    QTextEdit *textEdit_16;
    QTreeWidget *jointTree;
    QTextEdit *textEdit_17;
    QTextEdit *textEdit_18;
    QPushButton *minusX;
    QPushButton *plusX;
    QPushButton *minusY;
    QTextEdit *textEdit_19;
    QPushButton *plusY;
    QPushButton *minusZ;
    QTextEdit *textEdit_20;
    QPushButton *plusZ;
    QTextEdit *textEdit_21;
    QTextEdit *textEdit_22;
    QTextEdit *jointInfo;
    QTextEdit *textEdit_23;
    QDoubleSpinBox *jointXTranslate;
    QTextEdit *textEdit_25;
    QTextEdit *textEdit_26;
    QDoubleSpinBox *jointYTranslate;
    QTextEdit *textEdit_27;
    QDoubleSpinBox *jointZTranslate;
    QSlider *redFaceColorSlider;
    QSlider *greenFaceColorSlider;
    QSlider *blueFaceColorSlider;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuHelp;
    QMenu *menuImport;
    QMenu *menuMesh_Operators;
    QMenu *menuSkeleton_Operators;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1772, 913);
        actionQuit = new QAction(MainWindow);
        actionQuit->setObjectName(QStringLiteral("actionQuit"));
        actionCamera_Controls = new QAction(MainWindow);
        actionCamera_Controls->setObjectName(QStringLiteral("actionCamera_Controls"));
        importMeshAction = new QAction(MainWindow);
        importMeshAction->setObjectName(QStringLiteral("importMeshAction"));
        importSkeletonAction = new QAction(MainWindow);
        importSkeletonAction->setObjectName(QStringLiteral("importSkeletonAction"));
        actionTriangulate_Face = new QAction(MainWindow);
        actionTriangulate_Face->setObjectName(QStringLiteral("actionTriangulate_Face"));
        actionExtrude_Face = new QAction(MainWindow);
        actionExtrude_Face->setObjectName(QStringLiteral("actionExtrude_Face"));
        actionSubdivide_Mesh = new QAction(MainWindow);
        actionSubdivide_Mesh->setObjectName(QStringLiteral("actionSubdivide_Mesh"));
        actionAdd_Midpoint = new QAction(MainWindow);
        actionAdd_Midpoint->setObjectName(QStringLiteral("actionAdd_Midpoint"));
        actionSkin_Mesh = new QAction(MainWindow);
        actionSkin_Mesh->setObjectName(QStringLiteral("actionSkin_Mesh"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(centralWidget->sizePolicy().hasHeightForWidth());
        centralWidget->setSizePolicy(sizePolicy);
        mygl = new MyGL(centralWidget);
        mygl->setObjectName(QStringLiteral("mygl"));
        mygl->setGeometry(QRect(11, 11, 841, 571));
        vertexList = new QListWidget(centralWidget);
        vertexList->setObjectName(QStringLiteral("vertexList"));
        vertexList->setGeometry(QRect(890, 90, 141, 281));
        edgeList = new QListWidget(centralWidget);
        edgeList->setObjectName(QStringLiteral("edgeList"));
        edgeList->setGeometry(QRect(1040, 90, 141, 281));
        faceList = new QListWidget(centralWidget);
        faceList->setObjectName(QStringLiteral("faceList"));
        faceList->setGeometry(QRect(1190, 90, 141, 281));
        textEdit = new QTextEdit(centralWidget);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(890, 50, 141, 31));
        textEdit_2 = new QTextEdit(centralWidget);
        textEdit_2->setObjectName(QStringLiteral("textEdit_2"));
        textEdit_2->setGeometry(QRect(1040, 50, 141, 31));
        textEdit_3 = new QTextEdit(centralWidget);
        textEdit_3->setObjectName(QStringLiteral("textEdit_3"));
        textEdit_3->setGeometry(QRect(1190, 50, 141, 31));
        textEdit_4 = new QTextEdit(centralWidget);
        textEdit_4->setObjectName(QStringLiteral("textEdit_4"));
        textEdit_4->setGeometry(QRect(1410, 50, 311, 31));
        textEdit_5 = new QTextEdit(centralWidget);
        textEdit_5->setObjectName(QStringLiteral("textEdit_5"));
        textEdit_5->setGeometry(QRect(1410, 220, 311, 31));
        textEdit_6 = new QTextEdit(centralWidget);
        textEdit_6->setObjectName(QStringLiteral("textEdit_6"));
        textEdit_6->setGeometry(QRect(1430, 90, 81, 31));
        textEdit_7 = new QTextEdit(centralWidget);
        textEdit_7->setObjectName(QStringLiteral("textEdit_7"));
        textEdit_7->setGeometry(QRect(1430, 130, 81, 31));
        textEdit_8 = new QTextEdit(centralWidget);
        textEdit_8->setObjectName(QStringLiteral("textEdit_8"));
        textEdit_8->setGeometry(QRect(1430, 170, 81, 31));
        ySpin = new QDoubleSpinBox(centralWidget);
        ySpin->setObjectName(QStringLiteral("ySpin"));
        ySpin->setGeometry(QRect(1550, 300, 121, 31));
        ySpin->setDecimals(4);
        ySpin->setMinimum(-99);
        ySpin->setSingleStep(0.5);
        textEdit_9 = new QTextEdit(centralWidget);
        textEdit_9->setObjectName(QStringLiteral("textEdit_9"));
        textEdit_9->setGeometry(QRect(1460, 300, 81, 31));
        textEdit_10 = new QTextEdit(centralWidget);
        textEdit_10->setObjectName(QStringLiteral("textEdit_10"));
        textEdit_10->setGeometry(QRect(1460, 260, 81, 31));
        zSpin = new QDoubleSpinBox(centralWidget);
        zSpin->setObjectName(QStringLiteral("zSpin"));
        zSpin->setGeometry(QRect(1550, 340, 121, 31));
        zSpin->setDecimals(4);
        zSpin->setMinimum(-99);
        zSpin->setSingleStep(0.5);
        textEdit_11 = new QTextEdit(centralWidget);
        textEdit_11->setObjectName(QStringLiteral("textEdit_11"));
        textEdit_11->setGeometry(QRect(1460, 340, 81, 31));
        xSpin = new QDoubleSpinBox(centralWidget);
        xSpin->setObjectName(QStringLiteral("xSpin"));
        xSpin->setGeometry(QRect(1550, 260, 121, 31));
        xSpin->setDecimals(4);
        xSpin->setMinimum(-99);
        xSpin->setSingleStep(0.5);
        textEdit_12 = new QTextEdit(centralWidget);
        textEdit_12->setObjectName(QStringLiteral("textEdit_12"));
        textEdit_12->setGeometry(QRect(890, 10, 441, 31));
        textEdit_14 = new QTextEdit(centralWidget);
        textEdit_14->setObjectName(QStringLiteral("textEdit_14"));
        textEdit_14->setGeometry(QRect(1400, 10, 331, 31));
        textEdit_16 = new QTextEdit(centralWidget);
        textEdit_16->setObjectName(QStringLiteral("textEdit_16"));
        textEdit_16->setGeometry(QRect(890, 410, 441, 31));
        jointTree = new QTreeWidget(centralWidget);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QStringLiteral("1"));
        jointTree->setHeaderItem(__qtreewidgetitem);
        jointTree->setObjectName(QStringLiteral("jointTree"));
        jointTree->setGeometry(QRect(890, 460, 441, 391));
        textEdit_17 = new QTextEdit(centralWidget);
        textEdit_17->setObjectName(QStringLiteral("textEdit_17"));
        textEdit_17->setGeometry(QRect(1400, 410, 331, 31));
        textEdit_18 = new QTextEdit(centralWidget);
        textEdit_18->setObjectName(QStringLiteral("textEdit_18"));
        textEdit_18->setGeometry(QRect(1470, 500, 51, 31));
        minusX = new QPushButton(centralWidget);
        minusX->setObjectName(QStringLiteral("minusX"));
        minusX->setGeometry(QRect(1420, 500, 41, 31));
        plusX = new QPushButton(centralWidget);
        plusX->setObjectName(QStringLiteral("plusX"));
        plusX->setGeometry(QRect(1530, 500, 41, 31));
        minusY = new QPushButton(centralWidget);
        minusY->setObjectName(QStringLiteral("minusY"));
        minusY->setGeometry(QRect(1420, 540, 41, 31));
        textEdit_19 = new QTextEdit(centralWidget);
        textEdit_19->setObjectName(QStringLiteral("textEdit_19"));
        textEdit_19->setGeometry(QRect(1470, 540, 51, 31));
        plusY = new QPushButton(centralWidget);
        plusY->setObjectName(QStringLiteral("plusY"));
        plusY->setGeometry(QRect(1530, 540, 41, 31));
        minusZ = new QPushButton(centralWidget);
        minusZ->setObjectName(QStringLiteral("minusZ"));
        minusZ->setGeometry(QRect(1420, 580, 41, 31));
        textEdit_20 = new QTextEdit(centralWidget);
        textEdit_20->setObjectName(QStringLiteral("textEdit_20"));
        textEdit_20->setGeometry(QRect(1470, 580, 51, 31));
        plusZ = new QPushButton(centralWidget);
        plusZ->setObjectName(QStringLiteral("plusZ"));
        plusZ->setGeometry(QRect(1530, 580, 41, 31));
        textEdit_21 = new QTextEdit(centralWidget);
        textEdit_21->setObjectName(QStringLiteral("textEdit_21"));
        textEdit_21->setGeometry(QRect(1410, 460, 171, 31));
        textEdit_22 = new QTextEdit(centralWidget);
        textEdit_22->setObjectName(QStringLiteral("textEdit_22"));
        textEdit_22->setGeometry(QRect(1400, 630, 331, 31));
        jointInfo = new QTextEdit(centralWidget);
        jointInfo->setObjectName(QStringLiteral("jointInfo"));
        jointInfo->setGeometry(QRect(1410, 670, 311, 181));
        textEdit_23 = new QTextEdit(centralWidget);
        textEdit_23->setObjectName(QStringLiteral("textEdit_23"));
        textEdit_23->setGeometry(QRect(1590, 460, 131, 31));
        jointXTranslate = new QDoubleSpinBox(centralWidget);
        jointXTranslate->setObjectName(QStringLiteral("jointXTranslate"));
        jointXTranslate->setGeometry(QRect(1690, 500, 62, 31));
        jointXTranslate->setMinimum(-99.99);
        jointXTranslate->setSingleStep(0.2);
        textEdit_25 = new QTextEdit(centralWidget);
        textEdit_25->setObjectName(QStringLiteral("textEdit_25"));
        textEdit_25->setGeometry(QRect(1600, 500, 41, 31));
        textEdit_26 = new QTextEdit(centralWidget);
        textEdit_26->setObjectName(QStringLiteral("textEdit_26"));
        textEdit_26->setGeometry(QRect(1600, 540, 41, 31));
        jointYTranslate = new QDoubleSpinBox(centralWidget);
        jointYTranslate->setObjectName(QStringLiteral("jointYTranslate"));
        jointYTranslate->setGeometry(QRect(1690, 540, 62, 31));
        jointYTranslate->setMinimum(-99.99);
        jointYTranslate->setSingleStep(0.2);
        textEdit_27 = new QTextEdit(centralWidget);
        textEdit_27->setObjectName(QStringLiteral("textEdit_27"));
        textEdit_27->setGeometry(QRect(1600, 580, 41, 31));
        jointZTranslate = new QDoubleSpinBox(centralWidget);
        jointZTranslate->setObjectName(QStringLiteral("jointZTranslate"));
        jointZTranslate->setGeometry(QRect(1690, 580, 62, 31));
        jointZTranslate->setMinimum(-99.99);
        jointZTranslate->setSingleStep(0.2);
        redFaceColorSlider = new QSlider(centralWidget);
        redFaceColorSlider->setObjectName(QStringLiteral("redFaceColorSlider"));
        redFaceColorSlider->setGeometry(QRect(1540, 100, 160, 16));
        redFaceColorSlider->setStyleSheet(QLatin1String("QSlider::groove:horizontal {\n"
"    border: 1px solid #999999;\n"
"    height: 8px; /* the groove expands to the size of the slider by default. by giving it a height, it has a fixed size */\n"
"    background: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(0, 0, 0, 255), stop:1 rgba(255, 0, 0, 255));\n"
"    margin: 2px 0;\n"
"}\n"
"\n"
"QSlider::handle:horizontal {\n"
"    background: qlineargradient(x1:0, y1:0, x2:1, y2:1, stop:0 #b4b4b4, stop:1 #8f8f8f);\n"
"    border: 1px solid #5c5c5c;\n"
"    width: 18px;\n"
"    margin: -2px 0; /* handle is placed by default on the contents rect of the groove. Expand outside the groove */\n"
"    border-radius: 3px;\n"
"}"));
        redFaceColorSlider->setMaximum(255);
        redFaceColorSlider->setOrientation(Qt::Horizontal);
        greenFaceColorSlider = new QSlider(centralWidget);
        greenFaceColorSlider->setObjectName(QStringLiteral("greenFaceColorSlider"));
        greenFaceColorSlider->setGeometry(QRect(1540, 140, 160, 16));
        greenFaceColorSlider->setStyleSheet(QLatin1String("QSlider::groove:horizontal {\n"
"    border: 1px solid #999999;\n"
"    height: 8px; /* the groove expands to the size of the slider by default. by giving it a height, it has a fixed size */\n"
"    background: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(0, 0, 0, 255), stop:1 rgba(0, 255, 0, 255));\n"
"    margin: 2px 0;\n"
"}\n"
"\n"
"QSlider::handle:horizontal {\n"
"    background: qlineargradient(x1:0, y1:0, x2:1, y2:1, stop:0 #b4b4b4, stop:1 #8f8f8f);\n"
"    border: 1px solid #5c5c5c;\n"
"    width: 18px;\n"
"    margin: -2px 0; /* handle is placed by default on the contents rect of the groove. Expand outside the groove */\n"
"    border-radius: 3px;\n"
"}"));
        greenFaceColorSlider->setMaximum(255);
        greenFaceColorSlider->setOrientation(Qt::Horizontal);
        blueFaceColorSlider = new QSlider(centralWidget);
        blueFaceColorSlider->setObjectName(QStringLiteral("blueFaceColorSlider"));
        blueFaceColorSlider->setGeometry(QRect(1540, 180, 160, 16));
        blueFaceColorSlider->setStyleSheet(QLatin1String("QSlider::groove:horizontal {\n"
"    border: 1px solid #999999;\n"
"    height: 8px; /* the groove expands to the size of the slider by default. by giving it a height, it has a fixed size */\n"
"    background: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(0, 0, 0, 255), stop:1 rgba(0, 0, 255, 255));\n"
"    margin: 2px 0;\n"
"}\n"
"\n"
"QSlider::handle:horizontal {\n"
"    background: qlineargradient(x1:0, y1:0, x2:1, y2:1, stop:0 #b4b4b4, stop:1 #8f8f8f);\n"
"    border: 1px solid #5c5c5c;\n"
"    width: 18px;\n"
"    margin: -2px 0; /* handle is placed by default on the contents rect of the groove. Expand outside the groove */\n"
"    border-radius: 3px;\n"
"}"));
        blueFaceColorSlider->setMaximum(255);
        blueFaceColorSlider->setOrientation(Qt::Horizontal);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1772, 20));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QStringLiteral("menuHelp"));
        menuImport = new QMenu(menuBar);
        menuImport->setObjectName(QStringLiteral("menuImport"));
        menuMesh_Operators = new QMenu(menuBar);
        menuMesh_Operators->setObjectName(QStringLiteral("menuMesh_Operators"));
        menuSkeleton_Operators = new QMenu(menuBar);
        menuSkeleton_Operators->setObjectName(QStringLiteral("menuSkeleton_Operators"));
        MainWindow->setMenuBar(menuBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuImport->menuAction());
        menuBar->addAction(menuMesh_Operators->menuAction());
        menuBar->addAction(menuSkeleton_Operators->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuFile->addAction(actionQuit);
        menuHelp->addAction(actionCamera_Controls);
        menuImport->addAction(importMeshAction);
        menuImport->addAction(importSkeletonAction);
        menuMesh_Operators->addAction(actionSubdivide_Mesh);
        menuMesh_Operators->addSeparator();
        menuMesh_Operators->addAction(actionTriangulate_Face);
        menuMesh_Operators->addAction(actionExtrude_Face);
        menuMesh_Operators->addSeparator();
        menuMesh_Operators->addAction(actionAdd_Midpoint);
        menuSkeleton_Operators->addAction(actionSkin_Mesh);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Mini Maya", Q_NULLPTR));
        actionQuit->setText(QApplication::translate("MainWindow", "Quit", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        actionQuit->setShortcut(QApplication::translate("MainWindow", "Ctrl+Q", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        actionCamera_Controls->setText(QApplication::translate("MainWindow", "Camera Controls", Q_NULLPTR));
        importMeshAction->setText(QApplication::translate("MainWindow", "Import Mesh", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        importMeshAction->setShortcut(QApplication::translate("MainWindow", "Ctrl+M", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        importSkeletonAction->setText(QApplication::translate("MainWindow", "Import Skeleton", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        importSkeletonAction->setShortcut(QApplication::translate("MainWindow", "Ctrl+K", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        actionTriangulate_Face->setText(QApplication::translate("MainWindow", "Triangulate Face", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        actionTriangulate_Face->setShortcut(QApplication::translate("MainWindow", "Ctrl+F", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        actionExtrude_Face->setText(QApplication::translate("MainWindow", "Extrude Face", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        actionExtrude_Face->setShortcut(QApplication::translate("MainWindow", "Ctrl+E", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        actionSubdivide_Mesh->setText(QApplication::translate("MainWindow", "Subdivide Mesh", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        actionSubdivide_Mesh->setShortcut(QApplication::translate("MainWindow", "Ctrl+D", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        actionAdd_Midpoint->setText(QApplication::translate("MainWindow", "Add Midpoint", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        actionAdd_Midpoint->setShortcut(QApplication::translate("MainWindow", "Ctrl+P", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        actionSkin_Mesh->setText(QApplication::translate("MainWindow", "Skin Mesh", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        actionSkin_Mesh->setShortcut(QApplication::translate("MainWindow", "Ctrl+S", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        textEdit->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; text-decoration: underline;\">Vertices</span></p></body></html>", Q_NULLPTR));
        textEdit_2->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; text-decoration: underline;\">HalfEdges</span></p></body></html>", Q_NULLPTR));
        textEdit_3->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; text-decoration: underline;\">Faces</span></p></body></html>", Q_NULLPTR));
        textEdit_4->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; text-decoration: underline;\">Modify Selected Face Color</span></p></body></html>", Q_NULLPTR));
        textEdit_5->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; text-decoration: underline;\">Modify Selected Vertex Position</span></p></body></html>", Q_NULLPTR));
        textEdit_6->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:600;\">R</span></p></body></html>", Q_NULLPTR));
        textEdit_7->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:600;\">G</span></p></body></html>", Q_NULLPTR));
        textEdit_8->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:600;\">B</span></p></body></html>", Q_NULLPTR));
        textEdit_9->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:600;\">Y</span></p></body></html>", Q_NULLPTR));
        textEdit_10->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:600;\">X</span></p></body></html>", Q_NULLPTR));
        textEdit_11->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:600;\">Z</span></p></body></html>", Q_NULLPTR));
        textEdit_12->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:600; text-decoration: underline;\">MESH DATA</span></p></body></html>", Q_NULLPTR));
        textEdit_14->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:600; text-decoration: underline;\">MESH COMP. MODIFIERS</span></p></body></html>", Q_NULLPTR));
        textEdit_16->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:600; text-decoration: underline;\">JOINTS of SKELETON</span></p></body></html>", Q_NULLPTR));
        textEdit_17->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:600; text-decoration: underline;\">JOINT MODIFIERS</span></p></body></html>", Q_NULLPTR));
        textEdit_18->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:600;\">X</span></p></body></html>", Q_NULLPTR));
        minusX->setText(QApplication::translate("MainWindow", "-", Q_NULLPTR));
        plusX->setText(QApplication::translate("MainWindow", "+", Q_NULLPTR));
        minusY->setText(QApplication::translate("MainWindow", "-", Q_NULLPTR));
        textEdit_19->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:600;\">Y</span></p></body></html>", Q_NULLPTR));
        plusY->setText(QApplication::translate("MainWindow", "+", Q_NULLPTR));
        minusZ->setText(QApplication::translate("MainWindow", "-", Q_NULLPTR));
        textEdit_20->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:600;\">Z</span></p></body></html>", Q_NULLPTR));
        plusZ->setText(QApplication::translate("MainWindow", "+", Q_NULLPTR));
        textEdit_21->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; text-decoration: underline;\">Rotate Joint about Axis</span></p></body></html>", Q_NULLPTR));
        textEdit_22->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:600; text-decoration: underline;\">JOINT INFO</span></p></body></html>", Q_NULLPTR));
        textEdit_23->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" text-decoration: underline;\">Translate Joint</span></p></body></html>", Q_NULLPTR));
        textEdit_25->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:600;\">X</span></p></body></html>", Q_NULLPTR));
        textEdit_26->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:600;\">Y</span></p></body></html>", Q_NULLPTR));
        textEdit_27->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:600;\">Z</span></p></body></html>", Q_NULLPTR));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", Q_NULLPTR));
        menuHelp->setTitle(QApplication::translate("MainWindow", "Help", Q_NULLPTR));
        menuImport->setTitle(QApplication::translate("MainWindow", "Import", Q_NULLPTR));
        menuMesh_Operators->setTitle(QApplication::translate("MainWindow", "Mesh Operators", Q_NULLPTR));
        menuSkeleton_Operators->setTitle(QApplication::translate("MainWindow", "Skeleton Operators", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
