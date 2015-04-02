#include "graphics.h"

//Constante
#define L 500															//hauteur de la fenêtre
#define l 500															//longueur de la fenêtre

int main ()
{
	init_graphics(l,L);
	
wait_escape();
exit(0);
}
