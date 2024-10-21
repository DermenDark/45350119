#include <iostream>

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;

        b = a % b;
        a = temp; 

    }
    return a;
}

int main() {
    int a, b;
    
    std::cout << "Введите два числа: ";
    std::cin >> a >> b;
    
    // Вывод НОД
    std::cout << "НОД: " << gcd(a, b) << std::endl;
    
    return 0;
}
