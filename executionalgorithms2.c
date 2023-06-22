#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <ctype.h>
#include <string.h>
#include "sortAlgorithms.h"

typedef void (*ExecutorRecursiveSorts)(int*, int, int);
typedef int (*ExecutorRecursiveSearch)(int*, int, int, int);
typedef void (*ExecutorIteratorsSorts)(int*, int);
typedef int (*ExecutorIteratorsSearch)(int*, int, int, int*);

void executeIteratorsSearch(
    int *vector,
    int seekNumber,
    int sizeVector,
    int *pTIter,
    ExecutorIteratorsSearch exec,
    char* nameFunc
) {
    clock_t startClock, endClock;
    float diff;
    int minusOne = -1;
    int index;
    startClock = clock();
    index = exec(vector, seekNumber, sizeVector, pTIter);
    endClock =  clock();
    diff = (((float)endClock - (float)startClock) / 1000000.0F);
    printf("\n*************************************************************************\n");
    printf("\nA execução %s durou: %f segundos\n", nameFunc, diff);
    printf("Número de Iterações: %d\n", *pTIter);
    printf("Numero procurado: %d\n", seekNumber);
    if (index != minusOne && index <= sizeVector - 1){
        printf("Número encontrado: %d\n", *(vector + index));
    }
    else{
        printf("Número não encontrado: %d\n", index);
    }
    printf("\n*************************************************************************\n");
}

void executeIteratorsSort(
    int *vector,
    int sizeVector,
    ExecutorIteratorsSorts exec,
    char* nameFunc
) {
    clock_t startClock, endClock;
    float diff;
    startClock = clock();
    exec(vector, sizeVector);
    endClock =  clock();
    diff = (((float)endClock - (float)startClock) / 1000000.0F);
    printf("\n*************************************************************************\n");
    printf("\nA execução do %s durou %f segundos.\n", nameFunc, diff);
    printf("\n*************************************************************************\n");
}

void executeRecursiveSearch(
    int *vector,
    int startVector, 
    int endVector,
    int vectorSize,
    int seekNumber,
    ExecutorRecursiveSearch exec,
    char* nameFunc
) {
    clock_t startClock, endClock;
    float diff;
    int minusOne = -1;
    int index;
    startClock = clock();
    index = exec(vector, startVector, endVector, seekNumber);
    endClock =  clock();
    diff = (((float)endClock - (float)startClock) / 1000000.0F);
    printf("\n*************************************************************************\n");
    printf("\nA execução %s durou: %f segundos\n", nameFunc, diff);
    printf("Numero procurado: %d\n", seekNumber);
    if (index != minusOne && index <= vectorSize - 1){
        printf("Número encontrado: %d\n", *(vector + index));
    }
    else{
        printf("Número não encontrado: %d\n", index);
    }
    printf("\n*************************************************************************\n");
}

void executeRecursiveSorts(
    int *vector,
    int start,
    int end,
    ExecutorRecursiveSorts exec,
    char* nameFunc
) {
    clock_t startClock, endClock;
    float diff;
    startClock = clock();
    exec(vector, start, end);
    endClock =  clock();
    diff = (((float)endClock - (float)startClock) / 1000000.0F);
    printf("\n*************************************************************************\n");
    printf("\nA execução do %s durou %f segundos.\n", nameFunc, diff);
    printf("\n*************************************************************************\n");
}

void loadVectors(int *vector, int vectorSize, int rangeRand) {
    for (int i = 0; i < vectorSize; i++) {
        *(vector + i) = rand() % rangeRand;
    }
}

int randomNumbers(int range) {
    return rand() % range;
}

int main(int argc, char const *argv[]) {
    if (argc != 2){
        printf("Digite um número inteiro somente!!\n");
        return -1;
    }
    else{
        unsigned long int cont = 0;
        for (unsigned long int i = 0; i < strlen(argv[1]); i++){
            if (isdigit(argv[1][i])){
                cont++;
            }
        }
        if (strlen(argv[1]) != cont){
            printf("Digite um número inteiro somente!!\n");
            return -1;
        }
    }
    printf("**** Comparador de Algoritmos de Ordenação, %d posições. ****\n\n", (int) atoi(argv[1]));
    
    srand((unsigned)time(NULL));
    int vectorSize = (int) atoi(argv[1]);
    int rangeRand = vectorSize;
    ExecutorRecursiveSorts merge = &mergeSort;
    ExecutorRecursiveSorts quick = &quickSort;
    ExecutorRecursiveSearch binaryS = &recursiveBinarySearch;
    ExecutorIteratorsSearch sequence = &sequenceSearch;
    ExecutorIteratorsSorts bubble = &bubbleSort;
    ExecutorIteratorsSorts insert = &insertionSort;
    ExecutorIteratorsSorts selection = &selectionSort;
    // int qMemoVector = vectorSize * sizeof(int);
    int turnsIter = 0, *pTIter = &turnsIter;
    int startVector = 0, endVector = (vectorSize - 1);
    int *vector;
    vector = (int*) malloc(vectorSize *sizeof(vector));
    // vector = calloc(qMemoVector, sizeof(int));
    printf("%p\n", vector);

    loadVectors(vector, vectorSize, rangeRand);
    executeRecursiveSorts(vector, startVector, endVector, merge, "MergeSort");
    executeRecursiveSearch(
        vector,
        startVector,
        endVector,
        vectorSize, 
        randomNumbers(rangeRand),
        binaryS, 
        "Busca Binaria"
    );

    loadVectors(vector, vectorSize, rangeRand);
    executeRecursiveSorts(vector, startVector, endVector, merge, "MergeSort");
    executeIteratorsSearch(vector, randomNumbers(rangeRand), vectorSize, pTIter, sequence, "Busca Sequencial");
    
    loadVectors(vector, vectorSize, rangeRand);
    executeRecursiveSorts(vector, startVector, endVector, quick, "QuickSort");
    executeRecursiveSearch(
        vector,
        startVector,
        endVector,
        vectorSize, 
        randomNumbers(rangeRand),
        binaryS, 
        "Busca Binaria"
    );

    loadVectors(vector, vectorSize, rangeRand);
    executeRecursiveSorts(vector, startVector, endVector, quick, "QuickSort");
    executeIteratorsSearch(vector, randomNumbers(rangeRand), vectorSize, pTIter, sequence, "Busca Sequencial");

    loadVectors(vector, vectorSize, rangeRand);
    executeIteratorsSort(vector, vectorSize, bubble, "BubbleSort");
    executeRecursiveSearch(
        vector,
        startVector,
        endVector,
        vectorSize, 
        randomNumbers(rangeRand),
        binaryS, 
        "Busca Binaria"
    );
    loadVectors(vector, vectorSize, rangeRand);
    executeIteratorsSort(vector, vectorSize, bubble, "BubbleSort");
    executeIteratorsSearch(vector, randomNumbers(rangeRand), vectorSize, pTIter, sequence, "Busca Sequencial");

    loadVectors(vector, vectorSize, rangeRand);
    executeIteratorsSort(vector, vectorSize, selection, "SelectionSort");
    executeRecursiveSearch(
        vector,
        startVector,
        endVector,
        vectorSize, 
        randomNumbers(rangeRand),
        binaryS, 
        "Busca Binaria"
    );
    loadVectors(vector, vectorSize, rangeRand);
    executeIteratorsSort(vector, vectorSize, selection, "SelectionSort");
    executeIteratorsSearch(vector, randomNumbers(rangeRand), vectorSize, pTIter, sequence, "Busca Sequencial");

    loadVectors(vector, vectorSize, rangeRand);
    executeIteratorsSort(vector, vectorSize, insert, "InsertSort");
    executeRecursiveSearch(
        vector,
        startVector,
        endVector,
        vectorSize, 
        randomNumbers(rangeRand),
        binaryS, 
        "Busca Binaria"
    );
    loadVectors(vector, vectorSize, rangeRand);
    executeIteratorsSort(vector, vectorSize, insert, "InsertSort");
    executeIteratorsSearch(vector, randomNumbers(rangeRand), vectorSize, pTIter, sequence, "Busca Sequencial");

    free(vector);

    return 0;
}
