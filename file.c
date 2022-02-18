#include <stdio.h>
#include <stdlib.h>

#include "file.h"
#include "pile.h"
#include "graphe.h"
#include "cyclique.h"

File fileVide()
{ 
	   File F; 
	   F = (File)malloc(sizeof(struct _file_)); 
	   if (F == NULL) 
	   	printf("erreur allocation fileVide"); 
	   F->longueur = 0; 
	   F->tete = F->queue = NULL; 
	   return(F); 
} 
	 
void enfiler(File F, int val)
{ 
   Liste aux; 
   aux = (Liste)malloc(sizeof(struct _lis_)); 
   aux->val = val; 
   aux->svt = NULL; 
   if (F->longueur == 0)
    	F->tete = F->queue = aux; 
   else 
   { 
     F->queue->svt = aux; 
     F->queue = aux; 
   }
   ++(F->longueur); 
} 
	
 

int defiler(File F) { 
   Liste aux; 
   int val; 
   aux = F->tete; 
   val = aux->val; 
   if (F->longueur == 1)
      F->tete = F->queue = NULL;
   else 
      F->tete = F->tete->svt; 
   free(aux); 
   --(F->longueur); 
   return val; 
 } 	 

int parcoursFile( graphe g)
{
  int * trace = calloc(g.nbs,sizeof(int));
  int * couleur = calloc(g.nbs,sizeof(int));
  int t , v;
  liste aux ;
  File f = fileVide(); 
  // un graphe acyclique est 2-coloriable
  if (acyclique(g))
  {
  	printf("c est un graphe bi-coloriable \n");
  	return 1 ;
  }
  	
  for(int k = 0 ; k < g.nbs ; k++)
  {
    enfiler(f,k);
    
    if(trace[k] == BLANC)
    {
      trace[k] = GRIS;
      while(!fileEstVide(f))
      {
        v = defiler(f); 
        aux = g.adj[v];
        while(aux)
        {
          t = aux->num ;
          if(trace[t] == BLANC)
          {
            enfiler(f,t);
            if (couleur[v] == 0)
            	couleur[t] = 1 ;
            else 	
            	couleur[t] = 0 ;
            trace[t]=GRIS;
          }
          aux = aux -> svt ;
        }
        trace[v] = NOIR ;
      }
    }
  }
  for(int j = 0 ; j < g.nbs-1 ; j++)
  {
  	liste aux = g.adj[j] ;
  	while(aux)
  	{
  		if( couleur[j] == couleur[aux->num])
  		{
  			printf("ce n est pas un graphe bi-coloriable\n");
  			return 0 ;
  		}
  		aux = aux -> svt ;
  	}
  }
  printf(" c est un graphe bi-coloriable \n");
  return 1 ; 	
}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	


