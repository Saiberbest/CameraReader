#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "core/controller.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(Controller *controller, QWidget *parent = 0);
    ~MainWindow();

signals:
    void closingEvent();

protected:
    void closeEvent(QCloseEvent * event);

private slots:
    void on_actionManage_Camera_triggered();

    void on_actionPreferences_triggered();

    void on_actionQuit_triggered();

    void on_actionAbout_triggered();

    void on_actionStart_Camera_triggered();

private:
    Ui::MainWindow *ui;
    Controller *controller;
};

#endif // MAINWINDOW_H
