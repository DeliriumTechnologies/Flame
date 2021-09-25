#include "mainwindow.h"

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent)
{
    this->setWindowTitle("Phoenix3D 1.0");
    this->setWindowState(Qt::WindowState::WindowMaximized);
    this->setBaseSize(1280, 720);
}