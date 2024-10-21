#include <iostream>
double prov(double c){
    while (true) {
        char c;
        bool valid;
        valid = true;
        int num = 0;
        while (std::cin.get(c) && c != '\n') {
            if (c < '0' || c > '9') {
                valid = false;
                break;
            }
            num = num * 10 + (c - '0');
        }
        if (valid && num > 0) {
            std::cout << "Ввод корректен" << std::endl;
            break;
        } else {
            std::cout << "Ввод некорректен, попробуйте снова:" << std::endl;
            std::cin.clear(); // Очистка состояния
            std::cin.ignore(1000, '\n'); // Игнорирование остатка строки
        }}
    return 
}
int main() {
    double sine_value = prov(22);
    std::cout << "\nSine value: " << sine_value << std::endl;
    return 0;
}
