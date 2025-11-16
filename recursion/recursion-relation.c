#include <stdio.h>

void test(int);

int main() {

    test(5);

    return 0;
}

void test(int n) {
    if (n > 0) {
        printf("%d \n", n);
        test(n - 1);
        test(n - 1);
    }
}