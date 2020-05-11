#-------------------------------------------------
#
# Project created by QtCreator 2020-05-11T00:36:24
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Nodoka
TEMPLATE = app

PROJECT_ROOT = $$PWD/..
#--- Live 2D SDK Start ---#
L2D_SDK_DIR = $$PROJECT_ROOT/vendor/CubismSdkForNative

L2D_SDK_CORE_DIR = $$L2D_SDK_DIR/Core
L2D_SDK_CORE_LIB_DIR = $$L2D_SDK_CORE_DIR/lib/linux/x86_64
L2D_SDK_CORE_INC = $$L2D_SDK_CORE_DIR/include

L2D_SDK_FRAMEWORK_DIR = $$L2D_SDK_DIR/Framework
message("Current use Linux GL target")
DEFINES += CSM_TARGET_LINUX_GL

#--- Live 2D SDK End ---#

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    l2drenderwidget.cpp \
    $$L2D_SDK_FRAMEWORK_DIR/src/Effect/CubismBreath.cpp \
    $$L2D_SDK_FRAMEWORK_DIR/src/Effect/CubismEyeBlink.cpp \
    $$L2D_SDK_FRAMEWORK_DIR/src/Effect/CubismPose.cpp \
    $$L2D_SDK_FRAMEWORK_DIR/src/Id/CubismId.cpp \
    $$L2D_SDK_FRAMEWORK_DIR/src/Id/CubismIdManager.cpp \
    $$L2D_SDK_FRAMEWORK_DIR/src/Math/CubismMath.cpp \
    $$L2D_SDK_FRAMEWORK_DIR/src/Math/CubismMatrix44.cpp \
    $$L2D_SDK_FRAMEWORK_DIR/src/Math/CubismModelMatrix.cpp \
    $$L2D_SDK_FRAMEWORK_DIR/src/Math/CubismTargetPoint.cpp \
    $$L2D_SDK_FRAMEWORK_DIR/src/Math/CubismVector2.cpp \
    $$L2D_SDK_FRAMEWORK_DIR/src/Math/CubismViewMatrix.cpp \
    $$L2D_SDK_FRAMEWORK_DIR/src/Model/CubismMoc.cpp \
    $$L2D_SDK_FRAMEWORK_DIR/src/Model/CubismModel.cpp \
    $$L2D_SDK_FRAMEWORK_DIR/src/Model/CubismModelUserData.cpp \
    $$L2D_SDK_FRAMEWORK_DIR/src/Model/CubismModelUserDataJson.cpp \
    $$L2D_SDK_FRAMEWORK_DIR/src/Model/CubismUserModel.cpp \
    $$L2D_SDK_FRAMEWORK_DIR/src/Motion/ACubismMotion.cpp \
    $$L2D_SDK_FRAMEWORK_DIR/src/Motion/CubismExpressionMotion.cpp \
    $$L2D_SDK_FRAMEWORK_DIR/src/Motion/CubismMotion.cpp \
    $$L2D_SDK_FRAMEWORK_DIR/src/Motion/CubismMotionJson.cpp \
    $$L2D_SDK_FRAMEWORK_DIR/src/Motion/CubismMotionManager.cpp \
    $$L2D_SDK_FRAMEWORK_DIR/src/Motion/CubismMotionQueueEntry.cpp \
    $$L2D_SDK_FRAMEWORK_DIR/src/Motion/CubismMotionQueueManager.cpp \
    $$L2D_SDK_FRAMEWORK_DIR/src/Physics/CubismPhysics.cpp \
    $$L2D_SDK_FRAMEWORK_DIR/src/Physics/CubismPhysicsJson.cpp \
    $$L2D_SDK_FRAMEWORK_DIR/src/Rendering/OpenGL/CubismOffscreenSurface_OpenGLES2.cpp \
    $$L2D_SDK_FRAMEWORK_DIR/src/Rendering/OpenGL/CubismRenderer_OpenGLES2.cpp \
    $$L2D_SDK_FRAMEWORK_DIR/src/Rendering/CubismRenderer.cpp \
    $$L2D_SDK_FRAMEWORK_DIR/src/Type/csmRectF.cpp \
    $$L2D_SDK_FRAMEWORK_DIR/src/Type/csmString.cpp \
    $$L2D_SDK_FRAMEWORK_DIR/src/Utils/CubismDebug.cpp \
    $$L2D_SDK_FRAMEWORK_DIR/src/Utils/CubismJson.cpp \
    $$L2D_SDK_FRAMEWORK_DIR/src/Utils/CubismString.cpp \
    $$L2D_SDK_FRAMEWORK_DIR/src/CubismCdiJson.cpp \
    $$L2D_SDK_FRAMEWORK_DIR/src/CubismDefaultParameterId.cpp \
    $$L2D_SDK_FRAMEWORK_DIR/src/CubismFramework.cpp \
    $$L2D_SDK_FRAMEWORK_DIR/src/CubismModelSettingJson.cpp \
    components/l2d/l2dapp.cpp \
    components/l2d/l2dmodel.cpp \
    components/l2d/l2dallocator.cpp

HEADERS += \
        mainwindow.h \
    l2drenderwidget.h \
    components/l2d/l2dapp.h \
    components/l2d/l2dmodel.h \
    components/l2d/l2dallocator.h

INCLUDEPATH += \
    $$L2D_SDK_CORE_INC \
    $$L2D_SDK_FRAMEWORK_DIR/src

LIBS += \
    -L$$L2D_SDK_CORE_LIB_DIR \
    -lLive2DCubismCore \
    -lGLEW

FORMS += \
        mainwindow.ui
