
#ifndef pK_IOSTD_H
#define pK_IOSTD_H

#define pK_PRINT(s) printf(s)

/* Integer */
#define pK_READint(x) { if (scanf("%d", &x)!=1) return FALSE; }
#define pK_WRITEint(s)  printf("%d\n", s)

#define pK_READshort(x)  pK_READint(x)
#define pK_WRITEshort(s)  pK_WRITEint(s)

#define pK_READlong(x)  { if (scanf("%ld", &x)!=1) return FALSE; }
#define pK_WRITElong(s)  printf("%ld\n", s)


#define pK_WRITElogical(s) (s ? printf("True\n") : printf("False\n"))
#define pK_READlogical(s) pK_READint(s)

#define pK_READfloat(x) { if (scanf("%f", &x)!=1) return FALSE; }
#define pK_WRITEfloat(s)  printf("%f\n", s)

#define pK_READdouble(x) { if (scanf("%lf", &x)!=1) return FALSE; }
#define pK_WRITEdouble(s)  printf("%lf\n", s)


#define pK_READpK_String(x) { if (scanf("%s", &x)!=1) return FALSE; }
#define pK_WRITEpK_String(s)  printf("%s\n", s)

#define pK_READchar(x) { if (scanf("%c", &x)!=1) return FALSE; getchar();}
#define pK_WRITEchar(s)  printf("%c\n", s)


/* Complex */
#define pK_READpK_complex(x) { if (scanf("%f", &x.re)!=1) return FALSE; if (scanf("%f", &x.im)!=1) return FALSE;}
#define pK_WRITEpK_complex(s)  printf("(%f, %f)\n", s.re, s.im);

#define pK_READpK_complexd(x) { if (scanf("%lf", &x.re)!=1) return FALSE; if (scanf("%lf", &x.im)!=1) return FALSE;}
#define pK_WRITEpK_complexd(s)  printf("(%lf, %lf)\n", s.re, s.im);


#endif
