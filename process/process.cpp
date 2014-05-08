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

void Process::addImage(cv::Mat img)
{
    currentImage = img;
    if (isrunning)
        process();
}
