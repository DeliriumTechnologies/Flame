#include <QMainWindow>
#include <QGridLayout>
#include <Qt>

class MainWindow : public QMainWindow
{
public:
    MainWindow(QWidget* parent);
private:
    QGridLayout* m_gridLayout;
};