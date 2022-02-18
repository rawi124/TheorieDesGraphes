#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "time.h"

int nb ;

int acceptable(int i , int j , int n,int R[])
{
	int k ;
	for(k = 0 ; k < i ; k++)
		if (R[k] == j)
			return 0 ;
	for(k = 0 ; k < i ; k++)
		if(abs(j-R[k]) == i-k)
			return 0 ;
	return 1 ;
}

void reine (int i , int n , int pos[] )
{

	int j ;
	if(i == n)
	{
		nb++;
		return  ;
	}
	for(j = 0 ; j < n ;j++)
	{
		if (acceptable(i,j,n,pos))
		{
		pos[i] = j ;
		reine(i+1,n,pos);
		pos[i] = -1 ;

		}

	}
}

int main(int argc,char*argv[])
{
	nb = 0;
	int n = 15 ;
	int * tab = malloc(n*sizeof(int));
	float temps ;
	clock_t t1,t2 ;
	for(int i = 13 ; i < 20 ; i++)
	{
	t1= clock();
	reine(0,i,tab);
	t2 = clock() ;
	printf("%d  %f\n",i,(float)t2-t1);
}
	return 0 ;
}
