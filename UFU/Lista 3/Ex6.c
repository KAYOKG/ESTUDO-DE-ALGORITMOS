#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>

int contaPalavras(char* string);

int main(){
    setlocale(LC_ALL, "Portuguese_Brazil");
    char string[100];

    printf("Digite uma frase: ");
    scanf("%[^\n]", string);

    printf("A quantidade de palavras é: %d\n", contaPalavras(string));

    return 0;
}

int contaPalavras(char* string){
    int qtdPalavras = 0;
    int i = 0;

    while(string[i] != '\0'){
        if(!isspace(string[i]) && isspace(string[i+1])){
            qtdPalavras++;
        }
        i++;
    }

    return qtdPalavras+1;
}