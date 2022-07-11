#include "./src/header.h"
#include "./view/debug.c"
#include <time.h>

int main(){

    srand(time(NULL));
    
    imprimir();

    FILE *arquivo;
    
    //matriz dinamica
    int **matriz;
    matriz = malloc(3 * sizeof(int *));

    //matriz de vetores
    for (int i = 0; i < 3; i++){
        matriz[i] = malloc(3 * sizeof(int));
    }

    arquivo = fopen("./matriz.txt", "w"); 
  
    //verificar se arquivo existe
    if( arquivo == NULL ){
    	printf("\nerro ao abrir o arquivo 'matriz.txt'\n");
    	exit(1);
	}  

    //atribuir valores aleatórios a matriz (A, T, C, G)  
    for( int j=0; j < 3; j++){
        for( int i=0; i < 3; i++){
            matriz[i][j] = 10+(rand() % 90);
        }
	}	
	
    //atribuir matriz ao arquivo 
    for(int j=0; j < 3; j++){
        for( int i=0; i < 3;i++){
       		fprintf( arquivo,"%d\t", matriz[i][j]);
   		}

   		if(j < 3-1) fprintf(arquivo, "\n");
        
    }

    //printagem de matriz
    
    free(matriz);
    fclose(arquivo);

    return 0;
}