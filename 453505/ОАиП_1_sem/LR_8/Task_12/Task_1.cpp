#include "funk1/begin.h"

std::string fl = "file.txt"; 

int main() {
    
    char otvet; 
    std::cout << "\nCправочная автовокзала и расписание движения автобусов.\n\nВыполнил задание №1:  Ширко Владимир.";

    do {
        menu();
        funk_menu();
        std::cout << "\n\nЕсли хотите продолжить, то введите 'y' или 'Y', иначе введите любой другой символ: ";
        std::cin >> otvet;
        std::cin.ignore();
    } while (otvet == 'y' || otvet == 'Y');
    std::cout << "Программа завершена.\n";

    return 0;
}