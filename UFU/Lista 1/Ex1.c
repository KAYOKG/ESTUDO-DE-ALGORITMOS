#include <stdio.h>
#include <stdlib.h>

int main(){
    int dd, mm, aa;
    printf("Insira o dia, mes e o ano \n");
    scanf("%d", &dd);
    scanf("%d", &mm);
    scanf("%d", &aa);

    int resultado = aa*360 + mm*30 + dd;
    printf("Os anos, meses e dias transformados em dias sao = %d", resultado);

    return 0;
}