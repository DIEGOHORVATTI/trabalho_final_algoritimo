#include "../controller/fill.c"

void imprimir(){
  s_configuration config = Config();

  printf("\n%sversion: %d\nname: %s\nemail: %s%s\n", 
    __COLOR_BLUE, 
    config.version,
    config.name,
    config.email,
    __COLOR_FIM
  );

#include "../src/clearFree.c"
}