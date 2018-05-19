#-------------------------------------------------
#
# Project created by QtCreator 2013-06-16T08:32:14
#
#-------------------------------------------------

QT       -= core gui

TARGET = MCL
TEMPLATE = lib
CONFIG += staticlib

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

QMAKE_CXXFLAGS += -std=c++17

INCLUDEPATH += \
  "../boost 1.62" \
  "../GCL"

SOURCES += \
    Source/angle.cpp \
    Source/MCLError.cpp \
    Source/Shared.cpp \
    Source/common.cpp \
    Source/numeric.cpp


HEADERS += \
    Include/MCLError.h \
    Include/TPoint2D.hpp \
    Include/constants.h \
    Include/Statistics/variance.hpp \
    Include/Statistics/stdev.hpp \
    Include/Statistics/MinMax.hpp \
    Include/Statistics/mean.hpp \
    Include/Statistics/median.hpp \
    Include/Utility/sort.hpp \
    MCL \
    Include/Statistics/sum.hpp \
    Include/Trigonometry.hpp \
    Include/config.h \
    Include/common.h \
    Include/numeric.h \
    Include/angle.h \
    Include/functions.hpp \
    Include/TVector3D.hpp

