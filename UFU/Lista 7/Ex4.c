#include <stdio.h>
#include <stdlib.h>

#define quantidadeItens 4

typedef struct{
  int item[quantidadeItens];
  int inicio, fim;
} Fila;

void Inicia(Fila *F){
  F->inicio = F->fim = 0;
}

int Insere(Fila *F, int X){
  if (F->fim == quantidadeItens)
    return 0;
  else{
    F->item[F->fim++] = X;
    return 1;
  }
}

int Remove(Fila *F, int *X){
  if (F->inicio == F->fim)
    return 0;
  else{
    *X = F->item[F->inicio];
    F->inicio++;
    return 1;
  }
}

int main(){
  int i, X, soma = 0, contador = 0, valor = quantidadeItens;
  Fila F1;
  Inicia(&F1);

  printf("Digite %d valores:\n", valor);
  for (i = 0; i < valor; i++){
    scanf("%d", &X);
    Insere(&F1, X);
  }

  while (contador < 4){
    if (Remove(&F1, &X)){
            if (X > 0){
        soma += X;
        contador++;
      }
    }else{
      printf("Erro: Fila vazia!\n");
      break;
    }
  }


  printf("A soma dos 4 primeiros valores positivos da fila e: %d", soma);
  return 0;
}