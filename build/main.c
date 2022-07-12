#include "../src/header.h"                      // cabeçalhos
#include "../model/bd.c"                        // modelos
#include "../controller/verified_structure.c"   // verificar se estrutura e dados existe e converter os types 
#include "../controller/verified_file_config.c" // verificar se arquivo de configuração existe
#include "../controller/fill_file.c"            // preencher arquivo com dados da matriz de fill_matriz.c        
#include "../controller/fill_matriz.c"          // preencher matriz com dados de DNA aleatório e devolver a matriz para fill_file.c
#include "../view/debug.c"                      // depuração
#include "../view/index.c"                      // visualização de front end

int main(){
    
   // all_unit_testing(); // testes unitários de debug
   view_index();       // visualização geral

    return (0);
}