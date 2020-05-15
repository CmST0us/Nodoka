#ifndef L2DMODEL_H
#define L2DMODEL_H

#include <string>
#include <memory>

#include <CubismFramework.hpp>
#include <Model/CubismUserModel.hpp>
#include <CubismModelSettingJson.hpp>
#include <QDir>
#include <QSize>
#include <QOpenGLTexture>

using namespace Live2D::Cubism::Framework;

namespace Nodoka {

class L2DModel: public Csm::CubismUserModel {
private:
    QDir mModelRootDir;
    QString mModel3JsonFileName;

    std::unique_ptr<Csm::CubismModelSettingJson> mModelSettingJson;

    std::map<int, std::shared_ptr<QOpenGLTexture>> mTextureMap;
    std::shared_ptr<QOpenGLTexture> createTextureFromFilePath(const QString &filePath);
    void releaseTexture();
public:
    L2DModel(const QString &model3JsonFilePath);
    virtual ~L2DModel();

    void loadAsset();
    void setMVPMatrixWithSize(const QSize &size, float userScale = 1);
};

}

#endif // L2DMODEL_H
