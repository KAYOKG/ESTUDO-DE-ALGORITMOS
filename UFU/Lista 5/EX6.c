#include <stdio.h>
#include <stdlib.h>

int conversor(int segundos){
  int horas = segundos % 2;
  return horas;
}

int main(){
  int segundos;

  printf("Informe a quantidade de segundos para converter em horas: ");
  scanf("%d", &segundos);

  conversor(segundos);
  printf("convertida", conversor(segundos));
  return 0;
}