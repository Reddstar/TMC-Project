
#ifndef pK_SIGNAL_PREDEF_H
#define pK_SIGNAL_PREDEF_H

/* Constants */
#undef TRUE
#define TRUE 1
#undef FALSE
#define FALSE 0

/* Signal Predefined Types : logical, String, complex, Dcomplex */
typedef int logical;

#include "pK_String.h"
#include "pK_Complex.h"
#include "pK_Conv.h"
#include "pK_ArrayCmp.h"
#include "pK_stdio.h"

#define polychrony_exception(s) printf(s)

#endif
