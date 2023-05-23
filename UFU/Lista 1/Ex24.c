#include <stdio.h>
#include <stdlib.h>
#define Linha 3
#define Coluna 4

int main(){
    int matriz[Linha][Coluna], repete[Linha*Coluna], contador=0;

    for(int i=0; i<Linha; i++){
        for(int j=0; j<Coluna; j++){
            printf("Informe o elemento [%d][%d]: ", i, j);
            scanf("%d",&matriz[i][j]);
        }
    }
    printf("\n");
    for(int i=0; i<Linha; i++){
        for(int j=0; j<Coluna; j++){
            contador=0;

            for(int k = j+1; k<Coluna; k++){
                if(matriz[i][j] == matriz[i][k]){
                    printf("O elemento %d se repete\n", matriz[i][j]);
                    repete[contador++] = matriz[i][j];
                }
            }
            if(contador>0) printf("O elemento %d se repete %d vezes\n", matriz[i][j], contador);
        }
    }

    return 0;
}