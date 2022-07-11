#include "./handler.c"

s_configuration Config(){
  s_configuration config;

  if (ini_parse("./model/config.ini", handler, &config) < 0) { 
    printf("%s Arquivo não encontrado './model/config.ini'%s\n", __COLOR_RED, __COLOR_FIM);
  }

  return (config);
}