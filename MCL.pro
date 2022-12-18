#**********************************************************************************************************************************
#
# PROJECT:						Math Class Library
# FILE:               MCL
# SUBSYSTEM:					Maths class library.
# LANGUAGE:						C++
# TARGET OS:					WINDOWS/UNIX/LINUX/MAC
# LIBRARY DEPENDANCE: None.
# NAMESPACE:					MCL
# AUTHOR:							Gavin Blakeman.
# LICENSE:            GPLv2
#
#                     Copyright 2012-2022 Gavin Blakeman.
#                     This file is part of the Maths Class Library (MCL)
#
#                     MCL is free software: you can redistribute it and/or modify it under the terms of the GNU General Public
#                     License as published by the Free Software Foundation, either version 2 of the License, or (at your option)
#                     any later version.
#
#                     MCL is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied
#                     warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
#                     more details.
#
#                     You should have received a copy of the GNU General Public License along with MCL.  If not, see
#                     <http://www.gnu.org/licenses/>.
#
# OVERVIEW:           The MCL is a collection of mathematics functions for C++. The library uses templates as far as possible.
#                     All computationally intensive functions are multi-threaded as far as possible.
#
# CLASSES INCLUDED:
#
#
# HISTORY:            2015-09-22 GGB - astroManager 2015.09 release
#                     2014-01-13 GGB - Added file statistics/sum.hpp to the library
#                     2013-07-28 GGB - Added file statistics/median.hpp and utility/sort.hpp to the library.
#                     2013-06-16 GGB - File created.
#
#*********************************************************************************************************************************

TARGET = MCL
TEMPLATE = lib
CONFIG += staticlib create_prl

QMAKE_CXXFLAGS += -std=c++20

DESTDIR = ""
OBJECTS_DIR = "objects"

INCLUDEPATH += \
  "../GCL" \
  "../SCL"

SOURCES += \
    source/angle.cpp \
    source/Shared.cpp \
    source/common.cpp \
    source/numeric.cpp \
    test/functions/linearRegression.cpp \
    test/main.cpp \
    test/statistics/distributionFunctions/weibull_test.cpp \
    test/statistics/mean_test.cpp \
    test/statistics/median_test.cpp \
    test/statistics/percentile_test.cpp

HEADERS += \
    include/TPoint2D.hpp \
    include/constants.h \
    include/exceptions.h \
    include/functions/linearRegression.hpp \
    include/statistics/distributionFunctions/chi-square.h \
    include/statistics/distributionFunctions/weibull.hpp \
    include/statistics/kolmogorov-smirnov.hpp \
    include/statistics/minmax.hpp \
    include/statistics/percentile.hpp \
    include/statistics/variance.hpp \
    include/statistics/stdev.hpp \
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
    include/fraction.hpp \
    include/financial/futureValue.hpp \
    include/gcd.hpp \
    include/functions/gcd.hpp

DISTFILES += \
    changelog.txt \
    test/CMakeLists.txt

