#include <stdio.h>
#include <stdlib.h>

#include "graphe.h"
#include "pile.h"
#include "composanteGeante.h"

int pas  ;
int*trace ;
int*nombre ;

void parcoursGeant(int s , graphe G )
{
    trace[s] = 1 ;
    for (int j = 0 ; j < G.nbs ; j++)
    {
	     if(trace[j] == 0 && G.mat[s][j] == 1 )
	      {
		        pas ++;
		        parcoursGeant(j,G);
	      }
    }
}
void ComposanteConnexeGeante(graphe G)
{
    trace = calloc(G.nbs , sizeof(int));
    int sommet = 0 , x = 0 ;
    int n = G.nbs ;
    for (int i = 0 ; i < n ; i++)
    {
	     if(trace[i] == 0)
	     {
         parcoursGeant(i,G);
         	if(G.mat[i][i+pas])pas ++ ;
	       if (pas > x){ x = pas ;sommet = i;pas=0;}
       }
    }
  printf("le graphe geant est celui qui commence par %d et fait %d pas\n",sommet,x);
}


int * Trace ;
int CompoGeantePile(graphe g) 
{
  Trace = calloc(g.nbs,sizeof(int));
  int t , v ;
  liste aux ;
  pile p = NULL;
  int pas = 0 ;
  int maxi = 0 ;
  int nb = 0 ;
  for(int k = 0 ; k < g.nbs ; k++)
  {
    Empiler(k,&p);
    if(Trace[k] == BLANC)
    {
      nb++;
      Trace[k] = GRIS;
              
      while(p)
      {

        v = Depiler(&p);
        aux = g.adj[v];
        while(aux)
        {
          
          t = aux->num ;
          if(Trace[t] == BLANC)
          {
  
	    pas++; 
            Empiler(t,&p);
            Trace[t]=GRIS;
          }
          aux = aux -> svt ;
        }
        
      }
    }
    if(maxi < pas)
    	maxi = pas ;
    pas = 0 ;
  }
  return maxi ;

}
