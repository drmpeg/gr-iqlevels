INCLUDE(FindPkgConfig)
PKG_CHECK_MODULES(PC_IQLEVELS iqlevels)

FIND_PATH(
    IQLEVELS_INCLUDE_DIRS
    NAMES iqlevels/api.h
    HINTS $ENV{IQLEVELS_DIR}/include
        ${PC_IQLEVELS_INCLUDEDIR}
    PATHS ${CMAKE_INSTALL_PREFIX}/include
          /usr/local/include
          /usr/include
)

FIND_LIBRARY(
    IQLEVELS_LIBRARIES
    NAMES gnuradio-iqlevels
    HINTS $ENV{IQLEVELS_DIR}/lib
        ${PC_IQLEVELS_LIBDIR}
    PATHS ${CMAKE_INSTALL_PREFIX}/lib
          ${CMAKE_INSTALL_PREFIX}/lib64
          /usr/local/lib
          /usr/local/lib64
          /usr/lib
          /usr/lib64
)

INCLUDE(FindPackageHandleStandardArgs)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(IQLEVELS DEFAULT_MSG IQLEVELS_LIBRARIES IQLEVELS_INCLUDE_DIRS)
MARK_AS_ADVANCED(IQLEVELS_LIBRARIES IQLEVELS_INCLUDE_DIRS)

