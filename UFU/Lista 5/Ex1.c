#include <stdio.h>
#include <stdlib.h>

void ordenacao(int *MENOR, int *MEIO, int *MAIOR);
int main(){
  int x, y, z;
  printf("Informe 3 valores de entrada: \n");
  scanf("%d %d %d",&x , &y, &z);

  ordenacao(&x, &y, &z);

  printf("Ordenados: %d %d %d", x, y, z);

  return 0;
}

void ordenacao(int *MENOR, int *MEIO, int *MAIOR){
  int P;
  if(*MENOR >*MEIO){ //Se o valor de x for maior que y
    P = *MENOR;   // 1=  P RECEBE X
    *MENOR = *MEIO;  // 2=  X É ATRIBUIDO O VALOR DE Y
    *MEIO = P;   // 3=  Y ESTÁ VAZIO E POR ISSO PODE RECEBE P PARA TROCAR DE LUGAR COM O X
  }
  if(*MENOR > *MAIOR){ //Se o valor de x for maior que z
    P = *MENOR;
    *MENOR = *MAIOR;
    *MAIOR = P;
  }
  if(*MEIO > *MAIOR){ //Se o valor de y for maior que z
    P = *MEIO;
    *MEIO = *MAIOR;
    *MAIOR = P;
  }
}