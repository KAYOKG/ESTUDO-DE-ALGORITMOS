#include <stdio.h>
#include <stdlib.h>

int main(){
    int qtd, custo_total;

    printf("Qual a quantidade de frangos para a producao\n");
    scanf("%d", &qtd);

    custo_total = qtd * 11;

    printf("O custo de anel no pe de cada frango na producao sera de R$ 11,00\ne o custo total para todos os frangos sera de R$ %d", custo_total);

    return 0;
}