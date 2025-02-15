#include <iostream>
#include <vector>
void writen(std::vector<char> &vec,int begin, int end) {
    
    for (int i=begin; i<end;++i) {
        std::cout << vec[i];
    }
}

std::vector<char> analis(std::vector<char> &vec) {
    char a;
    bool vvod = false;
    bool no_great=true;

    while (no_great)
    {
        vvod = false;
        no_great=true;
        std::cout << "Введите строку (нажмите ENTER, когда захотите закончить ввод символов):\n";

        while ((a = getchar()) != '\n') {
            if (a == '0' || a == '1') {
                vec.push_back(a);
                no_great=false;
            } 
            else {
                vvod = true;
            }
        }
        if(no_great){
            std::cout << "\nВы ввели полностью неправильные символы!!!\nВы ввели полностью неправильные символы!!!\nВы ввели полностью неправильные символы!!!\n";
            no_great=true;
            }
    }

    if (vvod) {
        std::cout << "\nВы ввели строку неверно! (мы убрали ненужные символы): ";

        for (char ch : vec) {
            std::cout << ch;
        }
    } 

    return vec;
}

void osnova() {
    std::vector<char> c;
    c = analis(c);

    int count = 0; 
    char currentChar = '\0'; 
    bool foundEvenGroup = false; 

    std::cout << "Группы с четным количеством символов:\n";

    for (int i = 0; i <= c.size(); ++i) {
        char simvol_find = c[i];

        if (simvol_find == currentChar) {
            count++;
        } 
        else {
            if (count % 2 == 0 && count > 0) {
                std::cout << "\nГруппа: ";
                writen(c,(i-count),i);

                std::cout << "\n\tСимвол " <<currentChar << " встречается " << count << " раз(a).\n\tНачало группы-["<<i-count+1<<"].  Конец группы-["<<i<<"].\n\n";
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