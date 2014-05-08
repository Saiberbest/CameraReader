#ifndef IMAGECONVERTOR_H
#define IMAGECONVERTOR_H

#include "opencv2/opencv.hpp"
#include <QImage>
#include <QPixmap>

class ImageConvertor
{
public:
    ImageConvertor();

    QImage Mat2QImage(cv::Mat const& src);
    cv::Mat QImage2Mat(QImage const& src);
    QPixmap Mat2QPixmap(cv::Mat const& src);
};

#endif // IMAGECONVERTOR_H
