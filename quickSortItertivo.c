#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int quickSort(int *a, int p, int r) {
    int t;
    if (p < r) {
        int v = (rand() % (r - p)) + p;
        int pivo = a[v];
        a[v] = a[r];
        a[r] = pivo;
        int i = p - 1;
        int j = r;
        do {
            do {
                i++;
            } while (a[i] < pivo);
            do {
                j --;
            } while ((a[j] > pivo) && (j > p));
            if (i < j){
                t = a[i];
                a[i] = a[j];
                a[j] = t;
            }
        } while (i < j);
        a[r] = a[i];
        a[i] = pivo;
        quickSort(a, p, i - 1);
        quickSort(a, i + 1, r);
    }
    return 0;
}

int main(int argc, char const *argv[]) {
    srand((unsigned)time(NULL));
    int *vet;
    int vetSize = 3;
    int startQuickSort = 0, endQuickSort = (vetSize - 1);
    vet = malloc(vetSize * sizeof(int));
    for (int i = 0; i < vetSize; i++) {
        vet[i] = rand() % 100;
    }
    clock_t startClock, endClock;
    float diff;
    startClock = clock();
    quickSort(vet, startQuickSort, endQuickSort);
    endClock =  clock();
    diff = (((float)endClock - (float)startClock) / 1000000.0F);
    printf("A execução do QuickSort durou %f segundos.\n", diff);
    for (int i = 0; i < vetSize; i++) {
        printf("%ld\n", vet[i]);
    }
    free(vet);
    return 0;
}
