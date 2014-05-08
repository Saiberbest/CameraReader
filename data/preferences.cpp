#include "preferences.h"

Preferences::Preferences()
{
}


QString Preferences::getPathURL()
{
    return pathURL;
}

void Preferences::setPathURL(QString path)
{
    this->pathURL = path;
}
