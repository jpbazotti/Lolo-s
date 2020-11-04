#include<stdio.h>
#include<conio.h>

typedef struct 
{
    int x;
    int y;
} ponto_st;

ponto_st carrega_nivel(char nivel[13][13], char arquivo[10]);
void imprime_nivel(char nivel[13][13]);

int main(){

}

ponto_st carrega_nivel(char nivel[13][13], char arquivo[20]){
    FILE *data;
     if (!(data = fopen(arquivo, "r")))
    {
        printf("Erro ao carregar o nivel\n"); 
    }
    else{
        int i;
        int contador=0;
        while(!feof(data)){
            for(i=0;i<13;i++){
                nivel [contador][i];
                
            }
            contador++;
        }
    }
}