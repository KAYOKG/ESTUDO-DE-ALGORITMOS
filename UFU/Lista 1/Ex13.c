#include <stdio.h>
#include <stdlib.h>

#define vetor 5

int main(){
    int N[vetor], X[vetor], positivo=0;

    for(int i=0; i<vetor; i++){
        printf("Informe o numero da posicao %d: ", i+1);
        scanf("%d", &N[i]);

        if(N[i] > 0){
            X[i] = N[i];
            positivo++;
        }
    }
    printf(" Todos os numeros positivos do vetor: ");
    for(int i=0; i<positivo; i++){
        printf("%d ", X[i]);
    }

    return 0;
}