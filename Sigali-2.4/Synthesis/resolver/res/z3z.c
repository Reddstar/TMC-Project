#include "z3z.h"

z3z boolean2z3z(int b) {
  if (b) {
    return 1;
  } else {
    return 2;
  }
}

int z3z2boolean(z3z v) {
  if (v == 1) {
    return 1;
  } else { // v = 0 (absent) or v = 2
    return 0;
  }
}

z3z getonevalue(z3z *controllables) {
  // test possible values one by one
  // assume at least one possible
  // test the true possible value first
  if (controllables[1]) {
    return 1;
  } else if (controllables[2]) {
    return 2;
  } else {
    return 0;
  }
}

/* Return true if variable has strictly more than one possible value
   (the variable can be instantiated) */
int severalvalues(z3z *controllables) {
  int nbsol = 0;
  if (controllables[0]) { nbsol = nbsol + 1; }
  if (controllables[1]) { nbsol = nbsol + 1; }
  if (controllables[2]) { nbsol = nbsol + 1; }
  return (nbsol > 1);
}





