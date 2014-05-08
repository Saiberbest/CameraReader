#include "formmanagecamera.h"
#include "ui_formmanagecamera.h"

#include "data/camerainfo.h"

#include <QDebug>
#include <QMetaEnum>

FormManageCamera::FormManageCamera(QList<CameraInfo *> *listCameraInfo, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormManageCamera)
{
    ui->setupUi(this);
    this->listCameraInfo = listCameraInfo;
    listCheckBox = new QList<QCheckBox *>();
    fillForm();
    createGCheckBoxLayout();
    currentItem = -1;
}

FormManageCamera::~FormManageCamera()
{
    delete ui;
}

void FormManageCamera::fillForm()
{
    const QMetaObject & mo = CameraInfo::staticMetaObject;
    int i =0;
    QMetaEnum en;
    while((en = mo.enumerator(i++)).isValid()) {
        for(int j = 0; j < en.keyCount(); j++)
        {
            ui->cbType->addItem(en.valueToKey(j));
        }
    }
    refreschCB();
}

void FormManageCamera::refreschCB()
{
    ui->listWidget->clear();
    for(int i = 0; i < listCameraInfo->size(); i++)
    {
        ui->listWidget->addItem(listCameraInfo->at(i)->getName());
    }
}

void FormManageCamera::createGCheckBoxLayout()
{
    QVBoxLayout *vbox = new QVBoxLayout(ui->groupBox);

    const QMetaObject & mo = Process::staticMetaObject;
    int i =0;
    QMetaEnum en;
    while((en = mo.enumerator(i++)).isValid()) {
        for(int j = 0; j < en.keyCount(); j++)
        {
            QString name = en.valueToKey(j);
            QCheckBox *chBox = new QCheckBox(formatProcessName(name), this);
            vbox->addWidget(chBox);
        }
    }
    ui->groupBox->setLayout(vbox);
}

QString FormManageCamera::formatProcessName(QString name)
{
    name = name.replace("_", " ");
    name = name.toLower();
    name[0] = name[0].toUpper();
    return name;
}

void FormManageCamera::on_listWidget_itemClicked(QListWidgetItem *item)
{
    currentItem = ui->listWidget->currentRow();
    ui->leName->setText(listCameraInfo->at(currentItem)->getName());
    ui->leURL->setText(listCameraInfo->at(currentItem)->getUrl());
    ui->leLogin->setText(listCameraInfo->at(currentItem)->getLogin());
    ui->lePassword->setText(listCameraInfo->at(currentItem)->getPassword());
    ui->cbType->setCurrentIndex((int)listCameraInfo->at(currentItem)->getType());
    ui->cbFlipH->setChecked(listCameraInfo->at(currentItem)->getFlipHorizontal());
    ui->cbFlipV->setChecked(listCameraInfo->at(currentItem)->getFlipVertical());
}

void FormManageCamera::on_pbSave_clicked()
{
    if (currentItem == -1)
        return;
    listCameraInfo->at(currentItem)->setName(ui->leName->text());
    listCameraInfo->at(currentItem)->setLogin(ui->leLogin->text());
    listCameraInfo->at(currentItem)->setPassword(ui->lePassword->text());
    listCameraInfo->at(currentItem)->setUrl(ui->leURL->text());
    listCameraInfo->at(currentItem)->setType((CameraInfo::CameraType)ui->cbType->currentIndex());
    listCameraInfo->at(currentItem)->setFlipHorizontal(ui->cbFlipH->isChecked());
    listCameraInfo->at(currentItem)->setFlipVertical(ui->cbFlipV->isChecked());
    Process::ProcesType process;
    for (int i = 0 ; i < listCheckBox->size(); i++)
    {
        bool checked = listCheckBox->at(i)->isChecked();
        if (checked)
        {
            process = static_cast<Process::ProcesType>(i);
            //listCameraInfo->at(currentItem)->
        }
    }
    refreschCB();
}

void FormManageCamera::on_pbRemove_clicked()
{
    if (currentItem == -1)
        return;
    listCameraInfo->removeAt(currentItem);
    currentItem = -1;
    refreschCB();
    ui->leName->setText("");
    ui->leLogin->setText("");
    ui->lePassword->setText("");
    ui->leURL->setText("");
    ui->cbType->setCurrentIndex(0);
}

void FormManageCamera::on_pbAdd_clicked()
{
    CameraInfo *camInfo = new CameraInfo(CameraInfo::IP,"Name", "URL", "login", "password");
    listCameraInfo->append(camInfo);
    refreschCB();
    ui->listWidget->setCurrentRow(ui->listWidget->count() - 1);
    on_listWidget_itemClicked(ui->listWidget->item(ui->listWidget->count() - 1));
}
