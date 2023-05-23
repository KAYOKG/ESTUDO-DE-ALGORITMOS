#include <stdio.h>
#include <stdlib.h>

int main(){
    int vet[10];

    for(int i=0; i<10; i++){
        printf("Informe a posicao %d do vetor: ", i+1);
        scanf("%d", &vet[i]);

        for(int j=0; j<i; j++){
            if(vet[i] == j){
                printf("\nValor ja inserido\n");
                i--;
                break;
            }
        }
    }

    return 0;
}