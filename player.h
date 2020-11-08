#include "nivel.h"
#include "gravacao.h"
typedef struct
{
    ponto_st posicao;
    int coracoes;
} player_st;

// player_st movePlayer(char nivel[][13], player_st p, char key, gravacao *save)
// {
//     player_st jogador = p;
//     switch (key)
//     {
//     case 'w':
//         if (nivel[jogador.posicao.y - 1][jogador.posicao.x] != 'P')
//         {
//             nivel[jogador.posicao.y][jogador.posicao.x] = ' ';
//             nivel[jogador.posicao.y - 1][jogador.posicao.x] = '@';
//             jogador.posicao.y = jogador.posicao.y - 1;
//         }
//         break;

//     case 'a':
//         if (nivel[jogador.posicao.y][jogador.posicao.x-1] != 'P')
//         {
//             nivel[jogador.posicao.y][jogador.posicao.x] = ' ';
//             nivel[jogador.posicao.y][jogador.posicao.x - 1] = '@';
//             jogador.posicao.x = jogador.posicao.x - 1;
//         }
//         break;

//     case 's':
//         if (nivel[jogador.posicao.y + 1][jogador.posicao.x] != 'P')
//         {
//             nivel[p.posicao.y][p.posicao.x] = ' ';
//             nivel[p.posicao.y + 1][p.posicao.x] = '@';
//             jogador.posicao.y = jogador.posicao.y + 1;
//         }
//         break;

//     case 'd':
//         if (nivel[jogador.posicao.y][jogador.posicao.x+1] != 'P')
//         {
//             nivel[jogador.posicao.y][jogador.posicao.x] = ' ';
//             nivel[jogador.posicao.y][jogador.posicao.x + 1] = '@';
//             jogador.posicao.x = jogador.posicao.x + 1;
//         }
//         break;
//     case KEY_ESCAPE:
//         jogador.posicao.x = -1;
//         jogador.posicao.y = -1;
//         break;
//     }
//     return jogador;
// }
player_st movePlayer(char nivel[][13], player_st p, char key, gravacao *save)
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
        novaPos.x = jogador.posicao.x-1;
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
    }

    if(nivel[novaPos.y][novaPos.x] !='P'){
        nivel[novaPos.y][novaPos.x]='@';
        nivel[jogador.posicao.y][jogador.posicao.x]=' ';
        jogador.posicao.x=novaPos.x;
        jogador.posicao.y=novaPos.y;
    }
    if(key==KEY_ESCAPE){
        jogador.posicao.x=-1;
        jogador.posicao.y=-1;
    }
    return jogador;
}
