//#### verificação em ordem de ['A', 'T', 'C', 'G'] por ocorrencia
int verificacao(char *stringPercorrido){
  s_configuration config = Config();

  //debugar strings vindas para verificação
  if ( strcmp(config.STRINGS_VERIFICACAO, "true") == 0) printf("\n%s %s%s\n", __COLOR_BLUE, stringPercorrido, __COLOR_FIM);
  free((void *)config.STRINGS_VERIFICACAO);
  
  if (verificaModuloA(stringPercorrido) == 1) return(1);
  if (verificaModuloT(stringPercorrido) == 1) return(1);
  if (verificaModuloC(stringPercorrido) == 1) return(1);
  if (verificaModuloG(stringPercorrido) == 1) return(1);
}