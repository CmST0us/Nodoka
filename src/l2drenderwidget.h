#ifndef L2DRENDERWIDGET_H
#define L2DRENDERWIDGET_H
#include <GL/glew.h>
#include <iostream>
#include <QOpenGLWidget>
#include "components/l2d/l2dmodel.h"
#include <memory>

class L2DRenderWidget : public QOpenGLWidget
{
private:
    std::unique_ptr<Nodoka::L2DModel> mModel;

public:
    L2DRenderWidget(QWidget* parent = Q_NULLPTR, Qt::WindowFlags f = Qt::WindowFlags()) {

    }

protected:
    virtual void initializeGL() override;
    virtual void paintGL() override;
    virtual void resizeGL(int w, int h) override;
};

#endif // L2DRENDERWIDGET_H
