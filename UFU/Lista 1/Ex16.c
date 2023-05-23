#include <stdio.h>
#include <stdlib.h>

int main(){
    int vet1[10], vet2[10], vet3[10];

    for(int i=0; i<10; i++){
        printf("Informe o numero para a posicao %d do vetor 1: ", i+1);
        scanf("%d", &vet1[i]);
    }
    printf("\n");
    for(int i=0; i<10; i++){
        printf("Informe o numero para a posicao %d do vetor 2: ", i+1);
        scanf("%d", &vet2[i]);
    }
    printf("\n");
    printf("\nA soma dos 2 vetores: ");
    for(int i=0; i<10; i++){
        vet3[i] = vet1[i] + vet2[i];
        printf("%d ",vet3[i]);
    }

    return 0;
}