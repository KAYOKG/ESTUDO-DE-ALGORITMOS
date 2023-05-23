#include <stdio.h>
#include <stdlib.h>

// Funcao para fazer a pontuacao final
void pontuacaoFinal(int *A,int *B,int *golsA, int *golsB){
  if(*golsA > *golsB){
    *A += 3;
  }else if(*golsA < *golsB){
    *B += 3;
  }else if(*golsA == *golsB){
    *A += 1;
    *B += 1;
  }
}

int main(){
  int A, B, golsA, golsB;

  // Le os pontos do time A
  printf("Digite os pontos do time A: ");
  scanf("%d", &A);
  // Le os pontos do time B
  printf("Digite os pontos do time B: ");
  scanf("%d", &B);

  // Le o numero de gols do time A
  printf("Informe o numero de gols do time A: ");
  scanf("%d", &golsA);
  // Le o numero de gols do time B
  printf("Informe o numero de gols do time B: ");
  scanf("%d", &golsB);

  // Chama a funcao para fazer a pontuacao final
  pontuacaoFinal(&A,&B,&golsA,&golsB);

  // Imprime a pontuacao final do time A
  printf("Pontuacao final do time A: %d", A);
  // Imprime a pontuacao final do time B
  printf("\nPontuacao final do time B: %d", B);

  return 0;
}