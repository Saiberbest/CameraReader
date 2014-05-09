#include "camerainfo.h"

CameraInfo::CameraInfo(CameraType type, QString name, QString url, QString login, QString password)
{
    this->type = type;
    this->name = name;
    this->url = url;
    this->login = login;
    this->password = password;
    this->flipHorizontal = false;
    this->flipVertical = false;
    listProcess = new QList<Process::ProcesType>();
    listProcess->append(Process::CAMERA_SHOW);
}

CameraInfo::CameraType CameraInfo::getType()
{
    return this->type;
}

QString CameraInfo::getUrl()
{
    return this->url;
}

QString CameraInfo::getLogin()
{
    return this->login;
}

QString CameraInfo::getPassword()
{
    return this->password;
}

QString CameraInfo::getName()
{
    return this->name;
}

bool CameraInfo::getFlipHorizontal()
{
    return this->flipHorizontal;
}

bool CameraInfo::getFlipVertical()
{
    return this->flipVertical;
}

void CameraInfo::setType(CameraType type)
{
    this->type = type;
}

void CameraInfo::setUrl(QString url)
{
    this->url = url;
}

void CameraInfo::setLogin(QString login)
{
    this->login = login;
}

void CameraInfo::setPassword(QString password)
{
    this->password = password;
}

void CameraInfo::setName(QString name)
{
    this->name = name;
}

void CameraInfo::setFlipHorizontal(bool flip)
{
    this->flipHorizontal = flip;
}

void CameraInfo::setFlipVertical(bool flip)
{
    this->flipVertical = flip;
}

void CameraInfo::removeProcessCamera()
{
    listProcess->clear();
}

void CameraInfo::addProcessToCamera(Process::ProcesType type)
{
    listProcess->append(type);
}

bool CameraInfo::hasProcess(Process::ProcesType type)
{
    return listProcess->contains(type);
}

QList<Process::ProcesType> *CameraInfo::getProcesslist()
{
    return listProcess;
}
