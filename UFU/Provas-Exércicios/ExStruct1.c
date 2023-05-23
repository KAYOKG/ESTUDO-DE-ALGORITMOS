#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef struct{
    int salario, dd[MAX], mm[MAX], aa[MAX], num[MAX];
    char nome[MAX], rua[15], bairro[15];
}pessoa;

int main(){
    int soma_salario=0, j, pessoa_rica[MAX], pessoa_pobre=0;
    float media_salario;

    pessoa Pessoa[MAX];
    for(int i=0; i<MAX; i++){
        printf("Nome da pessoa %d: ", i+1);
        scanf(" %s", &Pessoa[i].nome);
        printf("Rua: ");
        scanf(" %s", &Pessoa[i].rua);
        printf("Numero: ");
        scanf(" %d", &Pessoa[i].num);
        printf("Bairro: ");
        scanf(" %s", &Pessoa[i].bairro);
        printf("Dia: ");
        scanf("%d", &Pessoa[i].dd);
        printf("Mes: ");
        scanf("%d", &Pessoa[i].mm);
        printf("Ano: ");
        scanf("%d", &Pessoa[i].aa);
        printf("Salario: ");
        scanf("%d", &Pessoa[i].salario);

        soma_salario += Pessoa[i].salario;
        media_salario = (float) soma_salario/MAX;
        if(Pessoa[i].salario > 2000){
            pessoa_rica[j] = Pessoa[i].salario;
            j++;
        }else if(Pessoa[i].salario < 1000){
            pessoa_pobre++;
        }
    }
    printf("\nA media dos salario: %.2f", media_salario);
    printf("\nAs Pessoas que possuem o salario maior que R$ 2.000,00 ");
    for(int i=0; i<j; i++){
        printf(" %c ", pessoa_rica[i]);
    }
    printf("\n%d pessoas tem o salario abaixo de R$ 1.000,00", pessoa_pobre);

    return 0;
}

