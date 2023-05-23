#include <stdio.h>
#include <stdlib.h>

void main(void){
  int a = 25;
  int *pa = &a;
  int b = *pa + a;
  printf("%d %d %d %d %d %d\n", a, pa, &a, *pa, b, &b);
}
