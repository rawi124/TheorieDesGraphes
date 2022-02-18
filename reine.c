#include "stdio.h"
#include "stdlib.h"
#include "reine.h"

int nb ;
int * colonne ;
int **LigneColonne ;

void reserverCavalier(int i , int j , int**tab , int n)
{
    if(i+1<n )
    {
        if(j+2<n)
            tab[i+1][j+2]++;
        if(j-2>=0)
            tab[i+1][j-2]++;
    }
    if(i+2<n)
    {
        if(j+1<n)
            tab[i+2][j+1]++;
        if(j-1>=0)
            tab[i+2][j-1]++; 
    }
}

void dereserverCavalier(int i , int j , int**tab , int n)
{
    if(i+1<n )
    {
        if(j+2<n)
            tab[i+1][j+2]--;
        if(j-2>=0)
            tab[i+1][j-2]--;
    }
    if(i+2<n)
    {
        if(j+1<n)
            tab[i+2][j+1]--;
        if(j-1>=0)
            tab[i+2][j-1]--; 
    }
}

void reineCavalier(int i , int n )
{

	int j ;
	if(i == n)
	{
		nb++;
		return  ;
	}
	for(j = 0 ; j < n ;j++)
	{
		if (!(colonne[j]))
		{
			if(!(LigneColonne[i][j]) )
			{
				colonne[j]++ ;
				reserverCavalier(i,j,LigneColonne,n);
				reineCavalier(i+1,n);
				colonne[j]-- ;
				dereserverCavalier(i,j,LigneColonne,n);
			}
		}

	}
}



int V(int m)
{
	nb = 0;
	colonne = malloc(m*sizeof(int));
	LigneColonne = calloc(m,sizeof(int*));
        for(int k =0;k<m;k++)
        	LigneColonne[k] = calloc(m,sizeof(int));
	reineCavalier(0,m);
	printf("%d\n",nb);
	return nb ;

}
