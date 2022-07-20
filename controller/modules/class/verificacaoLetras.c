int verificaLetra(char** matriz){
  s_configuration config = Config();

  // Verificar se existe uma ocorrencia que não é ['T', 'A', 'C', G']
  for (int j = 0; j < config.COLUNAS; j++){
    for (int i = 0; i < config.LINHAS; i++){
      
      if ( !(*(*(matriz + i) + j) == 'T' || *(*(matriz + i) + j) == 'A'|| *(*(matriz + i) + j) == 'C' || *(*(matriz + i) + j) == 'G') ){
        printFail();
        printf("\n%s ERRO: A letra ['%c'], na posição\n [Linha: %d][Coluna: %d]\n Não faz parte das bases nitrogenadas\n ['T', 'A', 'C', G']\n Arquivo: '%s'%s", __COLOR_LIGHT_RED, *(*(matriz + i) + j), i+1, j+1, config.ARQUIVO_TXT ,__COLOR_FIM);
        exit(0);
        free((void *)config.ARQUIVO_TXT);
      }
      
    }
  }

}