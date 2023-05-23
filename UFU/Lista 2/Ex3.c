#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int soma_valores(vet);

int main(){
    setlocale(LC_ALL, "Portuguese_Brazil");
    int vet[8];

    for(int i = 0; i < 8; i++){
        printf("Informe o valor da posição %d do vetor: ", i+1);
        scanf("%d", &vet[i]);
    }
    int soma = soma_vetores(vet);
    printf("A soma dos valores do vetor é igual a %d", soma);

    return 0;
}
int soma_vetores(int vet[8]){
    int soma=0;

    for(int i; i<8; i++){
        soma += vet[i];
    }
    return soma;
}