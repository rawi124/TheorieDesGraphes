#include <stdio.h>
#include <stdlib.h>

#include "graphe.h"
#include "hamitolien.h"

int * libre ;
int * parcou ;//normalement il est de taille le nombre d arete 
int compteur ;
void ParcoursHamiltonien(int s,int p,graphe  g)
{
	int t ;
	if(p == g.nbs)
	{
		compteur++;
		return  ;
	}
	for(t = 0 ; t < g.nbs ;t++)
	{
	    if(g.mat[s][t] || g.mat[t][s])
	    {
	       if (libre[t])
	       {
	           libre[t] = 0 ;
	           parcou[p] = t ;
	           ParcoursHamiltonien(t,p+1,g);
	           libre[t] = 1 ;
	        }
	    }
	}
}
void Hamitolien(graphe g)
{
	compteur = 0 ;
	libre = calloc(g.nbs,sizeof(int));
	for(int f = 0 ; f < g.nbs ; f++)
		libre[f] = 1 ;
		
	int nb = nbArete(g);
	parcou = calloc(nb,sizeof(int));
	ParcoursHamiltonien(0,0,g);
	if (compteur != 0)
	{
		printf("ce graphe est hamitolien %d fois et voici un parcours possible \n",compteur);
		for(int k = 0 ; k < g.nbs ; k++)
			printf("%d ",parcou[k]);
		printf("\n");
	}
	else 
		printf("ce graphe n est pas hamitolien \n");
}

