#include "Jeu.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>

void init_question(map **str){
	srand(time(NULL));
int nbrquest = 5, i = 0, j = 0, cpt = 0;
while (cpt < nbrquest){
		i = rand() % NBR_BLOC_Y;
		j = rand() % NBR_BLOC_X;
		if (str[i][j].tile == '1' && str[i][j].question == 0){
			str[i][j].question = 1;
			cpt++;
		}
}
}
void	init(map **str)
{
int fd, i = 0, j = 0, nb = 0;
fd = open("img/map.txt", O_RDONLY);
char c;

while (i < NBR_BLOC_Y){
		while (j < NBR_BLOC_X){
			read(fd, &c, 1);
			str[i][j].tile = c;
			str[i][j].ouvert = 0;
			str[i][j].question = 0;

		j++;
}
read(fd, &c, 1);
j = 0;
i++;
}
ouvrir(str, 13, 0);
init_question(str);
}
