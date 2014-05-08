#include "core/runapplication.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    runApplication w;

    return a.exec();
}
