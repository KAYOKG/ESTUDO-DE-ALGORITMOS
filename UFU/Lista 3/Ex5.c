#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

char* verificacao(int num);
int main(){
    setlocale(LC_ALL, "Portuguese_Brazil");
    int num;

    printf("Informe um numero: ");
    scanf("%d", &num);

    while(num <= 1){
        printf("Informe um numero maior que 1: ");
        scanf("%d", &num);
    }

    char* resposta = verificacao(num);

    printf("%s", resposta);

    return 0;
}

char* verificacao(int num){
    char* resposta;

    for(int i=2; i<num; i++){
        if(num%i == 0){
            resposta = "Não é primo";
            break;
        }else resposta = "É primo";
    }
    return resposta;
}