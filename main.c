#include<stdio.h>
#include<conio.h>
#include"nivel.h"

int main(){
    ponto_st player;
    char nivel [11][13];
    player = carrega_nivel(nivel,"nivel1.txt");
    imprime_nivel(nivel);
    return 0;
}

