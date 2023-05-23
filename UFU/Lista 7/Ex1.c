#include <stdio.h>
#define quantidadeItens 4


typedef struct {
  int valor;
} Elemento;


typedef struct {
  Elemento itens[quantidadeItens];
  int inicio, fim;
} Fila;


void inicializarFila(Fila *f) {
  f->inicio = 0;
  f->fim = -1;
}


int filaVazia(Fila *f) {
  return (f->inicio > f->fim);
}


int filaCheia(Fila *f) {
  return (f->fim == quantidadeItens - 1);
}


int inserir(Fila *f, Elemento item) {
  if (filaCheia(&f)) {
    return 0;
  }
  f->fim++;
  f->itens[f->fim] = item;
  return 1;
}


int remover(Fila *f, Elemento *item) {
  if (filaVazia(&f)) {
    return 0;
  }
  *item = f->itens[f->inicio];
  f->inicio++;
  return 1;
}


int main() {
  Fila f1, f2, f3;
  Elemento elemento;
  int i;
  inicializarFila(&f1);
  inicializarFila(&f2);
  inicializarFila(&f3);


  for (i = 0; i < quantidadeItens; i++) {
    printf("Digite o valor %d: ", i+1);
    scanf("%d", &elemento.valor);
    inserir(&f1, elemento);
  }

  // separan elementos da fila1
  while (!filaVazia(&f1)) {
    remover(&f1, &elemento);
    if (elemento.valor < 100) {
      inserir(&f2, elemento);
    }
    else {
      inserir(&f3, elemento);
    }
  }

  // exibe conteudo da fila 2
  printf("\nConteúdo da fila2:\n");
  while (!filaVazia(&f2)) {
    remover(&f2, &elemento);
    printf("%d", elemento.valor);
  }
  // exibe conteudo da fila 2
  printf("\nConteúdo da fila3:\n");
  while (!filaVazia(&f3)) {
    remover(&f3, &elemento);
    printf("%d", elemento.valor);
  }
  return 0;
}