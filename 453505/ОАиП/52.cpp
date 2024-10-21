#include <iostream>

// Custom factorial function
long long factorial(int n) {
    if (n == 0 || n == 1) return 1;
    long long result = 1;
    for (int i = 2; i <= n; ++i) {
        result *= i;
    }
    return result;
}

// Custom power function
double pow(double base, int exponent) {
    double result = 1.0;
    for (int i = 0; i < exponent; ++i) {
        result *= base;
    }
    return result;
}

// Sine function using Taylor series
double sinn(double kor) {
    double e = 6.28318530716; // 2 * pi
    double resul = kor; // Initialize resul with kor

    // Reduce kor to the range of [-pi, pi]
    while (resul > e) {
        resul -= e;
    }
    while (resul < -e) {
        resul += e;
    }

    double res = 0;
    // Taylor series expansion for sine
    for (int n = 0; n < 15; n++) {
        double prom = pow(resul, (2 * n + 1)) / factorial(2 * n + 1);
        if (n % 2 == 1) {
            prom = -prom; // Subtract the odd terms
        }
        std::cout << "\nRes: " << n << "-(" << prom;
        res += prom;
    }

    return res;
}

int main() {
    double angle = 10; // Example input
    double sine_value = sinn(angle);
    std::cout << "\nSine value: " << sine_value << std::endl;
    return 0;
}
