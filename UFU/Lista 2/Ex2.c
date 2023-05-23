#include <stdio.h>
#include <stdlib.h>

int main(){

    int custo_consumidor = custo_carro();
    printf("Custo final para o consumidor de R$%d", custo_consumidor);

    return 0;
}
int custo_carro(){
    int custo_fabrica, custo_consumidor; 

    printf("Insira o custo de fabrica do carro \n R$");
    scanf("%d", &custo_fabrica);

    custo_consumidor = custo_fabrica + (custo_fabrica*0.28 + custo_fabrica*0.45);

    return custo_consumidor;    
}