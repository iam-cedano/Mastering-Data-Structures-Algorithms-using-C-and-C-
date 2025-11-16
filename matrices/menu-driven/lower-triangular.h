#pragma once

class LowerTriangular : public Matrix {
    
    /*
    *   Row Method
    *   Lower Triangular Matrix:  
    *  
    *   [
    *      1 0 0 0 0
    *      2 8 0 0 0
    *      3 5 4 0 0
    *      4 7 5 6 0
    *      5 3 7 4 1
    *   ]
    *      
    *   It's like, we don't
    *   array: [1 | 2, 8 | 3, 5, 4 | 4, 7, 5, 6 | 5, 3, 7, 4, 1]
    *   size: n(n+1)/2 : 5(6)/2 = 15 ✅
    * 
    *   if i > j then 0
    *   if i <= j then j(j + 1)/2 + i
    * 
    *   (1 , 4) = 3
    *   4(4 + 1)/2 + 1 = 11, hence array[11] = 3 ✅
    *   
    *   (2, 2) = 4
    *   2(2 + 1)/2 + 2 = 5, hence array[5] = 4 ✅
    * 
    *   (0, 4) = 5
    *   4(4 + 1)/2 + 0 = 10, hence array[10] = 5 ✅
    *   
    */

    public:
        LowerTriangular(int size): Matrix(size, size) {}

        void initialize() override {
            system("clear");

            printf("Initializing matrix using Lower Triangular method.");

            int size = sizeof(int)*(this->rows*(this->cols + 1)/2);

            this->values = new int[size];
            
            for(int i = 0; i < this->rows; i++) {
                for(int j = 0; j < this->cols; j++) {
                    if (j > i) {
                        continue;
                    }

                    int input = 0;

                    printf("\n\n");

                    printf("Input for (%i, %i): ", j, i);
                    
                    scanf("%i", &input);

                    printf("\n");

                    int index = (j*(j + 1)/2) + i;

                    this->values[index] = input;
                }
            }
        }

        void display() override {
            for(int i = 0; i < this->rows; i++) {
                char leftBorder = this->getBorderCharacter(i,0);
                char rightBorder = '.';

                cout << leftBorder;
                for(int j = 0; j < this->cols; j++) {
                    rightBorder = this->getBorderCharacter(i, j);
                    
                    int result = this->get(i, j);

                    cout << " " << result << " ";
                }

                cout << rightBorder << endl;
            }
        }

        int get(int i, int j) override {
            if (i > j) {
                return 0;
            }

            int index = (i*(i + 1)/2) + j;

            return this->values[index];
        }
};
