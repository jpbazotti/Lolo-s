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
int printSave()
{	int opSuccess=0;
    FILE *file;
    if (!(file = fopen("save.bin", "rb")))
    {
        printf("Nao ha saves, por favor crie um novo jogo");
    }
    else
    {
        gravacao buffer;
        while (!feof(file))
        {

            if (fread(&buffer, sizeof(gravacao), 1, file) == 1)
            {
                printf("%d-Jogador:%s Nivel:%d\n", buffer.id,buffer.nomejogador,buffer.ultimafase);
            }
        }
		opSuccess=1;
        fclose(file);
    }
	return opSuccess;
}


//pega save pelo id
gravacao getSave(int pos){
	FILE *file;
	gravacao save;
	if(!(file = fopen("save.bin","rb"))){
		printf("Nao ha save file! Pressione um botao para continuar\n");
	}else{
	if(pos>0 && (pos)<getLast()){
	fseek(file, (pos-1)*sizeof(gravacao),SEEK_SET);
	if(fread(&save, sizeof(gravacao), 1, file) == 1){
		printf("Iniciando Jogo\n");
	}
	}else{
	printf("Save nao encontrado");
	save.id=-1;	
	}
	fclose(file);
	}
	return save;
}

//sobscreeve o save 
void changeSave(gravacao save){
	FILE *file;
	if (!(file = fopen("save.bin", "r+b")))
	{
		printf("Erro de leitura!\n");
	}
	fseek(file, (((save.id)-1) * sizeof(gravacao)), SEEK_SET);
	if (fwrite(&save, sizeof(gravacao), 1, file) != 1)
	{
		printf("Erro de escrita!\n");
	}
	fclose(file);
}