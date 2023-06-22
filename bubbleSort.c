#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bubbleSort(int *vet, unsigned long sizeVet) {
    int aux;
    unsigned long i, j, sum = 0, betterCondiction = 1;
    for ( i = 0; i < sizeVet; i++) {
        sum ++;
        for ( j = 0; j < sizeVet - betterCondiction; j++) {
            sum++;
            if (vet[j] > vet[j + 1] ) {
                aux = vet[j + 1];
                vet[j + 1] = vet[j];
                vet[j] = aux;
            }
        }
        // betterCondiction++;
    }
    printf("\n\nQuantidade de vezes que os laços foram executados: %ld\n", sum);
}

int binarySearch(int *vet, int wanted, int arraySize, int *turnsIter) {
    int low, high, kick, half;
    low = 0;
    high = arraySize - 1;
    while (low <= high){
        *turnsIter = *turnsIter + 1;
        half = (low + high) / 2;
        kick = vet[half];
        if (kick == wanted){
            return half;
        }
        if (kick > wanted){
            high = half - 1;
        }
        else{
            low = half + 1;
        }
    }
    return -1;
}

int sequenceSearch(int *vet, int wanted, int arraySize, int *turnsIter){
    for (int i = 0; i < arraySize; i++) {
        if (wanted == vet[i]) {
            return i;
        }
        *turnsIter = *turnsIter + 1;
    }
    return -1;
}

int main(int argc, char const *argv[]) {
    srand((unsigned)time(NULL));
    clock_t start, end;
    unsigned long vetSize = 100000;
    int *vet, seekNumber = 908, turnsIter = 0, *pTIter = &turnsIter;
    vet = malloc(vetSize * sizeof(int));
    for (unsigned long i = 0; i < vetSize; i++) {
        vet[i] = rand() % 1000;
    }

    start = clock();
    bubbleSort(vet, vetSize);
    end = clock();
    float diff = (((float)end - (float)start) / 1000000.0F);
    printf("\nA execução bubblesort durou: %f segundos\n", diff);

    start = clock();
    int positionNumber = binarySearch(vet, seekNumber, vetSize, pTIter);
    end =  clock();
    diff = (((float)end - (float)start) / 1000000.0F);
    printf("\nA execução busca binaria durou: %f segundos\n", diff);
    printf("Posição do número no array: %d\n Número: %d\n", positionNumber, vet[positionNumber]);
    printf("Número de iterções do laço: %d\n", turnsIter);

    start = clock();
    positionNumber = sequenceSearch(vet, seekNumber, vetSize, pTIter);
    end =  clock();
    diff = (((float)end - (float)start) / 1000000.0F);
    printf("\nA execução busca sequencial durou: %f segundos\n", diff);
    printf("Posição do número no array: %d\n Número: %d\n", positionNumber, vet[positionNumber]);
    printf("Número de iterções do laço: %d\n", (turnsIter + 1));
    printf("\nVetor ordenado:\n");
    // for (unsigned long i = 0; i < vetSize; i++) {
    //     printf("%d, ", vet[i]);
    // }
    free(vet);
    
    return 0;
}
