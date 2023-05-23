#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define Linha 3
#define Coluna 3

int main(){
    setlocale(LC_ALL, "Portuguese_Brazil");
    int matriz[Linha][Coluna], soma[Linha];

    for (int i=0; i< Linha; i++){
        for(int j=0; j< Coluna; j++){
            printf("Digite o elemento [%d][%d] da matriz: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
        printf("\n");
    }

    printf("Soma: ");
    for(int i=0; i< Linha; i++){
        soma[i] = 0;
        for(int j=0; j< Coluna; j++){
            soma[i] += matriz[i][j];
        }
        printf("%d ", soma[i]);
    }

    printf("\nA Matriz resultante é: ");
    for(int i=0; i< Linha; i++){
        for(int j=0; j< Coluna; j++){
            matriz[i][j] *= soma[i];
            printf("%d ", matriz[i][j]);
        }
    }

    return 0;
}