#include "../controller/fill.c"

void imprimir(){
  s_configuration config = Config();

  printf("\n%sLINHAS: %d\nCOLUNAS: %d\nOCORRENCIA: %d%s\n", 
    __COLOR_BLUE, 
    config.LINHAS,
    config.COLUNAS,
    config.OCORRENCIA,
    __COLOR_FIM
  );

  /* 
  if (config.name)
    free((void *)config.name); 
  */

}