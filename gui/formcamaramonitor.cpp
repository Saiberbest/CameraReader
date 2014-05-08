#include "formcamaramonitor.h"
#include "ui_formcamaramonitor.h"
#include <QtCore/qmath.h>
#include "gui/formshowcamera.h"

FormCamaraMonitor::FormCamaraMonitor(Controller *controller, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormCamaraMonitor)
{
    ui->setupUi(this);
    this->controller = controller;
    setupLayout();
}

FormCamaraMonitor::~FormCamaraMonitor()
{
    delete ui;
}

void FormCamaraMonitor::setupLayout()
{
    controller->prepareCamera();
    controller->prepareProcess();

    QList<FormShowCamera *> *listCameraShow = controller->getListCameraShow();
    int nb = listCameraShow->size();

    int cols = qCeil(qSqrt((qreal)nb));
    int rows = qCeil((qreal)nb / (qreal)cols);

    QGridLayout *layout = ui->gridLayout;
    int count = 0;
    for (int i = 0; i < rows && count < nb; i++)
    {
        for (int j = 0; j < cols && count < nb; j++)
        {
            layout->addWidget(listCameraShow->at(count), i , j);
            count++;
        }
    }
}
