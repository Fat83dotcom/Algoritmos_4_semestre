#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int geradorAleatorio(int tipo) {
  if (tipo == 0){
    return rand() % 50;
  }
  if (tipo == 1){
    return rand() % 50;
  }
  if (tipo == 2){
    return rand() % 150 + 900; 
  }
  if (tipo == 3){
    return rand() % 100 + 1;
  }
  return -1;
}

int main(int argc, char const *argv[]) {
    srand(time(NULL));
    for (int i = 0; i < 10; i++) {
        printf("Zero: %d\n", geradorAleatorio(0));
        printf("Um: %d\n", geradorAleatorio(1));
        printf("Dois: %d\n", geradorAleatorio(2));
        printf("Três: %d\n", geradorAleatorio(3));
    }
    
    
    return 0;
}
