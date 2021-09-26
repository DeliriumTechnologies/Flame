#include "mainwindow.h"

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent)
{
    this->setWindowTitle("Phoenix3D 1.0");
    this->setWindowState(Qt::WindowState::WindowMaximized);
    this->setBaseSize(1280, 720);

    this->m_engine = new QQmlEngine(this);
    this->m_baseComponent = new QQmlComponent(this->m_engine, QUrl("qrc:/res/qml/defaultLayout.qml"), this);

    QWidget* widget = qobject_cast<QWidget*>(this->m_baseComponent->create());

    qDebug() << qPrintable(this->m_baseComponent->errorString());

    this->setCentralWidget(widget);

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

    this->m_menuBar->setStyleSheet("QMenuBar { min-height: 30px; background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #5e5e5e, stop: 1 #3d3d3d)  } QMenuBar::item { padding: 0px 10px; background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #5e5e5e, stop: 1 #3d3d3d); color: #efefef } QMenuBar::item:pressed { background-color: #5b71a0 }");
    
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
    delete (this->m_baseComponent);
    delete (this->m_engine);
    QMainWindow::~QMainWindow();
}