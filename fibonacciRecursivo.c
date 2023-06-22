#include <stdio.h>

int fibonacci(int n){
    if (n == 1 || n == 2){
        return 1;
    }
    else{
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

int main(int argc, char const *argv[]) {
    int resultado;

    resultado = fibonacci(7);

    printf("%d\n", resultado);
    
    return 0;
}
