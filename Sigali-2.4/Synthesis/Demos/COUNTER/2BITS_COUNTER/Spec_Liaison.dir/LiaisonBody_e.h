typedef int boolean;
#define TRUE 1
#define FALSE 0

EXTERN void Draw(boolean ,boolean ,boolean );
EXTERN void WSTOP(long int *b);

EXTERN boolean r_vt_HE(int  *h1);

EXTERN void RESET_PANEL(boolean cauto);

EXTERN void resolver(int cod_cond[], int cod_x[], int cod_u[],
			   int cod_y[], boolean *fin_resolver);

EXTERN void WIWRITE(int ,int );
