/* _Decimal32 compare greater-than for soft-dfp

   Copyright (C) 2007, 2008 IBM Corporation.
   Copyright (C) 2008-2015 Free Software Foundation, Inc.

   This file is part of the Decimal Floating Point C Library.

   Author(s): Pete Eberlein <eberlein@us.ibm.com>

   The Decimal Floating Point C Library is free software; you can
   redistribute it and/or modify it under the terms of the GNU Lesser
   General Public License version 2.1.

   The Decimal Floating Point C Library is distributed in the hope that
   it will be useful, but WITHOUT ANY WARRANTY; without even the implied
   warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See
   the GNU Lesser General Public License version 2.1 for more details.

   You should have received a copy of the GNU Lesser General Public
   License version 2.1 along with the Decimal Floating Point C Library;
   if not, write to the Free Software Foundation, Inc., 51 Franklin
   Street, Fifth Floor, Boston, MA 02110-1301 USA.

   Please see libdfp/COPYING.txt for more information.  */

#ifndef _DECIMAL_SIZE
#  include <decimal32.h>
#  define _DECIMAL_SIZE 32
#  define ACTUAL_FUNCTION_NAME gtsd2
#endif

#include <decContext.h>
#include <decNumber.h>
#include <math.h>

#define FUNCTION_NAME gt

#include "dfpacc.h"
#include <dfpmacro.h>
CMPINT
PREFIXED_FUNCTION_NAME (DEC_TYPE x, DEC_TYPE y)
{
  decNumber dn_x, dn_y, result;
  decContext context;
  decContextDefault(&context, DEFAULT_CONTEXT);

  FUNC_CONVERT_TO_DN(&x, &dn_x);
  FUNC_CONVERT_TO_DN(&y, &dn_y);

  if(decNumberIsNaN(&dn_x) || decNumberIsNaN(&dn_y))
    return -1;

  decNumberCompare(&result, &dn_x, &dn_y, &context);
  return !decNumberIsNegative(&result) && !decNumberIsZero(&result);
}
hidden_def (PREFIXED_FUNCTION_NAME)
