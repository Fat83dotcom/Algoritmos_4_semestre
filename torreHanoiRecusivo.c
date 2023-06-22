#include <stdio.h>

void moverDiscos(int qD, char origem, char destino, char aux) {
    if (qD == 1) {
        printf("Mover disco %d de %c para %c ...\n", qD, origem, destino);
    }
    else {
        moverDiscos(qD - 1, origem, aux, destino);
        printf("Mover disco %d de %c para %c ...\n", qD, origem, destino);
        moverDiscos(qD - 1, aux, destino, origem);
    }
}

int main(int argc, char const *argv[]) {
    
    int qtdDiscos = 64;
    moverDiscos(qtdDiscos, 'A', 'C', 'B');
    return 0;
}
