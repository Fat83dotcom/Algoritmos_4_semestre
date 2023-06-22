#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <string.h>
#include "sortAlgorithms.h"

typedef void (*ExecuterRecursiveSorts)(unsigned long*, unsigned long, unsigned long);
typedef unsigned long (*ExecuterSearch)(unsigned long*, unsigned long, unsigned long, unsigned long*);
typedef void (*ExecuterSimpleSorts)(unsigned long*, unsigned long);
typedef unsigned long (*ExecuterRecursiveSearch)(unsigned long*, unsigned long, unsigned long, unsigned long, unsigned long*);

void executorRecursiveSearch(
    unsigned long *vector,
    unsigned long start,
    unsigned long end,
    unsigned long seekNumber,
    unsigned long *pTIter,
    ExecuterRecursiveSearch execution,
    char* nameFunc
) {
    clock_t startClock, endClock;
    float diff;
    unsigned long positionNumber;
    startClock = clock();
    positionNumber = execution(vector, start, end, seekNumber, pTIter);
    endClock =  clock();
    diff = (((float)endClock - (float)startClock) / 1000000.0F);
    printf("\nA execução %s durou: %f segundos\n", nameFunc, diff);
    printf("Número de iterções do laço: %ld\n", *pTIter);
    printf("Número Procurado: %ld\n", seekNumber);
    (seekNumber == *(vector + positionNumber)) ? printf(
        "Posição do número no array: %ld\n Número: %ld\n", positionNumber, *(vector + positionNumber)
    ) : printf("Número não encontrado!\n");
}

void executorSearch(
    unsigned long *vector,
    unsigned long seekNumber,
    unsigned long vetSize,
    unsigned long *pTIter,
    ExecuterSearch execution,
    char* nameFunc
) {
    clock_t startClock, endClock;
    float diff;
    unsigned long positionNumber;
    startClock = clock();
    positionNumber = execution(vector, seekNumber, vetSize, pTIter);
    endClock =  clock();
    diff = (((float)endClock - (float)startClock) / 1000000.0F);
    printf("\nA execução %s durou: %f segundos\n", nameFunc, diff);
    printf("Número de iterções do laço: %ld\n", *pTIter);
    printf("Número Procurado: %ld\n", seekNumber);
    (seekNumber == *(vector + positionNumber)) ? printf(
        "Posição do número no array: %ld\n Número: %ld\n", positionNumber, *(vector + positionNumber)
        ) : printf("Número não encontrado!\n");
}

void executorSimpleSorts(
    unsigned long *vector,
    unsigned long vetSize,
    ExecuterSimpleSorts exec,
    char* nameFunc
) {
    clock_t startClock, endClock;
    float diff;
    startClock = clock();
    exec(vector, vetSize);
    endClock = clock();
    diff = (((float)endClock - (float)startClock) / 1000000.0F);
    printf("\nA execução do %s durou: %f segundos\n", nameFunc, diff);
}


void executorRecursiveSorts(
    unsigned long *vector,
    unsigned long start,
    unsigned long end,
    ExecuterRecursiveSorts execution,
    char* namefunc
) {

    clock_t startClock, endClock;
    float diff;
    startClock = clock();
    execution(vector, start, end);
    endClock = clock();
    diff = (((float)endClock - (float)startClock) / 1000000.0F);
    printf("\nA execução %s durou: %f segundos\n",namefunc, diff);
}

void *loadVector(
    unsigned long quantityMemoryVet,
    unsigned long vetSize,
    unsigned long rangeRand
) {
    unsigned long *vet;
    vet = (unsigned long*) calloc(quantityMemoryVet, sizeof(unsigned long));
    for (unsigned long i = 0; i < vetSize; i++) {
        *(vet + i) = (unsigned long)rand() % rangeRand;
    }
    return vet;
}

int main(int argc, char const *argv[]) {
    if (argc != 2){
        printf("Digite um número inteiro somente!!\n");
        return -1;
    }
    else{
        unsigned long cont = 0;
        for (unsigned long i = 0; i < strlen(argv[1]); i++){
            if (isdigit(argv[1][i])){
                cont++;
            }
        }
        if (strlen(argv[1]) != cont){
            printf("Digite um número inteiro somente!!\n");
            return -1;
        }
    }
    printf("**** Comparador de Algoritmos de Ordenação, %ld posições. ****\n\n", (unsigned long) atoi(argv[1]));
    srand((unsigned)time(NULL));
    int rangeRand = 10000;
    ExecuterSimpleSorts bubble = &bubbleSort;
    ExecuterSimpleSorts selection = &selectionSort;
    ExecuterSimpleSorts insertion = &insertionSort;
    ExecuterRecursiveSorts merge = &mergeSort;
    ExecuterRecursiveSorts quick = &quickSort;
    ExecuterRecursiveSearch binaryRec = &recursiveBinarySearch;
    ExecuterSearch sequence = &sequenceSearch;
    unsigned long vetSize = 5;
    // unsigned long vetSize = (unsigned long) atoi(argv[1]);
    unsigned long startMergeSort = 0, endMergeSort = (vetSize - 1);
    unsigned long startQuickSort = 0, endQuickSort = (vetSize - 1);
    unsigned long quantityMemoryVet = vetSize * sizeof(unsigned long);
    unsigned long seekNumber = 0, turnsIter = 0, *pTIter = &turnsIter;
    unsigned long *vet;

    vet = loadVector(quantityMemoryVet, vetSize, rangeRand);
    executorRecursiveSorts(vet, startMergeSort, endMergeSort, merge, "MergeSort");
    seekNumber = (unsigned long)rand() % rangeRand;
    executorSearch(vet, seekNumber, vetSize, pTIter, sequence, "Busca Sequencial");
    free(vet);
    vet = loadVector(quantityMemoryVet, vetSize, rangeRand);
    executorRecursiveSorts(vet, startMergeSort, endMergeSort, merge, "MergeSort");
    seekNumber = (unsigned long)rand() % rangeRand;
    executorRecursiveSearch(vet, startMergeSort, endMergeSort, seekNumber, pTIter, binaryRec, "Busca Binária");
    free(vet);

    unsigned long *vet1;
    vet1 = loadVector(quantityMemoryVet, vetSize, rangeRand); 
    executorRecursiveSorts(vet1, startQuickSort, endQuickSort, quick, "QuickSort");
    seekNumber = (unsigned long)rand() % rangeRand;
    executorSearch(vet1, seekNumber, vetSize, pTIter, sequence, "Busca Sequencial");
    vet1 = loadVector(quantityMemoryVet, vetSize, rangeRand); 
    executorRecursiveSorts(vet1, startQuickSort, endQuickSort, quick, "QuickSort");
    seekNumber = (unsigned long)rand() % rangeRand;
    // executorSearch(vet1, seekNumber, vetSize, pTIter, binary, "Busca Binária");
    free(vet1);

    unsigned long *vet2;
    vet2 = loadVector(quantityMemoryVet, vetSize, rangeRand);
    executorSimpleSorts(vet2, vetSize, bubble, "BubbleSort");
    seekNumber = (unsigned long)rand() % rangeRand;
    executorSearch(vet2, seekNumber, vetSize, pTIter, sequence, "Busca Sequencial");
    vet2 = loadVector(quantityMemoryVet, vetSize, rangeRand);
    executorSimpleSorts(vet2, vetSize, bubble, "BubbleSort");
    seekNumber = (unsigned long)rand() % rangeRand;
    // executorSearch(vet2, seekNumber, vetSize, pTIter, binary, "Busca Binária");
    free(vet2);
    
    unsigned long *vet3;
    vet3 = loadVector(quantityMemoryVet, vetSize, rangeRand);
    executorSimpleSorts(vet3, vetSize, selection, "SelectionSort");
    seekNumber = (unsigned long)rand() % rangeRand;
    executorSearch(vet3, seekNumber, vetSize, pTIter, sequence, "Busca Sequencial");
    vet3 = loadVector(quantityMemoryVet, vetSize, rangeRand);
    executorSimpleSorts(vet3, vetSize, selection, "SelectionSort");
    seekNumber = (unsigned long)rand() % rangeRand;
    // executorSearch(vet3, seekNumber, vetSize, pTIter, binary, "Busca Binária");
    free(vet3);
    
    unsigned long *vet4;
    vet4 = loadVector(quantityMemoryVet, vetSize, rangeRand);
    executorSimpleSorts(vet4, vetSize, insertion, "InsertionSort");
    seekNumber = (unsigned long)rand() % rangeRand;
    executorSearch(vet4, seekNumber, vetSize, pTIter, sequence, "Busca Sequencial");
    vet4 = loadVector(quantityMemoryVet, vetSize, rangeRand);
    executorSimpleSorts(vet4, vetSize, insertion, "InsertionSort");
    seekNumber = (unsigned long)rand() % rangeRand;
    // executorSearch(vet4, seekNumber, vetSize, pTIter, binary, "Busca Binária");
    free(vet4);

    printf("**** Terminou ****");
    
    return 0;
}