#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define LINHA 2
#define COLUNA 3

int matriz();
int main(){
    int soma = matriz();

    printf("\nA soma de todos os valores pares da matriz é igual a %d", soma);

    return 0;
}
int matriz(){
    setlocale(LC_ALL, "Portuguese_Brazil");
    int matriz[LINHA][COLUNA], soma=0;

    for(int i=0; i<LINHA; i++){
        for(int j=0; j<COLUNA; j++){
            printf("Informe a posição [%d][%d] da matriz: ", i, j);
            scanf("%d", &matriz[i][j]);
            if(matriz[i][j] % 2==0){
                soma += matriz[i][j];
            }
        }
    }

    return soma;
}