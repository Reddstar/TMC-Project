#
# Memory manager (export)

include $(SIGALI_pack)/config

memincl=../mem/export
MEM=$(memincl)
obj=export
incl=export
tddpack=$(SIGALI_packTdd)
tdd_src_sigali=$(SIGALI_pack)/tdd

#  Compiling options

COPTIONS=-g 
LDOPTIONS=
YACCOPTIONS=-v
RMOPTIONS=-i
CC=$(CPP)  $(COMPILER_HOST_DEF) -I$(incl)
COMPILE=$(CC) $(COPTIONS) -I$(MEM)

IMPORT_SIGALI= $(obj)/tddassoc.o $(obj)/tddcache.o $(obj)/tdderror.o $(obj)/tddtable.o $(obj)/tdd.o 

LOC_OBJ=$(obj)/tdd_redefined.o $(obj)/tddundump.o $(obj)/tddmanager_re.o $(obj)/tddresolve_re.o 
all: $(IMPORT_SIGALI) $(LOC_OBJ)

$(obj)/tddassoc.o: $(tdd_src_sigali)/tddassoc.c  $(incl)/tddint.h
	$(COMPILE) -c $(tdd_src_sigali)/tddassoc.c -o $(obj)/tddassoc.o

$(obj)/tddcache.o:$(tdd_src_sigali)/tddcache.c $(incl)/tddint.h
	$(COMPILE) -c $(tdd_src_sigali)/tddcache.c -o $(obj)/tddcache.o

$(obj)/tddtable.o:$(tdd_src_sigali)/tddtable.c $(incl)/tddint.h
	$(COMPILE) -c $(tdd_src_sigali)/tddtable.c -o $(obj)/tddtable.o

$(obj)/tdderror.o: $(tdd_src_sigali)/tdderror.c $(incl)/tddint.h
	$(COMPILE) -c $(tdd_src_sigali)/tdderror.c  -o $(obj)/tdderror.o

$(obj)/tdd.o: $(incl)/tddint.h $(tdd_src_sigali)/tdd.c
	$(COMPILE) -c $(tdd_src_sigali)/tdd.c -o $(obj)/tdd.o

$(obj)/tddmanager_re.o: $(incl)/tddint.h tddmanager_re.c
	$(COMPILE) -c tddmanager_re.c -o $(obj)/tddmanager_re.o

$(obj)/tdd_redefined.o: $(incl)/tddint.h tdd_redefined.c
	$(COMPILE) -c tdd_redefined.c -o $(obj)/tdd_redefined.o


$(obj)/tddundump.o: $(incl)/tddint.h tddundump.c
	$(COMPILE) -I$(tdd_src_sigali) -c tddundump.c -o $(obj)/tddundump.o

tddundump.c:$(tdd_src_sigali)/tdddump_m.c $(tdd_src_sigali)/tddundump_g.c


$(obj)/tddresolve_re.o: $(incl)/tddint.h  tddresolve_re.c
	$(COMPILE) -c tddresolve_re.c -o $(obj)/tddresolve_re.o

clean:
	@rm $(obj)/*.o

force: clean all
