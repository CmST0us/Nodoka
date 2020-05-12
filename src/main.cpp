#include "mainwindow.h"
#include <QApplication>
#include <CubismFramework.hpp>
#include "components/l2d/l2dapp.h"
#include "components/l2d/l2dmodel.h"
#include <QDir>

int main(int argc, char *argv[])
{
    /// Init Live2D SDK
    Nodoka::L2DApp::currentApp()->initFramework();

    Nodoka::L2DModel model("/home/eki/Project/Qt_Project/Nodoka/vendor/CubismSdkForNative/Samples/Resources/Hiyori/Hiyori.model3.json");

    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
