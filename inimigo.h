#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h> 
#include "nivel.h"
//struc gravacao
typedef struct
{
	int vida;
	int movimento;
	ponto_st posicao;
} enemy;

//retorna a quantidade de inimigos restante no niuel
int enemiesLeft(char nivel[][13])
{
	int i;
	int j;
	int enemies=0;
	for (i = 0; i < 11; i++)
	{
		for (j = 0; j < 13; j++)
		{
			if(nivel[i][j]=='E'){
				enemies++;
			}
		}
	}
	return enemies;
}

//retorna um array com os inimigos do mapa
void getEnemies(char nivel[][13],enemy enemies[])
{
	int i = 0, j = 0, k = 0;
	for (i = 0; i < 11; i++)
	{
		for (j = 0; j < 13; j++)
		{
			if (nivel[i][j] == 'E')
			{
				enemies[k].vida = 1;
				enemies[k].movimento = 1;
				enemies[k].posicao.x = i;
				enemies[k].posicao.y = j;
				k++;
			}
		}
	}
}

//move inimigos aleatoriamente
void moveEnemies(char nivel[][13])
{
	srand(time(NULL));
	enemy *enemies=malloc((sizeof(enemy))*(enemiesLeft(nivel)));
	getEnemies(nivel,enemies);
	int qtd = ((sizeof(enemy))*(enemiesLeft(nivel))) / (sizeof(enemy));
	int i = 0;
	int move = 0;
	ponto_st novaPos;
	for (i = 0; i < qtd; i++)
	{
		if (enemies[i].movimento == 1)
		{
			move = rand() % 4;
			enemies[i].movimento = 0;
			if (move == 0)
			{
				novaPos.x = enemies[i].posicao.x;
				novaPos.y = enemies[i].posicao.y - 1;
			}
			else if (move == 1)
			{
				novaPos.x = enemies[i].posicao.x - 1;
				novaPos.y = enemies[i].posicao.y;
			}
			else if (move == 2)
			{
				novaPos.x = enemies[i].posicao.x;
				novaPos.y = enemies[i].posicao.y + 1;
			}
			else if (move == 3)
			{
				novaPos.x = enemies[i].posicao.x + 1;
				novaPos.y = enemies[i].posicao.y;
			}
			if (nivel[novaPos.x][novaPos.y] != ' ')
			{
				novaPos.x = enemies[i].posicao.x;
				novaPos.y = enemies[i].posicao.y;
				enemies[i].movimento = 1;
			}else{
			nivel[enemies[i].posicao.x][enemies[i].posicao.y] = ' ';
			nivel[novaPos.x][novaPos.y] = 'E';
			}
		}
	}
}