void view_index(){

  printDNA();

  switch (lerFile()){
  case 1:
    printf("\n\n [[ %sSimio%s ]]\n", __COLOR_LIGHT_PURPLE, __COLOR_FIM);
    printSimio();
  break;
  default:
    printf("\n\n [[ %sHumano%s ]]", __COLOR_LIGHT_BLUE, __COLOR_FIM);
    printHumano();
  }
  
}