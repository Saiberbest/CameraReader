#include "camerafactory.h"
#include "core/controller.h"
#include "process/ipcamera.h"
#include "process/webcam.h"
#include "process/processshowcamera.h"
#include "process/processsavevideo.h"

CameraFactory::CameraFactory(Controller *controller)
{
    listCamera = new QList<Camera *>();
    listCameraInfo = NULL;
    listShowCamera = NULL;
    this->controller = controller;
}

void CameraFactory::createCamera()
{
    if (listCameraInfo == NULL)
        return;

    for (int i = 0; i < listCameraInfo->size(); i++)
    {
        switch (listCameraInfo->at(i)->getType()) {
        case CameraInfo::IP:
            listCamera->append(new IpCamera(listCameraInfo->at(i)));
            break;
        case CameraInfo::WEBCAM:
            listCamera->append(new WebCam(listCameraInfo->at(i)));
            break;
        default:
            break;
        }
    }
}

void CameraFactory::createProcess()
{
    listShowCamera = new QList<FormShowCamera *>();
    for (int i = 0; i < listCameraInfo->size(); i++)
    {
        Camera *currentCamera = listCamera->at(i);
        CameraInfo *cameInfo = listCameraInfo->at(i);
        QList<Process::ProcesType> *listProcess = listCameraInfo->at(i)->getProcesslist();
        for(int j = 0; j < listProcess->size(); j++)
        {
            switch (listProcess->at(j)) {
            case Process::CAMERA_SHOW:
            {
                FormShowCamera *form = new FormShowCamera(controller, i, cameInfo->getName());
                listShowCamera->append(form);
                currentCamera->addProcess(new ProcessShowCamera(form));
            }
                break;
            case Process::SAVE_VIDEO:
            {
                ProcessSaveVideo *process = new ProcessSaveVideo(controller->getPreferences()->getPathURL(), cameInfo->getName());
                currentCamera->addProcess(process);
            }
                break;
            default:
                break;
            }
        }
    }
}


void CameraFactory::releaseCamera()
{
    for (int i = 0; i < listCamera->size(); i++)
    {
        listCamera->at(i)->stopReading();
    }
}

void CameraFactory::setCameraInfo(QList<CameraInfo *> *listCameraInfo)
{
    this->listCameraInfo = listCameraInfo;
}

QList<Camera *> *CameraFactory::getCameras()
{
    return listCamera;
}

QList<FormShowCamera *> *CameraFactory::getListShowCamera()
{
    return listShowCamera;
}
