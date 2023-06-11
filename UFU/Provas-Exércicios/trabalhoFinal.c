// ANCHOR - Kayo e Pedro
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
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
} cliente;

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

// ANCHOR - Funções para adicionar, alterar e deletar clientes
void insereCliente(no **inicio, cliente *novoCliente)
{
  if ((no *)malloc(sizeof(no)) == NULL)
  {
    printf("Memoria Cheia\n");
  }
  else
  {
    ((no *)malloc(sizeof(no)))->C = novoCliente;
    ((no *)malloc(sizeof(no)))->P = NULL;
    ((no *)malloc(sizeof(no)))->V = NULL;
    insereNaLista(inicio, ((no *)malloc(sizeof(no))));
  }
}

void alteraCliente(cliente *C, char *nome, int telefone, endereco end, Data dataNascimento)
{
  strcpy(C->nome, nome);
  C->telefone = telefone;
  C->end = end;
  C->dataNascimento = dataNascimento;
  // TODO - Tratar se terá espaço para a alteração dos dados
}

void removeCliente(no **inicio, cliente *C)
{
  while ((*inicio) != NULL)
  {
    if ((*inicio)->C == C)
    {
      removeNaLista(inicio, (*inicio));
      break;
    }
    (*inicio) = (*inicio)->proximo;
  }
}

// ANCHOR - Funções para adicionar, alterar e deletar produtos
void insereProduto(no **inicio, produto *novoProduto)
{
  if (((no *)malloc(sizeof(no))) == NULL)
  {
    printf("Memoria Cheia\n");
  }
  else
  {
    ((no *)malloc(sizeof(no)))->C = NULL;
    ((no *)malloc(sizeof(no)))->P = novoProduto;
    ((no *)malloc(sizeof(no)))->V = NULL;
    insereNaLista(inicio, ((no *)malloc(sizeof(no))));
  }
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
  while ((*inicio) != NULL)
  {
    if ((*inicio)->P == P)
    {
      removeNaLista(inicio, (*inicio));
      break;
    }
    (*inicio) = (*inicio)->proximo;
  }
}

void produtoEmVenda(no *inicio, int codigoProduto, int *result)
{
  *result = 0;
  while (inicio != NULL)
  {
    if (inicio->V != NULL && inicio->V->codigoProduto == codigoProduto)
    {
      *result = 1;
      break;
    }
    inicio = inicio->proximo;
  }
}

// ANCHOR - Funções para adicionar, alterar e deletar vendas
void insereVenda(no **inicio, char *cpfCliente, int codigoProduto, int quantidadeComprada)
{
  if (((no *)malloc(sizeof(no))) == NULL)
  {
    printf("Memoria cheia\n");
  }
  else
  {
    ((no *)malloc(sizeof(no)))->C = NULL;
    ((no *)malloc(sizeof(no)))->P = NULL;

    ((no *)malloc(sizeof(no)))->V = (venda *)malloc(sizeof(venda));
    if (((no *)malloc(sizeof(no)))->V == NULL)
    {
      printf("Memoria cheia\n");
      free(((no *)malloc(sizeof(no))));
    }
    else
    {
      strcpy(((no *)malloc(sizeof(no)))->V->cpfCliente, cpfCliente);
      ((no *)malloc(sizeof(no)))->V->codigoProduto = codigoProduto;
      ((no *)malloc(sizeof(no)))->V->quantidadeComprada = quantidadeComprada;

      ((no *)malloc(sizeof(no)))->V->anterior = NULL;
      ((no *)malloc(sizeof(no)))->V->proximo = NULL;

      insereNaLista(inicio, ((no *)malloc(sizeof(no))));
    }
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
  while ((*inicio) != NULL)
  {
    if ((*inicio)->V == V)
    {
      removeNaLista(inicio, (*inicio));
      break;
    }
    (*inicio) = (*inicio)->proximo;
  }
}

// ANCHOR - Funções para buscar clientes, produtos e vendas
cliente *buscaCliente(no *inicio, char *cpf)
{
  while (inicio != NULL)
  {
    // REVIEW - Juntar os 2 ifs em um só
    if (inicio->C != NULL && (strcmp(inicio->C->cpf, cpf) == 0))
    {
      return inicio->C;
    }
    inicio = inicio->proximo;
  }
  printf("Cliente com CPF (%s) não encontrado.\n", cpf);
  return NULL;
}

void clientePossuiVendas(no *inicio, char *cpfCliente, int *result)
{
  *result = 0;
  while (inicio != NULL)
  {
    if (inicio->V != NULL && strcmp(inicio->V->cpfCliente, cpfCliente) == 0)
    {
      *result = 1;
      break;
    }
    inicio = inicio->proximo;
  }
}

produto *buscaProduto(no *inicio, int codigo)
{
  while (inicio != NULL)
  {
    // REVIEW - Juntar os 2 ifs em um são
    if (inicio->P != NULL && (inicio->P->codigo == codigo))
    {

      return inicio->P;
    }
    inicio = inicio->proximo;
  }
  printf("Produto com código %d não encontrado.\n", codigo);
  return NULL;
}

venda *buscaVenda(no *inicio, char *cpfCliente, int codigoProduto)
{
  while (inicio != NULL)
  {
    // REVIEW - Juntar os 3 ifs em um são
    if (inicio->V != NULL && (strcmp(inicio->V->cpfCliente, cpfCliente) == 0 && inicio->V->codigoProduto == codigoProduto))
    {
      return inicio->V;
    }
    inicio = inicio->proximo;
  }
  printf("Venda com CPF %s e código %d não encontrada.\n", cpfCliente, codigoProduto);
  return NULL;
}

// ANCHOR - Funções para imprimir clientes, produtos e vendas
void imprimeClientes(no *inicio)
{
  while (inicio != NULL)
  {
    if (inicio->C != NULL)
    {
      printf("Nome: %s\n", inicio->C->nome);
      printf("CPF: %s\n", inicio->C->cpf);
      printf("Telefone: %d\n", inicio->C->telefone);
      printf("Data de nascimento: %d/%d/%d\n", inicio->C->dataNascimento.dd, inicio->C->dataNascimento.mm, inicio->C->dataNascimento.aaaa);
      printf("Endereço: %s\n", inicio->C->end.rua);
      printf("Número: %d\n", inicio->C->end.numero);
      printf("Bairro: %s\n", inicio->C->end.bairro);
      printf("Cidade: %s\n", inicio->C->end.cidade);
      printf("Estado: %s\n", inicio->C->end.estado);
      printf("\n");
    }
    inicio = inicio->proximo;
  }
}

void imprimeProdutos(no *inicio)
{
  while (inicio != NULL)
  {
    if (inicio->P != NULL)
    {
      printf("código: %d\n", inicio->P->codigo);
      printf("Descrição: %s\n", inicio->P->descricao);
      printf("Quantidade em estoque: %d\n", inicio->P->quantidadeEstoque);
      printf("Preço unitário: %.2f\n", inicio->P->precoUnitario);
      printf("\n");
    }
    inicio = inicio->proximo;
  }
}

void imprimeVendas(no *inicio)
{
  while (inicio != NULL)
  {
    if (inicio->V != NULL)
    {
      printf("CPF do cliente: %s\n", inicio->V->cpfCliente);
      printf("código do produto: %d\n", inicio->V->codigoProduto);
      printf("Quantidade comprada: %d\n", inicio->V->quantidadeComprada);
      printf("\n");
    }
    inicio = inicio->proximo;
  }
}

void mostraVendasAcimaEstoque(no *inicio, int quantidadeMinima)
{
  while (inicio != NULL)
  {
    if (inicio->V != NULL && inicio->V->quantidadeComprada > quantidadeMinima)
    {
      printf("CPF do cliente: %s\n", inicio->V->cpfCliente);
      printf("Código do produto: %d\n", inicio->V->codigoProduto);
      printf("Quantidade comprada: %d\n", inicio->V->quantidadeComprada);
      printf("\n");
    }
    inicio = inicio->proximo;
  }
}

void mostraProdutosAbaixoEstoque(no *inicio, int quantidadeMaxima)
{

  while (inicio != NULL)
  {
    if (inicio->P != NULL && inicio->P->quantidadeEstoque < quantidadeMaxima)
    {
      printf("Código: %d\n", inicio->P->codigo);
      printf("Descrição: %s\n", inicio->P->descricao);
      printf("Quantidade em estoque: %d\n", inicio->P->quantidadeEstoque);
      printf("Preço unitário: %.2f\n", inicio->P->precoUnitario);
      printf("\n");
    }
    inicio = inicio->proximo;
  }
}
//ANCHOR - Main
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
          no *novoCliente = (no *)malloc(sizeof(no));
          novoCliente->proximo = NULL;
          novoCliente->anterior = NULL;
          printf("Digite o nome do cliente: ");
          scanf("%s", novoCliente->C->nome);
          printf("Digite o CPF do cliente: ");
          scanf("%s", novoCliente->C->cpf);
          // NOTE - Verifica se o CPF já está cadastrado
          if ((buscaCliente(inicio, novoCliente->C->cpf)) != NULL)
          {
            printf("CPF já cadastrado.\n");
            free(novoCliente->C);
            free(novoCliente);
            break;
          }
          else
          {
            printf("\nNão existe copia do CPF no sistema, continue com os dados\n");
          }
          printf("Digite o endereço do cliente: ");
          printf("\nRua: ");
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
          scanf("%d", &novoCliente->C->telefone);
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

        case 2: // NOTE - Não deve aceitar códigos já cadastrados
          printf("\n=========INSERIR PRODUTO==========\n");
          produto *novoProduto = (produto *)malloc(sizeof(produto));
          printf("Digite o código do produto: ");
          scanf("%d", &novoProduto->codigo);
          if (buscaProduto(inicio, novoProduto->codigo) != NULL)
          {
            printf("Código já cadastrado.\n");
            free(novoProduto);
            break;
          }
          printf("Digite a descrição do produto: ");
          scanf("%s", novoProduto->descricao);
          printf("Digite a quantidade em estoque: ");
          scanf("%d", &novoProduto->quantidadeEstoque);
          printf("Digite o preço unitário: ");
          scanf("%f", &novoProduto->precoUnitario);
          novoProduto->anterior = NULL;
          novoProduto->proximo = NULL;
          insereProduto(&inicio, novoProduto);
          printf("Produto cadastrado com sucesso!\n");
          break;

        case 3: // NOTE - Não deve aceitar CPFs e códigos de produtos que não existam
          printf("\n=========INSERIR VENDA==========\n");
          venda *novaVenda = (venda *)malloc(sizeof(venda));
          printf("Digite o CPF do cliente: ");
          scanf("%s", novaVenda->cpfCliente);
          if (buscaCliente(inicio, novaVenda->cpfCliente) == NULL)
          {
            printf("CPF não cadastrado.\n");
            free(novaVenda);
            break;
          }
          printf("Digite o código do produto: ");
          scanf("%d", &novaVenda->codigoProduto);
          if (buscaProduto(inicio, novaVenda->codigoProduto) == NULL)
          {
            printf("Código de produto não cadastrado.\n");
            free(novaVenda);
            break;
          }
          printf("Digite a quantidade comprada: ");
          scanf("%d", &novaVenda->quantidadeComprada);
          if ((buscaProduto(inicio, novaVenda->codigoProduto))->quantidadeEstoque < novaVenda->quantidadeComprada)
          {
            printf("Quantidade em estoque insuficiente.\n");
            free(novaVenda);
            break;
          }
          novaVenda->anterior = NULL;
          novaVenda->proximo = NULL;
          insereVenda(&inicio, novaVenda->cpfCliente, novaVenda->codigoProduto, novaVenda->quantidadeComprada);
          (buscaProduto(inicio, novaVenda->codigoProduto))->quantidadeEstoque -= novaVenda->quantidadeComprada;
          printf("Venda cadastrada com sucesso!\n");
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
            cliente C;
            char nome[dados];
            int telefone;
            endereco end;
            Data dataNascimento;
            printf("\n=========ALTERAR CLIENTE==========\n");
            printf("\nDigite o CPF do cliente: ");
            scanf("%s", C.cpf);

            printf("Digite o novo nome do cliente: ");
            scanf("%s", nome);

            printf("Digite o novo telefone do cliente: ");
            scanf("%d", &telefone);

            printf("Digite o novo endereço do cliente (rua, bairro, cidade, estado, número): ");
            scanf("%s %s %s %s %d", end.rua, end.bairro, end.cidade, end.estado, &end.numero);

            printf("Digite a nova data de nascimento do cliente (dd, mm, aaaa): ");
            scanf("%d %d %d", &dataNascimento.dd, &dataNascimento.mm, &dataNascimento.aaaa);

            alteraCliente(&C, nome, telefone, end, dataNascimento);

            printf("\nDeseja alterar outro cliente? (1 - Sim / 0 - Não): ");
            scanf("%d", &opcaoCliente);
          } while (opcaoCliente != 0);
          break;

        case 2:
          do
          {
            produto P;
            int codigo, quantidadeEstoque;
            char descricao[dados];
            float precoUnitario;
            printf("\n=========ALTERAR PRODUTO==========\n");
            printf("\nDigite o código do produto: ");
            scanf("%d", &codigo);

            printf("Digite a nova quantidade em estoque do produto: ");
            scanf("%d", &quantidadeEstoque);

            printf("Digite a nova descrição do produto: ");
            scanf("%s", descricao);

            printf("Digite o novo preço unitário do produto: ");
            scanf("%f", &precoUnitario);

            alteraProduto(&P, codigo, quantidadeEstoque, descricao, precoUnitario);

            printf("\nDeseja alterar outro produto? (1 - Sim / 0 - Não): ");
            scanf("%d", &opcaoProduto);
          } while (opcaoProduto != 0);
          break;

        case 3:
          do
          {
            venda V;
            char cpfCliente[11];
            int codigoProduto, quantidadeComprada;
            printf("\n=========ALTERAR VENDA==========\n");
            printf("\nDigite o CPF do cliente: ");
            scanf("%s", cpfCliente);

            printf("Digite o código do produto: ");
            scanf("%d", &codigoProduto);

            printf("Digite a nova quantidade comprada: ");
            scanf("%d", &quantidadeComprada);

            alteraVenda(&V, cpfCliente, codigoProduto, quantidadeComprada);

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
            printf("\nDigite o CPF do cliente que deseja buscar: ");
            char cpfBusca[11];
            scanf("%s", cpfBusca);
            if ((buscaCliente(inicio, cpfBusca)) != NULL)
            {
              printf("\nCliente encontrado:\n");
              printf("CPF: %s\n", (buscaCliente(inicio, cpfBusca))->cpf);
              printf("Nome: %s\n", (buscaCliente(inicio, cpfBusca))->nome);
              // TODO - Colocar as outras informações do cliente
            }
            else
            {
              (buscaCliente(inicio, cpfBusca));
            }

            printf("\nDeseja buscar outro cliente? (1 - Sim / 0 - Não): ");
            scanf("%d", &opcaoCliente);
          } while (opcaoCliente != 0);
          break;

        case 2:
          do
          {
            printf("\nDigite o código do produto que deseja buscar: ");
            int codigoBusca;
            scanf("%d", &codigoBusca);
            if ((buscaProduto(inicio, codigoBusca)) != NULL)
            {
              printf("\nProduto encontrado:\n");
              printf("Código: %d\n", (buscaProduto(inicio, codigoBusca))->codigo);
              printf("Descrição: %s\n", (buscaProduto(inicio, codigoBusca))->descricao);
              printf("Preço unitário: %.2f\n", (buscaProduto(inicio, codigoBusca))->precoUnitario);
              printf("Quantidade em estoque: %d\n", (buscaProduto(inicio, codigoBusca))->quantidadeEstoque);
            }
            else
            {
              (buscaProduto(inicio, codigoBusca));
            }

            printf("\nDeseja buscar outro produto? (1 - Sim / 0 - Não): ");
            scanf("%d", &opcaoProduto);
          } while (opcaoProduto != 0);
          break;

        case 3:
          do
          {
            printf("\nDigite o CPF do cliente da venda: ");
            char cpfBusca[11];
            scanf("%s", cpfBusca);
            printf("Digite o código do produto da venda: ");
            int codigoBusca;
            scanf("%d", &codigoBusca);
            if ((buscaVenda(inicio, cpfBusca, codigoBusca)) != NULL)
            {
              printf("\nVenda encontrada:\n");
              printf("CPF do cliente: %s\n", (buscaVenda(inicio, cpfBusca, codigoBusca))->cpfCliente);
              printf("Código do produto: %d\n", (buscaVenda(inicio, cpfBusca, codigoBusca))->codigoProduto);
              printf("Quantidade comprada: %d\n", (buscaVenda(inicio, cpfBusca, codigoBusca))->quantidadeComprada);
              // TODO - Possível colocar o valor total da compra e o nome do cliente
            }

            printf("\nDeseja buscar outra venda? (1 - Sim / 0 - Não): ");
            scanf("%d", &opcaoVenda);
          } while (opcaoVenda != 0);
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
            printf("\nDigite o CPF do cliente que deseja remover: ");
            char cpfRemover[11];
            scanf("%s", cpfRemover);
            int possuiVendas;
            clientePossuiVendas(inicio, cpfRemover, &possuiVendas);
            if ((buscaCliente(inicio, cpfRemover)) != NULL && !possuiVendas)
            {
              removeCliente(&inicio, (buscaCliente(inicio, cpfRemover)));
              printf("\nCliente removido com sucesso!\n");
            }
            else
            {
              printf("\nNão foi possível remover o cliente pois ele possui vendas cadastradas.\n");
            }
            printf("\nDeseja remover outro cliente? (1 - Sim / 0 - Não): ");
            scanf("%d", &opcaoCliente);
          } while (opcaoCliente != 0);
          break;

        case 2: // NOTE - Não deve ser possível remover o produto se ele estiver em uma venda
          do
          {
            printf("\nDigite o código do produto que deseja remover: ");
            int codigoRemover;
            scanf("%d", &codigoRemover);
            produto *P = buscaProduto(inicio, codigoRemover);
            int emVenda;
            produtoEmVenda(inicio, codigoRemover, &emVenda);
            if (P != NULL && !emVenda)
            {
              removeProduto(&inicio, P);
              printf("\nProduto removido com sucesso!\n");
            }
            else
            {
              printf("\nNão foi possível remover o produto pois ele está cadastrado em uma venda.\n");
            }

            printf("\nDeseja remover outro produto? (1 - Sim / 0 - Não): ");
            scanf("%d", &opcaoProduto);
          } while (opcaoProduto != 0);
          break;

        case 3:
          do
          {
            printf("\nDigite o CPF do cliente da venda que deseja remover: ");
            char cpfVenda[11];
            scanf("%s", cpfVenda);
            printf("\nDigite o código do produto da venda que deseja remover: ");
            int codigoVenda;
            scanf("%d", &codigoVenda);
            venda *V = buscaVenda(inicio, cpfVenda, codigoVenda);
            if (V != NULL)
            {
              removeVenda(&inicio, V);
              printf("\nVenda removida com sucesso!\n");
            }
            else
            {
              printf("\nVenda não encontrada.\n");
            }

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
          printf("\n=========TODOS OS CLIENTE==========\n");
          imprimeClientes(inicio);
          break;

        case 2:
          printf("\n=========TODOS OS PRODUTOS==========\n");
          imprimeProdutos(inicio);
          break;

        case 3:
            printf("\n=========TODOS AS VENDAS==========\n");
            imprimeVendas(inicio);
          break;

        case 4:
          do
          {
            printf("\n=========TODOS AS COMPRAS ACIMA DE UM DETERMINADO VALOR==========\n");
            printf("Informe a quantidade mínima de estoque: ");
            int quantidadeMinima;
            scanf("%d", &quantidadeMinima);

            mostraVendasAcimaEstoque(inicio, quantidadeMinima);

            printf("\n Deseja ver compras acima de outra quantidade de estoque? (1 - Sim / 0 - Não): ");
            scanf("%d", &opcaoMostrar);
          } while (opcaoMostrar != 0);
          break;

        case 5:
          do
          {
            printf("\n=========TODOS OS PRODUTOS ABAIXO DE UM DETERMINADO ESTOQUE==========\n");
            printf("Informe a quantidade máxima de estoque: ");
            int quantidadeMaxima;
            scanf("%d", &quantidadeMaxima);
            mostraProdutosAbaixoEstoque(inicio, quantidadeMaxima);

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