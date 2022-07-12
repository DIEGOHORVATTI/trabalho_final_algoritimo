#include "../controller/verified_file_config.c"
#include "../controller/fill_file.c"
#include "../controller/fill_matriz.c"

void unit_testing_1(){
  s_configuration config = Config();

  printf("\n%s───────────────────────────────────────\nLINHAS: %d\nCOLUNAS: %d\nOCORRENCIA: %d\n───────────────────────────────────────%s\n", 
    __COLOR_BLUE, 
    config.LINHAS,
    config.COLUNAS,
    config.OCORRENCIA,
    __COLOR_FIM
  );

  /* if (config.name) free((void *)config.name); */

}

void all_unit_testing(){

  // unit_testing_1();
  fillMatriz();
}