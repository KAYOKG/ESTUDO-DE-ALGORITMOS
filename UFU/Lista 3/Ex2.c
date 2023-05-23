#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int numMaior(int x, int y){
    int z;
    if(x > y){
        return z = x;
    }
    else return z = y;
}

int main(){
    setlocale(LC_ALL, "Portuguese_Brazil");
    int x, y;

    printf("Informe o primeiro numero: ");
    scanf("%d", &x);
    printf("\nInforme o segundo numero: ");
    scanf("%d", &y);

    int z = numMaior(x, y);

    printf("\nO maior numero é: %d", z);

    return 0;
}