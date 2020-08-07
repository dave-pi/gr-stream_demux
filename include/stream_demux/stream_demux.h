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

#ifndef INCLUDED_STREAM_DEMUX_STREAM_DEMUX_H
#define INCLUDED_STREAM_DEMUX_STREAM_DEMUX_H

#include <stream_demux/api.h>
#include <gnuradio/block.h>

namespace gr {
namespace stream_demux {

/*!
 * \brief Stream demuxing block to demultiplex one stream into
 * many with a specified format.
 * \ingroup stream_operators_blk
 *
 * \details
 * Demuxes the input stream producing N output streams that
 * contains N0 items in the first stream, N1 items in the second,
 * etc. and repeats:
 *
 * [N0, N1, N2, ..., Nm, N0, N1, ...]
 */
class STREAM_DEMUX_API stream_demux : virtual public gr::block
{
public:
    // gr::blocks::stream_demux::sptr
    typedef boost::shared_ptr<stream_demux> sptr;

    /*!
     * \brief Creates a stream demuxing block to demultiplex one stream into
     * many with a specified format.
     *
     * \param itemsize the item size of the stream
     * \param lengths  a vector (list/tuple) specifying the number of
     *                 items to copy to each output stream.
     *
     */
    static sptr make(size_t itemsize, const std::vector<int>& lengths);
};

} // namespace stream_demux
} // namespace gr

#endif /* INCLUDED_STREAM_DEMUX_STREAM_DEMUX_H */

