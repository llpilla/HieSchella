# to be set appropiately
all: leanmd

leanmd: Main.o Cell.o Compute.o leanmd.decl.h
	$(CHARMC) $(OPTS) -module CkMulticast -language charm++ -o leanmd Main.o Cell.o Compute.o $(LBOPTS)
	mv leanmd $(BIN)/leanmd

Main.o: Main.cc Main.h leanmd.decl.h defs.h
	$(CHARMC) $(OPTS) -o Main.o Main.cc

Cell.o: Cell.cc Cell.h leanmd.decl.h defs.h
	$(CHARMC) $(OPTS) -o Cell.o Cell.cc

leanmd.decl.h:	leanmd.ci
	$(CHARMC) leanmd.ci

Compute.o: Compute.cc Compute.h leanmd.decl.h defs.h physics.h
	$(CHARMC) $(OPTS) -o Compute.o Compute.cc

test:
	./charmrun +p4 ./leanmd 4 4 4 101 20 20

clean:
	rm -f *.decl.h *.def.h *.o leanmd leanmd.prj charmrun
