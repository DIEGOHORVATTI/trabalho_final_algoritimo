void view_index(){

  printf("%s\n Verifica primeira ocorrencia de simio [\n\t'horizontal' -> \n\t'vertical' -> \n\t'diagonal principal' -> \n\t'diagonal segundaria' ->\n ]%s\n\n", __COLOR_LIGHT_CYAN, __COLOR_FIM);

  lerFile() == 1 ? printf("\n\n [[ %sSimio%s ]]", __COLOR_LIGHT_PURPLE, __COLOR_FIM) : printf("\n\n [[ %sHumano%s ]]", __COLOR_LIGHT_BLUE, __COLOR_FIM);
}