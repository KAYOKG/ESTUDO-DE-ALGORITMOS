#include <stdio.h>
#include <stdlib.h>

int main(){
    int N, fatorial = 1;

    printf("Informe um numero inteiro: ");
    scanf("%d",&N);

    for(int i=1; i <= N; i++){
        fatorial *= i;
        printf("\n Sequencia do fatorial %d", fatorial);
    }

    return 0;
}