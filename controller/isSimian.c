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
  if( stringPercorrida_A ){
    printf("\n Ocorrencia: %s", A()); 
    return(1);
  }

  char *stringPercorrida_T = strstr(stringPercorrido, T());
  if( stringPercorrida_T ){ 
    printf("\n Ocorrencia: %s", T());
    return(1);
  }

  char *stringPercorrida_C = strstr(stringPercorrido, C());
  if( stringPercorrida_C ){
    printf("\n Ocorrencia: %s", C());
    return(1);
  }

  char *stringPercorrida_G = strstr(stringPercorrido, G());
  if( stringPercorrida_G ){
    printf("\n Ocorrencia: %s", G());
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
    

    
      printf("\n");
      // printa matriz
      printf("\n matriz\n");
      printf("\n _____________________________\n");
      for(int j = 0; j < config.COLUNAS ; j++){
        for(int i = 0; i < config.LINHAS ; i++){
          printf(" %c", *(*(matriz + i) + j) );
        }printf("\n");
      }

      // printa horizontal
      printf("\n Horizontal\n");
      for(int j = 0; j < config.COLUNAS ; j++){
        for(int i = 0; i < config.LINHAS ; i++){
          printf(" %c", *(*(matriz + i) + j));
        }
        printf("\n");
      }
      printf("\n");

      // printa vertical
      printf("\n Vertical\n");
      for(int j = 0; j < config.COLUNAS ; j++){
        for(int i = 0; i < config.LINHAS ; i++){
          printf(" %c", *(*(matriz + j) + i));
        }
        printf("\n");
      }
      printf("\n");

      // printa diagonal principal superior
      printf("\n Diagonal principal superior\n");
      for(int j = 0; j < config.COLUNAS ; j++){
        for(int i = 0; i < config.LINHAS ; i++){
          printf(" %c", *(*(matriz + i) + (i-j)) );
        }
        printf("\n");
      }
      printf("\n");

      // printa diagonal principal inferior
      printf("\n Diagonal principal inferior\n");
      for(int j = 0; j < config.COLUNAS ; j++){
        for(int i = 0; i < config.LINHAS-1 ; i++){
          printf(" %c", *(*(matriz + i) + (i+j)) );
        }
        printf("\n");
      }
      printf("\n");

      // printa diagonais segundaria superior
      printf("\n Diagonal segundaria superior\n");
      for(int j = config.COLUNAS-1; j >= 0  ; j--){
        for(int i=config.LINHAS-1; i >= 0  ; i--){
          printf(" %c", *(*(matriz + i) + (j-i)));
        }
        printf("\n");
      }
      printf("\n");

      // printa diagonais segundaria inferior
      printf("\n Diagonal segundaria inferior\n");
      for(int j = config.COLUNAS-1; j >= 0  ; j--){
        for(int i=(config.LINHAS-1)-1; i >= 0  ; i--){
          printf(" %c", *(*(matriz + i) + (j+i)));
        }
        printf("\n");
      }

    printf("\n"); 
   

    }else{ printf("\n%s Erro ao alocar matriz dinamica 'matriz' %s\n", __COLOR_RED, __COLOR_FIM ); }
  
    // alocação do vetor da matriz
    char *stringPercorrido          = calloc( config.LINHAS, sizeof(char));
    char *stringPercorrido_superior = calloc( config.LINHAS, sizeof(char) );
    char *stringPercorrido_inferior = calloc( config.LINHAS, sizeof(char) );

    if(stringPercorrido){
      // atualizar vetor com linhas horizontais da matriz
      for(int j = 0; j < config.COLUNAS ; j++)
        for (int i=0; i < config.LINHAS; i++)
          *(stringPercorrido + i) = *(*(matriz + i) + j);
            if ( verificacao(stringPercorrido) == 1) printf(" -> horizontal");
        
        else{
          // atualizar vetor com linhas verticais da matriz
          for (int j = 0; j < config.COLUNAS; j++)
            for (int i = 0; i < config.LINHAS; i++)
              *(stringPercorrido + i) = *(*(matriz + j) + i);
                if ( verificacao(stringPercorrido) == 1) printf(" -> Vertical");
            
          //atualizar vetor com linhas diagonais da matriz
          else{
            // atualizar vetor com linhas diagonais superior triangular da matriz
            for(int j = 0; j < config.COLUNAS ; j++)
              for(int i = 0; i < config.LINHAS ; i++)
                *(stringPercorrido_superior + i) = *(*(matriz + i) + i-j);

            // atualizar vetor com linhas diagonais inferior triangular da matriz
            for(int j = 0; j < config.COLUNAS ; j++)
              for(int i = 0; i < config.LINHAS-1 ; i++)
                *(stringPercorrido_inferior + i) = *(*(matriz + i) + i+j);
                  if ( verificacao(stringPercorrido_superior) == 1 || verificacao(stringPercorrido_inferior) == 1) printf(" -> Diagonal Princiapal");
              
              else{
                // atualizar vetor com linhas diagonais segundaria superior
                for(int j = config.COLUNAS-1; j >= 0  ; j--)
                  for(int i=config.LINHAS-1; i >= 0  ; i--)
                    *(stringPercorrido_superior + i) = *(*(matriz + i) + (j - i));

                // atualizar vetor com linhas diagonais segundaria inferior
                for(int j = config.COLUNAS-1; j >= 0  ; j--)
                  for(int i=(config.LINHAS-1)-1; i >= 0  ; i--)
                    *(stringPercorrido_inferior + i) = *(*(matriz + i) + (j + i));
                      if( verificacao(stringPercorrido_superior) == 1 || verificacao(stringPercorrido_inferior) == 1){  printf(" -> Diagonal Segundaria: "); }
                
              }
                  
          }
        }

      free(stringPercorrido);
      free(stringPercorrido_superior);
      free(stringPercorrido_inferior);
    }else{ printf("\n%s Erro ao alocar matriz dinamica 'matriz' %s\n", __COLOR_RED, __COLOR_FIM ); }
  printf("\n\n");
 

  // libera a memória da matriz
  for (int i = 0; i < config.LINHAS; i++){
    free(matriz[i]);
  }
  free(matriz);

  return(0);
}