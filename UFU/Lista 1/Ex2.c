#include <stdio.h>
#include <stdlib.h>

int main(){
    int dias_totais,dias_restantes,dd,mm,aa;

    printf("De uma quantidade de dias para transformar em uma data dd/mm/aa \n");
    scanf("%d",&dias_totais);

    aa = dias_totais/360;
    dias_restantes = dias_totais%360;
    mm = dias_restantes/30;
    dd = dias_restantes - (mm * 30);

    printf("%d Convertido para dd/mm/aa -> %d dias, %d meses e %d anos", dias_totais, dd,mm,aa);

    return 0;
}