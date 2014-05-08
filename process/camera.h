#ifndef CAMERA_H
#define CAMERA_H
#include <QThread>
#include <opencv2/opencv.hpp>
#include "data/camerainfo.h"
#include "process/process.h"

class Camera : public QThread
{
    Q_OBJECT
public:
    Camera(CameraInfo *cameraInfo, QObject *parent=0);
    ~Camera();

    void startReading();
    void stopReading();

    void addProcess(Process *process);

    cv::Mat getImage();

    void setFlipHorizontal(bool flip);
    void setFlipVertical(bool flip);

    double getFPS();
    cv::Size getVideoSize();
    int getCodec();
signals:
    void imgReady();

protected:
    // opencv stuff
    cv::VideoCapture vcap;
    CameraInfo *cameraInfo;

    // opencv stuff
    cv::Mat image;

    void run();
private:
    QMutex mutexRead;
    // other stuff
    bool keepReading;

    bool flipHorizontal;
    bool flipVertical;

    bool first;

    double fps;
    cv::Size size;
    int codec;

    QList<Process *> *listProcess;

    void readCamera();

    void tellProcess();

    virtual bool connectToCamera() = 0;
};

#endif // CAMERA_H
