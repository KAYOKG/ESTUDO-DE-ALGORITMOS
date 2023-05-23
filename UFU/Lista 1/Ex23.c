#include <stdio.h>
#include <stdlib.h>
#define linha 6
#define coluna 4

int main(){
    int matriz[6][4], cont=0;

    for(int i=0; i<linha;i++){
        for(int j=0; j<coluna; j++){
            printf("\nInforme o elemento [%d][%d] da matriz: ", i+1, j+1);
            scanf("%d", &matriz[i][j]);
            if(matriz[i][j] > 30){
                cont++;
            }
        }
    }
    printf("\n======================================================\n");
    for(int i=0; i<linha;i++){
        for(int j=0; j<coluna; j++){
            printf("\nInforme o elemento [%d][%d] da matriz: ", i+1, j+1);
            scanf("%d", &matriz[i][j]);
            if(matriz[i][j] == 30){
                matriz[i][j] = 0;
            }
        }
    }
    for(int i=0; i<linha;i++){
        for(int j=0; j<coluna; j++){
            printf("\nO elemento [%d][%d] da matriz: %d", i+1, j+1, matriz[i][j]);
        }
    }
    printf("\n\nSendo o numero de elementos da priemria matriz que foram maior que 30 = %d", cont);

    return 0;
}
