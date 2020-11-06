
//imprime o menu do jogo
void printMenu(){
     printf("1-Novo Jogo\n");
     printf("2-Carregar jogo\n");
     printf("3-Creditos\n");
     printf("4-Sair\n");
}
//imprime os creditos do jogo
void printCreditos(){
     printf("Creditos\n");
     printf("Izaias Saturnino De Lima Neto\n");
     printf("Joao Pedro Lopes Bazotti\n");
}
//imprime a interface
void printInterface(int vidas, int pontos, int nivel){
     printf("=================================");
     printf("|Vidas: %d  Pontos: %d  Nivel:%d|");
     printf("=================================");
}