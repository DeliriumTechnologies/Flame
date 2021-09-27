#include <iostream>
#include <QMainWindow>
#include <QGridLayout>
#include <QGraphicsDropShadowEffect>
#include <QMenuBar>
#include <QFile>
#include <QTextStream>
#include <Qt>

class MainWindow : public QMainWindow
{
public:
    MainWindow(QWidget* parent);
    ~MainWindow();
private:
    QGridLayout* m_layout;
    QMenuBar* m_menuBar;
};