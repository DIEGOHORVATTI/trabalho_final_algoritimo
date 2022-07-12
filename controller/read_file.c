//ler arquivo txt e alocar em um vetor
char lerFile(char **matriz){

  s_configuration config = Config();
  FILE *arquivo = fopen(config.ARQUIVO_TXT, "r");
  
  //alocação do vetor da matriz
  char *vetorDNA;
  vetorDNA = malloc( (config.COLUNAS * config.LINHAS) * (sizeof(char*)) );
  
  //verificar se vetor DNA foi alocado
  if ( vetorDNA ){

    //copiar todo o conteudo doa rquivo .txt para o vetor vetorDNA 
    for( int i=0; !(feof(arquivo)); i++ ){
      fscanf(arquivo, "%s", &vetorDNA[i]);
    }
    
    //atribuir as dados do vetor a matriz
    int y=0;
    for(int j=0; j < config.COLUNAS; j++){
      for (int i=0; i < config.LINHAS; i++){
        *(*(matriz+i)+j) = vetorDNA[y];
        y++;
      }
    }
    
    //printar matriz
    for(int j=0; j < config.COLUNAS; j++){
      for (int i=0; i < config.LINHAS; i++){
        printf(" %c", *(*(matriz+i)+j));
      }
      printf("\n");
    }

    isSimian(matriz);
  }else{ printf("\n%s Erro ao alocar vetor dinamico de matriz: 'VetorDNA' %s\n", __COLOR_RED, __COLOR_FIM ); }
  

  free(vetorDNA);
  fclose(arquivo);
  free((void*) config.ARQUIVO_TXT);
}