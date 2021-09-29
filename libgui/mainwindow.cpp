#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    this->setWindowTitle("Flame");
    this->setWindowState(Qt::WindowState::WindowMaximized);
    this->setBaseSize(1920, 1080);
    this->setCursor(QCursor(QPixmap(":/res/img/cursor.png")));
    this->setWindowIcon(QIcon(":/res/imglogo.jpg"));
    this->setObjectName("_main_window");

    this->m_layout = new QGridLayout(this);

    this->setLayout(this->m_layout);

    this->m_menuBar = new QMenuBar(this);
    this->m_menuBar->setObjectName("_main_menu_bar");

    QMenu *fileMenu = new QMenu("File", this->m_menuBar);
    fileMenu->setObjectName("_file_menu");

    QMenu *editMenu = new QMenu("Edit", this->m_menuBar);
    editMenu->setObjectName("_edit_menu");

    QMenu *viewMenu = new QMenu("View", this->m_menuBar);
    viewMenu->setObjectName("_view_menu");

    QMenu *nodeMenu = new QMenu("Node", this->m_menuBar);
    nodeMenu->setObjectName("_node_menu");

    QMenu *renderMenu = new QMenu("Render", this->m_menuBar);
    renderMenu->setObjectName("_render_menu");

    QMenu *helpMenu = new QMenu("Help", this->m_menuBar);
    helpMenu->setObjectName("_help_menu");

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

    QGraphicsDropShadowEffect *shadow = new QGraphicsDropShadowEffect(this->m_menuBar);

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