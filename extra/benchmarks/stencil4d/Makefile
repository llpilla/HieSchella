OBJS = stencil4d.o

all: stencil4d

stencil4d: $(OBJS)
	$(CHARMC) -o stencil4d $(OBJS) -language charm++ $(LBOPTS) 
	mv stencil4d ${BIN}/stencil4d

projections: $(OBJS)
	$(CHARMC) -language charm++ -module CommonLBs -tracemode projections -lz -o stencil4d.prj $(OBJS)

summary: $(OBJS)
	$(CHARMC) -language charm++ -module CommonLBs -tracemode summary -lz -o stencil4d.sum $(OBJS)

stencil4d.decl.h: stencil4d.ci
	$(CHARMC)  stencil4d.ci

stencil4d.o: stencil4d.C stencil4d.decl.h
	$(CHARMC) -c stencil4d.C 

clean:
	rm -f *.decl.h *.def.h conv-host *.o stencil4d stencil4d.prj charmrun *~

test: stencil4d
	./charmrun +p4 ./stencil4d 32 16 +balancer GreedyLB $(TESTOPTS)
	./charmrun +p4 ./stencil4d 32 16 +balancer RefineLB $(TESTOPTS)

bgtest: stencil4d
	./charmrun +p4 ./stencil4d 32 16 +balancer CommLB +x2 +y2 +z1 +cth1 +wth1
