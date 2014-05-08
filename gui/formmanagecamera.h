#ifndef FORMMANAGECAMERA_H
#define FORMMANAGECAMERA_H

#include <QtWidgets>
#include "data/camerainfo.h"

namespace Ui {
class FormManageCamera;
}

class FormManageCamera : public QWidget
{
    Q_OBJECT

public:
    explicit FormManageCamera(QList<CameraInfo *> *listCameraInfo, QWidget *parent = 0);
    ~FormManageCamera();

private slots:

    void on_listWidget_itemClicked(QListWidgetItem *item);

    void on_pbSave_clicked();

    void on_pbRemove_clicked();

    void on_pbAdd_clicked();

private:
    Ui::FormManageCamera *ui;

    QList<CameraInfo *> *listCameraInfo;

    QList<QCheckBox *> *listCheckBox;

    int currentItem;

    void fillForm();
    void refreschCB();
    void createGCheckBoxLayout();
    QString formatProcessName(QString name);
};

#endif // FORMMANAGECAMERA_H
