#ifndef PREFERENCES_H
#define PREFERENCES_H

#include <QString>

class Preferences
{
public:
    Preferences();

    QString getPathURL();

    void setPathURL(QString path);

private:
    QString pathURL;
};

#endif // PREFERENCES_H
