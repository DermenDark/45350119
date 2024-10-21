#include <iostream>

double poow(double osnov,int step){
    double res=1;
    for(int n=0;n<step; n++){
        res *= osnov;
        
    }
    return res;
}

bool is_armstrong(int num) {
    int original = num;
    int sum = 0;
    int digits = 0;

    // Определяем количество цифр
    while (original > 0) {
        original /= 10;
        digits++;
    }

    original = num;

    // Вычисляем сумму цифр, возведенных в степень количества цифр
    while (original > 0) {
        int digit = original % 10;
        sum += poow(digit, digits);
        original /= 10;
    }

    return sum == num;
}

int main() {
    int limit;

    std::cout << "Введите число: ";
    std::cin >> limit;

    std::cout << "Числа Армстронга меньше " << limit << ":\n";

    for (int i = 0; i < limit; ++i) {
        if (is_armstrong(i)) {
            std::cout << i << std::endl;
        }
    }

    return 0;
}
