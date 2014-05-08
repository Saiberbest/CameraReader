#include "settings.h"
#include <QSettings>
#include <QDebug>

Settings::Settings()
{
    listCameraInfo = new QList<CameraInfo *>();
    pref = new Preferences();
}


void Settings::readSettings()
{
    QSettings *settings = new QSettings("camera.ini", QSettings::IniFormat);
    int size = settings->beginReadArray("cameras");
    for(int i = 0; i < size; i++)
    {
        settings->setArrayIndex(i);
        CameraInfo *info = new CameraInfo(
                    (CameraInfo::CameraType)settings->value("type").toInt(),
                    settings->value("name").toString(),
                    settings->value("url").toString(),
                    settings->value("login").toString(),
                    settings->value("password").toString()
                    );
        info->setFlipHorizontal(settings->value("flipH").toBool());
        info->setFlipVertical(settings->value("flipV").toBool());
        listCameraInfo->append(info);
    }
    settings->endArray();

    settings = new QSettings("pref.ini",QSettings::IniFormat);
    settings->beginGroup("PathDir");
    pref->setPathURL(settings->value("dir").toString());
    settings->endGroup();

}

void Settings::saveSettings()
{
    QSettings *settings = new QSettings("camera.ini", QSettings::IniFormat);
    settings->clear();
    //settings->beginGroup ("Camera");
    settings->beginWriteArray("cameras");
    for (int i = 0; i < listCameraInfo->size(); i++) {
        settings->setArrayIndex(i);
        settings->setValue ("type",     listCameraInfo->at(i)->getType());
        settings->setValue ("name",     listCameraInfo->at(i)->getName());
        settings->setValue ("url",      listCameraInfo->at(i)->getUrl());
        settings->setValue ("login",    listCameraInfo->at(i)->getLogin());
        settings->setValue ("password", listCameraInfo->at(i)->getPassword());
        settings->setValue ("flipH", listCameraInfo->at(i)->getFlipHorizontal());
        settings->setValue ("flipV", listCameraInfo->at(i)->getFlipVertical());
   }
    settings->endArray();
    //settings->endGroup();
}


QList<CameraInfo *> *Settings::getListCameraInfo()
{
    return listCameraInfo;
}

Preferences *Settings::getPreference()
{
    return pref;
}

void Settings::setListCameraInfo(QList<CameraInfo *> *listCameraInfo)
{
    this->listCameraInfo = listCameraInfo;
}

void Settings::setPreference(Preferences *pref)
{
    this->pref = pref;
}
