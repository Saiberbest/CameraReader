#include "processsavevideo.h"
#include <QDateTime>
#include <QDir>
#include <QDebug>

ProcessSaveVideo::ProcessSaveVideo(QString directory, QString filename) : Process()
{
    this->directory = directory;
    this->filename = filename;
    ready = false;
}

ProcessSaveVideo::~ProcessSaveVideo()
{
}

void ProcessSaveVideo::setFileName(QString filename)
{
    this->filename = filename;
}

void ProcessSaveVideo::process()
{
    outVideo << currentImage;
}

void ProcessSaveVideo::beginProcess()
{
    QDateTime now = QDateTime::currentDateTime();

    QString file = directory + "/" + filename + "_" + now.toString("yyyyMMddHHmmss") + ".avi";
    qDebug() << codec << fps << size.height;
    outVideo.open(file.toStdString(), codec, fps, size, true);
    if (!outVideo.isOpened())
    {
        qDebug()  << "Could not open the output video for write " << file;
        return;
    }
}

void ProcessSaveVideo::endProcess()
{
    outVideo.release();
}
