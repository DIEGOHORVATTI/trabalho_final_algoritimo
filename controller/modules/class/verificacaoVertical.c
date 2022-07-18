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