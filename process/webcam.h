#ifndef WEBCAM_H
#define WEBCAM_H

#include "camera.h"

class WebCam : public Camera
{
public:
    WebCam(CameraInfo *cameraInfo);

private:
    bool connectToCamera();
};

#endif // WEBCAM_H
