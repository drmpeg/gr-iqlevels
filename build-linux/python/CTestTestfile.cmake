# CMake generated Testfile for 
# Source directory: /media/psf/Home/Google Drive/inoui/src/gr-iqlevels/python
# Build directory: /media/psf/Home/Google Drive/inoui/src/gr-iqlevels/build-linux/python
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(qa_iqlevels "/usr/bin/sh" "qa_iqlevels_test.sh")
set_tests_properties(qa_iqlevels PROPERTIES  _BACKTRACE_TRIPLES "/usr/lib/x86_64-linux-gnu/cmake/gnuradio/GrTest.cmake;116;add_test;/media/psf/Home/Google Drive/inoui/src/gr-iqlevels/python/CMakeLists.txt;34;GR_ADD_TEST;/media/psf/Home/Google Drive/inoui/src/gr-iqlevels/python/CMakeLists.txt;0;")
subdirs("bindings")
