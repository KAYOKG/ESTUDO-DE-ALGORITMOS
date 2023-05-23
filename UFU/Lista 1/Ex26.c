#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(){
    int entrada, dd[99], mm[99], yyyy[99], hora[99], min[99], cont=0;
    char texto[99];

    for(int i=0; i<99;i++){
        printf("\nDigite 1 ou 0 ->>>>>> 1 - Registrar compromisso | 0 - Vizualizar compromissos\n");
        scanf("%d", &entrada);
        if(entrada == 0){
            break;
        }

        printf("\nCompromisso %d: ", i+1);
        scanf("%c", &texto[i]);
        printf("\nData dd/mm/yyyy: ");
        scanf("%d/%d/%d", &dd[i], &mm[i], &yyyy[i]);
        printf("\nHora: ");
        scanf("%d:%d", &hora[i], &min[i]);
        cont++;
    }

    for(int i=0; i<cont; i++){
        printf("\nCompromisso %d: ", i+1);
        printf("%s", texto[i]);
        printf("\nData: %d/%d/%d", dd[i], mm[i], yyyy[i]);
        printf("\nHora: %d:%d", hora[i], min[i]);
    }
    return 0;
}