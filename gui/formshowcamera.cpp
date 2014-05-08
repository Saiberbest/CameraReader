#include "formshowcamera.h"
#include "ui_formshowcamera.h"
#include "core/controller.h"

FormShowCamera::FormShowCamera(Controller *controller, int id, QString name, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormShowCamera)
{
    ui->setupUi(this);
    this->controller = controller;
    this->id = id;
    this->name = name;
    ui->lName->setText(this->name);
    ui->cbVertical->setChecked(controller->isCameraFlipVChecked(id));
    ui->cbHorizontal->setChecked(controller->isCameraFlipHChecked(id));
}

FormShowCamera::~FormShowCamera()
{
    delete ui;
}

void FormShowCamera::updateImage(const QPixmap pix)
{
    ui->lImage->setPixmap(pix);
}

void FormShowCamera::setName(QString name)
{
    this->name = name;
    ui->lName->setText(this->name);
}

int FormShowCamera::getHeightImage()
{
    return ui->lImage->height();
}

int FormShowCamera::getWidthImage()
{
    return ui->lImage->width();
}

void FormShowCamera::on_pbPlay_clicked()
{
    this->controller->startCamera(id);
}

void FormShowCamera::on_pbStop_clicked()
{
    this->controller->stopCamera(id);
}

void FormShowCamera::on_cbVertical_toggled(bool checked)
{
    this->controller->flipVerticalOnCamera(id, checked);
}

void FormShowCamera::on_cbHorizontal_toggled(bool checked)
{
    this->controller->flipHorizontalOnCamera(id, checked);
}
