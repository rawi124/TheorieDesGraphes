#ifndef FILE_H
#define FILE_H

#include "graphe.h"
#include "pile.h"
#include "cyclique.h"

#define GRIS 1
#define BLANC 0
#define NOIR 2

	 
struct _lis_ { 
	int val; 
	struct _lis_ *svt; 
};
typedef struct _lis_* Liste;

struct _file_ { 
	   int longueur; 
	   Liste tete; 
	   Liste queue; 
	}; 
typedef struct _file_ * File;  

#define fileEstVide(F) ((F)->longueur == 0) 
File fileVide(); 
void enfiler(File F, int element);  
int defiler(File F); 
int parcoursFile( graphe g);

#endif
