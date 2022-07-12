int isSimian(char *dna){

  s_configuration config = Config();

  //printar matriz
  for (int i=0; i < (config.LINHAS * config.COLUNAS); i++){
    printf("%c", dna[i]);
  }

  return(0);
}