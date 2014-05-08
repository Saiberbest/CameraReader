#ifndef CAMERAWORKER_H
#define CAMERAWORKER_H

#include "worker.h"
#include "process/camera.h"

class CameraWorker : public Worker
{
public:
    CameraWorker(Camera *camera, QObject *parent = 0);

    cv::Mat getImage();
public slots:
    void doWork();

private:
    Camera *camera;
    // other stuff
    bool keepReading;

    QMutex mutexRead;
    // opencv stuff
    cv::Mat image;
};

#endif // CAMERAWORKER_H
