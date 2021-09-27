#include "mainwindow.h"

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent)
{
    this->setWindowTitle("Phoenix3D 1.0");
    this->setWindowState(Qt::WindowState::WindowMaximized);
    this->setBaseSize(1280, 720);

    this->m_layout = new QGridLayout(this);

    this->setLayout(this->m_layout);

    this->m_menuBar = new QMenuBar(this);

    QMenu* fileMenu = new QMenu("File", this->m_menuBar);
    QMenu* editMenu = new QMenu("Edit", this->m_menuBar);
    QMenu* viewMenu = new QMenu("View", this->m_menuBar);
    QMenu* nodeMenu = new QMenu("Node", this->m_menuBar);
    QMenu* renderMenu = new QMenu("Render", this->m_menuBar);
    QMenu* helpMenu = new QMenu("Help", this->m_menuBar);

    this->m_menuBar->addMenu(fileMenu);
    this->m_menuBar->addMenu(editMenu);
    this->m_menuBar->addMenu(viewMenu);
    this->m_menuBar->addMenu(nodeMenu);
    this->m_menuBar->addMenu(renderMenu);
    this->m_menuBar->addMenu(helpMenu);

    QFile menuBarStyleSheet(":/res/qts/menuBar.qts");
    if (menuBarStyleSheet.open(QIODevice::ReadOnly | QIODevice::Text))
    {

        QTextStream in(&menuBarStyleSheet);

        QString data = "";

        while (!in.atEnd())
        {
            QString line = in.readLine();

            data.append(line);
            data.append(" ");
        }

        this->m_menuBar->setStyleSheet(data);
    }
    else 
    {
        std::cerr << "Failed to load stylesheet at qrc:/res/qts/menuBar.qts!" << std::endl;
    }

    QGraphicsDropShadowEffect* shadow = new QGraphicsDropShadowEffect(this->m_menuBar);

    shadow->setBlurRadius(10.0);
    shadow->setColor(QColor::fromRgb(0, 0, 0, 128));
    shadow->setXOffset(0.0);
    shadow->setYOffset(2.0);

    this->m_menuBar->setGraphicsEffect(shadow);

    this->setMenuBar(this->m_menuBar);
}

MainWindow::~MainWindow()
{
    delete (this->m_menuBar);
    delete (this->m_layout);
    QMainWindow::~QMainWindow();
}