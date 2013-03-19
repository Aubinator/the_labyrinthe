#include "Jeu.h"

void jouerSon(char *zik){

   if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) == -1)/*ici c'est l'initiation du lecteur
	en premier parametre on definit la frequence, en second, on fait appel aux differents formats, en troisième le chanel permetant
	de pouvoir jouer plusieurs musiques */
   {
      printf("%s", Mix_GetError());
   }
   Mix_Music *musique; //declaration du pointeur musique
   musique = Mix_LoadMUS(zik); //prise en charge de la musique
   Mix_PlayMusic(musique, 1); // le Mix_PlayMusic definit le nombre de lecture que l'on veut le -1 revoi a une lecture infini
}
