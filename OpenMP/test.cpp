#include "testing.h"
#include <omp.h>
#include <iostream>
#include <string>

using namespace std;

void test() {
    cout << "the begin of loop" << endl;

#pragma omp parallel for
    for (int i = 0; i < 10; ++i) {
        cout << i;
    }
    cout << endl << "the end of loop" << endl;

    //    Expected output will be similar to this:
    //    the begin of loop
    //    6378049152
    //    the end of loop
}