#include "processsavevideo.h"

ProcessSaveVideo::ProcessSaveVideo(QString filename,cv::Size size, int codec, double fps) : Process()
{
    this->filename = filename;
    this->size = size;
    this->codec = codec;
    this->fps = fps;
    ready = false;
}

ProcessSaveVideo::~ProcessSaveVideo()
{
    stopSave();
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
