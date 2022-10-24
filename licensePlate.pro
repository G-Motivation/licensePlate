QT       += core gui \
            multimedia \
            multimediawidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

QMAKE_CXXFLAGS_RELEASE = $$QMAKE_CFLAGS_RELEASE_WITH_DEBUGINFO
QMAKE_LFLAGS_RELEASE = $$QMAKE_LFLAGS_RELEASE_WITH_DEBUGINFO

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0
include(./licenseplatedialog.pri)
include(./testQT/gtest_dependency.pri)

SOURCES += \
    main.cpp \

HEADERS += \
    ui_licenseplatedialog.h \
    yolo_v2_class.hpp

FORMS += \
    licenseplatedialog.ui

win32: {
    LIBS += $$PWD/OpenCV/bin/libopencv_*.dll \
                   -L$$quote(C:/Program Files/NVIDIA GPU Computing Toolkit/CUDA/v11.7/lib/x64) -lcublas -lcuda -lcudadevrt -lcudart -lcudart_static -lOpenCL \
                   -L$${PWD} -lyolo_cpp_dll
    INCLUDEPATH += $$PWD/OpenCV/install/include
}

macx {
    LIBS += /Users/huangyaode/code/opencv/build_arm64/lib

    INCLUDEPATH += /opt/homebrew/Cellar/opencv/4.5.5_1/include/opencv4
}

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
