#-------------------------------------------------
#
# Project created by QtCreator 2013-06-16T08:32:14
#
#-------------------------------------------------

TARGET = MCL
TEMPLATE = lib
CONFIG += staticlib

#QT       -= core gui
QMAKE_CXXFLAGS += -std=c++17

win32:CONFIG(release, debug|release) {
  DESTDIR = "../Library/win32/release"
  OBJECTS_DIR = "../Library/win32/release/object/MCL"
  }
else:win32:CONFIG(debug, debug|release) {
  DESTDIR = "../Library/win32/debug"
  OBJECTS_DIR = "../Library/win32/debug/object/MCL"
}
else:unix:CONFIG(release, debug|release) {
  DESTDIR = "../Library/unix/release"
  OBJECTS_DIR = "../Library/unix/release/object/MCL"
}
else:unix:CONFIG(debug, debug|release) {
  DESTDIR = ""
  OBJECTS_DIR = "objects"
}

INCLUDEPATH += \
  "../boost 1.62" \
  "../GCL" \
  "../SCL"

SOURCES += \
    source/angle.cpp \
    source/Shared.cpp \
    source/common.cpp \
    source/numeric.cpp \
    source/error.cpp

HEADERS += \
    include/TPoint2D.hpp \
    include/constants.h \
    include/statistics/variance.hpp \
    include/statistics/stdev.hpp \
    include/statistics/MinMax.hpp \
    include/statistics/mean.hpp \
    include/statistics/median.hpp \
    include/utility/sort.hpp \
    MCL \
    include/statistics/sum.hpp \
    include/config.h \
    include/common.h \
    include/numeric.h \
    include/angle.h \
    include/functions.hpp \
    include/TVector3D.hpp \
    include/trigonometry.hpp \
    include/error.h

