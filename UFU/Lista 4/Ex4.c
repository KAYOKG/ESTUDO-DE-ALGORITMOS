#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

//fun��o que calcula a situa��o do aluno
char situacao(float p1, float p2, float p3, int faltas, int aulas, float *media){
  *media = (p1 + p2 + p3) / 3; //calcula a m�dia do aluno

  if(*media >= 6 && faltas <= (aulas * 0.25)){ //se a m�dia for maior ou igual a 6 e o n�mero de faltas for menor ou igual a 25% do n�mero de aulas, o aluno est� aprovado
    return 'A';
  }else if(*media < 6 && faltas <= (aulas * 0.25)){ //se a m�dia for menor que 6 e o n�mero de faltas for menor ou igual a 25% do n�mero de aulas, o aluno est� reprovado
    return 'R';
  }else{ //se o n�mero de faltas for maior que 25% do n�mero de aulas, o aluno est� reprovado por falta
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

  //chama a fun��o e armazena o resultado em uma vari�vel
  char resultado = situacao(p1, p2, p3, faltas, aulas, &media);

  if(resultado == 'A'){ //se o aluno est� aprovado
    printf("A m�dia do aluno �: %.1f e est� ->APROVADO<-", media);
  }else if(resultado == 'R'){ //se o aluno est� reprovado
    printf("A m�dia do aluno �: %.1f e est� ->REPROVADO<-", media);
  }else printf("O aluno est� ->REPROVADO POR FALTA<-"); //se o aluno est� reprovado por falta

  return 0;
}