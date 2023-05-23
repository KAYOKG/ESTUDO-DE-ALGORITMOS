#include <stdio.h>
#include <stdlib.h>

int main(){
    int I, A, B, C, maior, meio, menor;

    while(I != 1 && I != 2 && I != 3){
        printf("Informe o valor de I(1, 2 ou 3) e logo em seguida A, B e C\n");
        scanf("%d", &I);
    }
    scanf("%d", &A);
    scanf("%d", &B);
    scanf("%d", &C);
    
    // while(A != int && B != int && C != int){
    // scanf("%d", &A);
    // scanf("%d", &B);
    // scanf("%d", &C);
    // }

    if(A < B && A < C){
        menor = A;
    }else if(A > B && A > C){
        maior = A;
    }else{
        meio = A;
    }

    if(B < A && B < C){
        menor = B;
    }else if(B > A && B > C){
        maior = B;
    }else{
        meio = B;
    }

    if(C < B && C < A){
        menor = C;
    }else if(C > B && C > A){
        maior = C;
    }else{
        meio = C;
    }

    switch(I){
        case 1:
            printf(" Os seguintes valores dados em ordem crescente %d %d %d", menor, meio, maior);
            break;
        case 2:
            printf(" Os seguintes valores dados em ordem crescente %d %d %d", maior, meio, menor);
            break;
        case 3:
            printf(" Os seguintes valores dados em ordem crescente %d %d %d", menor, maior, meio);
            break;
    }

    return 0;
}