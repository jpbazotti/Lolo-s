#include <stdio.h>
#include "nivel.h"
#include "menu.h"
#include "rlutil.h"
#include "gravacao.h"
int main()
{
    cls();
    hidecursor();
    printMenu();
    int loop = 1;
    char nome[9];
    //loop principal
    while (loop)
    {
        gravacao gameState;
        
        if (kbhit())
        {
            cls();
            printMenu();
            char k = getkey();
            switch (k)
            {
            case '1':
            cls();
            printf("Digite seu nome:");
            showcursor();
            scanf("%s",nome);
            hidecursor();
            gameState.id=0;
            strcpy(gameState.nomejogador,nome);
            gameState.totalpts=0;
            gameState.ultimafase=1;
            gameState.vidas=3;
            break;  
            case '2':

            break;
            case '3':
                cls();
                printCreditos();
                anykey("Pressione qualquer tecla para voltar\n");
                cls();
                printMenu();
                break;
            case '4':
                loop = 0;
                break;
            default:
                break;
            }
        }
    }
    return 0;
}
