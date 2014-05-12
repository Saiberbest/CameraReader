#ifndef CAMERAINFO_H
#define CAMERAINFO_H
#include <QObject>
#include <QString>
#include "process/process.h"

class CameraInfo : public QObject
{
    Q_OBJECT
    Q_ENUMS(CameraType)
public:
    enum CameraType { IP, WEBCAM };

    CameraInfo(CameraType type, QString name, QString url, QString login, QString password);

    CameraType getType();
    QString getUrl();
    QString getLogin();
    QString getPassword();
    QString getName();

    bool getFlipHorizontal();
    bool getFlipVertical();

    void setType(CameraType type);
    void setUrl(QString url);
    void setLogin(QString login);
    void setPassword(QString password);
    void setName(QString name);

    void setFlipHorizontal(bool flip);
    void setFlipVertical(bool flip);

    void removeProcessCamera();
    void addProcessToCamera(Process::ProcesType type);
    bool hasProcess(Process::ProcesType type);
    QList<Process::ProcesType> *getProcesslist();
private:
    CameraType type;
    QString url;
    QString login;
    QString password;
    QString name;

    bool flipHorizontal;
    bool flipVertical;

    QList<Process::ProcesType> *listProcess;
};

#endif // CAMERAINFO_H
