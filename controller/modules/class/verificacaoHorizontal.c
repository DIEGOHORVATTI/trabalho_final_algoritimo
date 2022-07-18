int verificacaoHorizontal(char** matriz){
  s_configuration config = Config();

  char *stringPercorrido = (char*)calloc(config.LINHAS, sizeof(char));
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