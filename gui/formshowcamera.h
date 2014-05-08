#ifndef FORMSHOWCAMERA_H
#define FORMSHOWCAMERA_H

#include <QWidget>
#include "process/process.h"

class Controller;

namespace Ui {
class FormShowCamera;
}

class FormShowCamera : public QWidget
{
    Q_OBJECT
public:
    explicit FormShowCamera(Controller *controller, int id, QString name, QWidget *parent = 0);
    ~FormShowCamera();

    void updateImage(const QPixmap pix);
    void setName(QString name);
    int getHeightImage();
    int getWidthImage();
private slots:
    void on_pbPlay_clicked();

    void on_pbStop_clicked();

    void on_cbVertical_toggled(bool checked);

    void on_cbHorizontal_toggled(bool checked);

private:
    Ui::FormShowCamera *ui;
    int id;
    Controller *controller;
    QString name;
    void process();
};

#endif // FORMSHOWCAMERA_H
