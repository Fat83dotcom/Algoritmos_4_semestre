#include <stdio.h>

int sequence(int n) {
    if (n == 1) {
        printf("4");
        return 4;
    }
    else {
        n -= 1;
        printf("%d\n", (sequence(n) + sequence(n) + 4));
        return (sequence(n) + (2 * sequence(n)) + 4);
    }
    
}

int main(int argc, char const *argv[]) {
    int result;
    result = sequence(5);
    printf("%d\n", result);
    return 0;
}
