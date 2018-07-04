#ifndef pK_pK_STRING_H
#define pK_pK_STRING_H

#define pK_MAXSTRINGLENGTH_ 256
typedef char pK_String [pK_MAXSTRINGLENGTH_];

/* The strcmp() function  compares  two  strings  byte-by-byte,
   according  to  the ordering of your machine's character set.
   The function returns an integer greater than, equal  to,  or
   less  than  0,  if   the  string pointed to by s1 is greater
   than, equal to, or less than the string  pointed  to  by  s2
   respectively.  The sign of a non-zero return value is deter-
   mined  by the sign of the difference between the  values  of
   the  first  pair  of  bytes that differ in the strings being
   compared. */

#define pK_StringEQ(n,m) (strcmp(n,m) == 0)
#define pK_StringNEQ(n,m) (strcmp(n,m) != 0)
#define pK_StringLT(n,m) (strcmp(n,m) < 0)
#define pK_StringGT(n,m) (strcmp(n,m) > 0)
#define pK_StringLTE(n,m) (strcmp(n,m) <= 0)
#define pK_StringGTE(n,m) (strcmp(n,m) >= 0)


#endif
