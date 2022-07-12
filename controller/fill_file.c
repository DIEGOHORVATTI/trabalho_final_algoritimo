/*
  w  -> Escrita (cria o arquivo caso ele não exista)
  r  -> leitura
  a  -> anexar (adicionar informação ao final de um arquivo que já existe)
  r+ -> leitura e escrita
  w+ -> leitura e escrita (apaga o conteúdo caso o arquivo exista)
  a+ -> leitura e escrita (adiciona ao final do arquivo)
*/


void escreverFile(char **matriz){

  s_configuration config = Config();
  FILE *arquivo = fopen("./matriz.txt", "w+");

  // atribuir valores aleatórios a matriz [A, T, C, G]
  for (int j = 0; j < config.COLUNAS; j++){
    for (int i = 0; i < config.LINHAS; i++){
      fputc(*(*(matriz + i) + j), arquivo); // letra
      fputc(' ', arquivo);                  // espaço
    }
    //não atribuir '\n' para ultima linha do .txt
    if (j < config.COLUNAS-1){ 
      fputc('\n', arquivo);                 // quebra de linha
    }
  }

  fclose(arquivo);
}

char lerFile(char **matriz){
  
  FILE *arquivo = fopen("./matriz.txt", "r");
  
  while (!(feof(arquivo))){
    printf("%c", fgetc(arquivo));
  }
  fclose(arquivo);
}