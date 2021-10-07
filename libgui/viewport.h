#pragma once
#include "api.h"
#include <QGraphicsView>

enum EXPORTED ViewportShadingMode 
{
    VSM_WIRE,
    VSM_DEFAULT,
    VSM_LOOKDEV,
    VSM_RENDERED,
    VSM_MATCAPPED,
};

class EXPORTED Viewport : public QGraphicsView
{
public:
    Viewport(QWidget *parent);
private:
    ViewportShadingMode m_shadingMode;

};
