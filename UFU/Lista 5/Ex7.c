#include <stdio.h>
#include <stdlib.h>

void vetor(int vec[], int tam, int min, int max, int *tamanho_total, int *maior_valor, int *menor_valor); // funcao que gera um vetor aleatorio
int main(){
  int tam, min, max;

  printf("Informe o tamanho do vetor: ");
  scanf("%d", &tam); // le o tamanho do vetor
  printf("\nInform o valor minimo que ira aleatorizar o vetor: ");
  scanf("%d", &min); // le o valor minimo que ira aleatorizar o vetor
  printf("\nInform o valor maximo que ira aleatorizar o vetor: ");
  scanf("%d", &max); // le o valor maximo que ira aleatorizar o vetor

  int vec[tam], tamanho_total=0, maior_valor=0, menor_valor=vec[0]; // vetor que armazena os numeros aleatorios, tamanho total do vetor, maior valor do vetor e menor valor do vetor

  vetor(vec, tam, min, max, &tamanho_total, &maior_valor, &menor_valor); // chama a funcao que gera um vetor aleatorio

  printf("\nVetor gerado: ");
  for(int i=0; i<tam; i++){
    printf("%d ", vec[i]);
  }
  printf("\nTamanho total do vetor: %d | Maior valor: %d | Menor valor: %d", tamanho_total, maior_valor, menor_valor);

  return 0;
}
void vetor(int vec[], int tam, int min, int max, int *tamanho_total, int *maior_valor, int *menor_valor){
  srand(time(NULL)); // serve pra iniciar um gerador de numeros aleatorios

  for(int i=0; i< tam; i++){
    vec[i] = (rand() % (max - min + 1)) + min; // vai gerar numeros entre min e o max

    if(vec[i] > *maior_valor){ // se o valor do vetor na posicao i for maior que o maior valor
      *maior_valor = vec[i]; // o maior valor recebe o valor do vetor na posicao i
    }

    if(vec[i] < *menor_valor){ // se o valor do vetor na posicao i for menor que o menor valor
      *menor_valor = vec[i]; // o menor valor recebe o valor do vetor na posicao i
    }

    (*tamanho_total)++; // incrementa o tamanho total
  }
}