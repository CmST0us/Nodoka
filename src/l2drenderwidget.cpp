#include "l2drenderwidget.h"
#include <Live2DCubismCore.h>
#include "components/l2d/l2dapp.h"
#include "components/l2d/l2dmodel.h"
#include <Rendering/OpenGL/CubismRenderer_OpenGLES2.hpp>
#include <QDir>

void L2DRenderWidget::initializeGL() {
    glewInit();

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);


    this->mModel = std::unique_ptr<Nodoka::L2DModel>(new Nodoka::L2DModel("/home/eki/Project/Qt_Project/Nodoka/vendor/CubismSdkForNative/Samples/Resources/Hiyori/Hiyori.model3.json"));
    this->mModel->loadAsset();
}

void L2DRenderWidget::paintGL() {
    glClear(GL_COLOR_BUFFER_BIT);
    this->mModel->setMVPMatrixWithSize(QSize(this->width(), this->height()), 1.5f);
    this->mModel->GetModel()->Update();
    this->mModel->GetRenderer<Csm::Rendering::CubismRenderer_OpenGLES2>()->DrawModel();
    glClearColor(0, 0, 0, 1);

    this->update();
}

void L2DRenderWidget::resizeGL(int w, int h) {
    glViewport(0, 0, w, h);
    this->repaint();
}
