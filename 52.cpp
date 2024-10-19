#include <iostream>
#include <cstring>
#include <iomanip>

union FloatInt {
    float f;
    uint32_t i;
};

void printFloatBinary(float num) {
    FloatInt fi;
    fi.f = num;

    std::cout << "Float: " << num << "\n";
    std::cout << "Binary representation: ";

    for (int j = 31; j >= 0; --j) {
        std::cout << ((fi.i >> j) & 1);
        if (j == 24 || j == 16 || j == 8) {
            std::cout << " "; // Добавить пробелы для удобства чтения
        }
    }
    std::cout << "\n";
}

int main() {
    float num = -52.52f; // Пример числа
    printFloatBinary(num);
    return 0;
}
