OPTS	=	-O3 " #-g
CHARMC	=	"~/charm/bin/charmc $(OPTS)
LBOPTS	=	"-module CommonLBs -lscotch -lscotcherr -hwloc"
BIN	=	"~/tests/121212/bin"

all: lmd stencil kN lbtest

lmd:
	@echo "-- Building leanmd"
	cd leanmd ; $(MAKE) clean
	cd leanmd ; $(MAKE) all CHARMC=$(CHARMC) LBOPTS=$(LBOPTS) BIN=$(BIN)

kN:
	@echo "-- Building kNeighbor"
	cd kNeighbor ; $(MAKE) clean
	cd kNeighbor ; $(MAKE) all CHARMC=$(CHARMC) LBOPTS=$(LBOPTS) BIN=$(BIN)

stencil:
	@echo "-- Building stencil4d"
	cd stencil4d ; $(MAKE) clean
	cd stencil4d ; $(MAKE) all CHARMC=$(CHARMC) LBOPTS=$(LBOPTS) BIN=$(BIN)

lbtest:
	@echo "-- Building lb_test"
	cd lb_test ; $(MAKE) clean
	cd lb_test ; $(MAKE) all CHARMC=$(CHARMC) LBOPTS=$(LBOPTS) BIN=$(BIN)
