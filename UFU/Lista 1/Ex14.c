#include <stdio.h>
#include <stdlib.h>

int main(){
    int N[10], soma=0, negativos=0;

    for(int i = 0; i <10;i++){
        printf("Informe um numero inteiro para a posicao %d: ",i+1);
        scanf("%d",&N[i]);

        if(N[i]>0){
            soma += N[i];
        }else negativos++;
    }

    printf("\n");
    printf("Possuem %d numeros negativos", negativos);
    printf("\nA soma dos numeros positivos: %d", soma);

    return 0;
}