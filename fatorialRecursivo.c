#include <stdio.h>

int fatorial(int n){
    if (n == 1){
        return 1;
    }
    else{
        return n * fatorial(n - 1);
    }
}

int main(int argc, char const *argv[]){
    int resultado;

    resultado = fatorial(6);
    printf("%d\n", resultado);

    return 0;
}
