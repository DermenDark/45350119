#include "funk1/begin.h"


size_t max__size=256;
std::string fl="file.bin";


int main() {
    
    char otvet; 
    std::cout << "\nCправочная автовокзала и расписание движения автобусов.\n\nВыполнил задание №1:  Ширко Владимир.";

    do {
        osnova();
        std::cout << "\n\nЕсли хотите продолжить, то введите 'y' или 'Y', иначе введите любой другой символ: ";
        std::cin >> otvet;
        std::cin.ignore();
    } while (otvet == 'y' || otvet == 'Y');
    std::cout << "Программа завершена.\n";

    return 0;
}