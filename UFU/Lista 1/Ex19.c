#include <stdio.h>
#include <stdlib.h>

int main(){
    int vet1[10], j;

    for(int i=0; i<10; i++){
        printf("Informe o valor %d do vetor: ", i+1);
        scanf("%d", &vet1[i]);
        j = vet1[i];
    }
    printf("\nVetor invertido: ");
    for(int i=j; i>=0; i--){
        printf("%d ", vet1[i]);
    }

    return 0;
}