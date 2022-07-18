int verificacaoDiagonalPrincipal(char** matriz){
  s_configuration config = Config();

  char *stringPercorrido_superior = calloc( config.LINHAS, sizeof(char) );
  char *stringPercorrido_inferior = calloc( config.LINHAS, sizeof(char) );

  // atualizar vetor com linhas diagonais superior triangular da matriz
  for(int j = 0; j < config.COLUNAS ; j++){
    for(int i = 0; i < config.LINHAS ; i++){
      *(stringPercorrido_superior + i) = *(*(matriz + i) + (i-j));
    }
    if ( verificacao(stringPercorrido_inferior) == 1){
      printf(" -> Diagonal Princiapal");
      return (1);
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