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

// ANCHOR - Fun��es principais
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

// ANCHOR - Fun��es para adicionar, alterar, consultar e deletar clientes
void insereCliente(no **inicio, cliente *novoCliente)
{
  no *novoNo = (no *)malloc(sizeof(no)); // TODO - Tratar se a memoria est� cheia
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
  // TODO -  Tratar se ter� espa�o para a altera��o dos dados
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

// ANCHOR - Fun��es para adicionar, alterar, consultar e deletar produtos
void insereProduto(no **inicio, produto *novoProduto)
{
  no *novoNO = (no *)malloc(sizeof(no)); // TODO - Tratar se a memoria est� cheia
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
  // TODO -  Tratar se ter� espa�o para a altera��o dos dados
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

// ANCHOR - Fun��es para adicionar, alterar, consultar e deletar vendas
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
    printf("Erro ao alocar memoria para o n�o.\n");
  }
  // TODO - Acrescentar o pre�o do produto na venda
}

void alteraVenda(venda *V, char *cpfCliente, int codigoProduto, int quantidadeComprada)
{
  strcpy(V->cpfCliente, cpfCliente);
  V->codigoProduto = codigoProduto;
  V->quantidadeComprada = quantidadeComprada;
  // TODO -  Tratar se ter� espa�o para a altera��o dos dados
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

// ANCHOR - Fun��es para buscar clientes, produtos e vendas
cliente *buscaCliente(no *inicio, char *cpf)
{
  no *aux = inicio;
  while (aux != NULL)
  {
    // REVIEW - Juntar os 2 ifs em um s�o
    if (aux->C != NULL)
    {
      if (strcmp(aux->C->cpf, cpf) == 0)
      {
        return aux->C;
      }
    }
    aux = aux->proximo;
  }
  printf("Cliente com CPF %s n�o encontrado.\n", cpf);
  return NULL;
}

produto *buscaProduto(no *inicio, int codigo)
{
  no *aux = inicio;
  while (aux != NULL)
  {
    // REVIEW - Juntar os 2 ifs em um s�o
    if (aux->P != NULL)
    {
      if (aux->P->codigo == codigo)
      {
        return aux->P;
      }
    }
    aux = aux->proximo;
  }
  printf("Produto com c�digo %d n�o encontrado.\n", codigo);
  return NULL;
}

venda *buscaVenda(no *inicio, char *cpfCliente, int codigoProduto)
{
  no *aux = inicio;
  while (aux != NULL)
  {
    // REVIEW - Juntar os 3 ifs em um s�o
    if (aux->V != NULL)
    {
      if (strcmp(aux->V->cpfCliente, cpfCliente) == 0 && aux->V->codigoProduto == codigoProduto)
      {
        return aux->V;
      }
    }
    aux = aux->proximo;
  }
  printf("Venda com CPF %s e c�digo %d n�o encontrada.\n", cpfCliente, codigoProduto);
  return NULL;
}

// ANCHOR - Fun��es para imprimir clientes, produtos e vendas
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
      printf("Endere�o: %s\n", aux->C->end.rua);
      printf("N�mero: %d\n", aux->C->end.numero);
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
      printf("c�digo: %d\n", aux->P->codigo);
      printf("Descri��o: %s\n", aux->P->descricao);
      printf("Quantidade em estoque: %d\n", aux->P->quantidadeEstoque);
      printf("Pre�o unit�rio: %.2f\n", aux->P->precoUnitario);
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
      printf("c�digo do produto: %d\n", aux->V->codigoProduto);
      printf("Quantidade comprada: %d\n", aux->V->quantidadeComprada);
      printf("\n");
    }
    aux = aux->proximo;
  }
}
// REVIEW - Corrigir as vari�veis auxiliares nas fun��es todas, usar somente a inicio sem criar uma vari�veis auxiliar para isso

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
    printf("\nDigite a op��o desejada: ");
    scanf("%d", &opcao);

    int opcaoInserir, opcaoAlterar, opcaoBuscar, opcaoRemover, opcaoMostrar;
    // TODO - Os switch com op��es de sim e n�o podem ser adicionados switch para realizar essas a��es
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
        printf("\nDigite a op��o desejada: ");
        scanf("%d", &opcaoInserir);

        switch (opcaoInserir)
        {
        case 1: // ANCHOR - N�o deve aceitar CPFs j� cadastrados
          printf("\n=========INSERIR CLIENTE==========\n");
          // Cria um novo n� para o cliente
          no *novoCliente = (no *)malloc(sizeof(no));
          novoCliente->proximo = NULL;
          novoCliente->anterior = NULL;
          printf("Digite o nome do cliente: ");
          scanf("%s", novoCliente->C->nome);
          printf("Digite o CPF do cliente: ");
          scanf("%s", novoCliente->C->cpf);
          printf("Digite o endere�o do cliente: ");
          printf("Rua: ");
          scanf("%s", novoCliente->C->end.rua);
          printf("N�mero: ");
          scanf("%d", &novoCliente->C->end.numero);
          printf("Bairro: ");
          scanf("%s", novoCliente->C->end.bairro);
          printf("Cidade: ");
          scanf("%s", novoCliente->C->end.cidade);
          printf("Estado: ");
          scanf("%s", novoCliente->C->end.estado);
          printf("Digite o telefone do cliente: ");
          scanf("%s", novoCliente->C->telefone);
          // NOTE - Verifica se o CPF j� est� cadastrado
          if (buscarCliente(inicio, novoCliente->C->cpf) != NULL){
            printf("CPF j� cadastrado.\n");
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

        case 2: // ANCHOR - N�o deve aceitar c�digos j� cadastrados
          printf("\n=========INSERIR PRODUTO==========\n");
          // L�gica para inserir produto

          break;

        case 3: // NOTE - N�o deve aceitar CPFs e c�digos de produtos que n�o existam
          printf("\n=========INSERIR VENDA==========\n");
          // L�gica para inserir venda

          break;

        case 0:
          break;

        default:
          printf("Op��o inv�lida.\n");
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
        printf("\nDigite a op��o desejada: ");
        scanf("%d", &opcaoAlterar);

        int opcaoCliente, opcaoProduto, opcaoVenda;
        switch (opcaoAlterar)
        {
        case 1:
          do
          {
            // L�gica para alterar cliente

            printf("\nDeseja alterar outro cliente? (1 - Sim / 0 - N�o): ");
            scanf("%d", &opcaoCliente);
          } while (opcaoCliente != 0);
          break;

        case 2:
          do
          {
            // L�gica para alterar produto

            printf("\nDeseja alterar outro produto? (1 - Sim / 0 - N�o): ");
            scanf("%d", &opcaoProduto);
          } while (opcaoProduto != 0);
          break;

        case 3:
          do
          {
            // L�gica para alterar venda

            printf("\nDeseja alterar outra venda? (1 - Sim / 0 - N�o): ");
            scanf("%d", &opcaoVenda);
          } while (opcaoVenda != 0);
          break;

        case 0:
          break;

        default:
          printf("Op��o inv�lida.\n");
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
        printf("\nDigite a op��o desejada: ");
        scanf("%d", &opcaoBuscar);

        int opcaoCliente, opcaoProduto, opcaoVenda;
        switch (opcaoBuscar)
        {
        case 1:
          do
          {
            // L�gica para buscar cliente

            printf("\nDeseja buscar outro cliente? (1 - Sim / 0 - N�o): ");
            scanf("%d", &opcaoCliente);
          } while (opcaoCliente != 0);
          break;

        case 2:
          do
          {
            // L�gica para buscar produto

            printf("\nDeseja buscar outro produto? (1 - Sim / 0 - N�o): ");
            scanf("%d", &opcaoProduto);
          } while (opcaoProduto != 0);
          break;

        case 3:
          do
          {
            // L�gica para buscar venda

            printf("\nDeseja buscar outra venda? (1 - Sim / 0 - N�o): ");
            scanf("%d", &opcaoVenda);
          } while (opcaoVenda != 0);
          break;

        case 0:
          break;

        default:
          printf("Op��o inv�lida.\n");
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
        printf("\nDigite a op��o desejada: ");
        scanf("%d", &opcaoRemover);

        int opcaoCliente, opcaoProduto, opcaoVenda;
        switch (opcaoRemover)
        {
        case 1: // NOTE - N�o deve ser poss�vel remover clientes que possuem vendas
          do
          {
            // L�gica para remover cliente

            printf("\nDeseja remover outro cliente? (1 - Sim / 0 - N�o): ");
            scanf("%d", &opcaoCliente);
          } while (opcaoCliente != 0);
          break;

        case 2: // NOTE - N�o deve ser poss�vel remover o produto se ele estiver em uma venda
          do
          {
            // L�gica para remover produto

            printf("\nDeseja remover outro produto? (1 - Sim / 0 - N�o): ");
            scanf("%d", &opcaoProduto);
          } while (opcaoProduto != 0);
          break;

        case 3:
          do
          {
            // L�gica para remover venda

            printf("\nDeseja remover outra venda? (1 - Sim / 0 - N�o): ");
            scanf("%d", &opcaoVenda);
          } while (opcaoVenda != 0);
          break;

        case 0:
          break;

        default:
          printf("Op��o inv�lida.\n");
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
        printf("\nDigite a op��o desejada: ");
        scanf("%d", &opcaoMostrar);

        switch (opcaoMostrar)
        {
        case 1:
          do
          {
            // L�gica para mostrar clientes

            printf("\nDeseja mostrar outros clientes? (1 - Sim / 0 - N�o): ");
            scanf("%d", &opcaoMostrar);
          } while (opcaoMostrar != 0);
          break;

        case 2:
          do
          {
            // L�gica para mostrar produtos

            printf("\nDeseja mostrar outros produtos? (1 - Sim / 0 - N�o): ");
            scanf("%d", &opcaoMostrar);
          } while (opcaoMostrar != 0);
          break;

        case 3:
          do
          {
            // L�gica para mostrar vendas

            printf("\nDeseja mostrar outras vendas? (1 - Sim / 0 - N�o): ");
            scanf("%d", &opcaoMostrar);
          } while (opcaoMostrar != 0);
          break;

        case 4:
          do
          {
            // L�gica para mostrar compras acima de um X valor dos clientes

            printf("\nDeseja mostrar outras compras acima de um X valor dos clientes? (1 - Sim / 0 - N�o): ");
            scanf("%d", &opcaoMostrar);
          } while (opcaoMostrar != 0);
          break;

        case 5:
          do
          {
            // L�gica para mostrar produtos com estoque abaixo de X quantidade

            printf("\nDeseja mostrar outros produtos com estoque abaixo de X quantidade? (1 - Sim / 0 - N�o): ");
            scanf("%d", &opcaoMostrar);
          } while (opcaoMostrar != 0);
          break;

        case 0:
          break;

        default:
          printf("Op��o inv�lida.\n");
          break;
        }
      } while (opcaoMostrar != 0);
      break;

    case 0:
      break;

    default:
      printf("Op��o inv�lida.\n");
      break;
    }
  } while (opcao != 0);
}