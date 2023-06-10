#include <stdlib.h>
#include <stdio.h>
#include <locale.h>

#define dados 50

// ANCHOR - Structs
typedef struct
{
  int dd, mm, aaaa;
} Data;

typedef struct
{
  char rua[dados], bairro[dados], cidade[dados], estado[dados];
  int numero;
} endereco;

typedef struct
{
  char cpf[11], nome[dados];
  int telefone;
  endereco end;
  Data dataNascimento;
  struct cliente *anterior;
  struct cliente *proximo;
}cliente;

typedef struct
{
  int codigo, quantidadeEstoque;
  char descricao[dados];
  float precoUnitario;
  struct produto *anterior;
  struct produto *proximo;
} produto;

typedef struct
{
  char cpfCliente[11];
  int codigoProduto, quantidadeComprada;
  struct venda *anterior;
  struct venda *proximo;
} venda;

typedef struct espaco
{
  cliente *C;
  produto *P;
  venda *V;
  struct espaco *anterior;
  struct espaco *proximo;
} no;

// ANCHOR - Funções principais
void insereNaLista(no **inicio, no *itemDaLista)
{
  no *proximoLista;
  itemDaLista->anterior = NULL;
  itemDaLista->proximo = NULL;

  if (*inicio == NULL)
  {
    *inicio = itemDaLista;
  }
  else
  {
    proximoLista = *inicio;
    while (proximoLista->proximo != NULL)
    {
      proximoLista = proximoLista->proximo;
    }
    proximoLista->proximo = itemDaLista;
    itemDaLista->anterior = proximoLista;
  }
}

void removeNaLista(no **inicio, no *itemDaLista)
{
  if (*inicio == NULL)
  {
    printf("\nLista vazia\n");
  }
  else
  {
    if (itemDaLista->anterior != NULL)
    {
      itemDaLista->anterior->proximo = itemDaLista->proximo;
    }
    else
    {
      *inicio = itemDaLista->proximo;
    }
    if (itemDaLista->proximo != NULL)
    {
      itemDaLista->proximo->anterior = itemDaLista->anterior;
    }

    free(itemDaLista);
  }
}

// ANCHOR - Funções para adicionar, alterar, consultar e deletar clientes
void insereCliente(no **inicio, cliente *novoCliente)
{
  no *novoNo = (no *)malloc(sizeof(no)); // TODO - Tratar se a memoria está cheia
  novoNo->C = novoCliente;
  novoNo->P = NULL;
  novoNo->V = NULL;
  insereNaLista(inicio, novoNo);
}

void alteraCliente(cliente *C, char *nome, int telefone, endereco end, Data dataNascimento)
{
  strcpy(C->nome, nome);
  C->telefone = telefone;
  C->end = end;
  C->dataNascimento = dataNascimento;
  // TODO -  Tratar se terá espaço para a alteração dos dados
}

void removeCliente(no **inicio, cliente *C)
{
  no *aux = *inicio;
  while (aux != NULL)
  {
    if (aux->C == C)
    {
      removeCliente(inicio, aux);
      break;
    }
    aux = aux->proximo;
  }
}

// ANCHOR - Funções para adicionar, alterar, consultar e deletar produtos
void insereProduto(no **inicio, produto *novoProduto)
{
  no *novoNO = (no *)malloc(sizeof(no)); // TODO - Tratar se a memoria está cheia
  novoNO->C = NULL;
  novoNO->P = novoProduto;
  novoNO->V = NULL;
  insereNaLista(inicio, novoNO);
}

void alteraProduto(produto *P, int codigo, int quantidadeEstoque, char descricao[], float precoUnitario)
{
  P->codigo = codigo;
  P->quantidadeEstoque = quantidadeEstoque;
  strcpy(P->descricao, descricao);
  P->precoUnitario = precoUnitario;
  // TODO -  Tratar se terá espaço para a alteração dos dados
}

void removeProduto(no **inicio, produto *P)
{
  no *aux = *inicio;
  while (aux != NULL)
  {
    if (aux->P == P)
    {
      removeNaLista(inicio, aux);
      break;
    }
    aux = aux->proximo;
  }
}

// ANCHOR - Funções para adicionar, alterar, consultar e deletar vendas
void insereVenda(no **inicio, char *cpfCliente, int codigoProduto, int quantidadeComprada)
{
  no *novoNo = (no *)malloc(sizeof(no));
  if (novoNo != NULL)
  {
    novoNo->C = NULL;
    novoNo->P = NULL;

    novoNo->V = (venda *)malloc(sizeof(venda));
    if (novoNo->V != NULL)
    {
      strcpy(novoNo->V->cpfCliente, cpfCliente);
      novoNo->V->codigoProduto = codigoProduto;
      novoNo->V->quantidadeComprada = quantidadeComprada;

      novoNo->V->anterior = NULL;
      novoNo->V->proximo = NULL;

      insereNaLista(inicio, novoNo);
    }
    else
    {
      printf("Erro ao alocar memoria para a venda.\n");
      free(novoNo);
    }
  }
  else
  {
    printf("Erro ao alocar memoria para o não.\n");
  }
  // TODO - Acrescentar o preço do produto na venda
}

void alteraVenda(venda *V, char *cpfCliente, int codigoProduto, int quantidadeComprada)
{
  strcpy(V->cpfCliente, cpfCliente);
  V->codigoProduto = codigoProduto;
  V->quantidadeComprada = quantidadeComprada;
  // TODO -  Tratar se terá espaço para a alteração dos dados
}

void removeVenda(no **inicio, venda *V)
{
  no *aux = *inicio;
  while (aux != NULL)
  {
    if (aux->V == V)
    {
      removeNaLista(inicio, aux);
      break;
    }
    aux = aux->proximo;
  }
}

// ANCHOR - Funções para buscar clientes, produtos e vendas
cliente *buscaCliente(no *inicio, char *cpf)
{
  no *aux = inicio;
  while (aux != NULL)
  {
    // REVIEW - Juntar os 2 ifs em um são
    if (aux->C != NULL)
    {
      if (strcmp(aux->C->cpf, cpf) == 0)
      {
        return aux->C;
      }
    }
    aux = aux->proximo;
  }
  printf("Cliente com CPF %s não encontrado.\n", cpf);
  return NULL;
}

produto *buscaProduto(no *inicio, int codigo)
{
  no *aux = inicio;
  while (aux != NULL)
  {
    // REVIEW - Juntar os 2 ifs em um são
    if (aux->P != NULL)
    {
      if (aux->P->codigo == codigo)
      {
        return aux->P;
      }
    }
    aux = aux->proximo;
  }
  printf("Produto com código %d não encontrado.\n", codigo);
  return NULL;
}

venda *buscaVenda(no *inicio, char *cpfCliente, int codigoProduto)
{
  no *aux = inicio;
  while (aux != NULL)
  {
    // REVIEW - Juntar os 3 ifs em um são
    if (aux->V != NULL)
    {
      if (strcmp(aux->V->cpfCliente, cpfCliente) == 0 && aux->V->codigoProduto == codigoProduto)
      {
        return aux->V;
      }
    }
    aux = aux->proximo;
  }
  printf("Venda com CPF %s e código %d não encontrada.\n", cpfCliente, codigoProduto);
  return NULL;
}

// ANCHOR - Funções para imprimir clientes, produtos e vendas
void imprimeClientes(no *inicio)
{

  no *aux = inicio;
  while (aux != NULL)
  {
    if (aux->C != NULL)
    {
      printf("Nome: %s\n", aux->C->nome);
      printf("CPF: %s\n", aux->C->cpf);
      printf("Telefone: %d\n", aux->C->telefone);
      printf("Data de nascimento: %d/%d/%d\n", aux->C->dataNascimento.dd, aux->C->dataNascimento.mm, aux->C->dataNascimento.aaaa);
      printf("Endereço: %s\n", aux->C->end.rua);
      printf("Número: %d\n", aux->C->end.numero);
      printf("Bairro: %s\n", aux->C->end.bairro);
      printf("Cidade: %s\n", aux->C->end.cidade);
      printf("Estado: %s\n", aux->C->end.estado);
      printf("\n");
    }
    aux = aux->proximo;
  }
}

void imprimeProdutos(no *inicio)
{

  no *aux = inicio;
  while (aux != NULL)
  {
    if (aux->P != NULL)
    {
      printf("código: %d\n", aux->P->codigo);
      printf("Descrição: %s\n", aux->P->descricao);
      printf("Quantidade em estoque: %d\n", aux->P->quantidadeEstoque);
      printf("Preço unitário: %.2f\n", aux->P->precoUnitario);
      printf("\n");
    }
    aux = aux->proximo;
  }
}

void imprimeVendas(no *inicio)
{

  no *aux = inicio;
  while (aux != NULL)
  {
    if (aux->V != NULL)
    {
      printf("CPF do cliente: %s\n", aux->V->cpfCliente);
      printf("código do produto: %d\n", aux->V->codigoProduto);
      printf("Quantidade comprada: %d\n", aux->V->quantidadeComprada);
      printf("\n");
    }
    aux = aux->proximo;
  }
}
// REVIEW - Corrigir as variáveis auxiliares nas funções todas, usar somente a inicio sem criar uma variáveis auxiliar para isso

int main()
{
  setlocale(LC_ALL, "Portuguese_Brazil");
  no *inicio = NULL;

  int opcao;
  do
  {
    printf("\n=========MENU==========\n");
    printf("1 - Inserir cliente, produto, venda\n");
    printf("2 - Alterar cliente, produto, venda\n");
    printf("3 - Buscar cliente, produto, venda\n");
    printf("4 - Remover cliente, produto, venda\n");
    printf("5 - Mostrar clientes, produtos, vendas e outros...\n");
    printf("0 - Sair\n");
    printf("\nDigite a opção desejada: ");
    scanf("%d", &opcao);

    int opcaoInserir, opcaoAlterar, opcaoBuscar, opcaoRemover, opcaoMostrar;
    // TODO - Os switch com opções de sim e não podem ser adicionados switch para realizar essas ações
    switch (opcao)
    {
    // ANCHOR - Inserir
    case 1:
      do
      {
        printf("\n=========INSERIR==========\n");
        printf("1 - Inserir cliente\n");
        printf("2 - Inserir produto\n");
        printf("3 - Inserir venda\n");
        printf("0 - Voltar\n");
        printf("\nDigite a opção desejada: ");
        scanf("%d", &opcaoInserir);

        switch (opcaoInserir)
        {
        case 1: // ANCHOR - Não deve aceitar CPFs já cadastrados
          printf("\n=========INSERIR CLIENTE==========\n");
          // Cria um novo nó para o cliente
          no *novoCliente = (no *)malloc(sizeof(no));
          novoCliente->proximo = NULL;
          novoCliente->anterior = NULL;
          printf("Digite o nome do cliente: ");
          scanf("%s", novoCliente->C->nome);
          printf("Digite o CPF do cliente: ");
          scanf("%s", novoCliente->C->cpf);
          printf("Digite o endereço do cliente: ");
          printf("Rua: ");
          scanf("%s", novoCliente->C->end.rua);
          printf("Número: ");
          scanf("%d", &novoCliente->C->end.numero);
          printf("Bairro: ");
          scanf("%s", novoCliente->C->end.bairro);
          printf("Cidade: ");
          scanf("%s", novoCliente->C->end.cidade);
          printf("Estado: ");
          scanf("%s", novoCliente->C->end.estado);
          printf("Digite o telefone do cliente: ");
          scanf("%s", novoCliente->C->telefone);
          // NOTE - Verifica se o CPF já está cadastrado
          if (buscarCliente(inicio, novoCliente->C->cpf) != NULL){
            printf("CPF já cadastrado.\n");
            free(novoCliente);
            break;
          }
          // Insere o novo cliente na lista
          if (inicio == NULL)
          {
            inicio = novoCliente;
          }
          else
          {
            no *atual = inicio;
            while (atual->proximo != NULL)
            {
              atual = atual->proximo;
            }
            atual->proximo = novoCliente;
            novoCliente->anterior = atual;
          }
          printf("Cliente cadastrado com sucesso!\n");
          break;

        case 2: // ANCHOR - Não deve aceitar códigos já cadastrados
          printf("\n=========INSERIR PRODUTO==========\n");
          // Lógica para inserir produto

          break;

        case 3: // NOTE - Não deve aceitar CPFs e códigos de produtos que não existam
          printf("\n=========INSERIR VENDA==========\n");
          // Lógica para inserir venda

          break;

        case 0:
          break;

        default:
          printf("Opção inválida.\n");
          break;
        }
      } while (opcaoInserir != 0);
      break;

    // ANCHOR - Alterar
    case 2:
      do
      {
        printf("\n=========MENU==========\n");
        printf("1 - Alterar cliente\n");
        printf("2 - Alterar produto\n");
        printf("3 - Alterar venda\n");
        printf("0 - Voltar\n");
        printf("\nDigite a opção desejada: ");
        scanf("%d", &opcaoAlterar);

        int opcaoCliente, opcaoProduto, opcaoVenda;
        switch (opcaoAlterar)
        {
        case 1:
          do
          {
            // Lógica para alterar cliente

            printf("\nDeseja alterar outro cliente? (1 - Sim / 0 - Não): ");
            scanf("%d", &opcaoCliente);
          } while (opcaoCliente != 0);
          break;

        case 2:
          do
          {
            // Lógica para alterar produto

            printf("\nDeseja alterar outro produto? (1 - Sim / 0 - Não): ");
            scanf("%d", &opcaoProduto);
          } while (opcaoProduto != 0);
          break;

        case 3:
          do
          {
            // Lógica para alterar venda

            printf("\nDeseja alterar outra venda? (1 - Sim / 0 - Não): ");
            scanf("%d", &opcaoVenda);
          } while (opcaoVenda != 0);
          break;

        case 0:
          break;

        default:
          printf("Opção inválida.\n");
          break;
        }
      } while (opcaoAlterar != 0);
      break;

    // ANCHOR - Buscar
    case 3:
      do
      {
        printf("\n=========MENU==========\n");
        printf("1 - Buscar cliente\n");
        printf("2 - Buscar produto\n");
        printf("3 - Buscar venda\n");
        printf("0 - Voltar\n");
        printf("\nDigite a opção desejada: ");
        scanf("%d", &opcaoBuscar);

        int opcaoCliente, opcaoProduto, opcaoVenda;
        switch (opcaoBuscar)
        {
        case 1:
          do
          {
            // Lógica para buscar cliente

            printf("\nDeseja buscar outro cliente? (1 - Sim / 0 - Não): ");
            scanf("%d", &opcaoCliente);
          } while (opcaoCliente != 0);
          break;

        case 2:
          do
          {
            // Lógica para buscar produto

            printf("\nDeseja buscar outro produto? (1 - Sim / 0 - Não): ");
            scanf("%d", &opcaoProduto);
          } while (opcaoProduto != 0);
          break;

        case 3:
          do
          {
            // Lógica para buscar venda

            printf("\nDeseja buscar outra venda? (1 - Sim / 0 - Não): ");
            scanf("%d", &opcaoVenda);
          } while (opcaoVenda != 0);
          break;

        case 0:
          break;

        default:
          printf("Opção inválida.\n");
          break;
        }
      } while (opcaoBuscar != 0);
      break;

      // ANCHOR - Remover
    case 4:
      do
      {
        printf("\n=========MENU==========\n");
        printf("1 - Remover cliente\n");
        printf("2 - Remover produto\n");
        printf("3 - Remover venda\n");
        printf("0 - Voltar\n");
        printf("\nDigite a opção desejada: ");
        scanf("%d", &opcaoRemover);

        int opcaoCliente, opcaoProduto, opcaoVenda;
        switch (opcaoRemover)
        {
        case 1: // NOTE - Não deve ser possível remover clientes que possuem vendas
          do
          {
            // Lógica para remover cliente

            printf("\nDeseja remover outro cliente? (1 - Sim / 0 - Não): ");
            scanf("%d", &opcaoCliente);
          } while (opcaoCliente != 0);
          break;

        case 2: // NOTE - Não deve ser possível remover o produto se ele estiver em uma venda
          do
          {
            // Lógica para remover produto

            printf("\nDeseja remover outro produto? (1 - Sim / 0 - Não): ");
            scanf("%d", &opcaoProduto);
          } while (opcaoProduto != 0);
          break;

        case 3:
          do
          {
            // Lógica para remover venda

            printf("\nDeseja remover outra venda? (1 - Sim / 0 - Não): ");
            scanf("%d", &opcaoVenda);
          } while (opcaoVenda != 0);
          break;

        case 0:
          break;

        default:
          printf("Opção inválida.\n");
          break;
        }
      } while (opcaoRemover != 0);
      break;

      // ANCHOR - Mostrar
    case 5:
      do
      {
        printf("\n=========MENU==========\n");
        printf("1 - Mostrar clientes\n");
        printf("2 - Mostrar produtos\n");
        printf("3 - Mostrar vendas\n");
        printf("4 - Mostrar compras acima de um X valor dos clientes\n");
        printf("5 - Mostrar produtos com estoque abaixo de X quantidade\n");
        printf("0 - Voltar\n");
        printf("\nDigite a opção desejada: ");
        scanf("%d", &opcaoMostrar);

        switch (opcaoMostrar)
        {
        case 1:
          do
          {
            // Lógica para mostrar clientes

            printf("\nDeseja mostrar outros clientes? (1 - Sim / 0 - Não): ");
            scanf("%d", &opcaoMostrar);
          } while (opcaoMostrar != 0);
          break;

        case 2:
          do
          {
            // Lógica para mostrar produtos

            printf("\nDeseja mostrar outros produtos? (1 - Sim / 0 - Não): ");
            scanf("%d", &opcaoMostrar);
          } while (opcaoMostrar != 0);
          break;

        case 3:
          do
          {
            // Lógica para mostrar vendas

            printf("\nDeseja mostrar outras vendas? (1 - Sim / 0 - Não): ");
            scanf("%d", &opcaoMostrar);
          } while (opcaoMostrar != 0);
          break;

        case 4:
          do
          {
            // Lógica para mostrar compras acima de um X valor dos clientes

            printf("\nDeseja mostrar outras compras acima de um X valor dos clientes? (1 - Sim / 0 - Não): ");
            scanf("%d", &opcaoMostrar);
          } while (opcaoMostrar != 0);
          break;

        case 5:
          do
          {
            // Lógica para mostrar produtos com estoque abaixo de X quantidade

            printf("\nDeseja mostrar outros produtos com estoque abaixo de X quantidade? (1 - Sim / 0 - Não): ");
            scanf("%d", &opcaoMostrar);
          } while (opcaoMostrar != 0);
          break;

        case 0:
          break;

        default:
          printf("Opção inválida.\n");
          break;
        }
      } while (opcaoMostrar != 0);
      break;

    case 0:
      break;

    default:
      printf("Opção inválida.\n");
      break;
    }
  } while (opcao != 0);
}