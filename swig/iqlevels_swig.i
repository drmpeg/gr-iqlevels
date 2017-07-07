/* -*- c++ -*- */

#define IQLEVELS_API

%include "gnuradio.i"			// the common stuff

//load generated python docstrings
%include "iqlevels_swig_doc.i"

%{
#include "iqlevels/iqlevels.h"
%}


%include "iqlevels/iqlevels.h"
GR_SWIG_BLOCK_MAGIC2(iqlevels, iqlevels);
