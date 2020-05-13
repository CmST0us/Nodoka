#include "l2drenderwidget.h"
#include <Live2DCubismCore.h>
#include "components/l2d/l2dapp.h"
#include "components/l2d/l2dmodel.h"
#include <Rendering/OpenGL/CubismRenderer_OpenGLES2.hpp>
#include <QDir>

void L2DRenderWidget::initializeGL() {
    glewInit();
    this->mModel = std::unique_ptr<Nodoka::L2DModel>(new Nodoka::L2DModel("/home/eki/Project/Qt_Project/Nodoka/vendor/CubismSdkForNative/Samples/Resources/Hiyori/Hiyori.model3.json"));
    this->mModel->loadAsset();
}

void L2DRenderWidget::paintGL() {
    glClear(GL_COLOR_BUFFER_BIT);
    this->mModel->setMVPMatrixWithSize(QSize(this->width(), this->height()));
    this->mModel->GetModel()->Update();
    this->mModel->GetRenderer<Csm::Rendering::CubismRenderer_OpenGLES2>()->DrawModel();
    glClearColor(0, 1, 0, 1);;
}

void L2DRenderWidget::resizeGL(int w, int h) {
    glViewport(0, 0, w, h);
    this->repaint();
}
