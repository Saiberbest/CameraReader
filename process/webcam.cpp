#include "webcam.h"
#include <QDebug>

WebCam::WebCam(CameraInfo *cameraInfo) : Camera(cameraInfo)
{
}

bool WebCam::connectToCamera()
{
    if(!vcap.open(0)) {
        std::cout << "Error opening video stream or file" << std::endl;
        return false;
    }
    return true;
}
