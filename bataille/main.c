#include "graphics.h"


//faire les #define

typedef struct CARTE {
	
	int coul;   //1:coeur / 2:carreau / 3:pique / 4:trèfle
	int valeur; //valeur de la carte, de 1 à 13
	int ID;     //ID de la carte en fonction du jeu (pour 1 jeu c'est égale a 52, pour 2 c'est 104,..)
	int retourne;//0 si verso,1 si recto
	} CARTE;

typedef struct paquet{
	
	CARTE car[52]; //un jeu a 52 carte...
	int joueur	;   //joueur a qui appartient le jeu
	int debut;     //debut de la file
	int fin;	   //fin de la file
	} paq;

typedef struct connard{	//le moment ou j'ai pété un cable 
	paq paq1;			//ce...truc sert a...return 2 paquet,juste a ça...
	paq paq2;
}connard;

void test_jeu(paq jeu)
{
	printf("valeur  couleur  ID  num\n");
	int a;
	for (a=0;a<52;a++)
	{
		printf("  %d      %d       %d    %d\n",jeu.car[a].valeur,jeu.car[a].coul,jeu.car[a].ID,a+1);
	}
}

paq init_paquet(paq jeu)//toutes les valeurs du jeu sont mis a 0
{
	int a;
	
	for (a=0;a<=52;a++)
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
	int ID=0;
	
	for(a=1;a<=13;a++)
	{
		for(b=1;b<=4;b++)
		{
			
			jeu.car[ID].valeur=a;
			jeu.car[ID].coul=b;
			jeu.car[ID].ID=ID+1;
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
				jeuretour.car[a]=jeu.car[c-1];
				v=1;
			}
		}while(v==0);
	}
	return(jeuretour);
}

connard division(paq jeu1,paq jeu2)//divise le jeu1 en 2, la 2eme moitié va au jeu1
{
	connard a;
	int c;
	
	for(c=26;c<=52;c++)
	{
		jeu2.car[c-26]=jeu1.car[c];
		jeu1.car[c].ID=0;
		jeu1.car[c].valeur=0;
		jeu1.car[c].coul=0;
		
	}
	                             //de plus la file est initialisé.
	jeu1.debut=1;
	jeu2.debut=1;
	jeu1.fin=26;
	jeu2.fin=26;
	
	a.paq1=jeu1;
	a.paq2=jeu2;
	return(a);
	
}

void init_jeu(paq *jeu1,paq *jeu2) //initialise les jeux 1 et 2 (la moitié dans chaque)
{
	paq jeu3;
	connard a;
	
	//initialisation des paquet
	*jeu1=init_paquet(*jeu1);
	*jeu2=init_paquet(*jeu2);
	jeu3=init_paquet(jeu3);
	
	//création du jeu3 puis le jeu1 est mélangé
	jeu3=tri(jeu3);
	*jeu1=melange(jeu3,*jeu1);
	
	//divise le jeu et initialise les files
	a=division(*jeu1,*jeu2);
	*jeu1=a.paq1;
	*jeu2=a.paq2;

	
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
			
	if (comparaison(*jeu1,*jeu2)==0){bataille(jeu1,jeu2);} //si c'est 1,il y a battaille(même carte)
	

	
	

	return (cartesprises);
}

int filevide(paq jeu)//0 si la file est vide
{

	if (jeu.debut == jeu.fin){return 0;}
	else{return 1;}
	
}

// affichage carte
void affiche_carte_retourne( POINT hg, POINT bd, POINT hg2, POINT bd2)
{
	POINT l1, l2, l3, l4;
	int a=0 ;
	
	l1.x = l3.x= hg.x + 5;
	l2.x = l4.x= bd.x - 5;
	
	l1.y = l2.y = bd.y +5;
	l3.y = l4.y = bd2.y + 5;
	
	draw_line(l1,l2 ,red);
	draw_line(l3, l4, red);
	while (a < 90)
	{
		l1.y = l2.y = l1.y + 5;
		l3.y = l4.y = l3.y +5; 
		
		draw_line(l1,l2 ,red);
		draw_line(l3, l4, red);
		a = a + 5;
	}
}
void affiche_carte_vierge()
{
	
	POINT  centrej1, centrej1_dos, centrej2, centrej2_dos;
	POINT hg, bd, hg2, bd2, hg3, bd3, hg4, bd4;
	
	// emplacement des cartes les bitchez
	centrej1.x = centrej1_dos.x = centrej2.x = centrej2_dos.x = 450;
	centrej1.y = 200; centrej1_dos.y= 75;
	centrej2.y = 400; centrej2_dos.y= 525;
	
	hg=centrej1;		//ligne inutile qui empeche le waring en compilation
	
	// rectangles cartes

	
	hg.x = hg2.x = hg3.x = hg4.x = 425;
	bd.x = bd2.x = bd3.x = bd4.x = 475;
	hg.y= 125;	hg2.y= 250; hg3.y= 450; hg4.y = 575;
	bd.y= 25;	bd2.y= 150; bd3.y= 350; bd4.y = 475;
	
	draw_fill_rectangle( hg , bd , white);
	draw_fill_rectangle( hg2, bd2, white);
	draw_fill_rectangle( hg3, bd3, white);
	draw_fill_rectangle( hg4, bd4, white);
	draw_rectangle( hg , bd , red);
	draw_rectangle( hg2, bd2, red);
	draw_rectangle( hg3, bd3, red);
	draw_rectangle( hg4, bd4, red);
	
	affiche_carte_retourne( hg4, bd4, hg, bd);
}

int main ()//le main maggle
{
	paq jeu1;    //jeu du joueur 1
	paq jeu2;    //jeu du joueur 2
	int gagnant; //nombre de cartes dans les paquet des joueurs 1 et 2
	
	init_graphics(600,600);
	
	affiche_auto_off();
	
	fill_screen(green);
	affiche_carte_vierge();
	
	init_jeu(&jeu1,&jeu2);
	
	while(filevide(jeu1) && filevide(jeu2)) //filevide renvoit 1 pour une file non vide
	{
		combat(&jeu1,&jeu2);
		
		cartes_recupere(&jeu1,&jeu2,gagnant);
		affiche_all();
	}

	exit(0);
}
