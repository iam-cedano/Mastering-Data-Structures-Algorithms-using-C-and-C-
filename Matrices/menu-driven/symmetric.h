#pragma once    

class Symmetric : public Matrix {
    public:
        Symmetric(int size): Matrix(size, size) {}

        void initialize() override {

            system("clear");

            cout << "Initializing Symmetric Matrix." << endl;

            int size = this->rows*(this->rows + 1)/2;

            this->values = new int[size];

            for (int i = 0; i < size; i++) {
                int value = 0;
                    
                cout << "Value for #" << (i + 1) << ": ";
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
            if ( j > i ) {
                int aux = j;

                j = i;
                
                i = aux;
            }

            int index = i*(i+1)/2 + j - 1;

            if ( index < 0 ) { 
                index = 0;
            } 

            return this->values[index]; 
        }
};
