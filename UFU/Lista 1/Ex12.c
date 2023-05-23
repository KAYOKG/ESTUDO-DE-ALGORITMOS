#include <stdio.h>
#include <stdlib.h>

int main(){
    int idade, casada=0, pessoas=0, soma_idade=0, viuvas=0, largada=0, solteira=0;
    char civil;
    float media, porcentagem_largadas;

    
    while(idade > 0){
        printf("\nInforme a sua idade: ");
        scanf("%d",&idade);

        if(idade == 0) break;
        
        printf("Informe o seu estado civil(C - casado(a), S - solteiro(a), V - viuvo(a) e D - desquitado(a)): ");
        
        do{
            scanf(" %c", &civil);
        }while(civil != 'C' && civil != 'S' && civil != 'V' && civil != 'D' && civil != '0');

        if(civil == '0')break;

        switch(civil){
            case 'C':
                casada++;
                pessoas++;
                continue;
            case 'S':
                solteira++;
                pessoas++;
                continue;
            case 'V':
                soma_idade += idade;
                pessoas++;
                viuvas++;
                continue;
            case 'D':
                largada++;
                continue;
        }

        media = (float) soma_idade/viuvas;
        porcentagem_largadas= (float) largada/pessoas *100;

    }
        printf("\nPossui %d pessoas casadas", casada);
        printf("\nPossui %d pessoas solteiras", solteira);
        printf("\nPossui uma media de %.2f anos de idade as pessoas viuvas", media);
        printf("\nPossui uma porcentagem de %.2f pessoas largadas", porcentagem_largadas);

    return 0;
}