#ifndef CAMERAFACTORY_H
#define CAMERAFACTORY_H

#include "process/camera.h"
#include "data/camerainfo.h"
#include "gui/formshowcamera.h"

class CameraFactory
{
public:
    CameraFactory(Controller *controller);

    void createCamera();
    void createProcess();
    void setCameraInfo(QList<CameraInfo *> *listCameraInfo);
    QList<Camera *> *getCameras();
    QList<FormShowCamera *> *getListShowCamera();

private:
    Controller *controller;
    QList<Camera *> *listCamera;
    QList<CameraInfo *> *listCameraInfo;
    QList<FormShowCamera *> *listShowCamera;
};

#endif // CAMERAFACTORY_H
