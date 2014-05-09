#include "processshowcamera.h"

ProcessShowCamera::ProcessShowCamera(FormShowCamera *showCamera) : Process()
{
    this->showCamera = showCamera;
    imgConvertor = new ImageConvertor();
    size.height = showCamera->getHeightImage();
    size.width = showCamera->getWidthImage();
    QPixmap px(size.width,size.height);
    px.fill(Qt::black);
    showCamera->updateImage(px);
}

ProcessShowCamera::~ProcessShowCamera()
{
}

void ProcessShowCamera::process()
{
    cv::Mat img;
    cv::resize(currentImage, img, size);
    showCamera->updateImage(imgConvertor->Mat2QPixmap(img));
}

void ProcessShowCamera::beginProcess()
{
}

void ProcessShowCamera::endProcess()
{
    QPixmap px(size.width,size.height);
    px.fill(Qt::black);
    showCamera->updateImage(px);
}
