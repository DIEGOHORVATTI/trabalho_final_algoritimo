//Cabeçalhos
#include "../src/header.h"                      // all libs

//Globais
#include "../src/colors.h"                      // global Color

//Models
#include "../model/bd.c"                        // model database

//Back end
#include "../controller/verified_structure.c"   // verificar se estrutura e dados existe e converter os types 
#include "../controller/verified_file_config.c" // verificar se arquivo de configuração existe
#include "../controller/fill_file.c"            // preencher arquivo com dados da matriz de fill_matriz.c
#include "../controller/debug.c"                // Debug geral
#include "../controller/isSimian.c"             // verifica ocorrencias de DNAs 
#include "../controller/read_file.c"            // ler dados do arquivo e atualizar a matriz com os mesmos
#include "../controller/fill_matriz.c"          // preencher matriz com dados de DNA aleatório e devolver a matriz para fill_file.c

//Front end
#include "../view/index.c"                      // visualização de front end

int main(){

    fillMatriz();                               //preencher matriz
    view_index();                               // visualização geral

    return(0);
}