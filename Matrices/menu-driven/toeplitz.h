
#pragma once

#include "matrix.h"

class Toeplitz : public Matrix {
    public:
        Toeplitz(int size): Matrix(size, size) {}

        void initialize() override {
            
        }
        
        void display() override {

        }

        int get(int i, int j) override { 
            
            return 0; 
        }
};
