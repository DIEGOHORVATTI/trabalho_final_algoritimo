#include "../controller/fill.c"

void imprimir(){
  s_configuration config = Config();

  printf("\n%sversion: %d\nname: %s\nemail: %s%s\n", 
    color_azul, 
    config.version,
    config.name,
    config.email,
    color_fim
  );

#include "../src/clearFree.c"
}