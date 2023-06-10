#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct Arvore
{
  int info;
  struct Arvore *esq, *dir;
} Arvore;

Arvore *raiz;

Arvore *insere(Arvore *root, Arvore *r, int dado){
  if (r == NULL)  {
    r = (Arvore *)malloc(sizeof(Arvore));
    if (r == NULL)
      printf("Lotado\n");
    else{
      r->esq = NULL;
      r->dir = NULL;
      r->info = dado;
      if (root == NULL)
        return r;
      if (r->info < root->info)
        root->esq = r;
      else
        root->dir = r;
      return r;
    }
  }
  if (dado < r->info)
    insere(r, r->esq, dado);
  else
    insere(r, r->dir, dado);
  return r;
}

void PreOrdem(Arvore *root){
  if (root == NULL)
    return;
  printf("%d ", root->info);
  PreOrdem(root->esq);
  PreOrdem(root->dir);
}

void EmOrdem(Arvore *root){
  if (root == NULL)
    return;
  EmOrdem(root->esq);
  printf("%d ", root->info);
  EmOrdem(root->dir);
}

void PosOrdem(Arvore *root){
  if (root == NULL)
    return;
  PosOrdem(root->esq);
  PosOrdem(root->dir);
  printf("%d ", root->info);
}

int contaFolhas(Arvore *root){
  if (root == NULL)
    return 0;
  if (root->esq == NULL && root->dir == NULL)
    return 1;
  return contaFolhas(root->esq) + contaFolhas(root->dir);
}
/*ANCHOR - A função contaFolhas é responsável por contar o número de folhas em uma árvore binária.

Primeiro, ela verifica se a árvore está vazia, se estiver, retorna 0.

Em seguida, ela verifica se o nó atual é uma folha, ou seja, se ele não tem filhos (esquerdo e direito), se for uma folha, retorna 1.

Se o nó atual não for uma folha, a função chama a si mesma para o nó esquerdo e direito, somando o resultado das chamadas recursivas.

Ao final, a função retorna o número total de folhas na árvore.*/

int main(){
  setlocale(LC_ALL, "Portuguese_Brazil");
  int valor, opcao;
  raiz = NULL;

  do
  {
    printf("\n===========Menu===========\n");
    printf("1. Inserir valor na arvore\n");
    printf("2. Mostrar arvore em Pre-Ordem\n");
    printf("3. Mostrar arvore em Em-Ordem\n");
    printf("4. Mostrar arvore em Pos-Ordem\n");
    printf("5. Mostrar quantidade de folhas\n");
    printf("6. Sair\n");
    printf("Digite a opcao desejada: ");
    scanf("%d", &opcao);

    switch (opcao)
    {
    case 1:
      printf("Digite um valor: ");
      scanf("%d", &valor);
      if (raiz == NULL)
        raiz = insere(raiz, raiz, valor);
      else
        insere(raiz, raiz, valor);
      break;
    case 2:
      printf("\nPre-Ordem : ");
      PreOrdem(raiz);
      break;
    case 3:
      printf("\nEm-Ordem : ");
      EmOrdem(raiz);
      break;
    case 4:
      printf("\nPos-Ordem : ");
      PosOrdem(raiz);
      break;
    case 5:
      printf("\nNumero de nos folhas: %d", contaFolhas(raiz));
      break;
    case 6:
      printf("\nFim\n");
      break;
    default:
      printf("\nOpcão invalida!\n");
      break;
    }
  } while (opcao != 6);
}
