INCLUDE(FindPkgConfig)
PKG_CHECK_MODULES(PC_STREAM_DEMUX stream_demux)

FIND_PATH(
    STREAM_DEMUX_INCLUDE_DIRS
    NAMES stream_demux/api.h
    HINTS $ENV{STREAM_DEMUX_DIR}/include
        ${PC_STREAM_DEMUX_INCLUDEDIR}
    PATHS ${CMAKE_INSTALL_PREFIX}/include
          /usr/local/include
          /usr/include
)

FIND_LIBRARY(
    STREAM_DEMUX_LIBRARIES
    NAMES gnuradio-stream_demux
    HINTS $ENV{STREAM_DEMUX_DIR}/lib
        ${PC_STREAM_DEMUX_LIBDIR}
    PATHS ${CMAKE_INSTALL_PREFIX}/lib
          ${CMAKE_INSTALL_PREFIX}/lib64
          /usr/local/lib
          /usr/local/lib64
          /usr/lib
          /usr/lib64
          )

include("${CMAKE_CURRENT_LIST_DIR}/stream_demuxTarget.cmake")

INCLUDE(FindPackageHandleStandardArgs)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(STREAM_DEMUX DEFAULT_MSG STREAM_DEMUX_LIBRARIES STREAM_DEMUX_INCLUDE_DIRS)
MARK_AS_ADVANCED(STREAM_DEMUX_LIBRARIES STREAM_DEMUX_INCLUDE_DIRS)
