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

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <gnuradio/io_signature.h>
#include "iqlevels_impl.h"
#include <stdio.h>

namespace gr {
  namespace iqlevels {

    iqlevels::sptr
    iqlevels::make(double sample_rate, int showlevels)
    {
      return gnuradio::get_initial_sptr
        (new iqlevels_impl(sample_rate, showlevels));
    }

    /*
     * The private constructor
     */
    iqlevels_impl::iqlevels_impl(double sample_rate, int showlevels)
      : gr::sync_block("iqlevels",
              gr::io_signature::make(1, 1, sizeof(gr_complex)),
              gr::io_signature::make(0, 0, 0))
    {
      real_positive = 0.0;
      real_negative = 0.0;
      imag_positive = 0.0;
      imag_negative = 0.0;
      real_positive_threshold = 1.0;
      real_negative_threshold = -1.0;
      imag_positive_threshold = 1.0;
      imag_negative_threshold = -1.0;
      real_positive_threshold_count = 0;
      real_negative_threshold_count = 0;
      imag_positive_threshold_count = 0;
      imag_negative_threshold_count = 0;
      real_mean = 0.0;
      imag_mean = 0.0;
      delay = sample_rate / CHUNKS / 2;
      delay_count = delay;
      show_levels = showlevels;
      set_output_multiple(CHUNKS);
    }

    /*
     * Our virtual destructor.
     */
    iqlevels_impl::~iqlevels_impl()
    {
    }

    int
    iqlevels_impl::work(int noutput_items,
        gr_vector_const_void_star &input_items,
        gr_vector_void_star &output_items)
    {
      const gr_complex *in = (const gr_complex *) input_items[0];

      for (int i = 0; i < noutput_items; i += CHUNKS) {
        if (show_levels == TRUE) {
          for (int j = 0; j < CHUNKS; j++) {
            if (in[j].real() > real_positive) {
              real_positive = in[j].real();
            }
            if (in[j].real() < real_negative) {
              real_negative = in[j].real();
            }
            if (in[j].imag() > imag_positive) {
              imag_positive = in[j].imag();
            }
            if (in[j].imag() < imag_negative) {
              imag_negative = in[j].imag();
            }
            if (in[j].real() > real_positive_threshold) {
              real_positive_threshold_count++;
            }
            if (in[j].real() < real_negative_threshold) {
              real_negative_threshold_count++;
            }
            if (in[j].imag() > imag_positive_threshold) {
              imag_positive_threshold_count++;
            }
            if (in[j].imag() < imag_negative_threshold) {
              imag_negative_threshold_count++;
            }
            real_mean += in[j].real();
            imag_mean += in[j].imag();
          }
          real_mean = real_mean / noutput_items;
          imag_mean = imag_mean / noutput_items;
          delay_count--;
          if (delay_count == 0) {
            delay_count = delay;
            printf("real: range=[%+e to %+e],  mean=%+e,  count below -1=%d,  count above +1=%d\t", real_negative, real_positive, real_mean, real_negative_threshold_count, real_positive_threshold_count);
            printf("imag: range=[%+e to %+e],  mean=%+e,  count below -1=%d,  count above +1=%d\n", imag_negative, imag_positive, imag_mean, imag_negative_threshold_count, real_positive_threshold_count);
          }
        }
        in += CHUNKS;
      }

      // Tell runtime system how many output items we produced.
      return noutput_items;
    }

  } /* namespace iqlevels */
} /* namespace gr */

