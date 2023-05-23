#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define quantidadeItens 5

struct Fila
{
  int item[quantidadeItens];
  int inicio, fim;
};

void Inicia(struct Fila *F)
{
  (*F).inicio = (*F).fim = 0;
}

int Insere(struct Fila *F, int X)
{
  if (EstaCheia(*F))
    return 0;
  else
  {
    (*F).item[(*F).fim] = X;
    (*F).fim++;
    return 1;
  }
}

int RemoveComTroca(struct Fila *F, int *X)
{
  if (EstaVazia(*F))
    return 0;
  else
  {
    *X = (*F).item[(*F).inicio];
    (*F).inicio++;
    return 1;
  }
}

int Remove(struct Fila *F, int *X)
{
  if (EstaVazia(*F))
    return 0;
  else
  {
    *X = (*F).item[(*F).inicio];
    for (int i = (*F).inicio; i < quantidadeItens - 1; i++)
      (*F).item[i] = (*F).item[i + 1];
    (*F).fim--;
    return 1;
  }
}

int EstaVazia(struct Fila F)
{
  return (F.inicio == F.fim);
}

int EstaCheia(struct Fila F)
{
  return (F.fim == quantidadeItens);
}

int VerificaElemento(struct Fila F, int *X)
{
  if (EstaVazia(F))
    return 0;
  else
  {
    *X = F.item[F.inicio];
    return 1;
  }
}

void MostraFila(struct Fila F)
{
  int i;
  if (EstaVazia(F))
    printf("Fila Vazia!\n");
  else
  {
    printf("Elementos da fila: ");
    for (i = F.inicio; i < F.fim; i++)
      printf("%d ", F.item[i]);
    printf("\n");
  }
}

int main()
{
  struct Fila F;
  int alternativa, valor;

  Inicia(&F);

  printf("Escolha uma alternativa:\n");
  printf("1 - Inserir elementos na fila\n");
  printf("2 - Retirar elementos da fila com troca\n");
  printf("3 - Retirar elementos da fila sem troca\n");
  printf("4 - Verificar o elemento que esta na Saida da fila\n");
  printf("5 - Mostrar todos os elementos da fila\n");
  printf("6 - Sair\n");
  scanf("%d", &alternativa);

  switch (alternativa)
  {
  case 1:
    printf("Digite o valor a ser inserido: ");
    scanf("%d", &valor);
    if (Insere(&F, valor))
      printf("Valor inserido com sucesso!\n\n");
    else
      printf("Fila cheia, nao foi possível inserir!\n");
    break;

  case 2:
    if (Remove(&F, &valor))
      printf("Valor %d retirado com sucesso!\n", valor);
    else
      printf("Fila vazia, nao foi possível retirar!\n\n");
    break;

  case 3:
    if (RemoveComTroca(&F, &valor))
      printf("O elemento que esta na Saida da fila e %d\n", valor);
    else
      printf("Fila vazia, nao ha elementos na fila!\n\n");
    break;

  case 4:
    if (VerificaElemento(F, &valor))
      printf("O elemento que esta na Saida da fila e %d\n", valor);
    else
      printf("Fila vazia, nao ha elementos na fila!\n\n");
    break;

  case 5:
    MostraFila(F);
    break;

  case 6:
    printf("Programa encerrado!\n");
    break;

  default:
    printf("Opção invalida, tente novamente!\n\n");
    break;
  }

  while (alternativa != 6);

  return 0;
}
