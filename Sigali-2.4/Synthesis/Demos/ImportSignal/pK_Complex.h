/* 
   ---ISDT Complex Library. ---

   pK_complex : complex
   pK_complexd : double complex
   The code is defined in the file pK_complex.c
*/

#ifndef pK_COMPLEX_H
#define pK_COMPLEX_H

struct t_complex { float re, im; } ;
struct t_dcomplex { double re, im; } ;

typedef struct t_complex pK_complex;
typedef struct t_dcomplex pK_complexd;

EXTERN pK_complex pK_complexNew(float R1,float R2);

EXTERN float pK_complexRpart(pK_complex C );
EXTERN double pK_complexdRpart(pK_complexd C );

EXTERN float pK_complexIpart(pK_complex C );
EXTERN double pK_complexdIpart(pK_complexd C );

EXTERN pK_complex pK_complexNew(float R1,float R2);
EXTERN pK_complexd pK_complexdNew(double R1,double  R2);
EXTERN pK_complex pK_complexPlus ( pK_complex Complex1, pK_complex Complex2 );
EXTERN pK_complexd pK_complexdPlus ( pK_complexd Complex1, pK_complexd Complex2 );
EXTERN pK_complex pK_complexMinus ( pK_complex Complex1, pK_complex Complex2 );
EXTERN pK_complexd pK_complexdMinus ( pK_complexd Complex1, pK_complexd Complex2 );
EXTERN pK_complex pK_complexUMinus ( pK_complex Complex1 );
EXTERN pK_complexd pK_complexdUMinus ( pK_complexd E );
EXTERN pK_complex pK_complexMult ( pK_complex Complex1, pK_complex Complex2 );
EXTERN pK_complexd pK_complexdMult ( pK_complexd Complex1, pK_complexd Complex2 );
EXTERN pK_complex pK_complexDiv ( pK_complex Complex1, pK_complex Complex2 );
EXTERN pK_complexd pK_complexdDiv ( pK_complexd Complex1, pK_complexd Complex2 );
EXTERN pK_complex pK_complexPow ( pK_complex Complex1, long Complex2 );
EXTERN pK_complexd pK_complexdPow ( pK_complexd Complex1, long Complex2 );
EXTERN logical pK_complexEq ( pK_complex Complex1, pK_complex Complex2 );
EXTERN logical pK_complexdEq ( pK_complexd Complex1, pK_complexd Complex2 );
EXTERN logical pK_complexNeq ( pK_complex Complex1, pK_complex Complex2 );
EXTERN logical pK_complexdNeq ( pK_complexd Complex1, pK_complexd Complex2 );
EXTERN pK_complex pK_complexConj ( pK_complex E );
EXTERN pK_complexd pK_complexdConj ( pK_complexd E );
EXTERN float pK_complexMod ( pK_complex E );
EXTERN double pK_complexdMod ( pK_complexd E );
EXTERN float pK_complexArg ( pK_complex E );
EXTERN double pK_complexdArg ( pK_complexd E );

#endif
