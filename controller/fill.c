#include "./handler.c"

s_configuration Config(){
  s_configuration config;

  if (ini_parse("./model/config.ini", handler, &config) < 0) { 
    printf("%s Arquivo não encontrado './model/config.ini'%s\n", color_vermelhoclaro, color_fim);
  }

  return (config);
}
