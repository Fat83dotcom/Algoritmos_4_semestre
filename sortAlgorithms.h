#ifndef ALGORITHMS_H
#define ALGORITHMS_H

#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

void bubbleSort(int *vet, unsigned long int  sizeVet);
void insertionSort(int *vetor, unsigned long int  tamanhoVetor);
void selectionSort(int *vetor, unsigned long int  tamanhoVetor);
void mergeSort(int *vector, unsigned long int  start, unsigned long int end);
void merge(int *vector, unsigned long int start, unsigned long int half, unsigned long int end);
void quickSort(int *vector, unsigned long int start, unsigned long int end);
unsigned long int binarySearch(int *vet, int wanted, unsigned long int arraySize, unsigned long int *pTIter) ;
unsigned long int sequenceSearch(int *vet, int wanted, unsigned long int arraySize, unsigned long int *pTIter);
unsigned long int recursiveBinarySearch(
    int *vector,
    unsigned long int start,
    unsigned long intend,
    int seekNumber
);

void bubbleSort(int *vet, unsigned long int sizeVet) {
    int aux;
    unsigned long int sum = 0;
    unsigned long int i, j, betterCondiction = 1;
    for (i = 0; i < sizeVet; i++) {
        sum++;
        for (j = 0; j < sizeVet - betterCondiction; j++) {
            sum++;
            if (*(vet + j) > *(vet + (j + 1))) {
                aux = *(vet + j + 1);
                *(vet + (j + 1)) = *(vet + j);
                *(vet + j) = aux;
            }
        }
        betterCondiction++;
    }
    printf("\nO número de iterções dos laços foram: %ld\n", sum);
}

void insertionSort(int *vector, unsigned long int sizeVector){
    int key;
    unsigned long int sum = 0;
    unsigned long int i, j;
    unsigned long int zero = 0;
    unsigned long int one = 1;
    for ( j = one; j < sizeVector; j++){
        sum += one;
        key = vector[j];
        i = j - one;
        while (i >= zero && vector[i] > key){
            sum += one;
            vector[i + one] = vector[i];
            i--;
        }
        vector[i + one] = key;
    }
    printf("\nO número de iterções dos laços foram: %ld\n", sum);
}

void selectionSort(int *vetor, unsigned long int tamanhoVetor) {
    int aux, minimo;
    unsigned long int sum = 0;
    unsigned long int i, j, posMinimo;
    for (i = 0; i < tamanhoVetor - 1; i++) {
        sum += 1;
        minimo = *(vetor + i);
        posMinimo = i;
        for (j = i + 1; j < tamanhoVetor; j++) {
            sum += 1;
            if (minimo > *(vetor + j)) {
                minimo = *(vetor + j);
                posMinimo = j;
            }
        }
        if (posMinimo != i) {
            aux = *(vetor + posMinimo);
            *(vetor + posMinimo) = *(vetor + i);
            *(vetor + i) = aux;
        }
    }
    printf("\nO número de iterções dos laços foram: %ld\n", sum);
}

void mergeSort(int *vector, unsigned long int start, unsigned long int end) {
    unsigned long int half;
    if (start < end) {
        half = floor((start + end)) / 2;
        mergeSort(vector, start, half);
        mergeSort(vector, half + 1, end);
        merge(vector, start, half, end);
    }
}

void merge(int *vector, unsigned long int  start, unsigned long int  half, unsigned long int  end) {
    
    int *tempVet;
    unsigned long int p1, p2, sizeTempVet, iLoop, jLoop, kLoop;
    unsigned long int  end1 = 0, end2 = 0;
    sizeTempVet = end - start;
    p1 = start;
    p2 = half + 1;
    tempVet = (int*) malloc(sizeTempVet * sizeof(int));
    if (tempVet != NULL) {
        for ( iLoop = 0; iLoop < sizeTempVet; iLoop++) {
            if (!end1 && !end2) {
                if (vector[p1] < vector[p2]) {
                    tempVet[iLoop] = vector[p1++];
                }
                else {
                    tempVet[iLoop] = vector[p2++];
                }
                if (p1 > half){
                    end1 = 1;
                }
                if (p2 > end) {
                    end2 = 1;
                }
            }
            else {
                if (!end1) {
                    tempVet[iLoop] = vector[p1++];
                }
                else {
                    tempVet[iLoop] = vector[p2++];
                }
            }
        }
        for (jLoop = 0, kLoop = start; jLoop < sizeTempVet; jLoop++, kLoop++) {
            vector[kLoop] = tempVet[jLoop];
        }
        free(tempVet);
    }
}

void quickSort(int *vector, unsigned long int start, unsigned long int end) {
    int aux;
    if (start < end) {
        unsigned long int randomIndexPivot = (rand() % (end - start)) + start;
        int pivot = vector[randomIndexPivot];
        vector[randomIndexPivot] = vector[end];
        vector[end] = pivot;
        unsigned long int i = start - 1;
        unsigned long int j = end;
        do {
            do {
                i++;
            } while (vector[i] < pivot);
            do {
                j --;
            } while ((vector[j] > pivot) && (j > start));
            if (i < j){
                aux = vector[i];
                vector[i] = vector[j];
                vector[j] = aux;
            }
        } while (i < j);
        vector[end] = vector[i];
        vector[i] = pivot;
        quickSort(vector, start, i - 1);
        quickSort(vector, i + 1, end);
    }
}

unsigned long int binarySearch(int *vet, int wanted, unsigned long int arraySize, unsigned long int *pTIter) {
    *pTIter = 0;
    int kick = 0;
    unsigned long int low = 0, high = 0, half = 0;
    high = arraySize - 1;
    while (low <= high){
        *pTIter = *pTIter + 1;
        half = (low + high) / 2;
        kick = *(vet + half);
        if (kick == wanted){
            return half;
        }
        else if (kick > wanted){
            high = half - 1;
        }
        else{
            low = half + 1;
        }
    }
    return -1;
}

unsigned long int sequenceSearch(int *vet, int wanted, unsigned long int arraySize, unsigned long int *pTIter){
    *pTIter = 0;
    for (unsigned long int i = 0; i < arraySize; i++) {
        if (wanted == vet[i]) {
            return i;
        }
        *pTIter = *pTIter + 1;
    }
    return -1;
}

unsigned long int recursiveBinarySearch(int *vector, unsigned long int start, unsigned long int end, int seekNumber) {
    unsigned long int indexFind;
    if (start > end)
        return -1;
    else {
        indexFind = (start + end)/2;
        if (*(vector + indexFind) == seekNumber) {
            return indexFind;
        }
        else
            if (seekNumber < *(vector + indexFind)) {
                return recursiveBinarySearch(vector, start, indexFind - 1, seekNumber);
            }
            else {
                return recursiveBinarySearch(vector, indexFind + 1, end, seekNumber);
            }
        }
    }

#endif