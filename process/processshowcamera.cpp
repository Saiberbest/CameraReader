#include "processshowcamera.h"

ProcessShowCamera::ProcessShowCamera(FormShowCamera *showCamera) : Process()
{
    this->showCamera = showCamera;
    imgConvertor = new ImageConvertor();
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
    size.height = showCamera->getHeightImage();
    size.width = showCamera->getWidthImage();
}

void ProcessShowCamera::endProcess()
{
    cv::Mat m = cv::Mat::zeros(size.height, size.width, CV_32F);
    showCamera->updateImage(imgConvertor->Mat2QPixmap(m));
}
