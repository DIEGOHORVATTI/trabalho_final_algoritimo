//Criar letra randomica a cada milesegundo
char dnaLetra(){

  struct timeval tv;
  gettimeofday(&tv, 0);
  long int timeMilesegundos = tv.tv_usec * getpid();
  
  // precisão de milesegundos
  srand(timeMilesegundos);

  char string[] = {'A', 'T', 'C', 'G'};

  return (string[(rand() % 4)]);
}

//Criar matriz dinamica de ponteiros
char** createMatriz(){

  s_configuration config = Config();

  // aloca um vetor de config.LINHAS ponteiros para linhas
  char **matriz = (char **)malloc(config.LINHAS * sizeof(char *));

  // aloca um vetor com todos os elementos da matriz
  for (int i = 0; i < config.LINHAS; i++) *(matriz+i) = (char *)malloc(config.COLUNAS * sizeof(char));

  // verifica de matriz foi alocada
  if(matriz){
    return(matriz);
  }else{ printf("\n%s Erro ao alocar matriz dinamica 'matriz' %s\n", __COLOR_RED, __COLOR_FIM ); }
  
  // libera a memória da matriz
  for (int i = 0; i < config.LINHAS; i++) free( *(matriz+i) ); free(matriz);
}

//Atribuir matriz com valores aleatórios
char** ascribeMatriz(){

  s_configuration config = Config();
  char **matriz = createMatriz();

  // atribuir valores aleatórios a matriz [A, T, C, G]
  for (int j = 0; j < config.COLUNAS; j++){
    for (int i = 0; i < config.LINHAS; i++){
      *(*(matriz + i) + j) = dnaLetra();
    }
  }
  return(matriz);

  // libera a memória da matriz
  for (int i = 0; i < config.LINHAS; i++) free( *(matriz+i) ); free(matriz);
}

//Passar matriz para arquivo de texto
void fillMatriz(){
  s_configuration config = Config();
  
  FILE *arquivo = fopen(config.ARQUIVO_TXT, "r");
  char **matriz = createMatriz();
  matriz = ascribeMatriz();

  // verificar se arquivo existe
  if(arquivo){

    //verificar se é para criar arquivo em C aleatório
    if ( strcmp(config.ALEATORIO, "true") == 0) escreverFile(matriz);
    
  }else{ printf("\n%s Erro ao abrir o arquivo '%s'%s\n", __COLOR_RED, config.ARQUIVO_TXT, __COLOR_FIM); }

  fclose(arquivo);
  free((void*) config.ARQUIVO_TXT);
  // libera a memória da matriz
  for (int i = 0; i < config.LINHAS; i++) free( *(matriz+i) ); free(matriz);
}