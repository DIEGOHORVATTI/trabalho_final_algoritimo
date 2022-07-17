//#### Ocorrencias de sequencia de dna
char* A(){
  s_configuration config = Config();
  char *A = calloc(config.OCORRENCIA, sizeof(char));

  for (int i = 0; i < config.OCORRENCIA; i++) *(A + i) = 'A';

  return(A);
  free(A);
}

char* T(){
  s_configuration config = Config();
  char *T = calloc(config.OCORRENCIA, sizeof(char));

  for (int i = 0; i < config.OCORRENCIA; i++) *(T + i) = 'T';

  return(T);
  free(T);
}

char* C(){
  s_configuration config = Config();
  char *C = calloc(config.OCORRENCIA, sizeof(char));

  for (int i = 0; i < config.OCORRENCIA; i++) *(C + i) = 'C';

  return(C);
  free(C);
}

char* G(){
  s_configuration config = Config();
  char *G = calloc(config.OCORRENCIA, sizeof(char));

  for (int i = 0; i < config.OCORRENCIA; i++) *(G + i) = 'G';

  return(G);
  free(G);
}