#include <stdio.h>
//definicao de structs nivel e ponto


typedef struct 
{
    int x;
    int y;
}ponto_st ;



void imprime_nivel(char nivel[][13]){
   int i;
    int j;
    for(i=0;i<11;i++){
        for(j=0;j<13;j++){
            printf("%c",nivel[i][j]);
        }
        printf("\n");
        }
    }


ponto_st carrega_nivel(char nivel[][13], char arquivo[20]){
    FILE *data;
    ponto_st player;
    player.x=-1;
    player.y=-1;
     if (!(data = fopen(arquivo, "r")))
    {
        printf("Erro ao carregar o nivel\n"); 
    }
    else{
        int i;
        int contador=0;
        while(!feof(data)){
            for(i=0;i<13;i++){
                nivel[contador][i]=getc(data);  
                if(nivel[contador][i]=='@'){
                    player.x=contador;
                    player.y=i;
                }
            }
            getc(data);
            contador++;
        }
    }
    return player;
}