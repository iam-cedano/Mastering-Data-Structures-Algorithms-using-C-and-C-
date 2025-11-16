#pragma once

class Diagonal : public Matrix {
    public:
        Diagonal(int size): Matrix(size, size) {}

        void initialize() override {
            system("clear");

            cout << "Initializing Diagonal matrix of size " << rows << "x" << cols << endl;

            this->values = new int[this->rows];   

            for (int i = 0; i < this->rows; i++) {
                
                cout << "Value #" << i + 1 << ": ";
                cin >> this->values[i];

                system("clear");
            }
        
        }

        void display() override {

            for(int i = 0; i < this->rows; i++) {
                char leftBorder = this->getBorderCharacter(i,0);
                char rightBorder = '.';

                cout << leftBorder;

                for(int j = 0; j < this->cols; j++) {
                    rightBorder = this->getBorderCharacter(i, j);

                    if (i == j) {
                        cout << " " << this->values[i] << " ";
                        continue;
                    }

                    cout << " 0 ";
                }

                cout << rightBorder << endl;
            }
        }

        int get(int i, int j) override {
            if (i != j || i <= 0 || j <= 0) {
                return 0;
            }

            return this->values[i - 1];
        }
};