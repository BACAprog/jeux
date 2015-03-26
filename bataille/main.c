#include "graphics.h"
//#include <stdio.h> //au cas ou on a pas le graphics.c


//faire les #difine

typedef struct carte {
	
	int coul; //1:coeur / 2:carreau / 3:pique / 4:trèfle
	int valeur; //valeur de la carte, de 1 à 13
	int ID; //ID de la carte en fonction du jeu (pour 1 jeu c'est égale a 52, pour 2 c'est 104,..)
	int dessu; //si besoin est...
	int dessou;//...on eura besoin de l'un des 2
} carte;


void tri(carte jeu[52]) //initialise le jeu en le mélangant
{
int a,b;
	int ID=1;
	
	for(a=1;a<=13;a++)
	{
		for(b=1;b<=4;b++)
		{
			
			jeu[ID].valeur=a;
			jeu[ID].coul=b;
			jeu[ID].ID=ID;
			ID++; 
		}
	}
}

void melange(carte jeu[52],carte jeuretour[52])//mélange le paquet jeuretour a partir du jeu 
{
	int c,v,a;
	
	for(c=1;c<=52;c++)
	{
		v=0;
		do{
			a=alea_int(52);
			
			if(jeuretour[a].ID==0)
			{
				jeuretour[a]=jeu[c];
				v=1;
			}
		}while(v==0);
	}
	
}

void init_paquet(carte jeu[52])//toutes les valeurs du jeu sont mis a 0
{
	int a;
	
	for (a=0;a<52;a++)
	{
		jeu[a].valeur=0;
		jeu[a].coul=0;
		jeu[a].ID=0;
	}
}

void division(carte jeu1[52],carte jeu2[52])//divise le jeu1 en 2, la 2eme moitié va au jeu1
{
	int c;
	
	for(c=26;c<=52;c++)
	{
		jeu2[c-26]=jeu1[c];
		jeu1[c].ID=0;
		jeu1[c].valeur=0;
		jeu1[c].coul=0;
	}
	
}

void init_jeu(carte jeu1[52],carte jeu2[52]) //initialise les jeux 1 et 2 (la moitié dans chaque)
{
	carte jeu3[52];
	
	//initialisation des paquet(optionel)?
	init_paquet(jeu1);
	init_paquet(jeu2);
	init_paquet(jeu3);
	
	//création du jeu3 puis le jeu1 est mélangé
	tri(jeu3);
	melange(jeu3,jeu1);
	
	//divise le jeu
	division(jeu1,jeu2);
	
	
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

int main ()//le main maggle
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

	exit(0);
}
