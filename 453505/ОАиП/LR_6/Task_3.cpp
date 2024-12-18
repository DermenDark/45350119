#include <iostream>

void writen(const char* str) {
    std::cout << str << std::endl;
}

void osnova() {
    const int MAX_SIZE = 1000;
    char c[MAX_SIZE]; 
    char line[100]; 
    int index = 0; 

    std::cout << "Введите строки (для завершения ввода введите пустую строку):\n";

    while (true) {
        std::cin.getline(line, 100); 

        if (line[0] == '\0') break; 
        for (int i = 0; line[i] != '\0'; ++i) {
            c[index++] = line[i];
        }
        c[index++] = ' ';
    }

    c[index - 1] = '\0'; 

    std::cout << "Вы ввели строки: ";
    writen(c);

    std::cout << "Слова в обратном порядке: ";
    int end = index - 1;
    for (int i = index - 1; i >= 0; ) {
        while (i >= 0 && c[i] == ' ') {
            --i;
        }
        end = i + 1;
        while (i >= 0 && c[i] != ' ') {
            --i; 
        }
        for (int j = i + 1; j < end; ++j) {
            std::cout << c[j];
        }
        if (i >= 0) {
            std::cout << ' '; 
        }
    }
    std::cout << std::endl;
}

int main() {
    char otvet;
    std::cout << "\nИмеется массив строк. На том же месте не заводя других массивов, \nзаписать слова в обратном порядке, рассматривая все строки, т.е. \nпервое слово первой строки станет последним словом последней строки\n(если объединить строки, будет гораздо проще).\n\nВыполнил задание №3: Ширко Владимир.\nВариант-№4(19 в списке)\n\n";
    do {
        osnova();
        std::cout << "\nЕсли хотите продолжить, то введите 'y' или 'да', иначе введите любой символ: ";
        std::cin >> otvet;
        std::cin.ignore();
    } while (otvet == 'y' || otvet == 'Y');
    
    std::cout << "Программа завершена.\n";
    
    return 0;
}