#include <cmath>

long double computeDispersion(int n, long double m) {
    long double D = 0, b = 0;
    for (int i = 1; i <= n; ++i) {
        b = 0;
        if (i > 17) {
            b = sin(i);
        }
        else if (i <= 17) {
            b = 1 / tan(i * i);
        }
        D += (b - m) * (b - m);
    }
    D = D / n;

    return D;
}