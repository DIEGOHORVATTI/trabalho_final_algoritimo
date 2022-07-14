void debug(char **matriz){
  s_configuration config = Config();

  printf("\n");
      // printa matriz
      printf("\n Matriz");
      printf("\n%s ────────────────────────────%s\n", __COLOR_LIGHT_PURPLE, __COLOR_FIM);
      for(int j = 0; j < config.COLUNAS ; j++){
        for(int i = 0; i < config.LINHAS ; i++){
          printf(" %c", *(*(matriz + i) + j));
        }printf("\n");
      }

      // printa horizontal
      printf("\n Horizontal");
      printf("\n%s ────────────────────────────%s\n", __COLOR_LIGHT_PURPLE, __COLOR_FIM);
      for(int j = 0; j < config.COLUNAS ; j++){
        for(int i = 0; i < config.LINHAS ; i++){
          printf(" %c", *(*(matriz + i) + j));
        }
        printf("\n");
      }
      printf("\n");

      // printa vertical
      printf("\n Vertical");
      printf("\n%s ────────────────────────────%s\n", __COLOR_LIGHT_PURPLE, __COLOR_FIM);
      for(int j = 0; j < config.COLUNAS ; j++){
        for(int i = 0; i < config.LINHAS ; i++){
          printf(" %c", *(*(matriz + j) + i));
        }
        printf("\n");
      }
      printf("\n");

      // printa diagonal principal superior
      printf("\n Diagonal principal superior");
      printf("\n%s ────────────────────────────%s\n", __COLOR_LIGHT_PURPLE, __COLOR_FIM);
      for(int j = 0; j < config.COLUNAS ; j++){
        for(int i = 0; i < config.LINHAS ; i++){
          printf(" %c", *(*(matriz + i) + (i-j)) );
        }
        printf("\n");
      }
      printf("\n");

      // printa diagonal principal inferior
      printf("\n Diagonal principal inferior");
      printf("\n%s ────────────────────────────%s\n", __COLOR_LIGHT_PURPLE, __COLOR_FIM);
      for(int j = 0; j < config.COLUNAS ; j++){
        for(int i = 0; i < config.LINHAS-1 ; i++){
          printf(" %c", *(*(matriz + i) + (i+j)) );
        }
        printf("\n");
      }
      printf("\n");

      // printa diagonais segundaria superior
      printf("\n Diagonal segundaria superior");
      printf("\n%s ────────────────────────────%s\n", __COLOR_LIGHT_PURPLE, __COLOR_FIM);
      for(int j = config.COLUNAS-1; j >= 0  ; j--){
        for(int i=config.LINHAS-1; i >= 0  ; i--){
          printf(" %c", *(*(matriz + i) + (j-i)));
        }
        printf("\n");
      }
      printf("\n");

      // printa diagonais segundaria inferior
      printf("\n Diagonal segundaria inferior");
      printf("\n%s ────────────────────────────%s\n", __COLOR_LIGHT_PURPLE, __COLOR_FIM);
      for(int j = config.COLUNAS-1; j >= 0  ; j--){
        for(int i=(config.LINHAS-1)-1; i >= 0  ; i--){
          printf(" %c", *(*(matriz + i) + (j+i)));
        }
        printf("\n");
      }

    printf("\n");
}