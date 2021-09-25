#include <iostream>
#include <QApplication>

#include "mainwindow.h"

int main(int argc, char* argv[]) 
{
    std::cout << "Phoenix3D 1.0 by Jonas Korte." << std::endl;

    QApplication app(argc, argv);

    QWidget root;

    MainWindow window(&root);

    window.show();

    return app.exec();
}