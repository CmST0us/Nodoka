
#include <QString>
#include <QDir>
#include <QFile>
#include <QByteArray>
#include <QImage>
#include <Rendering/OpenGL/CubismRenderer_OpenGLES2.hpp>
#include "l2dmodel.h"

using namespace Nodoka;

/* Live2D Model Directory Tree:
 *
 * ModelName
 *      ModelName.moc3
 *      ModelName.model3.json *
 *      ModelName.physics3.json
 *      ModelName.pose3.json
 *      ModelName.userdata3.json
 *      motions
 *          ...
 *      ModelName.xxxx
 *          texture_xx.png
 *      expressions
 *          xxx.exp3.json
 *
 * --------------------------------
 * An Model should manager its own texture, so when distory model, the texture
 * should be release, too.
 */

L2DModel::~L2DModel() {
    this->releaseTexture();
}

L2DModel::L2DModel(const QString &model3JsonFilePath) {
    QString dirPath = model3JsonFilePath.section("/", 0, -2);
    this->mModelRootDir = QDir(dirPath);
    this->mModel3JsonFileName = model3JsonFilePath.section("/", -1);

    /// Read JSON File
    QFile jsonFile(model3JsonFilePath);
    if (jsonFile.open(QFile::ReadOnly)) {
        QByteArray data = jsonFile.readAll();
        auto modelSetting = new Csm::CubismModelSettingJson((const Csm::csmByte *)data.data(), (Csm::csmSizeInt)data.length());
        this->mModelSettingJson = std::unique_ptr<Csm::CubismModelSettingJson>((modelSetting));
    }
}

void L2DModel::loadAsset() {
    /// Load Model
    QString modelFileName(this->mModelSettingJson->GetModelFileName());
    if (modelFileName.length() > 0) {
        /// Has model file
        QString modelFilePath = this->mModelRootDir.filePath(modelFileName);
        QFile modelFile(modelFilePath);
        if (modelFile.open(QFile::ReadOnly)) {
            QByteArray data = modelFile.readAll();
            this->LoadModel((const Csm::csmByte *)data.data(), (Csm::csmSizeInt)data.length());
            Csm::csmMap<Csm::csmString, Csm::csmFloat32> layout;
            this->mModelSettingJson->GetLayoutMap(layout);
            this->GetModelMatrix()->SetupFromLayout(layout);
        }
    }

    /// Load Pose

    /// Load Expression

    /// Load Physics

    /// Load Texture
    this->CreateRenderer();

    /// Create Render
    Csm::csmInt32 textureCount = this->mModelSettingJson->GetTextureCount();
    for (int i = 0; i < textureCount; ++i) {
        QString textureFileName(this->mModelSettingJson->GetTextureFileName(i));
        QString textureFilePath = this->mModelRootDir.filePath(textureFileName);
        /// Create texture from file
        auto texture = this->createTextureFromFilePath(textureFilePath);
        this->mTextureMap[i] = texture;
        this->GetRenderer<Csm::Rendering::CubismRenderer_OpenGLES2>()->BindTexture(i, texture->textureId());
    }
}

void L2DModel::setMVPMatrixWithSize(const QSize &size, float userScale) {
    Csm::CubismMatrix44 projectionMatrix;
    float w = size.width();
    float h = size.height();
    float ratio = w / h;
    if (ratio > 1) {
        projectionMatrix.Scale(1 * userScale, ratio * userScale);
    } else {
        projectionMatrix.Scale(1 / ratio * userScale, 1 * userScale);
    }
    projectionMatrix.MultiplyByMatrix(this->GetModelMatrix());
    this->GetRenderer<Csm::Rendering::CubismRenderer_OpenGLES2>()->SetMvpMatrix(&projectionMatrix);
}

void L2DModel::releaseTexture() {
    auto textureCount = this->mModelSettingJson->GetTextureCount();
    auto map = this->GetRenderer<Csm::Rendering::CubismRenderer_OpenGLES2>()->GetBindedTextures();
    for (Csm::csmInt32 i = 0; i < textureCount; ++i) {
        this->mTextureMap.erase(i);
    }
}

std::shared_ptr<QOpenGLTexture> L2DModel::createTextureFromFilePath(const QString &filePath) {
    QImage textureImage(filePath);
    std::shared_ptr<QOpenGLTexture> texture(new QOpenGLTexture(textureImage));
    texture->setMinificationFilter(QOpenGLTexture::LinearMipMapLinear);
    texture->setMagnificationFilter(QOpenGLTexture::Linear);
    return texture;
}
