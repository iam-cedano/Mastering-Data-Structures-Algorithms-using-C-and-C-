#include <iostream>
#include "matrix.h"
#include "diagonal.h"
#include "lower-triangular.h"
#include "symmetric.h"
#include "toeplitz.h"

using namespace std;

// Function prototypes
void displayMenu();

int main() {

    int choice;

    do {    
        Matrix* matrix;
        cout << "Menu:" << endl;
        displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
            {
                Diagonal diagonal(5);

                matrix = &diagonal;
            }
            break;
            
            case 2:
            {
                LowerTriangular lowerTriangular(5);
                
                matrix = &lowerTriangular;
            }
            break;
            case 3:
            {
                Symmetric symmetric(5);

                matrix = &symmetric;
            }    
            break;

            case 4: 
            {
                Toeplitz toeplitz(5);

                matrix = &toeplitz;
            }
            break;
            case 5:
            {
                cout << "Exiting..." << endl;

                exit(0);

                break;
            }
            default:      
                system("clear");

                cout << "Invalid choice. Please try again." << endl;

                continue;
        }

        matrix->initialize();
        matrix->menu();

    } while(choice != 5);

    return 0;
}

void displayMenu() {
    cout << "1. Diagonal" << endl;
    cout << "2. Lower triangular matrix" << endl;
    cout << "3. Symmetric matrix" << endl;
    cout << "4. Toeplitz matrix" << endl;
    cout << "5. Exit" << endl;
}