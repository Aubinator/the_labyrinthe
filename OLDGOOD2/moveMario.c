#include "Jeu.h"
void	ouvrir(map **carte, int x, int y){
	    carte[x][y].ouvert = 1;
   if (x - 2 >= 0)
        carte[x-2][y].ouvert = 1;
    if (y - 2 >= 1)
            carte[x][y-2].ouvert = 1;
    if (x - 1 >= 0)
		carte[x-1][y].ouvert = 1;
	if (y - 1 >= 1)
			carte[x][y-1].ouvert = 1;
//	if (x + 2 < NBR_BLOC_Y)
  //          carte[x+2][y].ouvert = 1;
   if (y + 2 < NBR_BLOC_X)
            carte[x][y+2].ouvert = 1;
 //  if (y + 3 < NBR_BLOC_X)
   //         carte[x][y+3].ouvert = 1;
       if (x + 1 < NBR_BLOC_Y)
            carte[x+1][y].ouvert = 1;
    if (y + 1 < NBR_BLOC_X)
            carte[x][y+1].ouvert = 1;


}

void	moveMario(SDL_Surface *ecran, SDL_Rect *posMario, int direction, map *carte[NBR_BLOC_X]){

	int x = posMario->y/LARGEUR_TILE, y = posMario->x/LARGEUR_TILE;
	SDL_Surface *mario[4] = {NULL};
	mario[HAUT] = IMG_Load("img/mhaut.gif");
	mario[BAS] = IMG_Load("img/mbas.gif");
	mario[GAUCHE] = IMG_Load("img/mgauche.gif");
	mario[DROITE] = IMG_Load("img/mdroite.gif");
    aff_map(carte, ecran);
printf(" x%d NBR BLOC Y %d  posmario %d direction %d\n",x, NBR_BLOC_Y, posMario->y, direction );
    if (carte[x][y].question == 1){
        questionnaire(ecran);
        carte[x][y].question = 0;
        aff_map(carte, ecran);
        //SDL_BlitSurface(mario[direction],NULL,ecran, posMario);
        SDL_Flip(ecran);

        //printf(" verifions si j ai modifier la valeur %d x %d y %d\n",carte[x][y].question, x , y);
    }
               
               switch(direction)
        {
            case HAUT:
       
            	if (carte[x-1][y].tile == '1' && (x-1)>= 0)
            		posMario->y -= 34;
                SDL_BlitSurface(mario[HAUT],NULL,ecran, posMario);
                break;
       
             case BAS:
                         
                 if (carte[x+1][y].tile == '1' && x+1 < NBR_BLOC_Y)
                    posMario->y += 34;

                 SDL_BlitSurface(mario[BAS],NULL,ecran, posMario);
                    break;
       
            case DROITE:

                if (carte[x][y+1].tile == '1' && y+1 < NBR_BLOC_X)
                    posMario->x += 34;
                SDL_BlitSurface(mario[DROITE],NULL,ecran, posMario);
                break;

            case GAUCHE:

                if (carte[x][y-1].tile == '1' && y-1 >= 0)
                    posMario->x -= 34;
                SDL_BlitSurface(mario[GAUCHE],NULL,ecran, posMario);
                break;
                
                default:
                SDL_BlitSurface(mario[HAUT],NULL,ecran, posMario);
                break;
                 
        }
    
    ouvrir(carte, x, y);
	SDL_Flip(ecran);
    SDL_FreeSurface(mario[HAUT]);
    SDL_FreeSurface(mario[BAS]);
    SDL_FreeSurface(mario[GAUCHE]);
    SDL_FreeSurface(mario[DROITE]);
}    
  /*  int i = 0, j = 0;
    while (i < NBR_BLOC_Y){
        while (j < NBR_BLOC_X){
    putchar(carte[i][j].tile);
        j++;
}
printf("=======>>>>> i %d j %d",i, j );
putchar('\n');

j = 0;
i++;
}
printf("%d %d \n",y, x );
}
*/



/* 
while (continuer)
    {
        SDL_WaitEvent(&event);
        switch(event.type)
        {
            case SDL_QUIT:
                continuer = 0;
                break;
            case SDL_KEYDOWN:
                switch(event.key.keysym.sym)
                {
                    case SDLK_UP: // Flèche haut
                        posMario.y -= 34;
                        break;
                    case SDLK_DOWN: // Flèche bas
                        posMario.y += 34;
                        break;
                    case SDLK_RIGHT: // Flèche droite
                        posMario.x += 34;
                        break;
                    case SDLK_LEFT: // Flèche gauche
                        posMario.x -= 34;
                        break;
                }
                break;
        }
	
*/