#include "Jeu.h"
	

int questionnaire(SDL_Surface *ecran){
	quest str[9];
	str[0].quest ="je suis le plus celebre des sorciers";
	str[0].rep1 = "Matusalem";
	str[0].rep2 = "blade";
	str[0].rep3 = "harry potter";
	str[0].brep = 3;
	str[1].quest = "j'etais le patron de la societe apple";
	str[1].rep1 = "bill gates";
	str[1].rep2 ="steve jobs";
	str[1].rep3 = "steve wozniak";
	str[1].brep = 2;
	str[2].quest = "je suis le hero du jeu uncharted";
	str[2].rep1 = "kratos";
	str[2].rep2	="nathan drake";
	str[2].rep3="lara croft";
	str[2].brep = 2;
	str[3].quest = "je suis le plus beau de epicure";
	str[3].rep1 = "sady";
	str[3].rep2 = "putain ce quoi sa comme question";
	str[3].rep3 = "Moi meme bien sur";
	str[3].brep = 1;
	str[4].quest = "je suis le plus haut sommet de chine";
	str[4].rep1 = "l'everest";
	str[4].rep2 ="le kilipuko";
	str[4].rep3 ="le mont fuji";
	str[4].brep = 3;
	str[5].quest = "que veut dire la phrase preférée de alain RTFM";
	str[5].rep1 = "Riche Tres Fetard Mauvais";
	str[5].rep2 = "Read The Fucking Manual";
	str[5].rep3 = "Retourne taper fesser malika";
	str[5].brep = 2;
	str[6].quest = "quel est le surnom de aubin";
	str[6].rep1 = "Bino";
	str[6].rep2 ="kientega";
	str[6].rep3 ="Mario";
	str[6].brep = 1;
	str[7].quest = "qu'est ce que twilight";
	str[7].rep1 = "une insulte";
	str[7].rep2 = "un jeu";
	str[7].rep3 = "un film";
	str[7].brep = 3;
	str[8].quest = "qu'est ce qui permet a belly de devenir super B.B";
	str[8].rep1 = "du bouye";
	str[8].rep2 = "des biskrems";
	str[8].rep3 = "des bisous";
	str[8].brep = 2;
	srand(time(NULL));
	int continuer = 1, i = 1, nbquest, c = 0;

	SDL_Surface *fond  = NULL, *texte = NULL, *bh = NULL;
	
	fond = IMG_Load("img/parchemin.png");
	bh = IMG_Load("img/bh.png");
	SDL_Event event;
	SDL_Rect posFond, souris;
	posFond.x = 0;
	posFond.y = 0;
	souris.x = 46;
	SDL_BlitSurface(fond,NULL,ecran, &posFond);
	SDL_Flip(ecran);
	nbquest = rand() % 7;
	c = str[nbquest].brep;
	TTF_Init();
	TTF_Font *police = NULL, *police2 = NULL;
	police = TTF_OpenFont("img/angelina.ttf", 30), police2 = TTF_OpenFont("img/angelina.ttf", 20);
	SDL_Color couleur = {167, 156, 156}, couleur2 = {71, 81, 213};

	

	while (continuer)
    {
    	texte = TTF_RenderText_Blended(police, str[nbquest].quest, couleur);
	SDL_Rect  positionTexte;
	positionTexte.x = 46;
	positionTexte.y = 40;
	SDL_BlitSurface(texte, NULL, ecran, &positionTexte);

	texte = TTF_RenderText_Blended(police, str[nbquest].rep1, couleur);
	positionTexte.y = 185;
	SDL_BlitSurface(texte, NULL, ecran, &positionTexte);

	texte = TTF_RenderText_Blended(police, str[nbquest].rep2, couleur);
	positionTexte.y += 64;
	SDL_BlitSurface(texte, NULL, ecran, &positionTexte);

	texte = TTF_RenderText_Blended(police, str[nbquest].rep3, couleur);
	positionTexte.y += 64;
	SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
	SDL_Flip(ecran);
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
                    	if (i == c)
                    		return(1);
                    	else
                    		return(0);
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
       		souris.y = 180;
       	if (i == 2)
       		souris.y =  180+64;
       	if (i == 3)
       		souris.y = 180+(2*64);
       	SDL_BlitSurface(fond,NULL,ecran, &posFond);
       	SDL_BlitSurface(bh,NULL,ecran, &souris);
       	SDL_Flip(ecran);
       	
//pause();
	
}
	SDL_FreeSurface(fond);
	SDL_FreeSurface(bh);
	SDL_FreeSurface(texte);
	TTF_CloseFont(police);
	TTF_CloseFont(police2);


}
/* 
case SDL_MOUSEMOTION:
		printf("x = %d y = %d \n",event.motion.x, event.motion.y );
		*/