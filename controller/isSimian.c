char* A(){
  //[A]
  s_configuration config = Config();
  char *A = calloc(config.OCORRENCIA, sizeof(char));

  for (int i = 0; i < config.OCORRENCIA; i++) *(A + i) = 'A';

  return(A);
  free(A);
}

char* T(){
  //[T]
  s_configuration config = Config();
  char *T = calloc(config.OCORRENCIA, sizeof(char));

  for (int i = 0; i < config.OCORRENCIA; i++) *(T + i) = 'T';

  return(T);
  free(T);
}

char* C(){
  //[C]
  s_configuration config = Config();
  char *C = calloc(config.OCORRENCIA, sizeof(char));

  for (int i = 0; i < config.OCORRENCIA; i++) *(C + i) = 'C';

  return(C);
  free(C);
}

char* G(){
  //[G]
  s_configuration config = Config();
  char *G = calloc(config.OCORRENCIA, sizeof(char));

  for (int i = 0; i < config.OCORRENCIA; i++) *(G + i) = 'G';

  return(G);
  free(G);
}


int verificaHorizontal(char *stringPercorrido){

  char *horizontalA = strstr(stringPercorrido, A());
  if( horizontalA ){
    printf(" ocorrencia horizontal: %s\n", A());
    return(1);
  }

    char *horizontalT = strstr(stringPercorrido, T());
  if( horizontalT ){
    printf(" ocorrencia horizontal: %s\n", T());
    return(1);
  }

  char *horizontalC = strstr(stringPercorrido, C());
  if( horizontalC ){
    printf(" ocorrencia horizontal: %s\n", C());
    return(1);
  }

  char *horizontalG = strstr(stringPercorrido, G());
  if( horizontalG ){
    printf(" ocorrencia horizontal: %s\n", G());
    return(1);
  }
}

int verificaVertical(char *stringPercorrido){

  char *verticalA = strstr(stringPercorrido, A());
  if (verticalA)
  {
    printf(" ocorrencia vertical %s\n", A());
    return(1);
  }

  char *verticalT = strstr(stringPercorrido, T());
  if( verticalT ){
    printf(" ocorrencia vertical %s\n", T());
    return(1);
  }

  char *verticalC = strstr(stringPercorrido, C());
  if( verticalC ){
    printf(" ocorrencia vertical %s\n", C());
    return(1);
  }

  char *verticalG = strstr(stringPercorrido, G());
  if( verticalG ){
    printf(" ocorrencia vertical %s\n", G());
    return(1);
  }
}



int isSimian(char *dna){

  s_configuration config = Config();

  //matriz vetor de vetorescom ponteiros
  char **matriz;
  matriz = malloc(config.LINHAS * sizeof(char*));

  // aloca cada uma das linhas (vetores de config.COLUNAS inteiros)
  for (int i = 0; i < config.LINHAS; i++){
    matriz[i] = malloc(config.COLUNAS * sizeof(char));
  }
  
  // atualiza matriz
  if(matriz){
    int y=0;
    for(int j = 0; j < config.COLUNAS ; j++){
      for(int i = 0; i < config.LINHAS ; i++){
        *(*(matriz + i) + j) = *(dna+y);
        y++;
      }
    }
    
    // printa matriz 
    for(int j = 0; j < config.COLUNAS ; j++){
      for(int i = 0; i < config.LINHAS ; i++){
        printf(" %c", *(*(matriz + i) + j) );
      }printf("\n");
    }
    
  }else{ printf("\n%s Erro ao alocar matriz dinamica 'matriz' %s\n", __COLOR_RED, __COLOR_FIM ); }

  //VERIFiCAÇÃO DE OCORRENCIAS
  printf("\n");
  for(int j = 0; j < config.COLUNAS; j++){

    // alocação do vetor da matriz
    char *stringPercorrido = calloc( config.LINHAS, sizeof(char));

    if(stringPercorrido){
      
      // atualizar vetor com linhas horizontais da matriz
      for (int i=0; i < config.LINHAS; i++) *(stringPercorrido + i) = *(*(matriz + i) + j);
      if ( verificaHorizontal(stringPercorrido) != 0){

        // atualizar vetor com linhas verticais da matriz
        for (int i=0; i < config.LINHAS; i++) *(stringPercorrido + i) = *(*(matriz + j) + i);
        if ( verificaVertical(stringPercorrido) != 0){
        }

      }

      free(stringPercorrido);
    }else{ printf("\n%s Erro ao alocar matriz dinamica 'matriz' %s\n", __COLOR_RED, __COLOR_FIM ); }
  }
  printf("\n");
  
  // libera a memória da matriz
  for (int i = 0; i < config.LINHAS; i++){
    free(matriz[i]);
  }
  free(matriz);

  return(0);
}