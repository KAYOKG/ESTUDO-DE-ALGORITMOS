#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <stdbool.h>

#define quantidade 10
#define placa 4

typedef struct {
    char carro[placa];
} Carro;

typedef struct {
    int entrada;
    char vagas[quantidade][placa];
} Estacionamento;

void trataDados(char *entradaValor){
    if (*entradaValor == 'c'){
        *entradaValor = 'C';
    } else if (*entradaValor == 'p') {
        *entradaValor = 'P';
    }
}

int estacionamentoCheio(Estacionamento* e) {
    if (e->entrada == quantidade - 1) {
        printf("\nEstacionamento cheio, carro vai para a fila de espera");
        return 1;
    } else {
        return 0;
    }
}

void empilha(Estacionamento* e, char* valor) {
    if (e->entrada == quantidade - 1) {
        printf("\nEstacionamento cheio!\n");
        return;
    }
    e->entrada++;
    strcpy(e->vagas[e->entrada], valor);
    printf_s("\nCarro %s estacionado", valor);
}

void desempilha(Estacionamento *e) {
    if (e->entrada == -1) {
        printf("\nEstacionamento vazio!\n");
        return;
    }
    printf("\nCarro %s saiu do estacionamento",
    e->vagas[e->entrada]);
    e->entrada--;
}

void entraFilaEspera(bool *entradaPermitida) {
  if (*entradaPermitida == false) {
      printf("\nEntrada de carro não permitida");
  }
  else{
      printf("\nCarro entrou na fila de espera");
      *entradaPermitida = false;
  }
}

void imprimeSituacao(Estacionamento *e) {
    printf("\n\n========Situação final do estacionamento========\n");
    for (int i = e->entrada; i >= 0; i--){
        printf("Placa: %s\n", e->vagas[i]);
    }
}

int main(){
    setlocale(LC_ALL, "Portuguese_Brazil");
    Estacionamento e;
    Carro c;
    char entradaValor;
    char carroNaEspera = '\0'; //armazena a placa do carro na fila de espera
    bool entradaPermitida = true; // verificação se a entrada do carro é permitida
    int movimentos = 0;

    e.entrada = -1;

    printf("\nInforme C(chegada) | 0(Sair): ");
    scanf_s(" %c", &entradaValor);
    trataDados(&entradaValor);

    while(entradaValor != '0'){
      switch(entradaValor){
        case 'C':
          printf("\nChegada de carro");
          printf("\nInforme a placa do carro (XXX): ");
          scanf("%3s", &c.carro);

          if(estacionamentoCheio(&e) == 1){
            printf("\nEstacionamento cheio, o carro %s está na fila de espera", c.carro);
            carroNaEspera = c.carro;
            entraFilaEspera(&entradaPermitida);
            entradaPermitida = false;
            movimentos++;
          }
          else{
            printf("\nEstacionamento disponível");
            movimentos++;
            if(entradaPermitida == false){ //Se a entrada do carro estiver permitida ele entra no estacionamento
              empilha(&e, &carroNaEspera);
              carroNaEspera = '\0';
              entradaPermitida = true;
            }
            else{ //Se a entrada do carro não estiver permitida ele entra no estacionamento
              empilha(&e, c.carro);
            }
          }
          break;

        case 'P':
          printf("\nPartida de carro");
          desempilha(&e);
          if (e.entrada >= 0) {
              printf("Carro deslocado %d vezes\n", movimentos);
          } else {
              printf("Carro deslocado 0 vezes\n");
          }
          movimentos = 0;
          break;

        case '0':
          imprimeSituacao(&e);
          break;

        default:
          printf("\nOpção inválida!\n");
          break;
      }

      printf("\nInforme C(chegada) | P(partida) | 0(Sair): ");
      scanf_s(" %c", &entradaValor);
      trataDados(&entradaValor);
    }

    return 0;
}
