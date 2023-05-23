#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

float calculoInvest(char tipo, float valor);
int main(){
    float valor;
    char tipo;
    setlocale(LC_ALL, "Portuguese_Brazil");

    printf("Informe o valor do investimento: ");
    scanf("%f", &valor);
    printf("\nInforme o tipo de investimento: (1 - Poupança 2 - Fundos de renda fixa)\n");
    scanf(" %c", &tipo);
    
    float valorTotal = calculoInvest(tipo, valor);

    printf("\nO valor mensal do investimento será de R$%.2f", valorTotal);

    return 0;
}

float calculoInvest(char tipo, float valor){
    switch (tipo){
    case '1':
        valor =  valor * 0.03;
        break;
    case '2':
        valor = valor * 0.04;
        break;
    }
    return valor;
}