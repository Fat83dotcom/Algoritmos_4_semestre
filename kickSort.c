#include <stdlib.h>
#include <stdio.h>
#include <time.h>

unsigned long partition(unsigned long *vector, unsigned long start, unsigned long end);

void quickSort(unsigned long *vector, unsigned long start, unsigned long end){
    unsigned long pivot;
    if (end > start) {
        pivot = partition(vector, start, end);
        quickSort(vector, start, pivot - 1);
        quickSort(vector, pivot + 1, end);
    }
}

unsigned long partition(unsigned long *vector, unsigned long start, unsigned long end) {
    unsigned long left, right, pivot, aux;
    left = start;
    right = end;
    pivot = vector[start];
    while (left < right) {
        while (vector[left] <= pivot) {
            left++;
        }
        while (vector[right] > pivot) {
            right--;
        }
        if (left < right) {
            aux = vector[left];
            vector[left] = vector[right];
            vector[right] = aux;
        }
    }
    vector[start] = vector[right];
    vector[right] = pivot;
    return right;
}

int main(int argc, char const *argv[]) {
    srand((unsigned)time(NULL));
    unsigned long *vet;
    unsigned long vetSize = 500000;
    unsigned long startQuickSort = 0, endQuickSort = (vetSize - 1);
    vet = malloc(vetSize * sizeof(unsigned long));
    for (unsigned long i = 0; i < vetSize; i++) {
        vet[i] = rand() % 100;
    }
    clock_t startClock, endClock;
    float diff;
    startClock = clock();
    quickSort(vet, startQuickSort, endQuickSort);
    endClock =  clock();
    diff = (((float)endClock - (float)startClock) / 1000000.0F);
    printf("A execução do QuickSort durou %f segundos.\n", diff);
    // for (unsigned long i = 0; i < vetSize; i++) {
    //     printf("%ld\n", vet[i]);
    // }
    free(vet);
    return 0;
}
