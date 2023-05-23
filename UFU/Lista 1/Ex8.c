#include <stdio.h>
#include <stdlib.h>

int main(){
    int cod, cod_pais;
    float peso, imposto = 0, valor_total=0, preco_produto, grama;

    printf("Informe o codigo do produto: ");
    scanf("%d", &cod);
    while(cod < 1 || cod > 10){
        printf("Codigo invalido, insira de 1 a 10: ");
        scanf("%d", &cod);
    }
    printf("\nInforme o peso do produto em quilos: ");
    scanf("%f", &peso);

    printf("\nInforme o codigo pais de origem: ");
    scanf("%d", &cod_pais);
    while(cod_pais < 1 || cod_pais > 3){
        printf("\nCodigo invalido, insira de 1 a 3: ");
        scanf("%d", &cod_pais);
    }

    switch(cod){
        case 1:
        case 2:
        case 3:
        case 4:
            grama = 10*(peso * 1000);
            preco_produto = grama * 10;
            break;
        case 5:
        case 6:
        case 7:
            grama = 25*(peso * 1000);
            preco_produto = grama * 25;
            break;
        case 8:
        case 9: 
        case 10:
            grama = 35*(peso * 1000);
            preco_produto = grama * 35;
            break;
    }

    switch(cod_pais){
        case 1:
            imposto = preco_produto * 0;
            valor_total += imposto;
            break;
        case 2:
            imposto = preco_produto * 0.15;
            valor_total += imposto;
            break;
        case 3:
            imposto = preco_produto * 0.25;
            valor_total += imposto;
            break;
    }

    printf("\nO produto %d possui %.2f gramas e sendo cobrado R$%.2f de imposto\nEsse produto possui o valor total de R$%.2f", cod, grama, imposto, valor_total);

    return 0;
}