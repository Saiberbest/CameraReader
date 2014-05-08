#include "runapplication.h"
#include <QDebug>

runApplication::runApplication()
{
    settings = new Settings();
    settings->readSettings();

    controller = new Controller();
    controller->setCameraInfo(settings->getListCameraInfo());
    controller->setPreferences(settings->getPreference());

    mainWindow = new MainWindow(controller);
    mainWindow->show();

    connect(mainWindow, SIGNAL(closingEvent()), this, SLOT(endApplication()));
}

void runApplication::endApplication()
{
    settings->saveSettings();
}
