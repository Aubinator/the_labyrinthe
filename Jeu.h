#ifndef __JEU__
#define __JEU__
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define LARGEUR_TILE 34
#define HAUTEUR_TILE 34 
#define NBR_BLOC_X 18
#define NBR_BLOC_Y 14
#define WIDTH LARGEUR_TILE*NBR_BLOC_X
#define HEIGHT HAUTEUR_TILE*NBR_BLOC_Y

typedef struct map map;
struct map{
int ouvert, question;
char tile;
};

typedef struct quest quest;
struct quest{
	char *quest;
	int brep;
	char *rep1, *rep2, *rep3; 
};


enum{HAUT, BAS, GAUCHE, DROITE};

void 	aff_map(map *carte[], SDL_Surface *ecran);
void	init(map *str[]);
void	debut(SDL_Surface *ecran);
void 	pauses();
void	ouvrir(map **carte, int x, int y);
void	moveMario(SDL_Surface *ecran, SDL_Rect *posMario, int direction, map **carte, int *continuer, int *scoreTest, int *wintest);
int 	menu(SDL_Surface *ecran);
int		credit(SDL_Surface *ecran, int * continuer);
int		rules(SDL_Surface *ecran, int * continuer);
int 	questionnaire(SDL_Surface *ecran);
void 	aff_time(SDL_Surface *ecran,char *texte1, char *texte2);
void 	jouerSon(char *zik);


#endif
