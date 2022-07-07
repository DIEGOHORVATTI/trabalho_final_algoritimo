#include "../controller/handler.c"

s_configuration Config(){
  s_configuration config;

  if (ini_parse("./config.ini", handler, &config) < 0){
      printf("Can't load './config.ini'\n");
  }

  return( config );
}