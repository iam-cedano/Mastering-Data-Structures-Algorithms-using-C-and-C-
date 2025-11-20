#include <iostream>
#include <stdlib.h>
#include <thread>
#include <chrono>

using namespace std;

int main() {
    int rows = 7, columns = 5;
    int totalOfElements = 10;

    int* pr = new int[totalOfElements + 1], 
    *pc = new int[totalOfElements + 1], 
    *pv = new int[totalOfElements + 1];


    pr[0] = rows;
    pc[0] = columns;
    pv[0] = totalOfElements;

    int index = 1;

    for (int i = 0; i < totalOfElements; i++) {
        int vr = -1, vc = -1, vv = -1;
        
        do {
            cout << "Row: ";
            cin >> vr;

            if (! (vr >= 0 && vr <= rows) ) {
                cout << "Row must be lower or equal to " << rows << endl;  
            }
        } while(!(vr >= 0 && vr <= rows));
        
        do {
            cout << "Column: ";
            cin >> vc;

            if (! (vc >= 0 && vc <= columns) ) {
                cout << "Column must be lower or equal to " << columns << endl;  
            }
        } while(!(vc >= 0 && vc <= columns));

        
        cout << "Value: ";
        cin >> vv;

        pr[index] = vr;
        pc[index] = vc;
        pv[index] = vv;

        this_thread::sleep_for(chrono::milliseconds(300));
        cout << "Accepted ✅" << endl;
        
        index++;

        this_thread::sleep_for(chrono::milliseconds(500));
        cout << "--------------" << endl;
    }

    cout << "--- Information of the matrix ---" << endl;
    cout << "| Rows: " << pr[0] << "| Columns: " << pc[0] << "|" << endl;
    cout << "---------------------------------" << endl;

    for (int i = 1; i < totalOfElements; i++) {
        cout << "(" << pr[i] << "," << pc[i] << "): " << pv[i] << endl;
    }

    for (int i = 1; i < rows; i++) {
        for(int j = 1; j < columns; j++) {

        }
    }

    return 0;
}