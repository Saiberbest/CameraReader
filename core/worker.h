#ifndef WORKER_H
#define WORKER_H

#include <QObject>

class Worker : public QObject
{
    Q_OBJECT
public:
    explicit Worker(QObject *parent = 0);

    void stopWorking();
signals:
    void resultReady();

public slots:
    virtual void doWork()=0;

};

#endif // WORKER_H
