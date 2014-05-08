#ifndef PLANNER_H
#define PLANNER_H

#include <QWaitCondition>
#include <QMutex>

#include "process/process.h"

class Planner
{
public:
    Planner(Process *process, int waitTime, int processTime);
    ~Planner();

    void startPlanner();
    void stopPlanner();

private:
    QWaitCondition startRecord;
    QWaitCondition stopRecord;
    QMutex mutex;
};

#endif // PLANNER_H
