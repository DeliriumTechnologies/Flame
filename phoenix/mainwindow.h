#include <QMainWindow>
#include <QQmlEngine>
#include <QQmlComponent>
#include <QGraphicsDropShadowEffect>
#include <QMenuBar>
#include <Qt>

class MainWindow : public QMainWindow
{
public:
    MainWindow(QWidget* parent);
    ~MainWindow();
private:
    QQmlEngine* m_engine;
    QQmlComponent* m_baseComponent;
    QMenuBar* m_menuBar;
};