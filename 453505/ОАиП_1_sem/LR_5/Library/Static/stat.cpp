#include <cmath>

long double prozessing(int nnn) {
    long double a = 0, b = 0;

    for (int i = 1; i <= nnn; ++i) {
        b = 0;
        if (i > 17) {
            b = sin(i);
        }
        else if (i <= 17) {
            b = 1 / tan(i * i);
        }
        a += b;
    }
    a = a / nnn;

    return a;
}