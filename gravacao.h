#include<stdio.h>
//struc gravacao
typedef struct {
	int id;
	int totalpts;
	int ultimafase;
	int vidas;
	char nomejogador[9];
} gravacao;


//salva os dados do player
void geraGravacao(gravacao save){
	FILE *file;
	if(!(file = fopen("save.bin","ab"))){
		printf("Erro de leitura!\n");
	}
	if (fwrite(&save, sizeof(gravacao), 1, file) != 1){
		printf("Erro de escrita!\n");
	}
	fclose(file);
}

int getLast(){
	File *file;
	if(!(file = fopen("save.bin","rb"))){
		printf("Erro de leitura!\n");
	}
	fseek(file, 0, SEEK_END);
	int pos = ftell(file)/sizeof(gravacao);
	fclose(file);
	return pos;
}