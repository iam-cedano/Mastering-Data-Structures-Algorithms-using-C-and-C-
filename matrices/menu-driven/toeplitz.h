
#pragma once

class Toeplitz : public Matrix {
    /**
     * Toeplitz Matrix 
     * 
     * [ 2 3 4 5 7 
     *   1 2 3 4 5
     *   6 1 2 3 4
     *   8 6 1 2 3 
     *   9 8 6 1 2
     * ]
     * 
     * N = I + J - 1
     * 
     * if i <= j
     *  j - i - 1
     * 
     * if i > j
     *  I + i - j - 1
     */

    public:
        Toeplitz(int size): Matrix(size, size) {}

        void initialize() override {
            system("clear");

            cout << "Initializing Toeplitz Matrix" << endl;
            
            int size = this->rows + this->cols - 1;

            this->values = new int[size];

            for (int i = 0; i < size; i++) {
                int value = 0;

                cout << "Type the value for value #" << (i + 1) << ": ";
                cin >> value;

                this->values[i] = value;
            }
        }
        
        void display() override {
            
            for (int i = 0; i < this->rows; i++) {
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
            int value = 0;

            if ( i <= j ) {
                value = this->values[j - i];
            } else {
                value = this->values[this->rows - 1 + i - j];
            }

            return value; 
        }
};
