
// Resolution automatique

static unsigned long next = 1;
#define MYRAND_MAX 32767

static integer myrand()
{
  next = next * 1103515245 + 12345;
  return((unsigned)(next/65536) % (MYRAND_MAX+1));
}


/* tirage aleatoire d'un entier parmi [0 .. n-1]
   ---------------------------------------------*/
integer choix_parmi(integer n)
{
  integer ii;
  
  ii = myrand();
  ii = (integer) ((n-1)*ii / (MYRAND_MAX+1.0) );
  return ii ;
}
