#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "data/camerainfo.h"
#include "data/preferences.h"
#include "process/camera.h"
#include "core/camerafactory.h"

class Controller
{
public:
    Controller();
    ~Controller();
    void setCameraInfo(QList<CameraInfo *> *listCameraInfo);
    void setPreferences(Preferences *pref);

    QList<Camera *> *getCameras();
    QList<CameraInfo *> *getCameraInfo();
    Preferences *getPreferences();
    QList<FormShowCamera *> *getListCameraShow();

    bool isCameraFlipVChecked(int id);
    bool isCameraFlipHChecked(int id);

    int prepareCamera();
    void startCamera(int id);
    void stopCamera(int id);

    void flipHorizontalOnCamera(int id, bool flip);
    void flipVerticalOnCamera(int id, bool flip);

    void prepareProcess();
private:
    Preferences *pref;
    QList<CameraInfo *> *listCameraInfo;
    QList<Camera *> *listCamera;
    CameraFactory *camFactory;

};

#endif // CONTROLLER_H
