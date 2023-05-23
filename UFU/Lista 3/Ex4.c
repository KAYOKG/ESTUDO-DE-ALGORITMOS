#include <stdio.h>
#include <stdlib.h>

char* validacao(int senha);
int main(){
    int senha;

    printf("Informe a senha do usuario 4531: ");
    scanf("%d", &senha);

    char* resposta = validacao(senha);

    printf("\n%s", resposta);

    return 0;
}

char* validacao(int senha){
    char* resposta;
    if(senha == 4531){
        resposta = "senha validada";
    }else resposta = "senha invalida";

    return resposta;
}