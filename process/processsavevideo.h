#ifndef PROCESSSAVEVIDEO_H
#define PROCESSSAVEVIDEO_H

#include <QWaitCondition>
#include <QMutex>

#include "process/process.h"

class ProcessSaveVideo : public Process
{
public:
    ProcessSaveVideo(QString directory, QString filename);
    ~ProcessSaveVideo();
    void setFileName(QString filename);
private:
    QString filename;
    QString directory;

    bool ready;
    cv::VideoWriter outVideo;

    void process();
    void beginProcess();
    void endProcess();
};

#endif // PROCESSSAVEVIDEO_H
