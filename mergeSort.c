#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void mergeSort(int *vector, int start, int end) {
    int half;
    if (start < end) {
        half = floor((start + end)) / 2;
        mergeSort(vector, start, half);
        mergeSort(vector, half + 1, end);
        merge(vector, start, half, end);
    }
}

void merge(int *vector, int start, int half, int end) {
    int *tempVet, p1, p2, sizeTempVet, iLoop, jLoop, kLoop;
    int end1 = 0, end2 = 0;
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
