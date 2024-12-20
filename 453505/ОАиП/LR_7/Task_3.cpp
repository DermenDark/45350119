#include <iostream>
#include <iostream>
#include <string>
#include <algorithm>


using namespace std;


int charToValue(char c) {
    if (isdigit(c)) {
        return c - '0';
    } else {
        return toupper(c) - 'A' + 10; 
    }
}

char valueToChar(int value) {
    if (value < 10) {
        return '0' + value;
    } else {
        return 'A' + (value - 10);
    }
}


string add(string num1, string num2, int base) {
    string result;
    int carry = 0;
    int maxLength = max(num1.length(), num2.length());

    // Дополняем числа нулями слева
    num1.insert(0, maxLength - num1.length(), '0');
    num2.insert(0, maxLength - num2.length(), '0');

    for (int i = maxLength - 1; i >= 0; --i) {
        int sum = charToValue(num1[i]) + charToValue(num2[i]) + carry;
        carry = sum / base;
        result += valueToChar(sum % base);
    }

    if (carry) {
        result += valueToChar(carry);
    }

    reverse(result.begin(), result.end());
    return result;
}

// Функция для вычитания двух чисел в заданной системе счисления
string subtract(string num1, string num2, int base) {
    // Предполагаем, что num1 >= num2
    string result;
    int borrow = 0;
    int maxLength = max(num1.length(), num2.length());

    num1.insert(0, maxLength - num1.length(), '0');
    num2.insert(0, maxLength - num2.length(), '0');

    for (int i = maxLength - 1; i >= 0; --i) {
        int sub = charToValue(num1[i]) - charToValue(num2[i]) - borrow;
        if (sub < 0) {
            sub += base;
            borrow = 1;
        } else {
            borrow = 0;
        }
        result += valueToChar(sub);
    }

    while (result.length() > 1 && result.back() == '0') {
        result.pop_back();
    }

    reverse(result.begin(), result.end());
    return result;
}

void osnova() {
    int base;
    cout << "Введите основание системы счисления (2-36): ";
    cin >> base;

    if (base < 2 || base > 36) {
        cout << "Основание должно быть в диапазоне от 2 до 36." << endl;
        return ;
    }

    string num1;
    string num2;
    cout << "Введите первое число: ";
    cin >> num1;
    cout << "Введите второе число: ";
    cin >> num2;

    string sum = add(num1, num2, base);
    string difference = subtract(num1, num2, base);

    cout << "Сумма: " << sum << endl;
    cout << "Разность: " << difference << endl;
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