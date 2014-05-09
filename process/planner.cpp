#include "planner.h"

Planner::Planner(Process *process, int waitTimeS, int processTimeS)
{
    this->process = process;
    this->waitTime = waitTimeS * 1000;
    this->processTime = processTimeS * 1000;
    mutex.lock();
}

Planner::~Planner()
{
    process->stopProcess();
}

void Planner::startPlanner()
{
    mutex.lock();
    startRecord.wait(&mutex,waitTime);
    process->startProcess();
    mutex.unlock();
}

void Planner::stopPlanner()
{
    mutex.lock();
    startRecord.wait(&mutex,waitTime);
    process->stopProcess();
    mutex.unlock();
}
