#----------------------------------------------------------------
# Generated CMake target import file for configuration "Release".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "gnuradio::gnuradio-iqlevels" for configuration "Release"
set_property(TARGET gnuradio::gnuradio-iqlevels APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(gnuradio::gnuradio-iqlevels PROPERTIES
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/x86_64-linux-gnu/libgnuradio-iqlevels.so.801791d3"
  IMPORTED_SONAME_RELEASE "libgnuradio-iqlevels.so.1.0.0git"
  )

list(APPEND _IMPORT_CHECK_TARGETS gnuradio::gnuradio-iqlevels )
list(APPEND _IMPORT_CHECK_FILES_FOR_gnuradio::gnuradio-iqlevels "${_IMPORT_PREFIX}/lib/x86_64-linux-gnu/libgnuradio-iqlevels.so.801791d3" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
