#include <QOpenGLWidget>

enum ViewportShadingMode 
{
    VSM_WIRE,
    VSM_DEFAULT,
    VSM_LOOKDEV,
    VSM_RENDERED
};

class Viewport : public QOpenGLWidget
{
public:
    Viewport(QWidget *parent);
private:
    ViewportShadingMode m_shadingMode;

};