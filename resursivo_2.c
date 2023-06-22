#include <stdio.h>

long int potenciaBase2(int expoente){
    static long int n = 1;
    n *= 2;
    if (expoente == 1){
        return n;
    }
    return potenciaBase2(expoente - 1);
}

int main(int argc, char const *argv[]){
    long int resutado;

    resutado = potenciaBase2(10);
    printf("%ld\n", resutado);

    return 0;
}
