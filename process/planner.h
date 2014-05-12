#ifndef PLANNER_H
#define PLANNER_H

#include <QObject>
#include <QTimer>

#include "process/process.h"

class Planner : QObject
{
    Q_OBJECT
public:
    Planner(Process *process, int waitTimeS, int processTimeS);
    ~Planner();

    void startPlanner();
    void stopPlanner();

private slots:
    void startProcess();
    void stopProcess();
private:
    int waitTime;
    int processTime;

    QTimer *timerStart;
    QTimer *timerStop;

    Process *process;
};

#endif // PLANNER_H
