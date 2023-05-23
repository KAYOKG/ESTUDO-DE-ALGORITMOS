#include <stdio.h>
#include <stdlib.h>

int contaVogal(char vogal){
  switch(vogal){
    case 'a':
    case 'A':
    case 'e':
    case 'E':
    case 'i':
    case 'I':
    case 'o':
    case 'O':
    case 'u':
    case 'U':
      return 1;
      break;
    default:
      return 0;
  }
}

int contaVogais(char *nome){
  int cont = 0;
  for(int i=0; nome[i] != '\0'; i++){
    if(contaVogal(nome[i])){
      cont++;
    }
  }
  return cont;
}

void verificaNome(char *nome, int *valorVogal){
  *valorVogal = contaVogais(nome);
}

int main(){
  char nome1[50], nome2[50];

  printf("Informe o primeiro nome: ");
  scanf("%s", nome1);
  printf("Informe o segundoo nome: ");
  scanf("%s", nome2);

  int valorVogal1, valorVogal2;

  verificaNome(nome1, &valorVogal1);
  verificaNome(nome2, &valorVogal2);

  printf("O primeiro nome possui %d vogais e o segundo nome possui %d vogais", valorVogal1, valorVogal2);

  return 0;
}