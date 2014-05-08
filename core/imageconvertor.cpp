#include "imageconvertor.h"

ImageConvertor::ImageConvertor()
{
}

QImage ImageConvertor::Mat2QImage(cv::Mat const& src)
{
    cv::Mat temp; // make the same cv::Mat
    cvtColor(src, temp,CV_BGR2RGB); // cvtColor Makes a copt, that what i need
    QImage dest((uchar*) temp.data, temp.cols, temp.rows, temp.step, QImage::Format_RGB888);
    QImage dest2(dest);
    dest2.detach(); // enforce deep copy
    return dest2;
}

cv::Mat ImageConvertor::QImage2Mat(QImage const& src)
{
    cv::Mat tmp(src.height(),src.width(),CV_8UC3,(uchar*)src.bits(),src.bytesPerLine());
    cv::Mat result; // deep copy just in case (my lack of knowledge with open cv)
    cvtColor(tmp, result,CV_BGR2RGB);
    return result;
}

QPixmap ImageConvertor::Mat2QPixmap(cv::Mat const& src)
{
    QPixmap image;
    image = QPixmap::fromImage(Mat2QImage(src));
    return image;
}
