#include "graphics.h"
//#include <stdio.h> //au cas ou on a pas le graphics.c


//faire les #define

typedef struct CARTE {
	
	int coul;   //1:coeur / 2:carreau / 3:pique / 4:trèfle
	int valeur; //valeur de la carte, de 1 à 13
	int ID;     //ID de la carte en fonction du jeu (pour 1 jeu c'est égale a 52, pour 2 c'est 104,..)
	} CARTE;

typedef struct paquet{
	
	CARTE car[52]; //un jeu a 52 carte...
	int debut;     //debut de la file
	int fin;	   //fin de la file
	} paq;

paq init_paquet(paq jeu)//toutes les valeurs du jeu sont mis a 0
{
	int a;
	
	for (a=0;a<52;a++)
	{
		jeu.car[a].valeur=0;
		jeu.car[a].coul=0;
		jeu.car[a].ID=0;
		jeu.debut=0;
		jeu.fin=-1;
		
	}
	return (jeu);
}

paq tri(paq jeu) //initialise le jeu en le mélangant
{
	int a,b;
	int ID=1;
	
	for(a=1;a<=13;a++)
	{
		for(b=1;b<=4;b++)
		{
			
			jeu.car[ID].valeur=a;
			jeu.car[ID].coul=b;
			jeu.car[ID].ID=ID;
			ID++; 
		}
	}
	return (jeu);
}

paq melange(paq jeu,paq jeuretour)//mélange le paquet jeuretour a partir du jeu 
{
	int c,v,a;
	
	for(c=1;c<=52;c++)
	{
		v=0;
		do{
			a=alea_int(52);
			
			if(jeuretour.car[a].ID==0)
			{
				jeuretour.car[a]=jeu.car[c];
				v=1;
			}
		}while(v==0);
	}
	return(jeuretour);
}

void division(paq jeu1,paq jeu2)//divise le jeu1 en 2, la 2eme moitié va au jeu1
{
	int c;
	
	for(c=26;c<=52;c++)
	{
		jeu2.car[c-26]=jeu1.car[c];
		jeu1.car[c].ID=0;
		jeu1.car[c].valeur=0;
		jeu1.car[c].coul=0;
	}
	
}

void init_jeu(paq *jeu1,paq *jeu2) //initialise les jeux 1 et 2 (la moitié dans chaque)
{
	paq jeu3;
	
	//initialisation des paquet(optionel)?
	*jeu1=init_paquet(*jeu1);
	*jeu2=init_paquet(*jeu2);
	jeu3=init_paquet(jeu3);
	
	//création du jeu3 puis le jeu1 est mélangé
	jeu3=tri(jeu3);
	*jeu1=melange(jeu3,*jeu1);
	
	//divise le jeu
	division(*jeu1,*jeu2);
	
	
}

int comparaison(paq jeu1,paq jeu2)//comapare les 2 premières cartes de chaque paquet et return la valeur du gagnant
{											  //si il y a égalité c'est 0 qui est return
	if     (jeu1.car[0].valeur < jeu2.car[0].valeur){return(2);}
	else if(jeu1.car[0].valeur > jeu2.car[0].valeur){return(1);}
	else if(jeu1.car[0].valeur ==jeu2.car[0].valeur){return(0);}
	else   {printf("erreur dans la comparaison");return(100);}
}

void cartes_recupere(paq *jeu1,paq *jeu2,int a) //envois les cartes de chaque paque dans le paquet de "a"
{																		//et le place avec p1 ou p2
	
}


void bataille (paq *jeu1,paq *jeu2)
{
	//nombre de carte a coucher en fonction de la valeur de la carte 
	//a mettre dans un tas a part ?
	
	// avance des cartes
	
	//comparaison
}

paq combat(paq *jeu1,paq *jeu2)
{
	paq cartesprises;
			
	if (comparaison(*jeu1,*jeu2)){bataille(jeu1,jeu2);} //si c'est 1,il y a battaille(même carte)
	

	
	

	return (cartesprises);
}

int filevide(paq jeu)
{
	
	
	return (1);
}		

int main ()//le main maggle
{
	paq jeu1;    //jeu du joueur 1
	paq jeu2;    //jeu du joueur 2
	
	int gagnant; //nombre de cartes dans les paquet des joueurs 1 et 2
	
	init_jeu(&jeu1,&jeu2);
	
		printf("jeu1\n\n\n");
		printf("valeur  couleur  ID\n");
	int a;
	for (a=0;a<52;a++)
	{
		printf("  %d      %d     %d\n",jeu1.car[a].valeur,jeu1.car[a].coul,jeu1.car[a].ID);
	}
	
	while(filevide(jeu1) && filevide(jeu2)) //filevide revoi 1 pour une file non vide
	{
		combat(&jeu1,&jeu2);
		
		cartes_recupere(&jeu1,&jeu2,gagnant);
	}

	exit(0);
}
