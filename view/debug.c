#include "../controller/verified_file_config.c"
#include "../controller/fill_file.c"
#include "../controller/fill_matriz.c"

void unit_testing_1(){
  s_configuration config = Config();

  printf("\n%s───────────────────────────────────────\nLINHAS: %d\nCOLUNAS: %d\nOCORRENCIA: %d\nArquivo de texto: %s\n───────────────────────────────────────%s\n", 
    __COLOR_BLUE, 
    config.LINHAS,
    config.COLUNAS,
    config.OCORRENCIA,
    config.ARQUIVO_TXT,
    __COLOR_FIM
  );

  if (config.ARQUIVO_TXT) free((void *)config.ARQUIVO_TXT);

}

void all_unit_testing(){

  //unit_testing_1();
  fillMatriz();
}