#ifndef PROCESSSHOWCAMERA_H
#define PROCESSSHOWCAMERA_H

#include "process/process.h"
#include "gui/formshowcamera.h"
#include "core/imageconvertor.h"

class ProcessShowCamera : public Process
{
public:
    ProcessShowCamera(FormShowCamera *showCamera);
    ~ProcessShowCamera();

private:
    cv::Size size;
    FormShowCamera *showCamera;
    ImageConvertor *imgConvertor;
    void process();
    void beginProcess();
    void endProcess();
};

#endif // PROCESSSHOWCAMERA_H
