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