
# assumed: doxygen is available
adr=html/
all:  $(adr)index.html

$(adr)index.html: doxygenAAREADME  AAREADME.txt
	cp *.pdf $(adr).
	doxygen doxygenAAREADME

clean:
	-rm $(adr)*

force: clean all
