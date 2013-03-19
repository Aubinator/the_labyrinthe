#include "Jeu.h"
void winFin(SDL_Surface *ecran, int *continuer)
{
	*continuer = 0;
	SDL_Surface *welldone, *texte;
	welldone = IMG_Load("img/winner.png");
	SDL_Rect posImage;
	posImage.x = 0;
	posImage.y = 0;
	SDL_BlitSurface(welldone, NULL, ecran, &posImage);
	SDL_Flip(ecran);
	pauses();
	SDL_FreeSurface(welldone);
	//exit(0);
}

void looseFin(SDL_Surface *ecran, int *continuer)
{
	*continuer = 0;
	SDL_Surface *welldone, *texte;
	welldone = IMG_Load("img/loser.png");
	SDL_Rect posImage;
	posImage.x = 0;
	posImage.y = 0;
	SDL_BlitSurface(welldone, NULL, ecran, &posImage);
	SDL_Flip(ecran);
	pauses();
	SDL_FreeSurface(welldone);
	//return(0);
}
