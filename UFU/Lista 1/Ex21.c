#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define MAX 100

int main() {
    setlocale(LC_ALL, "Portuguese_Brazil");
    int vetor[MAX];
    int tamanho_atual, valor, posicao_remover;

    printf("Informe o tamanho atual do vetor (no máximo 100): ");
    scanf("%d", &tamanho_atual);

    for(int i = 0; i < tamanho_atual; i++) {
        printf("Informe o valor da posição %d do vetor: ", i);
        scanf("%d", &vetor[i]);
    }

    printf("Informe o valor a ser apagado: ");
    scanf("%d", &valor);

    // Busca o valor no vetor e guarda a posição
    for(int i = 0; i < tamanho_atual; i++) {
        if(vetor[i] == valor) {
            posicao_remover = i;
            break;
        }
    }

    // Remove o valor e ajusta a posição dos outros elementos
    for(int i = posicao_remover; i < tamanho_atual - 1; i++) {
        vetor[i] = vetor[i + 1];
    }

    // Diminui o tamanho atual do vetor pois um elemento foi removido
    tamanho_atual--;

    // Imprime o vetor após a remoção
    printf("Vetor após a remoção do valor:\n");
    for(int i = 0; i < tamanho_atual; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");

    return 0;
}