#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct no
{
  char nome[30];
  int idade;
  struct no *prox;
} noptr;

noptr *inicio;

void insere_lista(char nome[], int idade);
void lista_todos();
void remove_lista();
void aumenta_idade(char nome[]);
void lista_inversa(noptr *p);

void insere_lista(char nome[], int idade)
{
  noptr *novo = (noptr *)malloc(sizeof(noptr));
  strcpy(novo->nome, nome);
  novo->idade = idade;
  novo->prox = inicio;
  inicio = novo;
}

void remove_lista()
{
  noptr *p, *ant;
  if (inicio == NULL)
  {
    printf("\nLista Vazia!!!");
    return;
  }
  else
  {
    p = inicio;
    while (p != NULL)
    {
      ant = p;
      p = p->prox;
      printf("\nValor Removido: %s - %d", ant->nome, ant->idade);
      free(ant);
    }
    inicio = NULL;
  }
}

void lista_todos()
{
  if (inicio == NULL)
  {
    printf("\nLista Vazia!!!");
    return;
  }
  noptr *p;
  p = inicio;
  while (p)
  {
    printf("\nSaida: %s - %d", p->nome, p->idade);
    p = p->prox;
  }
  printf("\n");
}

void aumenta_idade(char nome[])
{
  noptr *p;
  p = inicio;
  while (p)
  {
    if (strcmp(p->nome, nome) == 0)
    {
      p->idade += 10;
      printf("\nIdade de %s aumentada em 10 anos. Nova idade: %d", p->nome, p->idade);
      return;
    }
    p = p->prox;
  }
  printf("\nNome nao encontrado na lista.");
}

void lista_inversa(noptr *p)
{
  if (p == NULL)
    return;
  lista_inversa(p->prox);
  printf("%s - %d\n", p->nome, p->idade);
}

int main()
{
  int recebe_idade = -1;
  char recebe_nome[30];
  inicio = NULL;
  do
  {
    printf("Digite um nome (ou 0 para sair): ");
    scanf("%s", recebe_nome);
    if (strcmp(recebe_nome, "0") != 0)
    {
      printf("Digite a idade: ");
      scanf("%d", &recebe_idade);
      insere_lista(recebe_nome, recebe_idade);
    }
  } while (strcmp(recebe_nome, "0") != 0);
  lista_todos();
  remove_lista();
  lista_todos();
  printf("\nDigite um nome para aumentar a idade em 10 anos: ");
  scanf("%s", recebe_nome);
  aumenta_idade(recebe_nome);
  lista_todos();
  printf("\nLista em ordem inversa:\n");
  lista_inversa(inicio);
  return 0;
}
