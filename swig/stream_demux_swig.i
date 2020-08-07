/* -*- c++ -*- */

#define STREAM_DEMUX_API

%include "gnuradio.i"           // the common stuff

//load generated python docstrings
%include "stream_demux_swig_doc.i"

%{
#include "stream_demux/stream_demux.h"
%}

%include "stream_demux/stream_demux.h"
GR_SWIG_BLOCK_MAGIC2(stream_demux, stream_demux);
