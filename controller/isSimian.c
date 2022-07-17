int isSimian(char *dna){

  s_configuration config = Config();

  //carrega matriz de vetor de arquivo.txt
  char **matriz = preencherMatrizArquivo(dna);

  if ( verificacaoHorizontal(matriz)         == 1) return(1);
  if ( verificacaoVertical(matriz)           == 1) return(1);
  if ( verificacaoDiagonalPrincipal(matriz)  == 1) return(1);
  if ( verificacaoDiagonalSegundaria(matriz) == 1) return(1);

  //libera memória matriz
  for (int i = 0; i < config.LINHAS; i++) free( *(matriz+i) ); free(matriz);
}