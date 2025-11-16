#include <stdio.h>

/**
 * Printing a Toeplitz Matrix 
 *
 * [  
 *   2 3 4 5 6
 *   7 2 3 4 5
 *   8 7 2 3 4
 *   9 8 7 2 3
 *  10 9 8 7 2
 * ]
 * 
 * Result: 
 * [
 *   2  3  4  5  6
 *   7  2  3  4  5
 *   8  7  2  3  4
 *   9  8  7  2  3
    10  9  8  7  2
  ]  
 *  Original size: 25
 *  Optimized: X*2 in this case (10 - 1) = 9, therefore the formula is 2x - 1
 *  Patterns:
 *   
 *    [ 2, 3, 4, 5, 6 | 7, 8, 9, 10 ]
 * 
 *    [ 2, 3, 4, 5, 6, 10, ]
 * 
 *  Now to get a specific number the formula is: (X - Y).
 *  Examples: 
 *      
 *      8 = (2, 4) = (2 - 4) = -2  

 *      10 = (0, 4) = (0 - 4) = -4 Both takes the same index
 *      6 = (4, 0) = (4 - 0) = 4

 *      9 = (1, 4) = (1 - 4) = -3
 * 
 * 
 *  From the teacher:
 *      "There will be a different formula according to the number's position."
 *      
 *      "If the element is in the upper part of the matrix" 
 *          When I >= J, hence to get a position is: Z = (I - J)
 *          When I < J, hence to get a position is: Z = N + (J - I - 1)
 */

int bunchOfNumbers[] = {2, 3, 4, 5, 6, 7, 8, 9, 10};
int size = sizeof(bunchOfNumbers)/sizeof(int);

void print();

int get(int i, int j);

int main() {
    int i = 0, j = 0;

    print();

    printf("-- Search number --");

    printf("\n\n");

    printf("I: ");
    
    scanf("%i", &i);

    printf("\n");
    
    printf("J: ");

    scanf("%i", &j);
    
    int result = get(i, j);

    printf("Result: %i", result);
}   

void print() {
    for(int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            printf(" %i ", get(j, i));
        }
        printf("\n");
    } 
}

int get(int I, int J) {
    int index = 0;
    int* result = NULL;

    if (I >= J) {
        index = I - J;
    } else {
        index = (size/2) + J - I;
    }

    result = bunchOfNumbers + index;

    return *result;
}
