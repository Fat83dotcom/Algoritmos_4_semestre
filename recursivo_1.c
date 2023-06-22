#include <stdio.h>

int simpleSequence(int sizeSeq){
    
    printf("%dº número da sequencia.\n", sizeSeq);
    if (sizeSeq == 0){
        return sizeSeq;
    }
    return simpleSequence(sizeSeq - 1); 
}

int main(int argc, char const *argv[]){
    int result;

    result =  simpleSequence(100000);
    printf("%d\n", result);
    
    return 0;
}
