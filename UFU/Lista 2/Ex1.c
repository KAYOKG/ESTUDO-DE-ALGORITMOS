#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL, "Portuguese_Brazil");
    
    int dias_total = converte_idade();

    printf("\nConvertido em dias é: %d", dias_total);

    return 0;
}
int converte_idade(){
    int dd,mm,aa;

    printf("Insira a idade (dd/mm/aa): ");
    scanf("%d %d %d", &dd, &mm, &aa);

    int dias_total = dd + mm*30 + aa*360;

    return dias_total;
}