#include "Jeu.h"

void aff_time(SDL_Surface *ecran, char *texte1, char *texte2)
{

	SDL_Surface *Tchrono, *TnChrono, *TScore, *TnScore;
	SDL_Surface *FondChrono = NULL;

	TTF_Init();
	TTF_Font *policeTexte = NULL, *policeNum = NULL;
	policeTexte = TTF_OpenFont("img/angelina.ttf", 22), policeNum = TTF_OpenFont("img/Type Keys Filled.ttf", 22);
	SDL_Color couleur = {255,255, 255}, couleur2 = {38, 255, 38};
	SDL_Rect  posTChrono, posChrono, posTScore, posScore,posFondChrono;

	posTChrono.x = 0, posTChrono.y = 8;
	posChrono.x = 92, posChrono.y = 8;
	posTScore.x = 400, posTScore.y = 8;
	posScore.x = 500, posScore.y = 8;
	posFondChrono.x = 0, posFondChrono.y = 0;


	TnChrono = TTF_RenderText_Blended(policeNum, texte1, couleur2);
	TnScore = TTF_RenderText_Blended(policeNum, texte2, couleur);
	Tchrono = TTF_RenderText_Blended(policeNum, "Temps", couleur);
	TScore = TTF_RenderText_Blended(policeNum, "Score", couleur);
	FondChrono = IMG_Load("img/FondChrono.png");

	SDL_BlitSurface(FondChrono, NULL, ecran, &posFondChrono);
	SDL_BlitSurface(Tchrono, NULL, ecran, &posTChrono);
	SDL_BlitSurface(TnChrono, NULL, ecran, &posChrono);
	SDL_BlitSurface(TScore, NULL, ecran, &posTScore);
	SDL_BlitSurface(TnScore, NULL, ecran, &posScore);
	SDL_Flip(ecran);



	TTF_CloseFont(policeTexte);
	TTF_CloseFont(policeNum);
	TTF_Quit();
	SDL_FreeSurface(Tchrono);
	SDL_FreeSurface(TnChrono);
	SDL_FreeSurface(TScore);
	SDL_FreeSurface(TnScore);
	SDL_FreeSurface(FondChrono);

}
