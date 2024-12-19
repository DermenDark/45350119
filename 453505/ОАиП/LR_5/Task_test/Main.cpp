#include <iostream>
#include "mylib/Squares.h"

using namespace std;


int main() {
    float n = 0, perm = 0;

    cin >> n >> perm;
    perm = kvadrat(n);

    cout << perm <<'\n'<<n;


    return 0;
}
