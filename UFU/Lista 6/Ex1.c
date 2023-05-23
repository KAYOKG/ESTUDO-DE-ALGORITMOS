#include <stdio.h>
#include <stdlib.h>
#define MAX 20

// Definição da estrutura de pilha
typedef struct{
  int topo;
  int dados[MAX];
} pilha;

// empilhar a pilha
void empilhar(pilha *p, int valor) {
  if (p->topo == MAX - 1) {
    printf("Pilha cheia!\n");
    return;
  }
  p->topo++;
  p->dados[p->topo] = valor;
}

// desempilhar a pilha
int desempilhar(pilha *p) {
  if (p->topo == -1) { // se o topo for -1, a pilha está vazia
    printf("Pilha vazia!\n");
    return -1;
  }
  int valor = p->dados[p->topo]; // pega o valor do topo
  p->topo--; // diminui o topo
  return valor; // retorna o valor
}

int main() {
  pilha pilha1, pilha2, pilha3;
  // inicia as pilhas com topo -1 para indicar que está vazia
  pilha1.topo = -1;
  pilha2.topo = -1;
  pilha3.topo = -1;

  int valor;

  // vai ler os valores e empilhar usando o for
  printf("Digite 20 valores para empilhar na PILHA1:\n");
  for (int i = 0; i < MAX; i++) {
    scanf("%d", &valor);
    empilhar(&pilha1, valor);
  }

  // tirando as coisas da pilha 1 e colocando na 2 e 3
  while (pilha1.topo != -1) {
    valor = desempilhar(&pilha1);
    if (valor < 100) {
      empilhar(&pilha2, valor);
    } else {
      empilhar(&pilha3, valor);
    }
  }

  // pilha 2
  printf("Elementos da PILHA2 (valores < 100):\n");
  while (pilha2.topo != -1) {
    valor = desempilhar(&pilha2);
    printf("%d\n", valor);
  }

  // pilha 3
  printf("Elementos da PILHA3 (valores >= 100):\n");
  while (pilha3.topo != -1) {
    valor = desempilhar(&pilha3);
    printf("%d\n", valor);
  }

  return 0;
}
