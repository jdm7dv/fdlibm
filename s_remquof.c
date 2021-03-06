/* Compute remainder and a congruent to the quotient.
   Copyright (C) 1997-2013 Free Software Foundation, Inc.
   This file is part of the GNU C Library.
   Contributed by Ulrich Drepper <drepper@cygnus.com>, 1997.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */

#ifndef __FDLIBM_H__
#include "fdlibm.h"
#endif

#ifndef __have_fpu_remquo

float __ieee754_remquof(float x, float y, int *quo)
{
	int32_t hx, hy;
	uint32_t sx;
	int cquo;
	int32_t qs;

	static const float zero = 0.0;

	GET_FLOAT_WORD(hx, x);
	GET_FLOAT_WORD(hy, y);
	sx = hx & IC(0x80000000);
	qs = sx ^ (hy & IC(0x80000000));
	hy &= IC(0x7fffffff);
	hx &= IC(0x7fffffff);

	/* Purge off exception values.  */
	if (hy == 0)
		return (x * y) / (x * y);		/* y = 0 */
	if ((hx >= IC(0x7f800000))			/* x not finite */
		|| (hy > IC(0x7f800000)))		/* y is NaN */
		return (x * y) / (x * y);

	if (hy <= IC(0x7dffffff))
		x = __ieee754_fmodf(x, 8 * y);	/* now x < 8y */

	if ((hx - hy) == 0)
	{
		*quo = qs ? -1 : 1;
		return zero * x;
	}

	x = __ieee754_fabsf(x);
	y = __ieee754_fabsf(y);
	cquo = 0;

	if (x >= 4 * y)
	{
		x -= 4 * y;
		cquo += 4;
	}
	if (x >= 2 * y)
	{
		x -= 2 * y;
		cquo += 2;
	}

	if (hy < IC(0x01000000))
	{
		if (x + x > y)
		{
			x -= y;
			++cquo;
			if (x + x >= y)
			{
				x -= y;
				++cquo;
			}
		}
	} else
	{
		float y_half = 0.5 * y;

		if (x > y_half)
		{
			x -= y;
			++cquo;
			if (x >= y_half)
			{
				x -= y;
				++cquo;
			}
		}
	}

	*quo = qs ? -cquo : cquo;

	if (sx)
		x = -x;
	return x;
}

#endif

float __remquof(float x, float y, int *quo)
{
	return __ieee754_remquof(x, y, quo);
}

__typeof(__remquof) remquof __attribute__((weak, alias("__remquof")));
