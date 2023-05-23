#include <stdio.h>
#include <stdlib.h>

int main(){
    float lab, sem, fin, media_ponderada;
    char conceito;

    printf("Informe a nota do trabalho de laboratorio do aluno\n");
    scanf("%f", &lab);
    printf("Informe a nota da avaliacao semestral do aluno\n");
    scanf("%f", &sem);
    printf("Informe a nota do exame final do aluno\n");
    scanf("%f", &fin);

    media_ponderada = (lab*2 + sem*3 + fin*5)/10; 

    if (media_ponderada >= 8.01 && media_ponderada <= 10.00)
    {
        conceito = 'A';
    }else if(media_ponderada >= 7.01 && media_ponderada <=8.0){
        conceito = 'B';
    }else if(media_ponderada >=6.01 && media_ponderada <=7.0){
        conceito = 'C';
    }else if(media_ponderada >=5.01 && media_ponderada <=6.0){
        conceito = 'D';
    }else if(media_ponderada >=0 && media_ponderada <=5.0){
        conceito = 'E';
    }    

    printf("A media ponderada das 3 notas foi %.2f e a colocacao do conceito foi de %c", media_ponderada, conceito);

    return 0;
}