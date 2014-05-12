#ifndef PROCESS_H
#define PROCESS_H

#include <QObject>
#include "opencv2/opencv.hpp"

class Planner;

class Process : public QObject
{
    Q_OBJECT
    Q_ENUMS(ProcesType)
public:
    enum ProcesType{ CAMERA_SHOW, SAVE_VIDEO };

    explicit Process(QObject *parent = 0);
    ~Process();

    void setSourceInfo(cv::Size size, int codec, double fps);
    void setPlanner(Planner *planner);
    void addImage(cv::Mat img);
    void initProcess();
    void startProcess();
    void stopProcess();
signals:

public slots:

protected:
    cv::Mat currentImage;
    cv::Size size;
    int codec;
    double fps;

    Planner *planner;
private:
    bool isrunning;
    void virtual process()=0;
    void virtual beginProcess()=0;
    void virtual endProcess()=0;
};

#endif // PROCESS_H
