#include <iostream>

const int MAX_SIZE = 256; 

void writen(char* arr, int begin, int end) {
    for (int i = begin; i < end; ++i) {
        std::cout << arr[i];
    }
}
void writen_1(const char* arr) {
    std::cout<<"Вы ввели строку:";
    while (*arr) {
        std::cout << *arr;
        arr++;
    }
    std::cout <<"\n";
}

int analis(char* arr) {
    char a;
    int index = 0;
    bool no_great = true;

    while (no_great) {
        no_great = true;
        std::cout << "Введите строку (нажмите ENTER, когда захотите закончить ввод символов):\n";

        while ((a = getchar()) != '\n') {
            if (a == '0' || a == '1') {
                if (index < MAX_SIZE) {
                    arr[index++] = a;
                }
                no_great = false;
            } else {
                std::cout << "Кривые руки ввели неверно символ: " << a << "\n";
            }
        }

        if (no_great) {
            std::cout << "\nВы ввели полностью неправильные символы!!!\n";
        }
        else{
            writen_1(arr);
        }
    }

    return index;
}

void osnova() {
    char c[MAX_SIZE];
    int size = analis(c);

    int count = 0;
    char currentChar = '\0';
    bool foundEvenGroup = false;

    std::cout << "Группы с четным количеством символов:\n";

    for (int i = 0; i <= size; ++i) {
        char simvol_find = (i < size) ? c[i] : '\0';

        if (simvol_find == currentChar) {
            count++;
        } else {
            if (count % 2 == 0 && count > 0) {
                std::cout << "\nГруппа: ";
                writen(c, i - count, i);

                std::cout << "\n\tСимвол " << currentChar << " встречается " << count << " раз(a).\n\tНачало группы-[" << (i - count + 1) << "].  Конец группы-[" << i << "].\n\n";
                foundEvenGroup = true;
            }

            currentChar = simvol_find;
            count = 1;
        }
    }

    if (!foundEvenGroup) {
        std::cout << "0\n";
    }
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