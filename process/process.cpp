#include "process.h"
#include "process/planner.h"

Process::Process(QObject *parent) :
    QObject(parent)
{
    this->planner = NULL;
}

Process::~Process()
{
    stopProcess();
}

void Process::initProcess()
{
    if (planner == NULL)
    {
        startProcess();
    }
    else
    {
        planner->startPlanner();
    }
}


void Process::startProcess()
{
    beginProcess();
    this->isrunning = true;
}

void Process::stopProcess()
{
    if (planner != NULL)
    {
        planner->stopPlanner();
    }

    this->isrunning = false;
    endProcess();
}

void Process::setSourceInfo(cv::Size size, int codec, double fps)
{
    this->size = size;
    this->fps = fps;
    this->codec = codec;
}

void Process::setPlanner(Planner *planner)
{
    this->planner = planner;
}


void Process::addImage(cv::Mat img)
{
    currentImage = img;
    if (isrunning)
        process();
}
