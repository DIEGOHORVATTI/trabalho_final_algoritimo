//#### Verificação de sub string
int verificaModuloA(char* stringPercorrido){
  char *stringPercorrida_A = strstr(stringPercorrido, A());
  if( stringPercorrida_A ){
    printf("\n Ocorrencia: %s", A()); 
    return(1);
  }
}
int verificaModuloT(char* stringPercorrido){
  char *stringPercorrida_T = strstr(stringPercorrido, T());
  if( stringPercorrida_T ){
    printf("\n Ocorrencia: %s", T());
    return (1);
  }
}
int verificaModuloC(char *stringPercorrido) {
  char *stringPercorrida_C = strstr(stringPercorrido, C());
  if( stringPercorrida_C ){
    printf("\n Ocorrencia: %s", C());
    return (1);
  }
}
int verificaModuloG(char *stringPercorrido) {
  char *stringPercorrida_G = strstr(stringPercorrido, G());
  if( stringPercorrida_G ){
    printf("\n Ocorrencia: %s", G());
    return (1);
  }
}