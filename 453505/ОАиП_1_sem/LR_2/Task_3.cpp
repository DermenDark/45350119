#include <iostream>

int main() {
    float sum, b1, q, n =19;

    std::cout << "Введите значение первого члена убыв. прогрессии b: ";
    std::cin >> b1;

    q = 1/(n+1);
    sum = b1/(1-q);
    
    std::cout << "результат: "<< sum;
    
    return 0;
}