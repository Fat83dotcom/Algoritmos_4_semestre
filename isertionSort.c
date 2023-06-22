#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void insertionSort(int *vetor, int tamanhoVetor){
    int i, j, chave;
    for ( j = 1; j < tamanhoVetor; j++){
        chave = vetor[j];
        i = j - 1;
        while (i >= 0 && vetor[i] > chave){
            vetor[i + 1] = vetor[i];
            i--;
        }
        vetor[i + 1] = chave;
    }
}

int main(int argc, char const *argv[]){
    const int tamanhoVetor = 100000;
    int vetor[tamanhoVetor];
    srand(time(NULL));

    for (int i = 0; i < tamanhoVetor; i++){
        vetor[i] = rand() % 100000;
    }
    
    insertionSort(vetor, tamanhoVetor);

    for (int i = 0; i < tamanhoVetor; i++){
        printf("%d\n", vetor[i]);
    }
    
    return 0;
}
