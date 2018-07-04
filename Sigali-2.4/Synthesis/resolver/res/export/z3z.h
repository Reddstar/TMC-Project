#ifndef Z3Z_H
#define Z3Z_H
/* Z/3Z values manipulations */

#include "integer.h"


typedef integer z3z; // 0 = absent, 1 = true, 2 = false

z3z boolean2z3z(int b);

int z3z2boolean(z3z v);

z3z getonevalue(z3z *controllables);

int severalvalues(z3z *controllables);

#endif
