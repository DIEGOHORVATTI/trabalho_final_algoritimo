//Criar letra randomica a cada milesegundo
char dnaLetra(){

  struct timeval tv;
  gettimeofday(&tv, 0);
  long int timeMilesegundos = tv.tv_usec * getpid();
  
  // precisão de milesegundos
  srand(timeMilesegundos);

  char string[] = {'A', 'T', 'C', 'G'};

  // 1 -> A
  // 2 -> T
  // 3 -> C
  // 4 -> G

  return (string[(rand() % 4)]);
}

//Criar matriz dinamica de ponteiros
char** createMatriz(){

  s_configuration config = Config();

  // aloca um vetor de config.LINHAS ponteiros para linhas
  char **matriz = (char **)malloc(config.LINHAS * sizeof(char *));

  // aloca cada uma das linhas (vetores de config.COLUNAS inteiros)
  for (int i = 0; i < config.LINHAS; i++) *(matriz+i) = (char *)malloc(config.COLUNAS * sizeof(char));

  return(matriz);

  // libera a memória da matriz
  for (int i = 0; i < config.LINHAS; i++) free(matriz[i]);
  free(matriz);
}

void fillMatriz(){

  s_configuration config = Config();

  FILE *arquivo = fopen(config.ARQUIVO_TXT, "r");

  char **matriz = createMatriz();

  //verifica de matriz foi alocada
  if(matriz != NULL){
    // verificar se arquivo existe
    if (arquivo != NULL){

      // atribuir valores aleatórios a matriz [A, T, C, G]
      for (int j = 0; j < config.COLUNAS; j++){
        for (int i = 0; i < config.LINHAS; i++){
          *(*(matriz + i) + j) = dnaLetra();
        }
      }
      
      //verificar se é para criar arquivo em C aleatório
      if ( strcmp(config.ALEATORIO, "true") == 0) escreverFile(matriz);

      // libera a memória da matriz
      for (int i = 0; i < config.LINHAS; i++) free(matriz[i]);
      free(matriz);
      // libera a memória do nome de aruivo de texto
      free((void*) config.ARQUIVO_TXT);

    }else{ printf("\n%s Erro ao abrir o arquivo '%s'%s\n", __COLOR_RED, config.ARQUIVO_TXT, __COLOR_FIM); }
  }else{ printf("\n%s Erro ao alocar matriz dinamica 'matriz' %s\n", __COLOR_RED, __COLOR_FIM ); }

  fclose(arquivo);
}