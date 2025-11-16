#include <stdio.h>
#include <stdlib.h>

int TriDiagonal(); 

int main() {
    return TriDiagonal();
}

/**
 *  |i - j| <= 1
 * 
 */
int TriDiagonal() {

    int row = 5, column = 5;

    int size = row + ( (row - 1)*2 );

    int* vault = malloc(sizeof(int)*size);
    

    for (int i = 0; i < size; i++) {

    }

    return 0;
}

