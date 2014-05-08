#ifndef RUNAPPLICATION_H
#define RUNAPPLICATION_H
#include <QObject>

#include "gui/mainwindow.h"
#include "core/controller.h"
#include "data/camerainfo.h"
#include "data/preferences.h"
#include "data/settings.h"


class runApplication : public QObject
{
    Q_OBJECT
public:
    runApplication();

private:
    MainWindow *mainWindow;
    Settings *settings;
    Controller *controller;
private slots:
    void endApplication();
};

#endif // RUNAPPLICATION_H
