#ifndef PLANNER_H
#define PLANNER_H

#include <QWaitCondition>
#include <QMutex>

#include "process/process.h"

class Planner
{
public:
    Planner(Process *process, int waitTimeS, int processTimeS);
    ~Planner();

    void startPlanner();
    void stopPlanner();

private:
    QWaitCondition startRecord;
    QWaitCondition stopRecord;
    QMutex mutex;

    int waitTime;
    int processTime;

    Process *process;
};

#endif // PLANNER_H
