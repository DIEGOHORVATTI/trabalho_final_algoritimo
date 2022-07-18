//Função principal
int isSimian(char *dna){
  s_configuration config = Config();

  //carrega matriz do vetor de DNA
  char **matriz = preencherMatrizArquivo(dna);

  //deburação
  debug(matriz);
  //debugFilhos(matriz);

  // verificação alvo ['horizontal', 'vertical', 'diagonal principal', 'diagonal segundaria']
  if ( verificacaoHorizontal         (matriz) == 1) return(1);
  if ( verificacaoVertical           (matriz) == 1) return(1);
  if ( verificacaoDiagonalPrincipal  (matriz) == 1) return(1);
  if ( verificacaoDiagonalSegundaria (matriz) == 1) return(1);

  //libera memória matriz
  for (int i = 0; i < config.LINHAS; i++) free( *(matriz+i) ); free(matriz);
}