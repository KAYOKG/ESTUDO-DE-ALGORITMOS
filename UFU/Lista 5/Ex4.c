#include <stdio.h>
#include <stdlib.h>

void primeiraUltimaIguais(int N, char matriz[N][50], int *cont, int vetor[N]){ // funcao que verifica se a primeira e a ultima letra sao iguais
  for(int i = 0; i < N; i++){ // percorre a matriz linha por linha
    if(matriz[i][0] == matriz[i][strlen(matriz[i])-1]){ // se a primeira letra da linha for igual a ultima
      vetor[*cont] = i; // armazena a linha em que a primeira e a ultima letra sao iguais
      (*cont)++; // incrementa o contador
    }
  }
}

int main(){
  int N;

  printf("Digite a quantidade de palavras: ");
  scanf("%d", &N); // le a quantidade de palavras

  char matriz[N][50]; // matriz que armazena as palavras
  for(int i = 0; i < N; i++){ // percorre a matriz linha por linha
    printf("Digite a palavra %d: ", i+1);
    scanf("%s", &matriz[i]); // le as palavras
  }

  int cont = 0; // contador que armazena a quantidade de palavras que a primeira e a ultima letra sao iguais
  int vetor[N]; // vetor que armazena as linhas que a primeira e a ultima letra sao iguais

  primeiraUltimaIguais(N, matriz, &cont, vetor); // chama a funcao que verifica se a primeira e a ultima letra sao iguais

  printf("Palavras que a primeira e a ultima letra sao iguais: ");
  for(int i = 0; i < cont; i++){ // percorre o vetor que armazena as linhas que a primeira e a ultima letra sao iguais
    printf("%s ", matriz[vetor[i]]); // imprime as palavras que a primeira e a ultima letra sao iguais
  }

  return 0;
}