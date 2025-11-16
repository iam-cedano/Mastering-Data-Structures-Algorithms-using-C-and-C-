#include <stdio.h>
#include <stdlib.h>


int RowMajorMethod();
int ColumnMajorMethod();

int main() {
    return ColumnMajorMethod();
}

int RowMajorMethod() {
    int rows, columns;

    printf("Type the value of I: ");
    scanf("%i", &rows);

    printf("Type the value of J: ");
    scanf("%i", &columns);

    // Handlers for Invalid Values 

    if (rows <= 0 || columns <= 0) {
        fprintf(stderr, "i or J must not be 0");

        return 1;
    }

    if (rows != columns) {
        fprintf(stderr, "I and J don't have the same value");
        
        return 1;
    }

    // End of Handlers for Invalid Values

    int selectedRow, selectedColumn;

    int spaceToOccupy = ((rows)*(columns + 1))/2; // Gauss's Method

    printf("Space to occupy: %i \n", spaceToOccupy);

    int *memory = (int*)malloc(sizeof(int)*spaceToOccupy);

    int *ptr = &memory[0];

    for(int i = 0; i < spaceToOccupy; i++) {
        printf("Type a value for #%i:", i + 1);

        scanf("%i", ptr);

        ptr++;
    }

    printf("Printing the first space: %i \n", memory[0]);

    // Printing the table:

    printf("\n");

    for(int row = 1; row <= rows; row++) {
        
        for(int column = 1; column <= columns; column++) {
            if (row < column) {
                printf(" 0 ");
           
                continue;
            } 

            int hops = ((row*(row - 1))/2) + column - 1;

            int cell = memory[hops];

            printf(" %i ", cell);
        }

        printf("\n");

    }

    // End of Printing the table

    printf("Type your selected row: ");
    scanf("%i", &selectedRow);

    printf("Type your selected column: ");
    scanf("%i", &selectedColumn);

    if (selectedRow < selectedColumn) {
        printf("Result: 0 \n");

        return 0;
    }

    int hops = ((selectedRow*(selectedRow - 1))/2) + selectedColumn - 1;
    
    int cell = memory[hops];

    printf("Result: %i \n", cell);

    free(memory);

    return 0;
}

int ColumnMajorMethod() {

    int rows, columns;

    printf("Type the value of I: ");
    scanf("%i", &rows);

    printf("Type the value of J: ");
    scanf("%i", &columns);

    // Handlers for Invalid Values 

    if (rows <= 0 || columns <= 0) {
        fprintf(stderr, "i or J must not be 0");

        return 1;
    }

    if (rows != columns) {
        fprintf(stderr, "I and J don't have the same value");
        
        return 1;
    }

    // End of Handlers for Invalid Values

    int selectedRow, selectedColumn;

    int spaceToOccupy = ((rows)*(columns + 1))/2; // Gauss's Method

    printf("Space to occupy: %i \n", spaceToOccupy);

    int *memory = (int*)malloc(sizeof(int)*spaceToOccupy);

    int *ptr = &memory[0];

    for(int i = 0; i < spaceToOccupy; i++) {
        printf("Type a value for #%i:", i + 1);

        scanf("%i", ptr);

        ptr++;
    }

    printf("Printing the first space: %i \n", memory[0]);

    // Printing the table:

    printf("\n");

    for(int row = 1; row <= rows; row++) {
        
        for(int column = 1; column <= columns; column++) {
            
            if (row < column) {
                printf(" 0 ");

                continue;
            } 

            int hops = columns*(column - 1) - ( (column - 2)*(column - 1) )/2 + (row - column);

            int cell = memory[hops];

            printf(" %i ", cell);
        }

        printf("\n");

    }

    // End of Printing the table

    printf("Type your selected row: ");
    scanf("%i", &selectedRow);

    printf("Type your selected column: ");
    scanf("%i", &selectedColumn);

    if (selectedRow < selectedColumn) {
        printf("Result: 0 \n");

        return 0;
    }

    int hops = columns*(selectedColumn - 1) - ( (selectedColumn - 2)*(selectedColumn - 1) )/2 + (selectedRow - selectedColumn);
    
    int cell = memory[hops];

    printf("Result: %i \n", cell);

    free(memory);
    
    return 0;
}