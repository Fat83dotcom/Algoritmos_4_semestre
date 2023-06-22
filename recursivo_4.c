#include <stdio.h>

int sum(int number) {
    if (number == 0) {
        return 0;
    }
    else{
        return number + sum(number - 1);
    }
}

int main(int argc, char const *argv[]){
    int result;
    result = sum(10000);
    printf("%d\n", result);
    return 0;
}
