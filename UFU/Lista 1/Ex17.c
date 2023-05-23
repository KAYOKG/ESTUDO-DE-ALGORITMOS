#include <stdio.h>
#include <stdlib.h>

int main(){
    int vet[8], vet1[8] = {0}, vet2[8] = {0}, j = 0, k = 0;

    for(int i=0; i<8; i++){
        printf("Informe o numero da posicao %d do vetor: ",i+1);
        scanf("%d",&vet[i]);

        if(vet[i] >= 0){
            vet1[i] = vet[i];
            j++;
        }else{
            vet2[i] = vet[i];
            k++;
        }
    }
    printf("\nOs numeros positivos sao: ");
    for(int i=0; i<j;i++){
        printf("%d ",vet1[i]);
    }
    printf("\nOs numeros negativos sao: ");
    for(int i=0; i<k;i++){
        printf("%d ",vet2[i]);
    }



    return 0;
}