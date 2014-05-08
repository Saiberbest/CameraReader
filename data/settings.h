#ifndef SETTINGS_H
#define SETTINGS_H

#include "data/camerainfo.h"
#include "data/preferences.h"

class Settings
{
public:
    Settings();

    void readSettings();
    void saveSettings();

    QList<CameraInfo *> *getListCameraInfo();
    Preferences *getPreference();

    void setListCameraInfo(QList<CameraInfo *> *listCameraInfo);
    void setPreference(Preferences *pref);
private:
    QList<CameraInfo *> *listCameraInfo;
    Preferences *pref;
};

#endif // SETTINGS_H
