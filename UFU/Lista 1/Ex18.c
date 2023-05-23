#include <stdio.h>
#include <stdlib.h>

int main(){
    int vet1[10], vet2[10];

    for(int i=0; i<10; i++){
        printf("Informe o numero da posicao %d do vetor 1: ", i+1);
        scanf("%d", &vet1[i]);
    }
    printf("\n");
    for(int i=0; i<10; i++){
        printf("Informe o numero da posicao %d do vetor 2: ", i+1);
        scanf("%d", &vet2[i]);
    }

    printf("\nIntercalacao dos 2 vetores: ");
    for(int i=0; i<20; i++){
        printf("%d ", vet1[i]);
        printf("%d ", vet2[i]);
    }

    return 0;
}