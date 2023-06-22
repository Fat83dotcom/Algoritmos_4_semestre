#include <stdio.h>

#define true 1
#define false 0

typedef int bool;

bool even(int number) {
    if (number == 0) {
        return true;
    }
    else if (number == 1) {
        return false;
    }
    else {
        return odd(number - 1);
    }
}

bool odd(int number) {
    if (number == 0) {
        return false;
    }
    else if (number == 1) {
        return true;
    }
    else{
        return even(number - 1);
    }
}

int main(int argc, char const *argv[]) {
    int number = 180;
    bool result;

    result = even(number);
    
    printf("%d\n", result);
    return 0;
}
