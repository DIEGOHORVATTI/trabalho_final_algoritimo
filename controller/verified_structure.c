// Verificação da API de .config:
// 1) verifica se existe um [cabeçalho]
// 2) verifica de no cabeçalho a um dado e um valor para ser lido
// 3) verifica se dado é existente
// 4) Modificar dado existente para tipo de dado setado no model
// atoi   -> inteiro, int
// strdup -> string, *char

static int handler(void* USER, const char* section, const char* name, const char* value){

    s_configuration *pconfig = (s_configuration *)USER;

    #define MATCH(s, n) strcmp(section, s) == 0 && strcmp(name, n) == 0
    
    if (MATCH("MATRIZ", "LINHAS")) { pconfig->LINHAS = atoi(value); }

    else if(MATCH("MATRIZ", "COLUNAS")) { pconfig->COLUNAS = atoi(value); }

    else if(MATCH("USER", "OCORRENCIA")){ pconfig->OCORRENCIA = atoi(value); }

    else if(MATCH("USER", "ALEATORIO")){ pconfig->ALEATORIO = strdup(value); }

    else if (MATCH("USER", "ARQUIVO_TXT")){ pconfig->ARQUIVO_TXT = strdup(value); } 
    
    else{ return(0); }

    return 1;
}