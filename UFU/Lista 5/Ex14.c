#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

void duplica(char *palavrinhas){
  char palavrinhasDuplicadas[90] = "";
  char *palavrinha = strtok(palavrinhas, " ");
  while(palavrinha != NULL){
    strcat(palavrinhasDuplicadas, palavrinha);
    strcat(palavrinhasDuplicadas, " ");
    strcat(palavrinhasDuplicadas, palavrinha);
    strcat(palavrinhasDuplicadas, " ");
    palavrinha = strtok(NULL, " ");
  }
  printf("%s", palavrinhasDuplicadas);

}

int main(){
  setlocale(LC_ALL, "Portuguese_Brazil");

  printf("Informe uma palavra ou frase que ira ser duplicada:\n");
  //scanf("%s", palavrinhas);
  char palavrinhas[90] = "O rato roeu a roupa do rei de roma";
  printf("%s", palavrinhas);
  printf("\n");

  duplica(palavrinhas);


  return 0;
}