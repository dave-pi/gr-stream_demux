/* -*- c++ -*- */
/*
 * Copyright 2020 Free Software Foundation, Inc.
 *
 * This file is part of GNU Radio
 *
 * GNU Radio is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3, or (at your option)
 * any later version.
 *
 * GNU Radio is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with GNU Radio; see the file COPYING.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street,
 * Boston, MA 02110-1301, USA.
 */

#ifndef INCLUDED_STREAM_DEMUX_STREAM_DEMUX_IMPL_H
#define INCLUDED_STREAM_DEMUX_STREAM_DEMUX_IMPL_H

#include <stream_demux/stream_demux.h>

namespace gr {
namespace stream_demux {

class STREAM_DEMUX_API stream_demux_impl : public stream_demux
{
private:
    const size_t d_itemsize;
    unsigned int d_stream;         // index of currently selected stream
    int d_residual;                // number of items left to put into current stream
    const gr_vector_int d_lengths; // number of items to pack per stream

public:
    stream_demux_impl(size_t itemsize, const std::vector<int>& lengths);

    void forecast (int noutput_items, gr_vector_int& ninput_items_required);

    int general_work(int noutput_items,
                     gr_vector_int& ninput_items,
                     gr_vector_const_void_star& input_items,
                     gr_vector_void_star& output_items);

};

} // namespace stream_demux
} // namespace gr

#endif /* INCLUDED_STREAM_DEMUX_STREAM_DEMUX_IMPL_H */

