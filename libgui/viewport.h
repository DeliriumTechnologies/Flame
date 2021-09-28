#pragma once
#include "api.h"
#include <QOpenGLWidget>

enum EXPORTED ViewportShadingMode 
{
    VSM_WIRE,
    VSM_DEFAULT,
    VSM_LOOKDEV,
    VSM_RENDERED,
    VSM_MATCAPPED,
};

class EXPORTED Viewport : public QOpenGLWidget
{
public:
    Viewport(QWidget *parent);
private:
    ViewportShadingMode m_shadingMode;

};
