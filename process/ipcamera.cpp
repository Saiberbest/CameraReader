#include "ipcamera.h"

IpCamera::IpCamera(CameraInfo *cameraInfo) : Camera(cameraInfo)
{
    QString login = cameraInfo->getLogin() + ":" + cameraInfo->getPassword();
    int index = cameraInfo->getUrl().indexOf("//");

    QString beginnig = cameraInfo->getUrl().right(index - 1);
    QString ending = cameraInfo->getUrl().left(index - 1);

    videoStreamAdress = beginnig + login + ending;
}

IpCamera::~IpCamera()
{
}

bool IpCamera::connectToCamera()
{
    if(!vcap.open(this->videoStreamAdress.toStdString())) {
        std::cout << "Error opening video stream or file" << std::endl;
        return false;
    }
    return true;
}
