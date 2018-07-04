CC= g++
LINKER=g++
ADR_vtagv=vt
OBJ_RES=$(ADR_EXPORT_RES)/*.o

all:$(DEMOLIB)

$(DEMOLIB):$(OBJ_RES) $(ADR_liaison)/LiaisonResolveur.c $(ADR_liaison)/LiaisonPacemaker.c $(ADR_spec_liaison)/LiaisonBody.c  $(ADR_vtagv)/vt_body.o
	$(LINKER) $(LINKER_DYN_OPTIONS) -I$(JDK_INCLUDE) -I$(JDK_INCL_DEP) -I$(SignalLibC_export) \
	-I$(ADR_EXPORT_RES) -I$(ADR_vtagv) -I$(ADR_liaison) -I$(ADR_spec_liaison) \
        $(ADR_vtagv)/vt_body.o \
	$(OBJ_RES) \
	$(ADR_liaison)/LiaisonResolveur.c \
	$(ADR_liaison)/LiaisonPacemaker.c \
        $(ADR_spec_liaison)/LiaisonBody.c \
        -o $(DEMOLIB)

$(ADR_vtagv)/vt_body.o:$(ADR_vtagv)/vt_body.c
	$(CC) -I$(SignalLibC_export) -D_NO_PROTO -c $(ADR_vtagv)/vt_body.c -o $(ADR_vtagv)/vt_body.o

$(ADR_vtagv)/vt_body.c:vt.SIG.SIG vt.PAR
	$(Signal_bin)/signal -c -tra vt.SIG.SIG -par=vt.PAR

force: clean  all

clean:
	\rm $(DEMOLIB) $(ADR_vtagv)/vt_body.o

