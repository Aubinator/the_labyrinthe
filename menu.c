#include <unistd.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include "Jeu.h"
int	credit(SDL_Surface *ecran, int * continuer){
	int i = 1;
	SDL_Surface *credit, *fond;
	SDL_Rect posFond, posCredit;
	SDL_Event event;
	posFond.x = 0;
	posFond.y = 0;
	posCredit.x = WIDTH/2 - 551;
	posCredit.y = HEIGHT;
	credit = IMG_Load("img/credits.png");
	fond = IMG_Load("img/fondCredits.jpg");
	while (posCredit.y != 0){
		SDL_PollEvent(&event);
		switch(event.type)
		{
			case SDL_QUIT:
				*continuer = 0;
				break;

		}
		posCredit.y--;
		SDL_BlitSurface(fond,NULL,ecran, &posFond);
		SDL_BlitSurface(credit,NULL,ecran, &posCredit);
		SDL_Delay(30);
		//passe = actu;
		SDL_Flip(ecran);

	}

	while (i){
		SDL_WaitEvent(&event);
		switch(event.type)
		{
			case SDL_KEYDOWN:
				i = 0;
				break;

		}

	}

	SDL_FreeSurface(fond);
	SDL_FreeSurface(credit);
	//menu(ecran);
	return(0);
}
int	rules(SDL_Surface *ecran, int * continuer){
	int i = 1;
	SDL_Surface *credit, *fond;
	SDL_Rect posFond, posCredit;
	SDL_Event event;
	posFond.x = 0;
	posFond.y = 0;
	posCredit.x = WIDTH/2 - 150;
	posCredit.y = HEIGHT;
	credit = IMG_Load("img/rules.png");
	fond = IMG_Load("img/fondRules.jpg");
	while (posCredit.y != 0){
		SDL_PollEvent(&event);
		switch(event.type)
		{
			case SDL_QUIT:
				*continuer = 0;
				break;
		}
		posCredit.y--;
		SDL_BlitSurface(fond,NULL,ecran, &posFond);
		SDL_BlitSurface(credit,NULL,ecran, &posCredit);
		SDL_Flip(ecran);

	}
	SDL_FreeSurface(fond);
	SDL_FreeSurface(credit);
	while (i){
		SDL_WaitEvent(&event);
		switch(event.type)
		{
			case SDL_KEYDOWN:
				i = 0;
				break;

		}
	}

	return (0);

}

int menu(SDL_Surface *ecran){
	SDL_Surface *fond = NULL, *bh;
	SDL_Event event;
	int i = 1, continuer = 1;
	fond = IMG_Load("img/menu.png");
	bh = IMG_Load("img/bhMenu.png");
	SDL_Rect posFond,souris, posBh;
	posFond.x = 0;	
	posFond.y = 0;
	souris.x = 165;
	if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) == -1)
	{
		printf("%s", Mix_GetError());
	}
	Mix_Music *musique; 
	musique = Mix_LoadMUS("sounds/musique_menu.mp3"); 
	Mix_PlayMusic(musique, - 1);
	while (continuer)
	{
		//    putchar(continuer + '0');
		SDL_WaitEvent(&event);
		switch(event.type)
		{
			case SDL_QUIT:
				continuer = 0;
				Mix_HaltMusic(); //Arrête la musique
				SDL_FreeSurface(ecran);
				exit(EXIT_SUCCESS);
				SDL_Quit();
				break;
			case SDL_KEYDOWN:
				switch(event.key.keysym.sym)
				{
					case SDLK_RETURN:
						if (i == 3){
							//Mix_HaltMusic(); //Arrête la musique
							credit(ecran, &continuer);
						}

						if (i == 2){
							//Mix_HaltMusic(); //Arrête la musique
							rules(ecran, &continuer);
						}

						if (i == 1){
							Mix_HaltMusic(); //Arrête la musique
							return (1);
						}
						if (i == 4){
							Mix_HaltMusic(); //Arrête la musique
							SDL_FreeSurface(ecran);
							exit(EXIT_SUCCESS);
							SDL_Quit();
						}
						break;

					case SDLK_UP: // Flèche haut
						i--;
						break;
					case SDLK_DOWN: // Flèche bas
						i++;
						break;

				}
				break;
				// continuer++;
		}
		if (i < 1 || i > 4)
			i = 1;
		if (i == 1)
			souris.y = 168;
		if (i == 2)
			souris.y = 230;
		if (i == 3)
			souris.y = 295;
		if (i == 4)
			souris.y = 355;
		SDL_BlitSurface(fond,NULL,ecran, &posFond);
		SDL_BlitSurface(bh,NULL,ecran, &souris);
		SDL_Flip(ecran);


	}
	SDL_FreeSurface(fond);
	return 0;
}
