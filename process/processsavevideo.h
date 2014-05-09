#ifndef PROCESSSAVEVIDEO_H
#define PROCESSSAVEVIDEO_H

#include <QWaitCondition>
#include <QMutex>

#include "process/process.h"
#include "process/planner.h"

class ProcessSaveVideo : public Process
{
public:
    ProcessSaveVideo(QString filename, Planner *planner = NULL);
    ~ProcessSaveVideo();
    void setFileName(QString filename);
private:
    QString filename;
    bool ready;
    cv::VideoWriter outVideo;

    Planner *planner;

    void process();
    void beginProcess();
    void endProcess();
};

#endif // PROCESSSAVEVIDEO_H
