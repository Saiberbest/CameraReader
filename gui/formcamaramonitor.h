#ifndef FORMCAMARAMONITOR_H
#define FORMCAMARAMONITOR_H

#include <QWidget>
#include "core/controller.h"
#include "gui/formshowcamera.h"

namespace Ui {
class FormCamaraMonitor;
}

class FormCamaraMonitor : public QWidget
{
    Q_OBJECT

public:
    explicit FormCamaraMonitor(Controller *controller, QWidget *parent = 0);
    ~FormCamaraMonitor();

private slots:
    void on_pbPlay_clicked();

    void on_pbStop_clicked();

private:
    Ui::FormCamaraMonitor *ui;
    Controller *controller;

    void setupLayout();
};

#endif // FORMCAMARAMONITOR_H
