#include <stdio.h>
#include <string.h>
//struc gravacao
typedef struct
{
	int id;
	int totalpts;
	int ultimafase;
	int vidas;
	char nomejogador[9];
} gravacao;

//salva os dados do player
void geraGravacao(gravacao save)
{
	FILE *file;
	if (!(file = fopen("save.bin", "ab")))
	{
		printf("Erro de leitura!\n");
	}
	if (fwrite(&save, sizeof(gravacao), 1, file) != 1)
	{
		printf("Erro de escrita!\n");
	}
	fclose(file);
}

//pega o ultimo id usado
int getLast()
{
	FILE *file;
	int pos = 0;
	if (!(file = fopen("save.bin", "rb")))
	{
		pos = 0;
	}
	else
	{
		fseek(file, 0, SEEK_END);
		pos = ftell(file) / sizeof(gravacao);
		fclose(file);
	}
	return pos+1;
}
//imprime os saves para selecao
void printSave()
{
    FILE *file;
    if (!(file = fopen("save.bin", "rb")))
    {
        printf("Erro na abertura do arquivo para leitura");
    }
    else
    {
        gravacao buffer;
        while (!feof(file))
        {

            if (fread(&buffer, sizeof(gravacao), 1, file) == 1)
            {
                printf("\n%d-Jogador:%s Nivel:%d", buffer.id,buffer.nomejogador,buffer.ultimafase);
            }
        }
        fclose(file);
    }
}

gravacao getSave(int pos){
	FILE *file;
	gravacao save;
	if(!(file = fopen("save.bin","rb"))){
		printf("Nao ha save file! Pressione um botao para continuar\n");
	}else{
	fseek(file, (pos-1)*sizeof(gravacao),SEEK_SET);
	if(fread(&save, sizeof(gravacao), 1, file) == 1){
		printf("Iniciando Jogo\n");
	}
	fclose(file);
	}
	return save;
}

void changeSave(gravacao save){
	FILE *file;
	if (!(file = fopen("save.bin", "wb")))
	{
		printf("Erro de leitura!\n");
	}
	fseek(file, (save.id-1)*sizeof(gravacao), SEEK_SET);
	if (fwrite(&save, sizeof(gravacao), 1, file) != 1)
	{
		printf("Erro de escrita!\n");
	}
	fclose(file);
}