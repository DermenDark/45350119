#include <iostream>

void osnova() {
    std::cout<<5;
}

int main() {
    char otvet;
    std::cout << "\nВ строке, состоящей из групп нулей и единиц, найти и вывести на экран группы с четным количеством символов.\n\nВыполнил задание №1: Ширко Владимир.\nВариант-№4(19 в списке)\n\n";

    do {
        osnova();
        std::cout << "\nЕсли хотите продолжить, то введите 'y' или 'Y', иначе введите любой другой символ: ";
        std::cin >> otvet;
        std::cin.ignore();
    } while (otvet == 'y' || otvet == 'Y');

    std::cout << "Программа завершена.\n";

    return 0;
}