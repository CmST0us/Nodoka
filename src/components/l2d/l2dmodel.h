#ifndef L2DMODEL_H
#define L2DMODEL_H

#include <string>
#include <memory>

#include <CubismFramework.hpp>
#include <Model/CubismUserModel.hpp>
#include <CubismModelSettingJson.hpp>
#include <QDir>

using namespace Live2D::Cubism::Framework;

namespace Nodoka {

class L2DModel: public Csm::CubismUserModel {
private:
    QDir mModelRootDir;
    QString mModel3JsonFileName;

    std::unique_ptr<Csm::CubismModelSettingJson> mModelSettingJson;

public:
    L2DModel(const QString &model3JsonFilePath);

    void loadAsset();
};

}

#endif // L2DMODEL_H
