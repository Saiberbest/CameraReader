#include "processsavevideo.h"

ProcessSaveVideo::ProcessSaveVideo(QString filename, Planner *planner) : Process()
{
    this->filename = filename;
    this->planner = planner;
    ready = false;
}

ProcessSaveVideo::~ProcessSaveVideo()
{
}

void ProcessSaveVideo::setFileName(QString filename)
{
    this->filename = filename;
}

void ProcessSaveVideo::process()
{
    outVideo << currentImage;
}

void ProcessSaveVideo::beginProcess()
{
    outVideo.open(filename.toStdString(), codec, fps, size, true);
}

void ProcessSaveVideo::endProcess()
{
    outVideo.release();
}
