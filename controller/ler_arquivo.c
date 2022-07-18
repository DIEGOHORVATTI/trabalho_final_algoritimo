//ler arquivo txt e alocar em um vetor
int lerFile(){

  s_configuration config = Config();
  FILE *arquivo = fopen(config.ARQUIVO_TXT, "r");
  
  //alocação do vetor da matriz
  char *vetorDNA;
  vetorDNA = malloc( (config.COLUNAS * config.LINHAS) * (sizeof(char*)) );
  
  //verificar se vetor DNA foi alocado
  if(vetorDNA){

    // copiar todo o conteudo do arquivo.txt para o vetor dinamico vetorDNA 
    for( int i=0; !(feof(arquivo)); i++ ){
      fscanf(arquivo, "%s", &vetorDNA[i]);
    }

    return(isSimian(vetorDNA));

  }else{ printf("\n%s Erro ao alocar vetor dinamico de matriz: 'VetorDNA' %s\n", __COLOR_RED, __COLOR_FIM ); }
  free(vetorDNA);
  fclose(arquivo);
  free((void*) config.ARQUIVO_TXT);
}