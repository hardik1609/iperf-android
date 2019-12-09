/*---------------------------------------------------------------
 * Copyright (c) 2015 Mentor Graphics Corporation
 *---------------------------------------------------------------
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software (Iperf) and associated
 * documentation files (the "Software"), to deal in the Software
 * without restriction, including without limitation the
 * rights to use, copy, modify, merge, publish, distribute,
 * sublicense, and/or sell copies of the Software, and to permit
 * persons to whom the Software is furnished to do
 * so, subject to the following conditions:
 *
 *
 * Redistributions of source code must retain the above
 * copyright notice, this list of conditions and
 * the following disclaimers.
 *
 *
 * Redistributions in binary form must reproduce the above
 * copyright notice, this list of conditions and the following
 * disclaimers in the documentation and/or other materials
 * provided with the distribution.
 *
 *
 * Neither the names of the University of Illinois, NCSA,
 * nor the names of its contributors may be used to endorse
 * or promote products derived from this Software without
 * specific prior written permission.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
 * OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE CONTIBUTORS OR COPYRIGHT
 * HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 * WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
 * ARISING FROM, OUT OF OR IN CONNECTION WITH THE
 * SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 * ________________________________________________________________
 * National Laboratory for Applied Network Research
 * National Center for Supercomputing Applications
 * University of Illinois at Urbana-Champaign
 * http://www.ncsa.uiuc.edu
 * ________________________________________________________________
 *
 * common.c
 * by Rahul Rajendran <rahul_rajendran@mentor.com>
 * -------------------------------------------------------------------
 * A wrapper function which calls clock_gettime with CLOCK_MONOTONIC
 * parameter. The intention is to replace relative time computations
 * to use the monotonic time, instead of system time for robustness
 * against system time jumps.
 * The wrapper function gettimeofday_monotonic() is intended to
 * replace all calls of gettimeofday().
 * ------------------------------------------------------------------- */

#include "headers.h"

int gettimeofday_monotonic( struct timeval* tv, void* timezone ) {
	struct timespec ts;
	int retval;
	retval = clock_gettime(CLOCK_MONOTONIC, &ts);

	tv->tv_sec = ts.tv_sec;
	tv->tv_usec = ts.tv_nsec / 1000L;

	return retval;
}

