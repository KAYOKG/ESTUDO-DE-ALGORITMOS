#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define quantidade 5
#define valoresFila 5

typedef struct{
  int item[valoresFila];
  int inicio, fim;
} Fila;

void inicia(Fila *f){
  f->inicio = f->fim = 0;
}

int inserir(Fila *f, int X){
  if(f->fim == valoresFila){
    printf("Fila cheia!\n");
    return 0;
  }else {
    f->item[f->fim] = X;
    f->fim++;
    return 1;
  }
}

int remover(Fila *f, int *X){
  if(f->inicio == f->fim){
    printf("Fila vazia!\n");
    return 0;
  }else{
    *X = f->item[f->inicio];
    f->inicio++;
    return 1;
  }
}

void mostrar(Fila *f){
  int i;
  printf("Fila: ");
  for(i = f->inicio; i < f->fim; i++){
    printf("%d ", f->item[i]);
  }
  printf("\n");
}

int main(){
  setlocale(LC_ALL, "Portuguese_Brazil");
  Fila f;
  int i=0, N, X, retornoInserir, retornoRemover;
  inicia(&f);

  printf("Informe quantos valores serão lidos: ");
  scanf("%d", &N);

  while(i < N){
    printf("Informe o valor %d: ", i+1);
    scanf("%d", &X);

    if(X < 100){
      retornoInserir = inserir(&f, X);
      if(retornoInserir == 0){
        printf("Não foi possível inserir o valor %d na fila!\n", X);
      }
    }else{
      retornoRemover = remover(&f, &X);
      if(retornoRemover == 0){
        printf("Não foi possível remover o valor %d da fila!\n", X);
      }
    }
    mostrar(&f);
  i++;
  }

  return 0;
}