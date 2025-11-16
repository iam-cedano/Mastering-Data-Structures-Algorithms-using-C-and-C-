#include <stdio.h>

int main() {
    int y = 0, x;
    char A[] = "finding";

    for(int i = 0; A[i] != '\0'; i++) {
        x = 1;

        x = x << (A[i] - 97);

        if ((y & x) > 0) {
            printf("Letter %c is duplicated \n", A[i]);
        } 

        y = y | x;
    }

    return 0;
}