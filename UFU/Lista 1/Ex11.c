#include <stdio.h>
#include <stdlib.h>

int main(){
    int N, valor[99], valor_L=0, valor_A=0, valor_H=0, valor_total=0;
    char cod;

    printf("Quantas mercadorias foram vendidas: ");
    scanf("%d", &N);

    for(int i = 0; i < N; i++){

        
        printf("\nDigite o Codigo(L, A ou H) da mercadoria %d ou (0) para encerrar: ", i+1);
        do{
            scanf(" %c", &cod);
        } while(cod != 'L' && cod != 'A' && cod != 'H' && cod != '0');

        if(cod == '0'){
            i = N;
            break;
        }
        
        switch(cod){
        case 'L':
            printf("valor: ");
            scanf(" %d", &valor[i]);
            valor_L += valor[i];
            valor_total += valor[i];
            break;
        case 'A':
            printf("valor: ");
            scanf(" %d", &valor[i]);
            valor_A += valor[i];
            valor_total += valor[i];
            break;
        case 'H':
            printf("valor: ");
            scanf(" %d", &valor[i]);
            valor_H += valor[i];
            valor_total += valor[i];
            break;
        // default: 
        //     cod = '0';
        //     break;
        }
        
        
    }
    printf("\nTotal vendido foi de %d", valor_total);
    printf("\nTotal vendido em Limpeza foi de %d", valor_L);
    printf("\nTotal vendido em Alimentacao foi de %d", valor_A);
    printf("\nTotal vendido em Higiene foi de %d", valor_H);

    return 0;
}