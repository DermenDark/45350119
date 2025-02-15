#include <iostream>
#include <cmath>
#include <vector>

extern "C" __declspec(dllexport) long double countCondition(int N, int k, const std::vector<long double>& X) {

    if (N == 1) {
        return (sin(X[k] / 2) < 0) ? 1 : 0;
    }

    int mid = N / 2;

    long double leftCount = countCondition(mid, k, X);
    long double rightCount = countCondition(N - mid, k + mid, X);

    return leftCount + rightCount;
}
extern "C" __declspec(dllexport) void glavn() {
    int N = 0;

    std::cout << "Введите размер массива: ";
    std::cin >> N;

    std::vector<long double> X(N);
    std::cout << "Введите элементы массива:\n";

    for (int i = 0; i < N; ++i) {
        std::cout << "Введите элемент X[" << i << "]: ";
        std::cin >> X[i];
    }

    long double M = countCondition(N, 0, X);
    std::cout << "Количество элементов, для которых sin(X_i / 2) < 0: " << M << std::endl;
}