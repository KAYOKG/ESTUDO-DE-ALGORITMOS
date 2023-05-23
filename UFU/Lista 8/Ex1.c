#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct produto
{
  int codigo;
  float preco;
  int quantidade;
  struct produto *prox;
} Produto;

Produto *inicio = NULL;

void insere_produto(int codigo, float preco, int quantidade)
{
  Produto *novo = (Produto *)malloc(sizeof(Produto));
  novo->codigo = codigo;
  novo->preco = preco;
  novo->quantidade = quantidade;
  novo->prox = inicio;
  inicio = novo;
}

void aplica_desconto(float taxa_desconto)
{
  Produto *p = inicio;
  while (p != NULL)
  {
    p->preco = p->preco * (1 - taxa_desconto / 100);
    p = p->prox;
  }
}

void relatorio(inicio)
{
  int qtd_estocada = 0;
  Produto *p = inicio;
  printf("Código\tPreço\n");
  while (p != NULL)
  {
    printf("  %d\t%.2f\n", p->codigo, p->preco);
    if (p->quantidade > 500)
    {
      qtd_estocada++;
    }
    p = p->prox;
  }
  printf("Quantidade de produtos com quantidade estocada superior a 500: %d\n", qtd_estocada);
}

int main()
{
  setlocale(LC_ALL, "Portuguese_Brazil");
  int codigo, quantidade;
  float preco, taxa_desconto;
  char continuar;
  do
  {
    printf("Digite o código do produto: ");
    scanf("%d", &codigo);
    printf("Digite o preço do produto: ");
    scanf("%f", &preco);
    printf("Digite a quantidade estocada do produto: ");
    scanf("%d", &quantidade);
    insere_produto(codigo, preco, quantidade);
    printf("Deseja cadastrar outro produto? (S/N) ");
    scanf(" %c", &continuar);
  } while (continuar == 'S' || continuar == 's');
  printf("Digite a taxa de desconto: ");
  scanf("%f", &taxa_desconto);
  aplica_desconto(taxa_desconto);
  relatorio();
  return 0;
}
