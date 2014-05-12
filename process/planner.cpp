#include "planner.h"

Planner::Planner(Process *process, int waitTimeS, int processTimeS) : QObject()
{
    this->process = process;
    this->waitTime = waitTimeS * 1000;
    this->processTime = processTimeS * 1000;
    timerStart = new QTimer(this);
    timerStop = new QTimer(this);
}

Planner::~Planner()
{
    process->stopProcess();
}

void Planner::startPlanner()
{
    connect(timerStart, SIGNAL(timeout()), this, SLOT(startProcess()));
    timerStart->start(waitTime);
    connect(timerStop, SIGNAL(timeout()), this, SLOT(stopProcess()));
}

void Planner::stopPlanner()
{
    timerStart->stop();
    disconnect(timerStart, SIGNAL(timeout()),this, SLOT(startProcess()));
    timerStop->stop();
    disconnect(timerStop, SIGNAL(timeout()), this, SLOT(stopProcess()));
}

void Planner::startProcess()
{
    timerStart->stop();
    process->startProcess();
    timerStop->start(processTime);
}

void Planner::stopProcess()
{
    timerStop->stop();
    process->stopProcess();
    timerStart->start(waitTime);
}
