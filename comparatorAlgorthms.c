#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <string.h>

typedef struct Temporizador{
    clock_t inicio;
    clock_t fim;
}Temporizador;

void bubbleSort(int *vetor, unsigned long int tamanhoVetor){
    unsigned long i, j;
    int aux;
    for (i = tamanhoVetor - 1; i > 0; i--){
        for (j = 0; j < i; j++){
            if (vetor[j] > vetor[j + 1]){
                aux = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = aux;
            }
        }
    }
}

void insertionSort(int *vetor, unsigned long int tamanhoVetor){
    unsigned long i, j;
    int chave;
    for (j = 1; j < tamanhoVetor; j++){
        chave = vetor[j];
        i = j - 1;
        while (i >= 0 && vetor[i] > chave){
            vetor[i + 1] = vetor[i];
            i--;
        }
        vetor[i + 1] = chave;
    }
}

void selectionSort(int *vetor, unsigned long int tamanhoVetor){
    unsigned long i,j;
    int aux, minimo, pos_minimo;
    for (i=0; i < tamanhoVetor - 1; i++){
        minimo = vetor[i];
        pos_minimo = i;
        for (j = i + 1; j < tamanhoVetor; j++){
            if (minimo > vetor[j]){
                minimo = vetor[j];
                pos_minimo = j;
            }
        }
        if (pos_minimo != i){
            aux = vetor[pos_minimo];
            vetor[pos_minimo] = vetor[i];
            vetor[i] = aux;
        }
    }
}

void preenchedorVetor(int *vetor, unsigned long int tamanhoVetor, unsigned long int rangeDosNumeros){
    Temporizador vet;
    srand(time(NULL));
    vet.inicio = clock();
    for (unsigned long int i = 0; i < tamanhoVetor; i++){
        vetor[i] = rand() % rangeDosNumeros;
    }
    vet.fim = clock();
    printf("O preenchimento de vetor durou %.5f segundos.\n", ((double)(vet.fim - vet.inicio)) / CLOCKS_PER_SEC);
}

void executorFuncao(void funcao(int*, unsigned long int), int *vetor, unsigned long int tamanhoVetor, char *nomeFuncao){
    Temporizador temp;
    temp.inicio = clock();
    funcao(vetor, tamanhoVetor);
    temp.fim = clock();
    printf("O algoritmo %s foi executado em %.5f segundos.\n", nomeFuncao, ((double)(temp.fim - temp.inicio)) / CLOCKS_PER_SEC);
}


int main(int argc, char const *argv[]){
    if (argc != 2){
        printf("Digite um número inteiro somente!!\n");
        return -1;
    }
    else{
        int cont = 0;
        for (int i = 0; i < strlen(argv[1]); i++){
            if (isdigit(argv[1][i])){
                cont++;
            }
        }
        if (strlen(argv[1]) != cont){
            printf("Digite um número inteiro somente!!\n");
            return -1;
        }
    }
    
    printf("**** Comparador de Algoritmos de Ordenação ****\n\n");
    
    void (*pBubble)(int*, unsigned long int) = &bubbleSort;
    void (*pInsertion)(int*, unsigned long int) = &insertionSort;
    void (*pSelection)(int*, unsigned long int) = &selectionSort;
    unsigned long int qtdElementos = (unsigned long int)atoi(argv[1]);
    unsigned long int tamanhoMemoriaAlocada = qtdElementos * sizeof(int);
    int *vetor = (int*) calloc(tamanhoMemoriaAlocada, sizeof(int));
    unsigned long int rangeNumeros = RAND_MAX;

    printf("A memória alocada contém %ld elementos aleatórios, "
            "ocupando %f Megabytes de espaço.\n", qtdElementos, (tamanhoMemoriaAlocada / 10E+5));

    preenchedorVetor(vetor, qtdElementos, rangeNumeros);
    
    executorFuncao(pBubble, vetor, qtdElementos, "BubbleSort");

    preenchedorVetor(vetor, qtdElementos, rangeNumeros);

    executorFuncao(pInsertion, vetor, qtdElementos, "InsertionSort");

    preenchedorVetor(vetor, qtdElementos, rangeNumeros);

    executorFuncao(pSelection, vetor, qtdElementos, "SelectionSort");

    free(vetor);

    return 0;
}