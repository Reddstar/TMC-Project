include $(SIGALI_pack)/config

memincl=../mem/export
tddincl=../tdd/export
resincl=export

obj=export
incl=$(resincl)

OPTIONS= -Wno-deprecated -g
COMPILER=$(CPP) $(OPTIONS) $(COMPILER_HOST_DEF) -I$(resincl) -I$(tddincl) -I$(memincl)

OBJECTS=$(obj)/configuration.o  $(obj)/equation.o  $(obj)/fonction.o  $(obj)/resolveur.o \
 $(obj)/variable.o

all: $(OBJECTS)

$(obj)/variable.o: variable.c $(incl)/variable.h
	$(COMPILER) -c variable.c  -o $(obj)/variable.o


$(obj)/configuration.o: configuration.c $(incl)/configuration.h  $(incl)/equation.h  $(incl)/fonction.h
	$(COMPILER) -c configuration.c -o $(obj)/configuration.o

$(obj)/equation.o: equation.c $(incl)/equation.h $(incl)/variable.h random.c
	$(COMPILER) -c equation.c -o $(obj)/equation.o

$(obj)/fonction.o: fonction.c $(incl)/fonction.h $(incl)/variable.h
	$(COMPILER) -c fonction.c -o $(obj)/fonction.o

$(obj)/resolveur.o: resolveur.c $(incl)/resolveur.h $(incl)/configuration.h
	$(COMPILER) -c resolveur.c -o $(obj)/resolveur.o

clean:
	@rm $(obj)/*.o

force: clean all


