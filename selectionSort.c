#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void selectionSort(int *vetor, int tamanhoVetor){
    int i,j,aux, minimo, posMinimo;
    for (i=0; i < tamanhoVetor - 1; i++) {
        minimo = vetor[i];
        posMinimo = i;
        for (j = i + 1; j < tamanhoVetor; j++) {
            if (minimo > vetor[j]) {
                minimo = vetor[j];
                posMinimo = j;
            }
        }
        if (posMinimo != i) {
            aux = vetor[posMinimo];
            vetor[posMinimo] = vetor[i];
            vetor[i] = aux;
        }
    }
}

int main(int argc, char const *argv[]) {
    
    const int tamanhoVetor = 5;
    int vetor[tamanhoVetor];
    srand(time(NULL));

    for (int i = 0; i < tamanhoVetor; i++){
        vetor[i] = rand() % 100;
    }
    
    selectionSort(vetor, tamanhoVetor);

    for (int i = 0; i < tamanhoVetor; i++){
        printf("%d\n", vetor[i]);
    }
    return 0;
}
