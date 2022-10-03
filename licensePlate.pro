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
    ui_licenseplatedialog.h

FORMS += \
    licenseplatedialog.ui

win32: {
    LIBS += OpenCV\bin\libopencv_*.dll
    INCLUDEPATH += OpenCV\install\include
}

macx {
    LIBS += /Users/huangyaode/code/opencv/build_arm64/lib

    INCLUDEPATH += /opt/homebrew/Cellar/opencv/4.5.5_1/include/opencv4
}

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
