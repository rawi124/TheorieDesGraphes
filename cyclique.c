#include <stdio.h>
#include <stdlib.h>

#include "graphe.h"
#include "pile.h"
#include "cyclique.h"



int acyc(sommet s , graphe g)
{
  int * trace = calloc(g.nbs,sizeof(int));
  int t , v ;
  liste aux ;
  pile p = NULL;
  for(int k = 0 ; k < g.nbs ; k++)
  {
    Empiler(k,&p);
    if(trace[k] == BLANC)
    //si sommet non visité
    {
      trace[k] = GRIS;
      //je marque que je suis passe par lui sans dire que je l'ai traite
      while(p)
      {
        v = Depiler(&p);
        aux = g.adj[v];
        while(aux)
        {
          t = aux->num ;
          if(trace[t] == GRIS)
          {
             printf("le graphe est cyclique\n");
             return 0 ;
          }
          if(trace[t] == BLANC)
          {
            Empiler(t,&p);
            trace[t]=GRIS;
        //gris veut dire deja ete sur la _pile_
        //blanc veut dire jamais visite
        //noir veut dire parcouru et sortie de la pile
          }
          
          aux = aux -> svt ;
        }
        trace[v] = NOIR ;
      }
    }
  }
  printf("le graphe est acyclique\n");
  return 1 ;

}

int * pas ;
int parcoursP(sommet s , graphe g)
{
  int courant , tete ;
  liste aux ;
  pile Pile = NULL;
  Empiler(s,&Pile);
  if(pas[s] == BLANC)
  {
    pas[s] = GRIS;
    while(Pile)
    {
        tete = Depiler(&Pile);
        aux = g.adj[tete];
        while(aux)
        {
          courant = aux->num ;
          if (pas[courant] == GRIS )
          	return 0 ;
          if(pas[courant] == BLANC)
          {
            Empiler(courant,&Pile);
            pas[courant]=GRIS;
          }

    
          aux = aux -> svt ;
        }
        pas[tete] = NOIR ;   
      }
    }
    return 1 ;
}
int acyclique(graphe g)
{	
	conversionListe(&g);
	pas = malloc(g.nbs * sizeof(int));
	for(int s = 0 ; s < g.nbs ; s++)
	{
		if(!parcoursP(s,g))
		{
			printf("le graphe est cyclique\n");
			return 0 ;
		}
	}
	printf("le graphe est Acyclique \n");
	return 1 ;
}
	


































