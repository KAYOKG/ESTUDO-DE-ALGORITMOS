#include <stdio.h> //Biblioteca padrão de entrada e saída
#include <stdlib.h> //Biblioteca padrão de funções de sistema
#include <locale.h> //Biblioteca para configurações de localidade

int vailidaData(int *dd, int *mm, int *aa){ //Função para validar a data
  if(*dd > 31 || *dd < 1){ //Verifica se o dia é maior que 31 ou menor que 1
    return 0; //Retorna 0 para indicar que a data é inválida
  }else if(*mm > 12 || *mm < 1){ //Verifica se o mês é maior que 12 ou menor que 1
    return 0; //Retorna 0 para indicar que a data é inválida
  }else if(*aa < 0){ //Verifica se o ano é menor que 0
    return 0; //Retorna 0 para indicar que a data é inválida
  }
  return 1; //Retorna 1 para indicar que a data é válida
}

void  dataFormatada(int *dd, int *mm, int *aa){ //Função para formatar a data
  char *mes[12] = {"Janeiro", "Fevereiro", "Março", "Abril", "Maio", "Junho", "Julho", "Agosto", "Setembro", "Outubro", "Novembro", "Dezembro"}; //Array com os meses do ano
  printf("%d de %s de %d", *dd, mes[*mm-1], *aa); //Imprime a data formatada
}

int main(){ //Função principal
  int dd, mm, aa; //Declaração de variáveis

  printf("Informe o dia, mes e ano"); //Imprime a mensagem na tela
  printf("\nDia: "); //Imprime a mensagem na tela
  scanf("%d", &dd); // le o dia
  printf("\nMes: "); //Imprime a mensagem na tela
  scanf("%d", &mm); // le o mes
  printf("\nAno: "); //Imprime a mensagem na tela
  scanf("%d", &aa); // le o ano

  if(vailidaData(&dd, &mm, &aa)){ //Chama a função para validar a data
    printf("\nData formatada:"); //Imprime a mensagem na tela
    dataFormatada(&dd, &mm, &aa); //Chama a função para formatar a data
  }else printf("\nData Invalida, informe o dia(31 dias), mes(12 meses) e ano"); //Imprime a mensagem na tela

  return 0;
}