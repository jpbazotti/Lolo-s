#include <stdio.h>
#include <string.h>

#ifndef nivel_h
#define nivel_h
//definicao de struct ponto

typedef struct
{
    int x;
    int y;
} ponto_st;

//desenha na tela o nivel em seu estado atual

void printLevel(char nivel[][13])
{
    int i;
    int j;
    for (i = 0; i < 11; i++)
    {
        for (j = 0; j < 13; j++)
        {
            printf("%c", nivel[i][j]);
        }
        printf("\n");
    }
}

//esconde o bau e retorna sua posicao
ponto_st hideChest(char nivel[][13])
{
    int i;
    int j;
    ponto_st pos;
    for (i = 0; i < 11; i++)
    {
        for (j = 0; j < 13; j++)
        {
            if (nivel[i][j] == 'T')
            {
                pos.x = i;
                pos.y = j;
                nivel[i][j] = ' ';
            }
        }
    }
    return pos;
}

//coloca o bau na posicao
void spawnChest(ponto_st pos, char nivel[][13])
{
    nivel[pos.x][pos.y]='T';
}
//carrega o nivel de um arquivo txt

ponto_st loadLevel(char nivel[][13], char arquivo[20])
{
    FILE *data;
    ponto_st player;
    player.x = -1;
    player.y = -1;
    if (!(data = fopen(arquivo, "r")))
    {
        printf("Erro ao carregar o nivel\n");
    }
    else
    {
        int i;
        int contador = 0;
        while (!feof(data))
        {
            for (i = 0; i < 13; i++)
            {
                nivel[contador][i] = getc(data);
                if (nivel[contador][i] == '@')
                {
                    player.y = contador;
                    player.x = i;
                }
            }
            getc(data);
            contador++;
        }
    }
    return player;
}

//escolhe o arquivo do nivel
char *chooseLevel(int levelNumber)
{
    static char nivel[11];
    switch (levelNumber)
    {
    case 1:
        strcpy(nivel, "nivel1.txt");
        break;

    case 2:
        strcpy(nivel, "nivel2.txt");
        break;

    case 3:
        strcpy(nivel, "nivel3.txt");
        break;
    }
    return nivel;
}
#endif