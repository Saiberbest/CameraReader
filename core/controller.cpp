#include "controller.h"
#include <QDebug>

Controller::Controller()
{
    camFactory = new CameraFactory(this);
}

void Controller::setCameraInfo(QList<CameraInfo *> *listCameraInfo)
{
    this->listCameraInfo = listCameraInfo;
}

void Controller::setPreferences(Preferences *pref)
{
    this->pref = pref;
}

QList<Camera *> *Controller::getCameras()
{
    return listCamera;
}

QList<CameraInfo *> *Controller::getCameraInfo()
{
    return listCameraInfo;
}

Preferences *Controller::getPreferences()
{
    return pref;
}

QList<FormShowCamera *> *Controller::getListCameraShow()
{
    return camFactory->getListShowCamera();
}

bool Controller::isCameraFlipVChecked(int id)
{
    return listCameraInfo->at(id)->getFlipVertical();
}

bool Controller::isCameraFlipHChecked(int id)
{
    return listCameraInfo->at(id)->getFlipHorizontal();
}

int Controller::prepareCamera()
{
    camFactory->setCameraInfo(listCameraInfo);
    camFactory->createCamera();
    listCamera = camFactory->getCameras();
    return listCamera->size();
}

void Controller::startCamera(int id)
{
    qDebug() << "startCamera" << id;
    listCamera->at(id)->startReading();
}

void Controller::stopCamera(int id)
{
    listCamera->at(id)->stopReading();
}

void Controller::flipHorizontalOnCamera(int id, bool flip)
{
    listCamera->at(id)->setFlipHorizontal(flip);
    listCameraInfo->at(id)->setFlipHorizontal(flip);
}

void Controller::flipVerticalOnCamera(int id, bool flip)
{
    listCamera->at(id)->setFlipVertical(flip);
    listCameraInfo->at(id)->setFlipVertical(flip);
}

void Controller::prepareProcess()
{
    camFactory->createProcess();
}
