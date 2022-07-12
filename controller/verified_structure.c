// atoi   -> inteiro, int
// strdup -> string, *char

// 1) Verificação da API de .config:
// 2) Existe um [cabeçalho]? 
// 3) Nesse cabeçalho a um dado e um valor para ser lido?
// 4) Esse dado é existente?
// 5) Modificar dado existente. 

static int handler(void* USER, const char* section, const char* name, const char* value){

    s_configuration *pconfig = (s_configuration *)USER;

    #define MATCH(s, n) strcmp(section, s) == 0 && strcmp(name, n) == 0
    
    if (MATCH("MATRIZ", "LINHAS")) { pconfig->LINHAS = atoi(value); }

    else if(MATCH("MATRIZ", "COLUNAS")) { pconfig->COLUNAS = atoi(value); }

    else if(MATCH("USER", "OCORRENCIA")){ pconfig->OCORRENCIA = atoi(value); }

    else if (MATCH("USER", "ARQUIVO_TXT")){ pconfig->ARQUIVO_TXT = strdup(value); } 
    
    else{ return(0); }

    return 1;
}