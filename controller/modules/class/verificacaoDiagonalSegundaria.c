int verificacaoDiagonalSegundaria_superior(char** matriz){
  s_configuration config = Config();

  char *stringPercorrido = (char*)calloc( config.LINHAS, sizeof(char) );
  // atualizar vetor com linhas diagonais segundaria superior
  for(int j= config.COLUNAS-1; j >= 0; j--){
    for(int i=config.LINHAS-1; i >= 0; i--){
      *(stringPercorrido + i) = *(*(matriz+i) + (j-i));
    }
    if( verificacao(stringPercorrido) == 1 ){  
      printf(" -> Diagonal Segundaria");
      return (1);
    }
  }
  // libera a memória
  free(stringPercorrido);
}

int verificacaoDiagonalSegundaria_inferior(char** matriz){
  s_configuration config = Config();

  char *stringPercorrido = (char*)calloc( config.LINHAS, sizeof(char) );
  // atualizar vetor com linhas diagonais segundaria superior
  for(int j = config.COLUNAS-1; j >= 0; j--){
    for(int i=(config.LINHAS-1)-1; i >= 0; i--){
      *(stringPercorrido + i) = *(*(matriz+i) + (j+i));
    }
    if( verificacao(stringPercorrido) == 1 ){  
      printf(" -> Diagonal Segundaria: ");
      return (1);
    }
  }
  // libera a memória
  free(stringPercorrido);
}


int verificacaoDiagonalSegundaria(char** matriz){
  if (verificacaoDiagonalSegundaria_superior(matriz) == 1) return(1);
  if (verificacaoDiagonalSegundaria_inferior(matriz) == 1) return(1);
}