#include <stdio.h>
#include "menu.h"
#include "rlutil.h"
#include "player.h"

int main()
{
    cls();
    hidecursor();
    printMenu();
    int loop = 1;
    int game = 0;
    char nome[9];
    char level[13][13];
    int loaded = 0;
    player_st jogador;
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
            //cria save e usa como gamestate
            case '1':
                cls();
                printf("Digite seu nome:");
                showcursor();
                scanf("%s", nome);
                hidecursor();
                gameState.id = getLast();
                strcpy(gameState.nomejogador, nome);
                gameState.totalpts = 0;
                gameState.ultimafase = 1;
                gameState.vidas = 3;
                geraGravacao(gameState);
                game = 1;
                break;
                //seta gamestate para o save
            case '2':
                cls();
                printSave();
                printf("\nEscolha um save\n");
                k = getkey();
                printf("%d\n", (int)k - 48);
                gameState = getSave((int)k - 48);
                game = 1;
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
            //loop do jogo
            while (game)
            {
                if (!loaded)
                {
                    jogador.posicao = loadLevel(level, chooseLevel(gameState.ultimafase));
                    loaded = 1;
                    cls();
                    printInterface(gameState.vidas, gameState.totalpts, gameState.ultimafase);
                    printLevel(level);
                }

                if (kbhit())
                {
                    char move = getkey();
                    cls();
                    jogador = movePlayer(level, jogador, move, &gameState);
                    printInterface(gameState.vidas, gameState.totalpts, gameState.ultimafase);
                    printLevel(level);
                    if (jogador.posicao.x == -1)
                    {
                        game = 0;
                        loaded = 0;
                        cls();
                        printMenu();
                    }
                }
            }
        }
    }
    return 0;
}
