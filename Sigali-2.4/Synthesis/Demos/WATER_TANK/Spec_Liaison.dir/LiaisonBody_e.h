typedef int boolean;
#define TRUE 1
#define FALSE 0

EXTERN void WSTOP(long int *b);

EXTERN void Draw(boolean  Flow_Pump, boolean  Flow_Valve2, boolean  Valve2,boolean Valve3, boolean Valve4); 
EXTERN void Draw_State(boolean X0,boolean X1,boolean X2,boolean X3,boolean X4,boolean X5,boolean X6,boolean Flow);
EXTERN boolean r_vt_HE(int  *h1);

EXTERN void RESET_PANEL(boolean cauto);

EXTERN void resolver(int cod_cond[], int cod_x[], int cod_u[],
			   int cod_y[], boolean *fin_resolver);

EXTERN void WIWRITE(int *widgst_pt, int v);
