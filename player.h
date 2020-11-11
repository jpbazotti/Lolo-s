#include "nivel.h"
#include "gravacao.h"
//definicao do player
typedef struct
{
    ponto_st posicao;
    int coracoes;
} player_st;
//logica de movimentacao da caixa
int moveBox(char nivel[][13], ponto_st pos, char key)
{
    int movePossible = 0;
    ponto_st caixa = pos;
    ponto_st novaPosCaixa;

    switch (key)
    {
    case 'w':
        novaPosCaixa.x = caixa.x;
        novaPosCaixa.y = caixa.y - 1;
        break;

    case 'a':
        novaPosCaixa.x = caixa.x - 1;
        novaPosCaixa.y = caixa.y;
        break;

    case 's':
        novaPosCaixa.x = caixa.x;
        novaPosCaixa.y = caixa.y + 1;
        break;

    case 'd':
        novaPosCaixa.x = caixa.x + 1;
        novaPosCaixa.y = caixa.y;
        break;
    default:
        novaPosCaixa.x = caixa.x;
        novaPosCaixa.y = caixa.y;
        break;
    }

    if (nivel[novaPosCaixa.y][novaPosCaixa.x] == ' ')
    {
        movePossible = 1;
        nivel[novaPosCaixa.y][novaPosCaixa.x] = 'B';
        nivel[caixa.y][caixa.x] = ' ';
    }
    return movePossible;
}
//logica de colisao e movimentacao do player
player_st movePlayer(char nivel[][13], player_st p, char key, gravacao *save, int pInicial)
{
    player_st jogador = p;
    ponto_st novaPos;
    switch (key)
    {
    case 'w':
        novaPos.x = jogador.posicao.x;
        novaPos.y = jogador.posicao.y - 1;
        break;

    case 'a':
        novaPos.x = jogador.posicao.x - 1;
        novaPos.y = jogador.posicao.y;
        break;

    case 's':
        novaPos.x = jogador.posicao.x;
        novaPos.y = jogador.posicao.y + 1;
        break;

    case 'd':
        novaPos.x = jogador.posicao.x + 1;
        novaPos.y = jogador.posicao.y;
        break;
    default:
        novaPos.x = jogador.posicao.x;
        novaPos.y = jogador.posicao.y;
        break;
    }
    if (nivel[novaPos.y][novaPos.x] == 'A')
    {
        (*save).vidas = (*save).vidas - 1;
        jogador.posicao.x = -2;
        jogador.posicao.y = -2;
        (*save).totalpts = pInicial;
    }
    else if (nivel[novaPos.y][novaPos.x] == 'C')
    {
        jogador.coracoes++;
        nivel[novaPos.y][novaPos.x] = '@';
        nivel[jogador.posicao.y][jogador.posicao.x] = ' ';
        jogador.posicao.x = novaPos.x;
        jogador.posicao.y = novaPos.y;
    }
    else if (nivel[novaPos.y][novaPos.x] == '@')
    {
        nivel[jogador.posicao.y][jogador.posicao.x] = '@';
    }
    else if (nivel[novaPos.y][novaPos.x] == 'B')
    {
        if (moveBox(nivel, novaPos, key))
        {
            nivel[novaPos.y][novaPos.x] = '@';
            nivel[jogador.posicao.y][jogador.posicao.x] = ' ';
            jogador.posicao.x = novaPos.x;
            jogador.posicao.y = novaPos.y;
        }
    }
    else if (nivel[novaPos.y][novaPos.x] == 'E')
    {
        if (jogador.coracoes > 0)
        {
            jogador.coracoes--;
            nivel[novaPos.y][novaPos.x] = '@';
            nivel[jogador.posicao.y][jogador.posicao.x] = ' ';
            jogador.posicao.x = novaPos.x;
            jogador.posicao.y = novaPos.y;
            (*save).totalpts = ((*save).totalpts) + 1;
            if ((*save).totalpts % 10 == 0)
            {
                (*save).vidas = (*save).vidas + 1;
            }
        }
        else
        {
            (*save).vidas = (*save).vidas - 1;
            jogador.posicao.x = -2;
            jogador.posicao.y = -2;
            (*save).totalpts = pInicial;
        }
    }
    else if (nivel[novaPos.y][novaPos.x] == 'T')
    {
        (*save).ultimafase++;
        jogador.posicao.x = -2;
        jogador.posicao.y = -2;
        jogador.coracoes=0;
    }
    else if (nivel[novaPos.y][novaPos.x] != 'P')
    {
        nivel[novaPos.y][novaPos.x] = '@';
        nivel[jogador.posicao.y][jogador.posicao.x] = ' ';
        jogador.posicao.x = novaPos.x;
        jogador.posicao.y = novaPos.y;
    }
    if (key == KEY_ESCAPE || (*save).vidas == 0)
    {
        jogador.posicao.x = -1;
        jogador.posicao.y = -1;
    }
    return jogador;
}
