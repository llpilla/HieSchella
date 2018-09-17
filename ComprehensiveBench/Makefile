OPTS	= -O3
CHARMDIR = ~/charm
CHARMC = $(CHARMDIR)/bin/charmc $(OPTS)

OBJS	= ComprehensiveBench.o

all: ComprehensiveBench

ComprehensiveBench: $(OBJS)
	$(CHARMC) -language charm++ -module CommonLBs -o $(output_file) $(OBJS)

projections: $(COMPOBJS)
	$(CHARMC) -language charm++ -tracemode projections -lz -o ComprehensiveBench.prj $(OBJS)

ComprehensiveBench.decl.h: ComprehensiveBench.ci
	$(CHARMC) ComprehensiveBench.ci

ComprehensiveBench.o: ComprehensiveBench.C ComprehensiveBench.decl.h
	$(CHARMC) -c ComprehensiveBench.C

clean:
	rm -f *.decl.h *.def.h conv-host *.o charmrun *~ ComprehensiveBench.prj

