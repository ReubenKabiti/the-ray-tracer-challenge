TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        graphics/canvas.cpp \
        main.cpp \
        math/color.cpp \
        math/helper.cpp \
        math/matrix.cpp \
        math/tuple.cpp

HEADERS += \
    graphics/canvas.h \
    math/color.h \
    math/helper.h \
    math/matrix.h \
    math/tuple.h

DEFINES += "QT_DEBUG"

DISTFILES += \
    README.md
