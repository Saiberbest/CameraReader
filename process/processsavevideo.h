#ifndef PROCESSSAVEVIDEO_H
#define PROCESSSAVEVIDEO_H

#include <QWaitCondition>
#include <QMutex>

#include "process/process.h"

class ProcessSaveVideo : public Process
{
public:
    ProcessSaveVideo(QString filename, cv::Size size, int codec, double fps);
    ~ProcessSaveVideo();
    void setFileName(QString filename);
private:
    QString filename;
    bool ready;
    cv::VideoWriter outVideo;

    cv::Size size;
    int codec;
    double fps;

    void process();
    void beginProcess();
    void endProcess();
};

#endif // PROCESSSAVEVIDEO_H
