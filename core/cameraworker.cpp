#include "cameraworker.h"

CameraWorker::CameraWorker(Camera *camera, QObject *parent) : Worker(parent)
{
    this->camera = camera;
    keepReading = true;
}

cv::Mat CameraWorker::getImage()
{
    mutexRead.lock();
    cv::Mat img = image;
    mutexRead.unlock();
    return img;
}

void CameraWorker::doWork() {

}
