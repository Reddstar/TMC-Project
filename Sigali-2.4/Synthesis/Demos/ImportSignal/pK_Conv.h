/*	conversion functions	*/

#ifndef pK_CONVERSIONS_H
#define pK_CONVERSIONS_H

/* Result : event */
#define pK_2_event(x) (true)

/* Result : logical */
#define pK_logical_2_logical(x)  x
#define pK_event_2_logical(x)  (true)
#define pK_short_2_logical(x)  ((logical) (x))
#define pK_int_2_logical(x)    ((logical) (x))
#define pK_long_2_logical(x)   ((logical) (x))
#define pK_float_2_logical(x)  ((logical) ((long) (x)))
#define pK_double_2_logical(x)  ((logical) ((long) (x)))
EXTERN logical pK_pK_complex_2_logical ( pK_complex E );
EXTERN logical pK_pK_complexd_2_logical ( pK_complexd E );

/* Result : short */
#define pK_short_2_short(x) x
#define pK_event_2_short(x) ((short) (1))
#define pK_logical_2_short(x) ((short) (x ? 1 : 0))
#define pK_int_2_short(x)    ((short) (x))
#define pK_long_2_short(x)   ((short) ((int) (x)))
EXTERN short pK_float_2_short ( float x );
EXTERN short pK_double_2_short ( double x );
EXTERN short pK_pK_complex_2_short ( pK_complex E );
EXTERN short pK_pK_complexd_2_short ( pK_complexd E );


/* Result :int */
#define pK_int_2_int(x) x
#define pK_short_2_int(x) ((int) (x))
#define pK_event_2_int(x) ((int) (1))
#define pK_logical_2_int(x) ((int) (x ? 1 : 0))
#define pK_long_2_int(x)     ((int) (x))
EXTERN int pK_float_2_int ( float x );
EXTERN int pK_double_2_int ( double x );
EXTERN int pK_pK_complex_2_int ( pK_complex E );
EXTERN int pK_pK_complexd_2_int ( pK_complexd E );

/* Result : long */
#define pK_long_2_long(x)   x
#define pK_short_2_long(x) ((long) (x))
#define pK_int_2_long(x)   ((long) (x)) 
#define pK_event_2_long(x) ((long) (1))
#define pK_logical_2_long(x) ((long) (x ? 1 : 0))
EXTERN long pK_float_2_long(float x);
EXTERN long pK_double_2_long(double x);
EXTERN long pK_pK_complex_2_long ( pK_complex E );
EXTERN long pK_pK_complexd_2_long ( pK_complexd E );

/* Result : float */
#define pK_float_2_float(x) x
#define pK_event_2_float(x) ((float)(1.0))
#define pK_logical_2_float(x) ((float) (x ? 1 : 0))
#define pK_short_2_float(x) ( (float) (x))
#define pK_int_2_float(x)   ( (float) (x))
#define pK_long_2_float(x)  ( (float) (x))
#define pK_double_2_float(x) ((float) (x))
EXTERN float pK_pK_complex_2_float ( pK_complex E );
EXTERN float pK_pK_complexd_2_float ( pK_complexd E );

/* Result : double */
#define pK_double_2_double(x) x
#define pK_event_2_double(x) ((double)(1.0))
#define pK_logical_2_double(x) ((double) (x ? 1 : 0))
#define pK_short_2_double(x) ( (double) (x))
#define pK_int_2_double(x)   ( (double) (x))
#define pK_long_2_double(x)  ( (double) (x))
#define pK_float_2_double(x) ( (double) (x))
EXTERN double pK_pK_complex_2_double ( pK_complex E );
EXTERN double pK_pK_complexd_2_double ( pK_complexd E );

/* Result : complex */
#define pK_complex_2_pK_complex(x) x
#define pK_event_2_pK_complex(x) ( pK_complexNew(1.0, 0.0) )
EXTERN pK_complex pK_logical_2_pK_complex ( logical E );
EXTERN pK_complex pK_short_2_pK_complex ( short E );
EXTERN pK_complex pK_int_2_pK_complex ( int E );
EXTERN pK_complex pK_long_2_pK_complex ( long E );
EXTERN pK_complex pK_float_2_pK_complex ( float E );
EXTERN pK_complex pK_double_2_pK_complex ( double E );
EXTERN pK_complex pK_pK_complexd_2_pK_complex ( pK_complexd E );

/* Result : double complex */
#define pK_pK_complexd_2_pK_complexd(x) x
EXTERN pK_complexd pK_pK_complex_2_pK_complexd ( pK_complex E );
#define pK_event_2_pK_complexd(x) ( pK_complexdNew((double) 1.0, (double)0.0))
EXTERN pK_complexd pK_logical_2_pK_complexd ( logical E );
EXTERN pK_complexd pK_short_2_pK_complexd ( short E );
EXTERN pK_complexd pK_int_2_pK_complexd ( int E );
EXTERN pK_complexd pK_long_2_pK_complexd ( long E );
EXTERN pK_complexd pK_float_2_pK_complexd ( float E );
EXTERN pK_complexd pK_double_2_pK_complexd ( double E );

/* Result : char ; restricted to short in CONV_INTRINSIC.LIB ; */
EXTERN  char pK_short_2_char(short x);

/* char_2* */
#define pK_char_2_pK_complexd(C) pK_short_2_pK_complexd( (short) C)
#define pK_char_2_pK_complex(C) pK_short_2_pK_complex( (short) C)
#define pK_char_2_double(C) ( pK_short_2_double( (short) C))
#define pK_char_2_float(C) ( pK_short_2_float( (short) C))
#define pK_char_2_long(C) ( pK_short_2_long( (short) C))
#define pK_char_2_int(C)   ( pK_short_2_int( (short) C))
#define pK_char_2_short(C) ( (short) C)
#define pK_char_2_logical(C) ( pK_short_2_logical (short) C)

/* enum_2* */
#define pK_enum_2_pK_complexd(C) pK_short_2_pK_complexd( (short) C)
#define pK_enum_2_pK_complex(C) pK_short_2_pK_complex( (short) C)
#define pK_enum_2_double(C) ( pK_short_2_double( (short) C))
#define pK_enum_2_float(C) ( pK_short_2_float( (short) C))
#define pK_enum_2_long(C) ( pK_short_2_long( (short) C))
#define pK_enum_2_int(C)   ( pK_short_2_int( (short) C))
#define pK_enum_2_short(C) ( (short) C)
#define pK_enum_2_logical(C) ( pK_short_2_logical (short) C)

#endif
