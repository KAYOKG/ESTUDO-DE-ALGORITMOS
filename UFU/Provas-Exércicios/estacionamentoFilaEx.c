#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <stdbool.h>

#define quantidade 10
#define placa 4

//SECTION - Structs
typedef struct{ //NOTE - Características do carro
  char carro[placa];
} Carro;

typedef struct{ //NOTE - Características do estacionamento(Fila)
  int inicio;
  int fim;
  char vagas[quantidade][placa];
} Estacionamento;
//!SECTION - Fim das structs

//SECTION - Funções
void trataDados(char *entradaValor){  //NOTE - Trata os dados de entrada
  if (*entradaValor == 'c'){
    *entradaValor = 'C';
  }
  else if (*entradaValor == 'p'){
    *entradaValor = 'P';
  }
}

int estacionamentoCheio(Estacionamento *e){ //NOTE - Verifica se o estacionamento está cheio
  if ((e->fim + 1) % quantidade == e->inicio){
    printf("\nEstacionamento cheio, carro vai para a fila de espera");
    return 1;
  }
  else{
    return 0;
  }
}

void enfileira(Estacionamento *e, char *valor){ //NOTE - Enfileira o carro no estacionamento
  if ((e->fim + 1) % quantidade == e->inicio){
    printf("\nEstacionamento cheio!\n");
    return;
  }
  strcpy(e->vagas[e->fim], valor);
  e->fim = (e->fim + 1) % quantidade;
  printf_s("\nCarro %s estacionado", valor);
}

void desenfileira(Estacionamento *e){ //NOTE - Desenfileira o carro do estacionamento
  if (e->inicio == e->fim){
    printf("\nEstacionamento vazio!\n");
    return;
  }
  printf("\nCarro %s saiu do estacionamento",
    e->vagas[e->inicio]);
  e->inicio = (e->inicio + 1) % quantidade;
}

void entraFilaEspera(bool *entradaPermitida){ //NOTE - Entra na fila de espera
  if (*entradaPermitida == false){
    printf("\nEntrada de carro não permitida");
  }
  else{
    printf("\nCarro entrou na fila de espera");
    *entradaPermitida = false;
  }
}
//!SECTION - Fim das funções

//SECTION - Main
int main(){
  setlocale(LC_ALL, "Portuguese_Brazil");
  Estacionamento e;
  Carro c;
  char entradaValor;
  char carroNaEspera = '\0';
  bool entradaPermitida = true;
  int movimentos = 0;

  e.inicio = 0;
  e.fim = 0;

  printf("\nInforme C - (chegada) | 0 - (Sair): ");
  scanf_s(" %c", &entradaValor);
  trataDados(&entradaValor);

  while (entradaValor != '0'){
    switch (entradaValor){
    case 'C':
      printf("\nChegada de carro");
      printf("\nInforme a placa do carro (XXX): ");
      scanf("%3s", &c.carro);

      if (estacionamentoCheio(&e) == 1){
        printf("\nEstacionamento cheio, o carro %s está na fila de espera", c.carro);
        carroNaEspera = c.carro;
        entraFilaEspera(&entradaPermitida);
        entradaPermitida = false;
        movimentos++;
      }
      else{
        printf("\nEstacionamento disponível");
        movimentos++;
        if (entradaPermitida == false){
          enfileira(&e, &carroNaEspera);
          carroNaEspera = '\0';
          entradaPermitida = true;
        }
        else{
          enfileira(&e, c.carro);
        }
      }
      break;

    case 'P':
      printf("\nPartida de carro");
      desenfileira(&e);
      if (e.inicio != e.fim){
        printf("\nVeiculo(s) deslocado(s) %d vez(es)\n", movimentos);
      }
      else{
        printf("\nVeiculo(s) deslocado(s) 0 vez(es)\n");
      }
      movimentos = 0;
      break;

    case '0':
      break;

    default:
      printf("\nOpção Invalida\n");
      break;
    }

    printf("\nInforme C(chegada) | P(partida) | 0(Sair): ");
    scanf_s(" %c", &entradaValor);
    trataDados(&entradaValor);
  }

  return 0;
}
