#include <stdio.h>
#include <stdlib.h>
#define MAX 5

typedef struct{
    char* nome, endereco;
    int tel;
}Pessoa;

int main(){
    Pessoa p[MAX];

    for(int i = 0; i < MAX; i++){
        printf("\nInforme o nome da pessoa %d: ", i+1);
        scanf("%s", &p[i].nome);

        printf("\nInforme o telefone da pessoa %d: ", i+1);
        scnaf("%d", &p[i].tel);

        printf("\nInforme o endereco da pessoa %d: ", i+1);
        scanf("%s", &p[i].endereco);
    }

    printf("\nDados em ordem alfabetica\n");
    for(int i = 0; i < MAX; i++){
        printf("\nNome %s", p[i].nome);
        printf("\nTelefone %d", p[i].tel);
        printf("\nEndereco %s", &p[i].endereco);
    }
}