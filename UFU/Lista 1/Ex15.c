#include <stdio.h>
#include <stdlib.h>

#define MAX 6

int main(){
    int N[MAX], X[MAX] = {0}, J[MAX] = {0}, par=0, impar=0;

    for(int i = 0; i <6; i++){
        printf("Informe o numero do elemento %d: ", i+1);
        scanf("%d", &N[i]);

        if(N[i]%2 == 0){
            X[i] = N[i];
            par++;
        }else{
            J[i] = N[i];
            impar++;
        }
    }
    printf("Possuem %d numeros pares, sendo eles: ", par);
    for(int i = 0; i <6; i++){
        printf("%d, ", X[i]);
    }
    printf("\nPossuem %d numeros impares, sendo eles: ", impar);
    for(int i = 0; i <6; i++){
        printf("%d, ", J[i]);
    }
    return 0;
}