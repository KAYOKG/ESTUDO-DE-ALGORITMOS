#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void calculoRaiz(int a, int b, int c, int *x1, int *x2){ // Cria a função calculoRaiz que recebe os valores de A, B e C e os ponteiros de X1 e X2.
  *x1 = (-b + sqrt((b * b) - (4 * a * c))) / (2 * a); // Calcula o valor de X1.
  *x2 = (-b - sqrt((b * b) - (4 * a * c))) / (2 * a); // Calcula o valor de X2.
}

void decrementa_incrementa(int *a, int *b){ // Cria a função decrementa_incrementa que recebe os valores de A e B.
  (*a)--; // Decrementa o valor de A.
  (*b)++; // Incrementa o valor de B.
}

void troca(int *a, int *b){ // Cria a função troca que recebe os valores de A e B.
  int aux = *a; // Cria uma variável auxiliar que recebe o valor de A.
  *a = *b; // A recebe o valor de B.
  *b = aux; // B recebe o valor de A.
}

int main(){
  int a, b, c, x1, x2; // Declara as variáveis A, B, C, X1 e X2.

  printf("Digite o valor de A: "); // Solicita um valor para A.
  scanf("%d", &a); // Recebe o valor de A.
  printf("Digite o valor de B: "); // Solicita um valor para B.
  scanf("%d", &b); // Recebe o valor de B.
  printf("Digite o valor de C: "); // Solicita um valor para C.
  scanf("%d", &c); // Recebe o valor de C.

  troca(&a, &b); // Troca o valor de A e B.
  printf("Valores trocados de A e B: %d %d\n", a, b); // Imprime na tela o valor de A e B trocados.
  decrementa_incrementa(&a, &b); // Decrementa e incrementa o valor de A e B.
  printf("Valores decrementados e incrementados de A e B: %d %d\n", a, b); // Imprime na tela o valor de A e B decrementados e incrementados.
  calculoRaiz(a, b, c, &x1, &x2); // Calcula os valores de X1 e X2.
  printf("Valores de X1 e X2: %d %d\n", x1, x2); // Imprime na tela os valores de X1 e X2.

  return 0;
}