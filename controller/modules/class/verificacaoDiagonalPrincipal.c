int verificacaoDiagonalPrincipal_superior(char** matriz){
  s_configuration config = Config();

  char *stringPercorrido = (char*)calloc( config.LINHAS, sizeof(char) );
  // atualizar vetor com linhas diagonais superior triangular da matriz
  for(int j = 0; j < config.COLUNAS ; j++){
    for(int i = 0; i < config.LINHAS ; i++){
      *(stringPercorrido + i) = *(*(matriz + i) + (i-j));
    }
    if ( verificacao(stringPercorrido) == 1){
      printf(" -> Diagonal Princiapal");
      return (1);
    }
  }
  // libera a memória
  free(stringPercorrido);
}

int verificacaoDiagonalPrincipal_inferior(char** matriz){
  s_configuration config = Config();

  char *stringPercorrido = (char*)calloc( config.LINHAS, sizeof(char) );
  // atualizar vetor com linhas diagonais inferior triangular da matriz
  for(int j = 0; j < config.COLUNAS ; j++){
    for(int i = 0; i < config.LINHAS-1 ; i++){
      *(stringPercorrido + i) = *(*(matriz + i) + (i+j));
    }
    if ( verificacao(stringPercorrido) == 1){
      printf(" -> Diagonal Princiapal");
      return (1);
    }
  }
  // libera a memória
  free(stringPercorrido);
}

int verificacaoDiagonalPrincipal(char** matriz){
  if (verificacaoDiagonalPrincipal_superior(matriz) == 1) return(1);
  if (verificacaoDiagonalPrincipal_inferior(matriz) == 1) return(1);
}