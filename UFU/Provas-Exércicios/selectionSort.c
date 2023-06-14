#include <stdio.h>
#include <stdlib.h>

#define tamanhoDoVetor 10
int main(){

  double notas[tamanhoDoVetor] = {4.5, 7.0, 8.5, 9.0, 6.5, 5.0, 7.0, 8.0, 9.5, 10.0};
  double aux;

  // ANCHOR - Selection Sort
  for (int i = 0; i < tamanhoDoVetor; i++){//NOTE - Percorre o vetor até a penúltima posição

    for (int j = i + 1; j < tamanhoDoVetor; j++){//NOTE - Percorre o vetor a partir da posição seguinte a i

      if (notas[i] > notas[j]){//NOTE - Se o valor de i for maior que o valor de j, troca os valores

        aux = notas[i];//NOTE - Armazena o valor de i em uma variável auxiliar

        notas[i] = notas[j];//NOTE - Armazena o valor de j em i

        notas[j] = aux;//NOTE - Armazena o valor de i (armazenado na variável auxiliar) em j
      }
    }
  }
  for (int i = 0; i < tamanhoDoVetor; i++)
  {
    printf("| %.1lf |", notas[i]);
  }
  return 0;
}
