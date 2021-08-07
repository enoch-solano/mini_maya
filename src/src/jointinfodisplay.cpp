#include "jointinfodisplay.h"
#include "ui_jointinfodisplay.h"

JointInfoDisplay::JointInfoDisplay(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::JointInfoDisplay)
{
    ui->setupUi(this);
}

JointInfoDisplay::~JointInfoDisplay()
{
    delete ui;
}

void JointInfoDisplay::slot_setPosText(QString s) {
    ui->posLabel->setText(s);
}

void JointInfoDisplay::slot_setAxisText(QString s) {
    ui->aorLabel->setText(s);
}

void JointInfoDisplay::slot_setDegText(QString s) {
    ui->degLabel->setText(s);
}

void JointInfoDisplay::slot_setJointIDText(QString s) {
    ui->jointIDLabel->setText(s);
}

void JointInfoDisplay::slot_setJointNameText(QString s) {
    ui->jointNameLabel->setText(s);
}
