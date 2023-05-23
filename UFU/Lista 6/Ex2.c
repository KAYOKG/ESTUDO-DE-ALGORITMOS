#include <stdio.h>
#include <string.h>
#define MAX 5

typedef struct{
  int topo;
  int dados[MAX]
}

int main(){
  int N, X[N];

  printf("Informe a quantidade de valores que deseja empilhar: ");
  scanf("%d", &N);

  for(int i = 0; i<N; i++){
    printf("\nInforme o valor %d de X: ", i+1);
    scanf("%d", &X[i]);

    if(X < 100){
      
      printf("\nO valor %d foi empilhado", X);
    }else if(X >= 100){
      printf("\nO valor %d foi desempilhado");
    }
  }

  return 0;
}