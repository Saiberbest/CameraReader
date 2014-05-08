#include "formpreferences.h"
#include "ui_formpreferences.h"

#include <QFileDialog>
#include <QDebug>

FormPreferences::FormPreferences(Preferences *pref, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormPreferences)
{
    ui->setupUi(this);
    this->pref = pref;
    fillForm();
}

FormPreferences::~FormPreferences()
{
    delete ui;
}

void FormPreferences::on_pbBrowse_clicked()
{
    QFileDialog dialog;
    dialog.setFileMode(QFileDialog::Directory);
    dialog.setOption(QFileDialog::ShowDirsOnly);

    int result = dialog.exec();
    if (result)
    {
        pref->setPathURL(dialog.selectedFiles()[0]);
        qDebug()<<pref->getPathURL();
        ui->leDirPath->setText(pref->getPathURL());
    }
}

void FormPreferences::fillForm()
{
     ui->leDirPath->setText(pref->getPathURL());
}

void FormPreferences::on_pbSave_clicked()
{
    pref->setPathURL(ui->leDirPath->text());
}
