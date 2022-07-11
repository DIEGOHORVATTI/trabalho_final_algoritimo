#include "../model/bd.c"

static int handler(void* USER, const char* section, const char* name, const char* value){
    s_configuration *pconfig = (s_configuration *)USER;

    //verificação da API, existe um [cabeçalho] e um dado e um valor para ser lido
    #define MATCH(s, n) strcmp(section, s) == 0 && strcmp(name, n) == 0
    
    if (MATCH("MATRIZ", "LINHAS")) {
        pconfig->LINHAS = atoi(value);
    }
    else if (MATCH("MATRIZ", "COLUNAS")) {
        pconfig->COLUNAS = atoi(value);
    }
    else if (MATCH("USER", "OCORRENCIA")){
        pconfig->OCORRENCIA = atoi(value);
    }
    /* 
    else if (MATCH("USER", "email")){
        pconfig->email = strdup(value);
    } 
    */
    else{ 
        return(0); 
    }

    return 1;
}