#include "mainwindow.h"
#include "formmanagecamera.h"
#include "formpreferences.h"
#include "formcamaramonitor.h"
#include "formabout.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(Controller *controller, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->controller = controller;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::closeEvent(QCloseEvent * event)
{
    emit closingEvent();
}

void MainWindow::on_actionManage_Camera_triggered()
{
    setCentralWidget(new FormManageCamera(controller->getCameraInfo(), this));
}

void MainWindow::on_actionPreferences_triggered()
{
    setCentralWidget(new FormPreferences(controller->getPreferences(), this));
}

void MainWindow::on_actionQuit_triggered()
{
    this->close();
}

void MainWindow::on_actionAbout_triggered()
{
    setCentralWidget(new FormAbout(this));
}

void MainWindow::on_actionStart_Camera_triggered()
{
    setCentralWidget(new FormCamaraMonitor(controller, this));
}
