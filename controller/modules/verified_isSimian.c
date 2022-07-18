//#### verificação em ordem de ['A', 'T', 'C', 'G'] por ocorrencia
int verificacao(char *stringPercorrido){

  //debugar strings vindas para verificação
  printf("\n%s\n", stringPercorrido);

  if (verificaModuloA(stringPercorrido) == 1) return(1);
  if (verificaModuloT(stringPercorrido) == 1) return(1);
  if (verificaModuloC(stringPercorrido) == 1) return(1);
  if (verificaModuloG(stringPercorrido) == 1) return(1);
}