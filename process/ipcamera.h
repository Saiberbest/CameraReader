#ifndef IPCAMERA_H
#define IPCAMERA_H

#include "camera.h"

class IpCamera : public Camera
{
public:
    IpCamera(CameraInfo *cameraInfo);
    ~IpCamera();

private:
    QString videoStreamAdress;
    bool connectToCamera();
};

#endif // IPCAMERA_H
