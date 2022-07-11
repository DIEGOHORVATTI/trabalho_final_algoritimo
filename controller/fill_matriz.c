/*
  w  -> Escrita (cria o arquivo caso ele não exista)
  r  -> leitura
  a  -> anexar (adicionar informação ao final de um arquivo que já existe)
  r+ -> leitura e escrita
  w+ -> leitura e escrita (apaga o conteúdo caso o arquivo exista)
  a+ -> leitura e escrita (adiciona ao final do arquivo)
*/

void fillMatriz(){

  srand(time(NULL)); //seed

  s_configuration config = Config();
  
  FILE *arquivo = fopen("./matriz.txt", "w+");

  // matriz dinamica
    // aloca um vetor de config.LINHAS ponteiros para linhas
    int **matriz;
    matriz = malloc(config.LINHAS * sizeof(int *));

    // aloca cada uma das linhas (vetores de config.COLUNAS inteiros)
    for (int i = 0; i < config.LINHAS; i++){
      matriz[i] = malloc(config.COLUNAS * sizeof(int));
    }
  
  //verifica de matriz foi alocada
  if(matriz != NULL){
    printf("\n%s Matriz alocada com sucesso%s\n", __COLOR_BLUE, __COLOR_FIM);
  
    // verificar se arquivo existe
    if (arquivo != NULL){

      printf("\n%s Arquivo 'matriz.txt' encontrado%s\n\n", __COLOR_BLUE, __COLOR_FIM);

      // atribuir valores aleatórios a matriz (A, T, C, G)
      for (int j = 0; j < config.COLUNAS; j++){
        for (int i = 0; i < config.LINHAS; i++){
          *(*(matriz + i) + j) = 10+(rand() % 90);
        }
      }
      
      // printar matriz
      for (int j = 0; j < config.COLUNAS; j++){
        for (int i = 0; i < config.LINHAS; i++){
          //printf(" %d", mat[j][i]);
          printf(" %d", *(*(matriz+i) + j) );
        }
        printf("\n");
      }

      // libera a memória da matriz
      for (int i = 0; i < config.LINHAS; i++){
        free(matriz[i]);
      }
      free(matriz);

    }else{
      printf("\n%s Erro ao abrir o arquivo 'matriz.txt'%s\n", __COLOR_RED, __COLOR_FIM );
    }
  }

  fclose(arquivo);

} 