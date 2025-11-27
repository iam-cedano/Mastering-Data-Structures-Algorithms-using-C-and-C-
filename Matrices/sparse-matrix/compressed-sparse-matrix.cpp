#include <iostream>
#include <stdlib.h>
#include <thread>
#include <chrono>

using namespace std;

int main() {
    int rows = 8, columns = 9;
    int values = 8;

    int
    *cv = new int[values],
    *cr = new int[values + 1],
    *cc = new int[values];
    
    cr[0] = 0;

    for (int i = 0; i < values; i++) {
        int r = 0, c = 0, v = 0;
        
        do {
            cout << "Row: ";
            cin >> r;
        } while(! (r > 0 && r <= rows));

        do {
            cout << "Column: ";
            cin >> c;
        } while(! (c > 0 && c <= columns));

        cout << "Value: ";
        cin >> v;

        cr[r] = cr[r] + 1;
        cc[i] = c;
        cv[i] = v;

        cout << "Accepted ✅" << endl;
    }

    for (int i = 1; i < values + 1; i++) {
        cr[i] = cr[i] + cr[i - 1];

        cout << cr[i] << endl;
    }

    int pc = 0;

    for (int i = 1; i <= rows; i++) {
        int numbers_in_the_row = cr[i] - cr[i - 1];

        for (int j = 0; j <= columns; j++) {
            if (numbers_in_the_row == 0) {
                cout << " 0 ";

                continue;
            }

            for (int z = 0; z < numbers_in_the_row; z++) {
                if (cc[pc + z] == j) {
                    cout << " " << cv[pc + z] << " ";
                } else {
                    cout << " 0 ";
                }
            }
        }

        cout << "\n\n" << endl;
        pc += numbers_in_the_row;
    }

    return 0;
}