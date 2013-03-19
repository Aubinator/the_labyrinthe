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
posCredit.x = WIDTH/2 - 150;
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
	bh = IMG_Load("img/bh.png");
	SDL_Rect posFond,souris, posBh;
	posFond.x = 0;	
	posFond.y = 0;
	souris.x = 165;

	while (continuer)
    {
   //    putchar(continuer + '0');
        SDL_WaitEvent(&event);
        switch(event.type)
        {
            case SDL_QUIT:
               continuer = 0;
                break;
           case SDL_KEYDOWN:
                switch(event.key.keysym.sym)
                {
                    case SDLK_RETURN:
                    	if (i == 3)
                    		credit(ecran, &continuer);
                    	if (i == 2)
                    		rules(ecran, &continuer);
	                    if (i == 1)
    	                	continuer = 0;

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
        if (i < 1 || i > 3)
        	i = 1;
        if (i == 1)
       		souris.y = 172;
       	if (i == 2)
       		souris.y = 239;
       	if (i == 3)
       		souris.y = 307;
       	SDL_BlitSurface(fond,NULL,ecran, &posFond);
       	SDL_BlitSurface(bh,NULL,ecran, &souris);
       	SDL_Flip(ecran);
       	
	
}
	SDL_FreeSurface(fond);
    return 0;
}
