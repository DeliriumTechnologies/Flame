#include <iostream>
#include <QApplication>

#include "mainwindow.h"

int main(int argc, char* argv[]) 
{
    std::cout << "Phoenix3D 1.0 by Jonas Korte." << std::endl;

    QApplication app(argc, argv);

    QWidget root;

    MainWindow window(&root);

    window.setStyleSheet("QMainWindow { background-color: #3d3d3d }");

    window.show();

    return app.exec();
}