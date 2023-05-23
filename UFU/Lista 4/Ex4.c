#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

//função que calcula a situação do aluno
char situacao(float p1, float p2, float p3, int faltas, int aulas, float *media){
  *media = (p1 + p2 + p3) / 3; //calcula a média do aluno

  if(*media >= 6 && faltas <= (aulas * 0.25)){ //se a média for maior ou igual a 6 e o número de faltas for menor ou igual a 25% do número de aulas, o aluno está aprovado
    return 'A';
  }else if(*media < 6 && faltas <= (aulas * 0.25)){ //se a média for menor que 6 e o número de faltas for menor ou igual a 25% do número de aulas, o aluno está reprovado
    return 'R';
  }else{ //se o número de faltas for maior que 25% do número de aulas, o aluno está reprovado por falta
    return 'F';
  }
}

int main(){
  setlocale(LC_ALL, "Portuguese_Brazil");
  float p1, p2, p3, media;
  int faltas, aulas;

  printf("Digite a nota da prova 1: ");
  scanf("%f", &p1);
  printf("Digite a nota da prova 2: ");
  scanf("%f", &p2);
  printf("Digite a nota da prova 3: ");
  scanf("%f", &p3);
  printf("Digite a quantidade de faltas: ");
  scanf("%d", &faltas);
  printf("Digite a quantidade de aulas: ");
  scanf("%d", &aulas);

  //chama a função e armazena o resultado em uma variável
  char resultado = situacao(p1, p2, p3, faltas, aulas, &media);

  if(resultado == 'A'){ //se o aluno está aprovado
    printf("A média do aluno é: %.1f e está ->APROVADO<-", media);
  }else if(resultado == 'R'){ //se o aluno está reprovado
    printf("A média do aluno é: %.1f e está ->REPROVADO<-", media);
  }else printf("O aluno está ->REPROVADO POR FALTA<-"); //se o aluno está reprovado por falta

  return 0;
}