#include<iostream>

void osnova(){
    std::vector<char> c;
    char a;

    std::cout << "Введите строку:\n ";

    while ((a = getchar()) != '\n') {
        c.push_back(a);
    }

    std::cout << "Вы ввели строку: ";

    for (char ch : c) {
        std::cout << ch;
    }

    std::cout << std::endl;
}

int main() {
    char otvet;
    std::cout << "\nВ строке, состоящей из групп нулей и единиц, найти и вывести на экран группы с четным количеством символов.\n\nВыполнил задание:Ширко Владимир.\nВариант-№4(19 в списке)\n\n";
    do {
        osnova();
        std::cout << "\nХотите ввести еще один массив чисел? \n(Если хотите продолжить то введите 'y' или 'да', иначе ввести любой символ): ";
        std::cin >> otvet;
        std::cin.ignore();
    } while (otvet == 'y' || otvet == 'Y');
    
    std::cout << "Программа завершена.\n";
    
    return 0;
}