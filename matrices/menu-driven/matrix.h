#include <iostream>

using namespace std;

class Matrix {
    protected:
        int rows;
        int cols;
        int* values;
    public:
        Matrix(int rows, int cols): rows(rows), cols(cols), values(nullptr) {
            if (rows != cols) {
                throw invalid_argument("Matrix must be square for diagonal, lower triangular, upper triangular, and symmetric matrices.");
            }
        };

        virtual void initialize() = 0;
        virtual void display() = 0;
        virtual int get(int i, int j) = 0;

        void target() {
            this->display();

            int i = 0, j = 0, result = 0;

            printf("Specify coordinates \n");
            
            printf("I: ");

            scanf("%i", &i);

            printf("\n");

            printf("J: ");

            scanf("%i", &j);

            printf("\n");

            result = this->get(i, j); 

            printf("Result: %i \n\n", result);
        }

        void menu() {
            int opt = 0;
            
            do 
            {
             this->display();

             printf("1. Select one item \n");
             printf("2. Exit \n\n");

             printf("Option: ");
             scanf("%i", &opt);

             switch(opt) {
                case 1: 
                    system("clear");

                    this->target();
                break;
                case 2:
                    system("clear");
                break;
             }
            } while(opt != 2);
        }

    protected: 
        char getBorderCharacter(int row, int column) {
            if (row == 0 && column == 0) {
                return '┌';
            }

            if (row == 0 && column == (this->cols - 1)) {
                return '┐';
            }

            if (row == (this->rows - 1) && column == 0) {
                return '└';
            }

            if (row == (this->rows - 1) && column == (this->cols - 1)) {
                return '┘';
            }

            return '|';
        }
};