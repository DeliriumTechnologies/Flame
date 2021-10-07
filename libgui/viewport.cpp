#include "viewport.h"

Viewport::Viewport(QWidget* parent) : QGraphicsView(parent)
{
    this->m_shadingMode = ViewportShadingMode::VSM_DEFAULT;
}