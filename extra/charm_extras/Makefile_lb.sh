#!/bin/sh
UNCOMMON_LDBS="TempAwareGreedyLB MetisLB ScotchLB TeamLB WSLB"
COMMON_LDBS="BlockLB CommLB DummyLB GreedyAgentLB GreedyCommLB GreedyLB NeighborCommLB NeighborLB OrbLB PhasebyArrayLB RandCentLB RecBipartLB RefineLB RefineCommLB RotateLB TreeMatchLB"
OTHER_LDBS="ComboCentLB GraphPartLB GraphBFTLB GridCommLB GridCommRefineLB GridHybridLB GridHybridSeedLB GridMetisLB HbmLB HybridLB RefineKLB RefineTopoLB TopoCentLB TopoLB TopologyAwareLB StatsLB NucoLB NucoLBNode NucoLBCent HwTopoLB HwTopoLBNode HwTopoLBCent StatsLBCent StatsLBNode HierarchicalLB"
ALL_LDBS="$COMMON_LDBS $OTHER_LDBS"

out="Make.lb"

echo "# Automatically generated by script Makefile_lb.sh" > $out
echo "ALL_LDBS=\\" >> $out
for bal in $ALL_LDBS 
do 
	echo "   \$(L)/libmodule$bal.a \\" >> $out 
done
echo "   manager.o" >> $out
echo >> $out

for bal in $ALL_LDBS $UNCOMMON_LDBS
do 
	dep=""
	[ -r libmodule$bal.dep ] && dep="cp -f libmodule$bal.dep "'$'"(L)/"
        manager=""
        [ $bal = 'GreedyCommLB' ] && manager="manager.o"
        [ $bal = 'GridCommLB' ] && manager="manager.o"
        [ $bal = 'GridCommRefineLB' ] && manager="manager.o"
        [ $bal = 'GridHybridLB' ] && manager="manager.o"
        [ $bal = 'GridHybridSeedLB' ] && manager="manager.o"
        [ $bal = 'TreeMatchLB' ] && manager="tm_tree.o tm_bucket.o tm_timings.o tm_mapping.o"
	cat >> $out << EOB 

\$(L)/libmodule$bal.a: $bal.o $manager
	\$(CHARMC) -o \$(L)/libmodule$bal.a $bal.o $manager
	$dep
LBHEADERS += $bal.h $bal.decl.h

EOB
done

echo "// AUTOMATICALLY GENERATED FILE" > EveryLB.ci
echo "" >> EveryLB.ci
echo "module EveryLB {" >> EveryLB.ci
for bal in $ALL_LDBS
do
	echo "  extern module $bal;" >> EveryLB.ci
done
echo "" >> EveryLB.ci
echo "  initnode void initEveryLB(void);" >> EveryLB.ci
echo "};" >> EveryLB.ci

echo "// AUTOMATICALLY GENERATED FILE" > CommonLBs.ci
echo "" >> CommonLBs.ci
echo "module CommonLBs {" >> CommonLBs.ci
for bal in $COMMON_LDBS
do
        echo "  extern module $bal;" >> CommonLBs.ci
done
echo "" >> CommonLBs.ci
echo "  initnode void initCommonLBs(void);" >> CommonLBs.ci
echo "};" >> CommonLBs.ci

echo "# used for make depends" >> $out
echo "ALL_LB_OBJS=EveryLB.o \\" >> $out
echo "    CommonLBs.o \\" >> $out
for bal in $ALL_LDBS $UNCOMMON_LDBS
do
	echo "    $bal.o \\" >> $out
done
echo "    manager.o  \\" >> $out
echo "    tm_tree.o  \\" >> $out
echo "    tm_timings.o  \\" >> $out
echo "    tm_bucket.o \\" >> $out
echo "    tm_mapping.o" >> $out

echo "# EveryLB dependecies" >> $out
echo "EVERYLB_DEPS=EveryLB.o \\" >> $out
for bal in $ALL_LDBS
do
	echo "    $bal.o \\" >> $out
done
echo "    manager.o \\" >> $out
echo "    tm_tree.o  \\" >> $out
echo "    tm_timings.o  \\" >> $out
echo "    tm_bucket.o \\" >> $out
echo "    tm_mapping.o" >> $out

echo "# CommonLBs dependencies" >> $out
echo "COMMONLBS_DEPS=CommonLBs.o \\" >> $out
for bal in $COMMON_LDBS
do
	echo "    $bal.o \\" >> $out
done
echo "    manager.o" \\>> $out
echo "    tm_tree.o  \\" >> $out
echo "    tm_timings.o  \\" >> $out
echo "    tm_bucket.o \\" >> $out
echo "    tm_mapping.o" >> $out

cat >> $out <<EOB

\$(L)/libmoduleEveryLB.a: \$(EVERYLB_DEPS)
	\$(CHARMC) -o \$(L)/libmoduleEveryLB.a \$(EVERYLB_DEPS)

\$(L)/libmoduleCommonLBs.a: \$(COMMONLBS_DEPS)
	\$(CHARMC) -o \$(L)/libmoduleCommonLBs.a \$(COMMONLBS_DEPS)
EOB