#include "process.h"

Process::Process(QObject *parent) :
    QObject(parent)
{
}

Process::~Process()
{
    stopProcess();
}

void Process::startProcess()
{
    beginProcess();
    this->isrunning = true;
}

void Process::stopProcess()
{
    this->isrunning = false;
    endProcess();
}

void Process::setSourceInfo(cv::Size size, int codec, double fps)
{
    this->size = size;
    this->fps = fps;
    this->codec = codec;
}

void Process::addImage(cv::Mat img)
{
    currentImage = img;
    if (isrunning)
        process();
}
