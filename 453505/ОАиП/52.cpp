#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>

int digitsCount(float n) {
    std::ostringstream oss;
    oss << std::fixed << std::setprecision(1) << n;  // Устанавливаем нужную точность
    std::string numberStr = oss.str();  // Преобразуем в строку

    return numberStr.length();  // Возвращаем количество символов
}

int main() {
    float value;
    std::cout << "value: ";
    std::cin >> value;
    
    int count = digitsCount(value);
    std::cout << "digits count: " << count << std::endl;

    return 0;
}
