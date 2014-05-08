#ifndef PROCESS_H
#define PROCESS_H

#include <QObject>
#include "opencv2/opencv.hpp"

class Process : public QObject
{
    Q_OBJECT
    Q_ENUMS(ProcesType)
public:
    enum ProcesType{ CAMERA_SHOW, SAVE_VIDEO };

    explicit Process(QObject *parent = 0);
    ~Process();

    void addImage(cv::Mat img);
    void startProcess();
    void stopProcess();
signals:

public slots:

protected:
    cv::Mat currentImage;

private:
    bool isrunning;
    void virtual process()=0;
    void virtual beginProcess()=0;
    void virtual endProcess()=0;
};

#endif // PROCESS_H
