#include<GL/glew.h>

#include "mainwindow.h"
#include <QApplication>
#include <CubismFramework.hpp>
#include "components/l2d/l2dapp.h"
int main(int argc, char *argv[])
{
    /// Setup OpenGL Context


    /// Init Live2D SDK
    Nodoka::L2DApp::currentApp()->initFramework();

    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
