#include <iostream>
#include <CubismFramework.hpp>
#include "l2dapp.h"

using namespace Nodoka;
/// some problem with qt namespace searching ^,^, so I will not use Csm.
using namespace Live2D::Cubism::Framework;

namespace Nodoka {
    static L2DApp *s_l2dAppInstance = NULL;
}

L2DApp::L2DApp() {
    mAppAllocator = std::unique_ptr<L2DAllocator>(new L2DAllocator());
    mLogLevel = Csm::CubismFramework::Option::LogLevel_Verbose;
}

L2DApp *L2DApp::currentApp() {
    if (Nodoka::s_l2dAppInstance == NULL) {
        Nodoka::s_l2dAppInstance = new L2DApp();
    }
    return Nodoka::s_l2dAppInstance;
}

bool L2DApp::initFramework() {
    L2DApp *currentApp = L2DApp::currentApp();
    Csm::CubismFramework::Option option;
    option.LogFunction = L2DApp::logMessage;
    option.LoggingLevel = currentApp->mLogLevel;
    currentApp->mInitOption = option;
    if (Csm::CubismFramework::StartUp(currentApp->mAppAllocator.get(), &(currentApp->mInitOption))) {
        Csm::CubismFramework::Initialize();
        return true;
    }
    return false;
}

void L2DApp::logMessage(const Live2D::Cubism::Framework::csmChar *message) {
    std::cout<<"[Live2D]"<<message<<std::endl;
    /// [TODO] write to disk log file.
}
