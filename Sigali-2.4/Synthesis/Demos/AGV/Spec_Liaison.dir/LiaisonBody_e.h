typedef int boolean;
#define TRUE 1
#define FALSE 0

EXTERN void WSTOP(long int *b);
EXTERN void dessine_chariot_agv1(int Pos_AGV1[]);
EXTERN void dessine_chariot_agv2(int Pos_AGV2[]);
EXTERN void dessine_chariot_agv3(int Pos_AGV3[]);
EXTERN void dessine_chariot_agv4(int Pos_AGV4[]);
EXTERN void dessine_chariot_agv5(int Pos_AGV5[]);
EXTERN void dessine_chariot_wst1(int Pos_WST1[]);
EXTERN void dessine_chariot_wst2(int Pos_WST2[]);
EXTERN void dessine_chariot_wst3(int Pos_WST3[]);
EXTERN void dessine_chariot_wst4(int Pos_WST4[]);
EXTERN void dessine_chariot_wst5(int Pos_WST5[]);
EXTERN void affiche_conflit(int a, int b, int c, int d);
/* EXTERN void rhe(int  *h1,int *h2);*/
EXTERN boolean r_vt_HE(int  *h1);

EXTERN void RESET_PANEL(boolean cauto);

EXTERN void resolver(int cod_cond[], int cod_x[], int cod_u[],
			   int cod_y[], boolean *fin_resolver);

EXTERN void WIWRITE(int *widgst_pt, int v);
