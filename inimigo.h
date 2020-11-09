#include <stdio.h>
#include <string.h>
//struc gravacao
typedef struct
{
	int vida;
	int movimento;
	int x;
	int y;
} enemy;

enemy* getEnemies(char nivel[][13]){
	enemy enemies[];
	int i = 0, j = 0, k = 0;
	for(i = 0; i < 11; i++){
		for(j = 0; j < 13; j++){
			if(nivel[i][j] == 'E'){
				enemies[k].vida = 1;
				enemies[k].movimento = 1;
				enemies[k].x = i;
				enemies[k].y = j;
				k++;
			}
		}
	}
	return enemies;
}