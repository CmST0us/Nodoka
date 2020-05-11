#ifndef L2DAPP_H
#define L2DAPP_H

#include <CubismFramework.hpp>
#include "l2dallocator.h"
#include <memory>

namespace Nodoka {

class L2DApp
{
public:
    Csm::CubismFramework::Option mInitOption;
    std::unique_ptr<L2DAllocator> mAppAllocator;
    Csm::CubismFramework::Option::LogLevel mLogLevel;
public:
    L2DApp();
    static L2DApp *currentApp();

    static bool initFramework();
    static void logMessage(const Csm::csmChar *message);
};

}


#endif // L2DAPP_H
