#include <iostream>
#include <QApplication>

#include "mainwindow.h"

int main(int argc, char *argv[])
{
    std::cout << "Phoenix3D 1.0 by Jonas Korte." << std::endl;

    QApplication app(argc, argv);
    app.setOverrideCursor(QCursor(QPixmap(":/res/img/cursor.png")));
    app.setObjectName("_application");

    QWidget root;
    root.setObjectName("_application_root");

    MainWindow window(&root);
    window.setStyleSheet("QMainWindow { background-color: #3d3d3d }");
    window.show();

    return app.exec();
}