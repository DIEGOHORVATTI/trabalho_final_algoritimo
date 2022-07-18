//#### preencer matriz 
char** preencherMatrizArquivo(char* dna){
  s_configuration config = Config();

  //matriz vetor de vetorescom ponteiros
  char **matriz = createMatriz();

  // atualiza matriz
  if(matriz){
    int y=0;
    for(int j = 0; j < config.COLUNAS ; j++){
      for(int i = 0; i < config.LINHAS ; i++){
        *(*(matriz + i) + j) = *(dna+y);
        y++;
      }
    }

    return(matriz);
    
    //libera memória matriz
    for (int i = 0; i < config.LINHAS; i++) free( *(matriz+i) ); free(matriz);
  }else{ printf("\n%s Erro ao alocar matriz dinamica 'matriz' %s\n", __COLOR_RED, __COLOR_FIM ); }
}