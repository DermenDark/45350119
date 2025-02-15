#include <iostream>
#include <string>

void writen(const std::string& str) {
    std::cout << str << std::endl;
}

std::string analis(int fakt) {
    std::string input;

    switch (fakt) {
        case 1:
            std::cout << "\n\tВведите текст, который будет обрабатывать код.\n\t(нажмите ENTER, когда захотите закончить ввод символов): ";
            break;
        case 2:
            std::cout << "\n\tВведите подстроку, которую собираетесь использовать для вставки \n\t(нажмите ENTER, когда захотите закончить ввод символов): ";
            break;
        default:
            std::cout << "\nВведите строку, которую собираетесь использовать:\n";
            break;
    }

    std::getline(std::cin, input);

    std::cout << "\nВы ввели строку: ";
    writen(input);

    return input;
}

void osnova() {
    std::string c;
    std::string stroca;

    char simvol;

    c = analis(1);
    stroca = analis(2);
    std::cout << "\nВведите символ для замены: ";
    std::cin >> simvol;
    std::cin.ignore(); 

    size_t pos = 0;
    while ((pos = c.find(simvol, pos)) != std::string::npos) {
        c.replace(pos+1, 1, stroca); 
        pos += stroca.length(); 
    }

    std::cout << "Результат после замены: ";
    writen(c);
}

int main() {
    char otvet;
    std::cout << "\nВ тексте заменить все вхождения символа на подстроку.\nВыполнил задание №2: Ширко Владимир.\nВариант-№4(19 в списке)\n\n";
    do {
        osnova();
        std::cout << "\nЕсли хотите продолжить, то введите 'y' или 'Y', иначе введите любой другой символ: ";
        std::cin >> otvet;
        std::cin.ignore();
    } while (otvet == 'y' || otvet == 'Y');

    std::cout << "Программа завершена.\n";

    return 0;
}