//#### Verificação de sub string
int verificaModuloA(char* stringPercorrido){
  char *stringPercorrida_A = strstr(stringPercorrido, A());
  if( stringPercorrida_A ){
    printf("\n Ocorrencia: %s", A()); 
    return(1);
  }
}
int verificaModuloT(char* stringPercorrido){
  char *stringPercorrida_T = strstr(stringPercorrido, T());
  if( stringPercorrida_T ){
    printf("\n Ocorrencia: %s", T());
    return (1);
  }
}
int verificaModuloC(char *stringPercorrido) {
  char *stringPercorrida_C = strstr(stringPercorrido, C());
  if( stringPercorrida_C ){
    printf("\n Ocorrencia: %s", C());
    return (1);
  }
}
int verificaModuloG(char *stringPercorrido) {
  char *stringPercorrida_G = strstr(stringPercorrido, G());
  if( stringPercorrida_G ){
    printf("\n Ocorrencia: %s", G());
    return (1);
  }
}

//#### verificação em ordem de ['A', 'T', 'C', 'G'] por ocorrencia
int verificacao(char *stringPercorrido){

  //debugar strings vindas para verificação
  printf("\n%s\n", stringPercorrido);

  if (verificaModuloA(stringPercorrido) == 1) return(1);
  if (verificaModuloT(stringPercorrido) == 1) return(1);
  if (verificaModuloC(stringPercorrido) == 1) return(1);
  if (verificaModuloG(stringPercorrido) == 1) return(1);
}

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

    return (matriz);
    
    //libera memória matriz
    for (int i = 0; i < config.LINHAS; i++) free( *(matriz+i) ); free(matriz);
  }else{ printf("\n%s Erro ao alocar matriz dinamica 'matriz' %s\n", __COLOR_RED, __COLOR_FIM ); }
}

//#### verificação ['horizontal']
int verificacaoHorizontal(char** matriz){
  s_configuration config = Config();

  char *stringPercorrido = calloc(config.LINHAS, sizeof(char));
  // atualizar vetor com linhas horizontais da matriz
  for(int j = 0; j < config.COLUNAS ; j++){
    for (int i=0; i < config.LINHAS; i++){
      *(stringPercorrido + i) = *(*(matriz + i) + j);
    }
    if ( verificacao(stringPercorrido) == 1){
      printf(" -> horizontal");
      return (1);
    }
  }

  // libera a memória
  free(stringPercorrido);
}

//#### verificação ['vertical']
int verificacaoVertical(char** matriz){
  s_configuration config = Config();

  char *stringPercorrido = calloc(config.LINHAS, sizeof(char));
  // atualizar vetor com linhas verticais da matriz
  for (int j = 0; j < config.COLUNAS; j++){
    for (int i = 0; i < config.LINHAS; i++){
      *(stringPercorrido + i) = *(*(matriz + j) + i);
    }
    if ( verificacao(stringPercorrido) == 1){
      printf(" -> Vertical");
      return (1);
    }
  }

  // libera a memória
  free(stringPercorrido);
}

//#### verificação ['diagonal principal']
int verificacaoDiagonalPrincipal(char** matriz){
  s_configuration config = Config();

  char *stringPercorrido_superior = calloc( config.LINHAS, sizeof(char) );
  char *stringPercorrido_inferior = calloc( config.LINHAS, sizeof(char) );

  // atualizar vetor com linhas diagonais superior triangular da matriz
  for(int j = 0; j < config.COLUNAS ; j++){
    for(int i = 0; i < config.LINHAS ; i++){
      *(stringPercorrido_superior + i) = *(*(matriz + i) + (i-j));
    }
  }

  // atualizar vetor com linhas diagonais inferior triangular da matriz
  for(int j = 0; j < config.COLUNAS ; j++){
    for(int i = 0; i < config.LINHAS-1 ; i++){
      *(stringPercorrido_inferior + i) = *(*(matriz + i) + (i+j));
    }
    if ( verificacao(stringPercorrido_inferior) == 1){
      printf(" -> Diagonal Princiapal");
      return (1);
    }
  }

  // libera a memória
  free(stringPercorrido_superior);
  free(stringPercorrido_inferior);
}

//#### verificação ['diagonal segundaria']
int verificacaoDiagonalSegundaria(char** matriz){
  s_configuration config = Config();

  char *stringPercorrido_superior = calloc( config.LINHAS, sizeof(char) );
  char *stringPercorrido_inferior = calloc( config.LINHAS, sizeof(char) );

  // atualizar vetor com linhas diagonais segundaria superior
  for(int j = config.COLUNAS-1; j >= 0  ; j--){
    for(int i=config.LINHAS-1; i >= 0  ; i--){
      *(stringPercorrido_superior + i) = *(*(matriz+i) + (j-i));
    }
    if( verificacao(stringPercorrido_superior) == 1 ){  
      printf(" -> Diagonal Segundaria");
      return (1);
    }
  }

  // atualizar vetor com linhas diagonais segundaria inferior
  for(int j = config.COLUNAS-1; j >= 0  ; j--){
    for(int i=(config.LINHAS-1)-1; i >= 0  ; i--){
      *(stringPercorrido_inferior + i) = *(*(matriz+i) + (j+i));
    }
    if( verificacao(stringPercorrido_inferior) == 1 ){  
      printf(" -> Diagonal Segundaria: ");
      return (1);
    }
  }

  // libera a memória
  free(stringPercorrido_superior);
  free(stringPercorrido_inferior);
}