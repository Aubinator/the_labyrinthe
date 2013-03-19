#include "Jeu.h"
void aff_map(map **carte, SDL_Surface *ecran)
{
int i = 0, j = 0;
SDL_Surface *fond = NULL, *marche, *inv, *quest;
	fond  = IMG_Load("img/fond.png");
	marche = IMG_Load("img/marche.png");
	inv = IMG_Load("img/lab.png");
	quest = IMG_Load("img/pastille.png");
	SDL_Rect posFond, posQuest;

	while (i < NBR_BLOC_Y){
		while (j < NBR_BLOC_X){
			posFond.y = i*LARGEUR_TILE;
			posFond.x = j*HAUTEUR_TILE;
			if (carte[i][j].tile == '0')
				SDL_BlitSurface(fond,NULL,ecran, &posFond);
			else
				SDL_BlitSurface(marche,NULL,ecran, &posFond);
			if (carte[i][j].ouvert == 0)	
				SDL_BlitSurface(inv,NULL,ecran, &posFond);
	
				
				if (carte[i][j].question == 1)
		{
				posQuest.y = i*LARGEUR_TILE+7;
				posQuest.x = j*HAUTEUR_TILE+7;
				SDL_BlitSurface(quest,NULL,ecran, &posQuest);
		}

		j++;
		}
		j = 0;
		i++;
	}
} 
