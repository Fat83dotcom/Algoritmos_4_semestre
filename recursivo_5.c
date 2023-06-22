#include <stdio.h>

int sumVector(int lenVect, int *vector) {
    if (lenVect == 0){
        return 0;
    }
    else {
        return vector[lenVect - 1] + sumVector(lenVect - 1, vector);
    }
}

int main(int argc, char const *argv[]) {
    int vector[10] = {1, 2, 3}, result;
    result = sumVector(3, vector);
    printf("%d\n", result);

    return 0;
}
