void unit_testing_1(){
  s_configuration config = Config();

  printf("\n%s───────────────────────────────────────%s\n", __COLOR_LIGHT_BLUE, __COLOR_FIM);
    printf("LINHAS: %d\nCOLUNAS: %d\nOCORRENCIA: %d\nArquivo de texto: %s", 
      config.LINHAS,
      config.COLUNAS,
      config.OCORRENCIA,
      config.ARQUIVO_TXT
    );
  printf("\n%s───────────────────────────────────────%s\n", __COLOR_LIGHT_BLUE, __COLOR_FIM);

  if (config.ARQUIVO_TXT) free((void *)config.ARQUIVO_TXT);
}

void unit_testing_2(){
  printf("\n%s───────────────────────────────────────%s\n", __COLOR_CYAN, __COLOR_FIM);
    fillMatriz();
  printf("\n%s───────────────────────────────────────%s\n", __COLOR_CYAN, __COLOR_FIM);
}

void all_unit_testing(){

  unit_testing_1();

  unit_testing_2();
}