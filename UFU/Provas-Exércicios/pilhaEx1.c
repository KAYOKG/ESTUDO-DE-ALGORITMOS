#include <stdio.h>
#include <stdlib.h>

struct stack{
  int topo;
  int dados[10];
}pilha;

void empilha(int x){
  pilha.topo++;
  pilha.dados[pilha.topo] = x;
}

int desempilha(){
  if (pilha.topo == -1){
    printf("\nPilha vazia!\n");
    exit(1);
  }
  int valor = pilha.dados[pilha.topo];
  pilha.topo--;
  return valor;
}

int main(void){
  int x;
  pilha.topo = -1;
  empilha(4);
  empilha(2);
  empilha(7);
  x = desempilha(); printf("\n %d", x);
  x = desempilha(); printf("\n %d", x);
  x = desempilha(); printf("\n %d", x);
  x = desempilha(); printf("\n %d", x);

  return 0;
}