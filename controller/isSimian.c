int isSimian(char *dna){

  s_configuration config = Config();

  //printar vetor
  /* 
    for (int i=0; i < (config.LINHAS * config.COLUNAS); i++){
      printf("%c", dna[i]);
    } 
  */

  //[A, T, C, G]
  char *A = calloc( config.OCORRENCIA, sizeof(char) );
  char *T = calloc( config.OCORRENCIA, sizeof(char) );
  char *C = calloc( config.OCORRENCIA, sizeof(char) );
  char *G = calloc( config.OCORRENCIA, sizeof(char) );

  for (int i = 0; i < config.OCORRENCIA; i++){
    *(A + i) = 'A';
    *(T + i) = 'T';
    *(C + i) = 'C';
    *(G + i) = 'G';
  }

  char *A_vertical_horizontal = strstr(dna, A);
  if(A_vertical_horizontal){
    printf(" %s\n", A);
    return(1); 
  }

  char *T_vertical_horizontal = strstr(dna, T);
  if(T_vertical_horizontal){
    printf(" %s\n", T);
    return(1); 
  }

  char *C_vertical_horizontal = strstr(dna, C);
  if(C_vertical_horizontal){
    printf(" %s\n", C);
    return(1); 
  }

  char *G_vertical_horizontal = strstr(dna, G);
  if(G_vertical_horizontal){
    printf(" %s\n", G);
    return(1); 
  }

  free(A);
  free(T);
  free(C);
  free(G);
  return(0);
}