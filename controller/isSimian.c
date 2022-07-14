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


int verificacao(char *stringPercorrido){
  char *stringPercorrida_A = strstr(stringPercorrido, A());
  printf("%s", A());
  if( stringPercorrida_A ) return(1);

  char *stringPercorrida_T = strstr(stringPercorrido, T());
  printf("%s", T());
  if( stringPercorrida_T ) return(1);

  char *stringPercorrida_C = strstr(stringPercorrido, C());
  printf("%s", C());
  if( stringPercorrida_C ) return(1);

  char *stringPercorrida_G = strstr(stringPercorrido, G());
  printf("%s", G());
  if( stringPercorrida_G ) return(1);
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
      if ( verificacao(stringPercorrido) == 1){ printf(" ocorrencia horizontal: ");
        else{

          if ( verificacao(stringPercorrido) == 1){ printf(" ocorrencia Vertical: ");
            else{
              printf(" ocorrencia Diagonal Princial: ");
              // atualizar vetor com linhas verticais da matriz
              for (int i=0; i < config.LINHAS; i++) *(stringPercorrido + i) = *(*(matriz + j) + i);
              if ( verificacao(stringPercorrido) != 1) printf(" ocorrencia Vertical: %s\n", G());
              if ( verificacao(stringPercorrido) != 0){
                
                // atualizar vetor com linhas diagonais principais da matriz
                for (int i=0; i < config.LINHAS; i++) *(stringPercorrido + i) = *(*(matriz + i) + i);
                if ( verificacao(stringPercorrido) != 1) printf(" ocorrencia horizontal: %s\n", G());
                if ( verificacao(stringPercorrido) != 0){
                }
              
              }
            }
          }
          
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