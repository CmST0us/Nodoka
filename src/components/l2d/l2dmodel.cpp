
#include <QString>
#include <QDir>
#include <QFile>
#include <QByteArray>

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
 */

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

    /// Load Pose

    /// Load Expression

    /// Load Physics

    /// Create Render

    /// Load Texture
}
