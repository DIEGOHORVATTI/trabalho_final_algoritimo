char dnaLetra(){

  struct timeval tv; // tv -> timeval
  gettimeofday(&tv, 0);

  long int timeMilesegundos = tv.tv_usec * getpid(); // precisão de milesegundos
  srand(timeMilesegundos);

  char string[] = {'A', 'T', 'C', 'G'};

  // 1 -> A
  // 2 -> T
  // 3 -> C
  // 4 -> G

  return (string[(rand() % 4)]);
}

void fillMatriz(){

    s_configuration config = Config();

    FILE *arquivo = fopen(config.ARQUIVO_TXT, "w+");
    
    // aloca um vetor de config.LINHAS ponteiros para linhas
    char **matriz;
    matriz = malloc(config.LINHAS * sizeof(char*));

    // aloca cada uma das linhas (vetores de config.COLUNAS inteiros)
    for (int i = 0; i < config.LINHAS; i++){
      matriz[i] = malloc(config.COLUNAS * sizeof(char));
    }

    //verifica de matriz foi alocada
    if(matriz != NULL){
      //#printf("\n%s Matriz alocada com sucesso%s\n", __COLOR_BLUE, __COLOR_FIM);

      // verificar se arquivo existe
      if (arquivo != NULL){
        //#printf("\n%s Arquivo 'matriz.txt' encontrado%s\n\n", __COLOR_BLUE, __COLOR_FIM);

        // atribuir valores aleatórios a matriz [A, T, C, G]
        for (int j = 0; j < config.COLUNAS; j++){
          for (int i = 0; i < config.LINHAS; i++){
            *(*(matriz + i) + j) = dnaLetra();
          }
        }

        escreverFile(matriz);
        lerFile();

        // libera a memória da matriz
        for (int i = 0; i < config.LINHAS; i++){
          free(matriz[i]);
        }
        free(matriz);
        free((void*) config.ARQUIVO_TXT);

      }else{ printf("\n%s Erro ao abrir o arquivo 'matriz.txt'%s\n", __COLOR_RED, __COLOR_FIM ); }
    }else{ printf("\n%s Erro ao alocar matriz dinamica 'matriz' %s\n", __COLOR_RED, __COLOR_FIM ); }

    fclose(arquivo);
}