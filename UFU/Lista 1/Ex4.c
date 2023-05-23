#include <stdio.h>
#include <stdlib.h>

int main(){
    float reais,gasosa, combustivel;

    printf("Quantos reais de gasolina deseja abastecer?\nR$ ");
    scanf("%f", &reais);
    printf("Qual o preco do combustivel?\nR$ ");
    scanf("%f", &combustivel);

    gasosa = reais/combustivel;

    printf("Foi abastecido %.2f litros de gasolina", gasosa);

    return 0;
}