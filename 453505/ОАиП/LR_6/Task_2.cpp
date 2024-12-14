#include <iostream>
#include <vector>
void writen(std::vector<char> &vec) {
    
    for (char ch: vec) {
        std::cout << ch;
    }
}
std::vector<char> analis(std::vector<char> &vec) {
    char a;
    bool vvod = false;
    bool no_great=true;

        vvod = false;
        no_great=false;
        std::cout << "Введите строку (нажмите ENTER, когда захотите закончить ввод символов):\n";

        while ((a = getchar()) != '\n') {
            vec.push_back(a);
        }

    std::cout << "Вы ввели строку: ";
    for (char ch : vec) {
        std::cout << ch;
    }

    return vec;
}

void osnova() {
    std::vector<char> c;
    std::vector<char> stroca;
    char simvol;
    c = analis(c);
    stroca = analis(stroca);

    int count = 0; 
    char currentChar = '\0'; 
    bool foundEvenGroup = false; 

    for (int i = 0; i <= c.size(); ++i) {
        char simvol_find =simvol;

        if (simvol_find != currentChar && simvol_find == c[i]) {
            for (char ch :stroca)
            {
                c.push_back(ch);
            }
            foundEvenGroup = true;
        }
    }

    if (!foundEvenGroup) {
        std::cout << "Не найдено нужных элементов!\n";
    }
}

int main() {
    char otvet;
    std::cout << "\nВ тексте после указанного символа вставить подстроку.\n\nВыполнил задание №2: Ширко Владимир.\nВариант-№4(19 в списке)\n\n";
    do {
        osnova();
        std::cout << "\nЕсли хотите продолжить, то введите 'y' или 'Y', иначе введите любой другой символ: ";
        std::cin >> otvet;
        std::cin.ignore();
    } while (otvet == 'y' || otvet == 'Y');

    std::cout << "Программа завершена.\n";

    return 0;
}