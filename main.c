#include "./src/header.h"
#include "./view/debug.c"

int main(){
    
    imprimir();

    FILE *arquivo;
    
    int i, j, matriz[3][3];
    
    arquivo = fopen("matriz.txt", "w"); 
  
    //verificar se arquivo existe
    if( arquivo == NULL ){
    	printf("\nerro ao abrir o arquivo 'matriz.txt'\n");
    	exit(1);
	}  

    //atribuir valores aleatórios a matriz        
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            matriz[i][j] = 10+(rand() % 90);
        }
	}	
	
    //atribuir matriz ao arquivo 
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
       		fprintf( arquivo,"%d\t", matriz[i][j]);
   		}
   		fprintf( arquivo,"\n");
    }
    
    //printagem de matriz
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            printf(" %d", matriz[i][j]);
        }
        printf("\n");
    }

    fclose(arquivo);

    return 0;
}