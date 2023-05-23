#include <stdio.h>
#include <stdlib.h>

float media(float lab, float sem, float fin);

int main(){
    float lab, sem, fin;
    char conceito;

    printf("\nInforme a nota do trabalho de laboratorio do aluno: ");
    scanf("%f", &lab);
    printf("\nInforme a nota da avaliacao semestral do aluno: ");
    scanf("%f", &sem);
    printf("\nInforme a nota do exame final do aluno: ");
    scanf("%f", &fin);

    float media_ponderada = media(lab, sem, fin);

    if (media_ponderada >= 8.01 && media_ponderada <= 10.00)
    {
        conceito = 'A';
    }else if(media_ponderada >= 7.01){
        conceito = 'B';
    }else if(media_ponderada >=6.01){
        conceito = 'C';
    }else if(media_ponderada >=5.01 ){
        conceito = 'D';
    }else if(media_ponderada >=0 ){
        conceito = 'E';
    }    

    printf("A media ponderada das 3 notas foi %.2f e a colocacao do conceito foi de %c", media_ponderada, conceito);

    return 0;
}
float media(float lab, float sem, float fin){
    
    float media_ponderada = (lab*2 + sem*3 + fin*5)/10; 

    return media_ponderada;
}
