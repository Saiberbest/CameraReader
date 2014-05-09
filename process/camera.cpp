#include "camera.h"
#include <QDebug>

Camera::Camera(CameraInfo *cameraInfo, QObject *parent) : QThread(parent)
{
    this->cameraInfo = cameraInfo;
    keepReading = false;
    flipHorizontal = cameraInfo->getFlipHorizontal();
    flipVertical = cameraInfo->getFlipVertical();
    listProcess = new QList<Process *>();
    first = true;
}

Camera::~Camera()
{
    stopReading();
    vcap.release();
}

void Camera::startReading()
{
    if (!keepReading && connectToCamera())
    {
        keepReading = true;
        start();
    }
}

void Camera::stopReading()
{
    if (keepReading)
    {
        keepReading = false;
    }
}

void Camera::addProcess(Process *process)
{
    listProcess->append(process);
}

cv::Mat Camera::getImage()
{
    mutexRead.lock();
    cv::Mat img = image;
    mutexRead.unlock();
    return img;
}

void Camera::setFlipHorizontal(bool flip)
{
    this->flipHorizontal = flip;
}

void Camera::setFlipVertical(bool flip)
{
    this->flipVertical = flip;
}

double Camera::getFPS()
{
    return this->fps;
}

cv::Size Camera::getVideoSize()
{
    return this->size;
}

int Camera::getCodec()
{
    return this->codec;
}

void Camera::run()
{
    readCamera();
}

void Camera::readCamera()
{
    while(vcap.grab() && keepReading) {
        mutexRead.lock();
        vcap >> image;
        mutexRead.unlock();
        if (image.data)
        {
            /*if (first)
            {
                size = cv::Size((int) vcap.get(CV_CAP_PROP_FRAME_WIDTH),    // Acquire input size
                                (int) vcap.get(CV_CAP_PROP_FRAME_HEIGHT));
                codec = static_cast<int>(vcap.get(CV_CAP_PROP_FOURCC));
                fps = vcap.get(CV_CAP_PROP_FPS);
                first = false;
            }*/
            cv::Mat tmp = image;
            if (flipHorizontal && flipVertical)
            {
                cv::flip(image,tmp, -1);
            }
            else if (flipHorizontal)
            {
                cv::flip(image,tmp, 0);
            }
            else if (flipVertical)
            {
                cv::flip(image,tmp, 1);
            }
            image = tmp;
            tmp.release();

            tellProcess();
            emit imgReady();
        }
    }
    vcap.release();
}

void Camera::tellProcess()
{
    for(int i = 0 ; i < listProcess->size(); i++)
    {
        listProcess->at(i)->addImage(image);
    }

}
