typedef int boolean;
#define TRUE 1
#define FALSE 0

EXTERN void WSTOP(long int *b);
EXTERN void Draw_Cat(int Pos_Cat[]);
EXTERN void Draw_Mouse(int Pos_Mouse[]);
EXTERN void Draw_Door_Cat(int Door_Cat[]);
EXTERN void Draw_Door_Mouse(int Door_Mouse[]);
EXTERN void Draw_Conflict(int Conflict);
EXTERN boolean r_vt_HE(int  *h1);
/* EXTERN void rhe(int  *h1,int *h2);*/

EXTERN void RESET_PANEL(boolean cauto);

EXTERN void resolver(int cod_cond[], int cod_x[], int cod_u[],
			   int cod_y[], boolean *fin_resolver);

EXTERN void WIWRITE(int *widgst_pt, int v);
