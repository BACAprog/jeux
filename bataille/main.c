//#include "graphics.h"
#include <stdio.h> //au cas ou on a pas le graphics.c
typedef struct carte {
	
	int coul; //1:coeur / 2:carreau / 3:pique / 4:trèfle
	int valeur; //valeur de la carte, de 1 à 13
	int ID; //ID de la carte en fonction du jeu (pour 1 jeu c'est égale a 52, pour 2 c'est 104,..)
} carte;


void melange(carte jeu[52]) //initialise le jeu en le mélangant
{
	int a,b,c;
	int ID=1;
	
	for(a=1;a<13;a++)
	{
		for(b=0;b<4;b++)
		{
			
			c=alea_int(52);
			
			if(jeu[c].valeur==0)
			{
				jeu[c].valeur=a;
				jeu[c].coul=b;
				jeu[c].ID=ID;
				ID++; 
			}
		}
	}
}

void init_paquet(carte jeu[52])
{
	int a;
	
	for (a=0;a<52;a++)
	{
		jeu[a].valeur=0;
		jeu[a].coul=0;
		jeu[a].ID=0;
	}
}

void init_jeu(carte jeu1[52],carte jeu2[52]) //initialise le jeu(inutile?)
{
	init_paquet(jeu1);
	init_paquet(jeu2);
	melange(jeu1);
	
}

int comparaison(carte jeu1[52],carte jeu2[52])//comapare les 2 premières cartes de chaque paquet et return la valeur du gagnant
{
	return(0);
}

void cartes_recupere(carte jeu1[52],carte jeu2[52],int a) //envois les 2 premieres cartes de chaque paque dans le paquet de "a"
{
	
}

int nb_de_carte(carte jeu[52]) //détermine le nombre de carte le jeu
{
	return(0);
}

int main ()
{
	carte jeu1[52];
	carte jeu2[52];
	int a,p1,p2;
	p1=p2=26;
	
	init_jeu(jeu1,jeu2);
	while(p1>0 && p2>0)
	{
		a=comparaison(jeu1,jeu2);
		cartes_recupere(jeu1,jeu2,a);
		p1=nb_de_carte(jeu1);
		p2=nb_de_carte(jeu2);
	}
	for (a=0;a<52;a++)
	{
		printf("%d   %d  %d \n",jeu1[a].valeur,jeu1[a].coul,a); 
	}
	
	exit(0);
}