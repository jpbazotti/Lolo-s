typedef gravacao {
	int id;
	int totalpts;
	int ultimafase;
	int vidas;
	char nomejogador[9];
} gravacao;

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
