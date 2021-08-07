#ifndef JOINTINFODISPLAY_H
#define JOINTINFODISPLAY_H

#include <QWidget>

namespace Ui {
class JointInfoDisplay;
}

class JointInfoDisplay : public QWidget {
    Q_OBJECT

public:
    explicit JointInfoDisplay(QWidget *parent = 0);
    ~JointInfoDisplay();

public slots:
    void slot_setPosText(QString);
    void slot_setAxisText(QString);
    void slot_setDegText(QString);
    void slot_setJointIDText(QString);
    void slot_setJointNameText(QString);

private:
    Ui::JointInfoDisplay *ui;
};

#endif // JOINTINFODISPLAY_H
