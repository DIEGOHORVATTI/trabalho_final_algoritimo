//##Cabeçalhos
    #include "../src/header.h"                             // all libs

//##Globais
    #include "../src/colors.h"                             // global Color

//##Models
    #include "../model/bd.c"                               // model database

//##Back end
    #include "../controller/verified_structure.c"          // verificar se estrutura e dados existe e converter os types 
    #include "../controller/verified_file_config.c"        // verificar se arquivo de configuração existe
    //Modulos de verificação
    #include "../controller/modules/ocorrencias.c"         // Retorna ocorrencias de configuração
    #include "../controller/modules/verified_sub_string.c" // verifica se á ocorrencias em string
    #include "../controller/modules/verified_isSimian.c"   // verifica todos os as classes de ocorrencias
    //Classes de ocorrencias
    #include "../controller/modules/class/verificacaoHorizontal.c"
    #include "../controller/modules/class/verificacaoVertical.c"
    #include "../controller/modules/class/verificacaoDiagonalPrincipal.c"
    #include "../controller/modules/class/verificacaoDiagonalSegundaria.c"
    //Depuração
    #include "../controller/debug.c"                       // Debug geral
    //Preencher matrizes e arquivos
    #include "../controller/fill_file.c"                   // preencher arquivo de texto com matriz randomica 
    #include "../controller/fill_matriz.c"                 // preencher matriz com dados de DNA aleatório e devolver a matriz para fill_file.c
    #include "../controller/modules/fill_matriz.c"         // preencher matriz com dna de arquivo vetor
    //Envio de verificação e DNA
    #include "../controller/isSimian.c"                    // envia DNA para verificação em verified_isSimian.c
    #include "../controller/ler_arquivo.c"                 // preencher arquivo com dados da matriz de fill_matriz.c

//##Front end
    #include "../view/index.c"                             // visualização de front end

int main(){

    fillMatriz();                                      // preencher matriz
    view_index();                                      // visualização geral

    return(0);
}