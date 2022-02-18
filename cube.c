#include <stdio.h>
#include <stdlib.h>

#include "graphe.h"
#include "cube.h"

int weight(int x)
{
	int res = 0 ;
	while(x > 0)
	{
		x&=(x-1);
		res++;
	}
	return res ;
}
graphe hypercube(int r)
{
	int n = (1 << r );

	graphe g = creer_graphe(n);
		
	for(int i = 0 ; i < n ; i++)
	{
		for(int j = i+1; j < n ; j++)
		{
			
			if( weight(i^j) == 1)
			{
				g.mat[i][j] = g.mat[j][i] = 1 ;
				
			}
		}
	}
	return g ;
} 
