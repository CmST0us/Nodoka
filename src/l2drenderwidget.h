#ifndef L2DRENDERWIDGET_H
#define L2DRENDERWIDGET_H

#include <iostream>
#include <QOpenGLWidget>

class L2DRenderWidget : public QOpenGLWidget
{
public:
    L2DRenderWidget(QWidget* parent = Q_NULLPTR, Qt::WindowFlags f = Qt::WindowFlags()) {

    }

protected:
    virtual void paintGL() override;
};

#endif // L2DRENDERWIDGET_H
