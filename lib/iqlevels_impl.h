/* -*- c++ -*- */
/* 
 * Copyright 2017 Ron Economos.
 * 
 * This is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3, or (at your option)
 * any later version.
 * 
 * This software is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this software; see the file COPYING.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street,
 * Boston, MA 02110-1301, USA.
 */

#ifndef INCLUDED_IQLEVELS_IQLEVELS_IMPL_H
#define INCLUDED_IQLEVELS_IQLEVELS_IMPL_H

#include <iqlevels/iqlevels.h>

#define TRUE   1
#define FALSE  0
#define CHUNKS 100

namespace gr {
  namespace iqlevels {

    class iqlevels_impl : public iqlevels
    {
     private:
      float real_positive;
      float real_negative;
      float imag_positive;
      float imag_negative;
      float real_positive_threshold;
      float real_negative_threshold;
      float imag_positive_threshold;
      float imag_negative_threshold;
      int real_positive_threshold_count;
      int real_negative_threshold_count;
      int imag_positive_threshold_count;
      int imag_negative_threshold_count;
      float real_mean;
      float imag_mean;
      int delay;
      int delay_count;
      int show_levels;

     public:
      iqlevels_impl(double sample_rate, int showlevels);
      ~iqlevels_impl();

      int work(int noutput_items,
         gr_vector_const_void_star &input_items,
         gr_vector_void_star &output_items);
    };

  } // namespace iqlevels
} // namespace gr

#endif /* INCLUDED_IQLEVELS_IQLEVELS_IMPL_H */

