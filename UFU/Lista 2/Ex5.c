#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define MAX 3

typedef struct{
    int idade;
    char nome[20], sexo;
}Pessoa;

int pessoa();

int main(){
    setlocale(LC_ALL, "Portuguese_Brazil");

    int idade_maior = pessoa();
    printf("\nSão %d pessoas que possuem a idade maior que 15", idade_maior);

    return 0;
}
int pessoa(){
    setlocale(LC_ALL, "Portuguese_Brazil");
    int homens=0, idade_maior=0;

    Pessoa p[MAX];

    for(int i=0; i<MAX; i++){
        printf("\nInforme o nome: ");
        scanf(" %s", &p[i].nome);
        printf("Informe o sexo(M | F): ");
        scanf(" %c", &p[i].sexo);
        printf("Informe a idade: ");
        scanf("%d", &p[i].idade);

        if(p[i].sexo == 'M'){
            homens++;
        }
        if(p[i].idade > 15){
            idade_maior++;
        }
    }
    printf("A contagem foi de %d homens", homens);

    return idade_maior;

}