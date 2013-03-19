#include "Jeu.h"
int	main()
{

	map **carte;
	int i = 0, j = 0, continuer = 1,actu = 0, passe = 0, compteur = 0, rejouer = 1, score = 500, scoreTest = -1, winTest = 0;
	SDL_Surface *ecran = NULL;
	ecran = SDL_SetVideoMode(WIDTH, HEIGHT,32, SDL_HWSURFACE | SDL_DOUBLEBUF );
	SDL_Rect posMario;

	//printf("%d\n", posMario.x);
	SDL_Event event;
	if (ecran ==  NULL)
	{
		printf("Error initialisation \n");
		exit(EXIT_FAILURE);
	}

	SDL_WM_SetCaption("Labyrinthe",NULL);
	carte = malloc(NBR_BLOC_Y * sizeof(map)+2*sizeof(map));
	while (i < NBR_BLOC_Y){
		carte[i] = malloc(NBR_BLOC_X * sizeof(map)+ 2*sizeof(map));
		i++;
	}

	while (rejouer){
		posMario.x= 0;
		posMario.y= 13*34; 
		debut(ecran);
		init(carte);
		//aff_map(carte, ecran);
		SDL_EnableKeyRepeat(100, 100);
		menu(ecran);
		moveMario(ecran, &posMario,HAUT, carte, &continuer, &scoreTest, &winTest);
		actu = SDL_GetTicks(), compteur = actu + 90000, continuer = 1;
		while (continuer)
		{

			char texte1[20], texte2[20];

			actu = SDL_GetTicks();
			SDL_PollEvent(&event);
			switch(event.type)
			{
				case SDL_QUIT:
					continuer = 0;
					rejouer = 0;
					break;

				case SDL_KEYDOWN:
					switch(event.key.keysym.sym)
					{

						case SDLK_UP: // Flèche haut
							jouerSon("sounds/brickHit.wav");
							moveMario(ecran, &posMario,HAUT, carte, &continuer, &scoreTest, &winTest);
							break;
						case SDLK_DOWN: // Flèche bas
							jouerSon("sounds/brickHit.wav");
							moveMario(ecran, &posMario,BAS, carte, &continuer, &scoreTest, &winTest);
							break;
						case SDLK_RIGHT: // Flèche droite
							jouerSon("sounds/brickHit.wav");
							moveMario(ecran, &posMario,DROITE, carte, &continuer, &scoreTest, &winTest);
							break;
						case SDLK_LEFT: // Flèche gauche
							jouerSon("sounds/brickHit.wav");
							moveMario(ecran, &posMario,GAUCHE, carte, &continuer, &scoreTest, &winTest);
							break;
						default:
							break;
					}
					break;
					// continuer++;
			}
			passe = compteur - actu;
			if (scoreTest == 0 && score > 0){
				score -= 100, compteur -= 10000;
				jouerSon("sounds/verre-casse.wav");
			}
			else if (scoreTest == 1){
				score += 100, compteur += 10000;
				jouerSon("sounds/dring.wav");

				SDL_Flip(ecran);
			}
			scoreTest = -1;
			if (passe > 0){
				sprintf(texte1, "%d", passe/1000);
				sprintf(texte2, "%d", score);
				aff_time(ecran, texte1, texte2);
			}
			else{
				jouerSon("sounds/gameover.wav");
				looseFin(ecran, &continuer);


				continuer = 0;

			}
			if (winTest == 1){
				jouerSon("sounds/Clapping.mp3");
				winFin(ecran, &continuer);
				continuer = 0;
			}
			SDL_Flip(ecran);
			winTest = -1;

			SDL_Delay(30);
		}
		rejouer = 1;
		aff_map(carte, ecran);

	}

	SDL_FreeSurface(ecran);
	exit(EXIT_SUCCESS);
	SDL_Quit();
	return 0;
}
