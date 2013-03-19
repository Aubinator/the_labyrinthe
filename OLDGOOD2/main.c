#include "Jeu.h"
int	main()
{

	map **carte;
	int i = 0, j = 0, continuer = 1, rejouer = 1;
	SDL_Surface *ecran = NULL;
	ecran = SDL_SetVideoMode(WIDTH, HEIGHT,32, SDL_HWSURFACE | SDL_DOUBLEBUF);
	SDL_Rect posMario;
	posMario.x= 0;
	posMario.y= 13*34; 
	printf("%d\n", posMario.x);
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
	debut(ecran);
	init(carte);
	aff_map(carte, ecran);
	moveMario(ecran, &posMario,HAUT, carte);
   	SDL_EnableKeyRepeat(100, 100);
   	menu(ecran);
while (continuer)
    {
   //    putchar(continuer + '0');

        SDL_WaitEvent(&event);
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
                       moveMario(ecran, &posMario,HAUT, carte);
                        break;
                    case SDLK_DOWN: // Flèche bas
                       moveMario(ecran, &posMario,BAS, carte);
                        break;
                    case SDLK_RIGHT: // Flèche droite
                       moveMario(ecran, &posMario,DROITE, carte);
                        break;
                    case SDLK_LEFT: // Flèche gauche
                       moveMario(ecran, &posMario,GAUCHE, carte);
                        break;
                }
                break;
       // continuer++;
        }
  SDL_Flip(ecran);
//pause();
	
}
}
	SDL_FreeSurface(ecran);
	exit(EXIT_SUCCESS);
	SDL_Quit();
	return 0;
}
void	debut(SDL_Surface *ecran){
	int i = 0;
		while (i <= 255){
		SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, i, i, i));
		SDL_Flip(ecran);
		usleep(5000);
		i++;
	}
}
void pause()
{
	int continuer = 1;
	SDL_Event event;

	while (continuer)
	{
		SDL_WaitEvent(&event);
		switch(event.type)
		{
			case SDL_QUIT:
				continuer = 0;
				break;
			case SDL_KEYDOWN:
				continuer = 0;
				break;
		}
	}
}
