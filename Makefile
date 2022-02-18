libgraphe.a : inout.o graphe.o connexe.o pile.o file.o euler.o disjoint.o coloriage.o hamitolien.o cyclique.o composanteGeante.o cube.o ensemble.o articulation.o kruscal.o reine.o
	ar crs libgraphe.a inout.o graphe.o connexe.o pile.o file.o euler.o disjoint.o coloriage.o hamitolien.o cyclique.o composanteGeante.o cube.o ensemble.o articulation.o kruscal.o reine.o
graphe.o : graphe.c
	gcc -c -Wall graphe.c
inout.o : inout.c
	gcc -c -Wall inout.c
connexe.o : connexe.c
	gcc -Wall -c connexe.c
euler.o : euler.c
	gcc -Wall -c euler.c
pile.o : pile.c
	gcc -Wall -c pile.c
file.o : file.c
	gcc -Wall -c file.c
reine.o : reine.c
	gcc -Wall -c reine.c
disjoint.o : disjoint.c
	gcc -Wall -c disjoint.c	
coloriage.o : coloriage.c
	gcc -Wall -c coloriage.c
hamitolien.o : hamitolien.c
	gcc -Wall -c hamitolien.c
cyclique.o : cyclique.c
	gcc -Wall -c cyclique.c
composanteGeante.o : composanteGeante.c
	gcc -Wall -c composanteGeante.c
cube.o : cube.c
	gcc -Wall -c cube.c
ensemble.o : ensemble.c
	gcc -Wall -c ensemble.c
articulation.o : articulation.c
	gcc -c -Wall articulation.c
kruscal.o : kruscal.c
	gcc -c -Wall kruscal.c -lm
