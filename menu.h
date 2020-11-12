
//imprime o menu do jogo
void printMenu(){
     printf("1-Novo Jogo\n");
     printf("2-Carregar jogo\n");
     printf("3-Controles\n");
     printf("4-Creditos\n");
     printf("5-Sair\n");
}
//imprime os creditos do jogo
void printCreditos(){
     printf("Creditos\n");
     printf("Izaias Saturnino De Lima Neto\n");
     printf("Joao Pedro Lopes Bazotti\n");
}
//imprime os controles
void printControls(){
     printf("Se movimente com WASD\n");
     printf("Pressione ESC para sair e salvar\n");
     printf("Pressione qualquer outra tecla para esperar um turno(util para emboscar inimigos)\n");
}

//imprime a interface
void printInterface(int vidas, int pontos, int nivel, int coracoes){
     printf("=================================================\n");
     printf("|Vidas: %2d  Coracoes: %2d  Pontos: %3d  Nivel:%2d |\n",vidas,coracoes,pontos,nivel);
     printf("=================================================\n");
}