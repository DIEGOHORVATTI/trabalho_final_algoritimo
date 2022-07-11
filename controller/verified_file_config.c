#include "./verified_structure.c"

// Verificar se arquivo de configuração existe com a função ini_parse da API do inih.c 
// Caso exista retorne a struct 'config' de configuração para arquivo alvo 

s_configuration Config(){
  s_configuration config;

  if (ini_parse("./config.ini", handler, &config) < 0) {
    printf("%s File not found: './config.ini'%s\n", __COLOR_RED, __COLOR_FIM);
  }

  return(config);
}