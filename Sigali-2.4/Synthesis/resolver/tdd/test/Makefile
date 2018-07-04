#
# Memory manager (export)

MEM=$(memincl)
obj=../export
incl=../export

COPTIONS=-g 
LDOPTIONS=
YACCOPTIONS=-v
RMOPTIONS=-i
CC=g++  $(COMPILER_HOST_DEF) -I$(incl)
COMPILE=${CC} ${COPTIONS} -I${MEM}

#-------------------------
#    test
#-------------------------
test: tddtest_re.o $(obj)/tddmanager_re.o $(obj)/tdd_re.o $(obj)/tdddump_re.o\
	     $(obj)/tddtable_re.o $(obj)/tddcache_re.o $(obj)/tddassoc_re.o $(obj)/tdderror_re.o $(obj)/tddresolve_re.o
	${CC} ${COPTIONS}  tddtest_re.o $(obj)/tddmanager_re.o $(obj)/tdd_re.o $(obj)/tdddump_re.o\
		$(obj)/tddtable_re.o $(obj)/tddcache_re.o $(obj)/tddassoc_re.o $(obj)/tdderror_re.o $(obj)/tddresolve_re.o\
		${MEM}/memblock.o ${MEM}/memrec.o\
		-o tddtest

tddtest_re.o: $(incl)/tddint.h tddtest_re.c random.c
	$(COMPILE) -c tddtest_re.c -o  tddtest_re.o

