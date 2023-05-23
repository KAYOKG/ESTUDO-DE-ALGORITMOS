#include <stdio.h>
#include <stdlib.h>

int main(){
    int cod[5], num[5], num_acidentes[5], media=0, media_acidentes=0, cidades=0, maior_cidade, menor_cidade;

    for(int i=0; i<5; i++){
        printf("\nInforme o codigo da cidade %d: ", i+1);
        scanf("%d", &cod[i]);
        printf("Informe o numero de veiculos de passeio: ");
        scanf("%d", &num[i]);
        printf("Informe o numero de acidentes de transito com vitimas: ");
        scanf("%d", &num_acidentes[i]);
        media += num[i];

        if(num[i] <2000){
            media_acidentes += num_acidentes[i];
            cidades++;
        }
    }
    
    float media_veiculos = (float) media/5;
    media_acidentes = (float) media_acidentes/cidades;
    int maior_indice = num_acidentes[0];
    int menor_indice = num_acidentes[0];

    for(int i=0; i<5; i++){
        if(maior_indice < num_acidentes[i]){
            maior_indice = num_acidentes[i];
            maior_cidade = cod[i];
        }else{
            menor_indice = num_acidentes[i];
            menor_cidade = cod[i];
        }
    }

    printf("\nA cidade %d possui o maior indice -> %d", maior_cidade, maior_indice);
    printf("\nA cidade %d possui o menor indice -> %d", menor_cidade, menor_indice);
    printf("\nA media de veiculos nas 5 cidades juntas -> %.2f", media_veiculos);
    printf("\nA media de acidentes de transito nas cidades -> %d", media_acidentes);

    return 0;
}