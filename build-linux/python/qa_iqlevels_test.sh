#!/usr/bin/sh
export VOLK_GENERIC=1
export GR_DONT_LOAD_PREFS=1
export srcdir="/media/psf/Home/Google Drive/inoui/src/gr-iqlevels/python"
export GR_CONF_CONTROLPORT_ON=False
export PATH="/media/psf/Home/Google Drive/inoui/src/gr-iqlevels/build-linux/python":"$PATH"
export LD_LIBRARY_PATH="":$LD_LIBRARY_PATH
export PYTHONPATH=/media/psf/Home/Google Drive/inoui/src/gr-iqlevels/build-linux/test_modules:$PYTHONPATH
/usr/bin/python3 /media/psf/Home/Google Drive/inoui/src/gr-iqlevels/python/qa_iqlevels.py 
