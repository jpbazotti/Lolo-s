#include <stdio.h>
#include "menu.h"
#include "rlutil.h"
#include "player.h"
#include "inimigo.h"
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
    int saveChoice = 0;
    int pontosInicio = 0;
    player_st jogador;
    ponto_st bau;
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
                printf("Escolha um save(digite e aperte enter):\n");
                if (printSave())
                {
                    showcursor();
                    scanf("%d", &saveChoice);
                    gameState = getSave(saveChoice);
                    hidecursor();
                    if (gameState.id != -1)
                    {
                        game = 1;
                    }
                    else
                    {
                        anykey("\nPressione qualquer tecla para voltar");
                        cls();
                        printMenu();
                    }
                }
                else
                {
                    anykey("\nPressione qualquer tecla para voltar");
                    cls();
                    printMenu();
                }
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
                    jogador.coracoes = 0;
                    jogador.posicao = loadLevel(level, chooseLevel(gameState.ultimafase));
                    loaded = 1;
                    bau = hideChest(level);
                    pontosInicio = gameState.totalpts;
                    cls();
                    printInterface(gameState.vidas, gameState.totalpts, gameState.ultimafase, jogador.coracoes);
                    printLevel(level);
                    printf("Nome: %s", gameState.nomejogador);
                    changeSave(gameState);
                }

                if (kbhit())
                {
                    char move = getkey();
                    cls();
                    jogador = movePlayer(level, jogador, move, &gameState, pontosInicio);

                    if (enemiesLeft(level) == 0)
                    {
                        spawnChest(bau, level);
                    }
                    else
                    {
                        moveEnemies(level);
                    }
                    printInterface(gameState.vidas, gameState.totalpts, gameState.ultimafase, jogador.coracoes);
                    printLevel(level);
                    printf("Nome: %s", gameState.nomejogador);
                    if (jogador.posicao.x == -1)
                    {
                        game = 0;
                        loaded = 0;
                        cls();
                        if (gameState.vidas == 0)
                        {
                            gameState.vidas = 3;
                            gameState.totalpts = 0;
                            gameState.ultimafase = 1;

                            printf("Voce perdeu todas as vidas, GAME OVER, de volta ao nivel 1!");
                            anykey("\nPressione qualquer tecla para continuar");
                            cls();
                        }
                        changeSave(gameState);
                        cls();
                        printMenu();
                    }
                    if (jogador.posicao.x == -2)
                    {
                        cls();
                        printf("Voce perdeu uma vida, tome mais cuidado!");
                        anykey("\nPressione qualquer tecla para continuar");
                        loaded = 0;
                        cls();
                    }else if(jogador.posicao.x == -3&&gameState.ultimafase!=4){
                        cls();
                        printf("Voce passou de nivel!");
                        anykey("\nPressione qualquer tecla para continuar e salvar");
                        loaded = 0;
                        cls();
                    }
                    if (gameState.ultimafase == 4)
                    {
                        game = 0;
                        loaded = 0;
                        cls();
                        printf("Voce ganhou!");
                        anykey("\nPressione qualquer tecla para voltar ao menu");
                        cls();
                        printMenu();
                    }
                }
            }
        }
    }
    return 0;
}
