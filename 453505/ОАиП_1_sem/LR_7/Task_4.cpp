#include <iostream>
using namespace std;

bool is_divisible(int n, int p) {
    while (n >= p) {
        int shift = 0;
        while ((p << shift) <= n) {shift++;}
        --shift;
        n -= p << shift;}
    return n == 0;
}

void osnova() {
    int prov[] = {3, 61, 131};

    int user_number;
    cout << "Введите число для проверки: ";
    cin >> user_number;

    for (int i = 0; i < 3; i++) {
        bool result = is_divisible(user_number, prov[i]);
        cout << "\nЧисло " << user_number << " " << (result ? "делится" : "не делится") << " на " << prov[i] << ".";
    }
}

int main() {
    char otvet;
    cout << "\nВ строке, состоящей из групп нулей и единиц, найти и вывести на экран группы с четным количеством символов.\n\nВыполнил задание №3: Ширко Владимир.\nВариант-№4(19 в списке)\n\n";

    do {
        osnova();
        cout << "\nЕсли хотите продолжить, то введите 'y' или 'Y', иначе введите любой другой символ: ";
        cin >> otvet;
        cin.ignore();
    } while (otvet == 'y' || otvet == 'Y');

    cout << "Программа завершена.\n";

    return 0;
}