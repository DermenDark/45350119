#include <iostream>
#include <string>
#include <algorithm>
std::string subtract(std::string&, std::string&);

std::string divideByTwo(const std::string& num) {
    std::string result;
    int remainder = 0;
    
    for (char digit : num) {
        int current = remainder * 10 + (digit - '0');
        result.push_back((current / 2) + '0');
        remainder = current % 2;
    }

    // Удаление ведущих нулей
    while (result.size() > 1 && result[0] == '0') {
        result.erase(result.begin());
    }

    return result.empty() ? "0" : result;
}

// Нахождение остатка от деления числа на 2
int findRemainder(const std::string& num) {
    return (num.back() - '0') % 2;
}

std::string pram(const std::string& num) {
    std::string binary; 
    std::string temp = num; 
    bool isNegative = false;
    
    if (temp[0] == '-') {
        isNegative = true;
        temp = temp.substr(1); 
    }
    
    while (temp != "0") { 
        int rem = findRemainder(temp);
        binary.push_back(rem + '0'); 
        temp = divideByTwo(temp);
    }

    std::reverse(binary.begin(), binary.end()); // Разворачиваем результат

    // Добавляем знак числа
    binary.insert(binary.begin(), isNegative ? '1' : '0');
    return binary;
}

std::string obrat_pram(const std::string& num) {
    std::string binary=num;

    if (num[0] != '1') {
        return binary;
    }

    for (size_t i = 1; i < binary.size(); i++) {
        binary[i] = (binary[i] == '1') ? '0' : '1';
    }
    return binary;
}

std::string toObratCode(const std::string& num) {
    std::string binary = pram(num);

    if (num[0] != '-') {
        return binary;
    }

    for (size_t i = 1; i < binary.size(); i++) {
        binary[i] = (binary[i] == '1') ? '0' : '1';
    }

    return binary;
}

std::string addd(std::string &num_1, std::string &num_2) {
    std::string temp_1 = num_1;
    std::string temp_2 = num_2;
    std::string res;

    // Выровнять длины строк, дополняя нулями слева
    while (temp_1.size() < temp_2.size()) temp_1 = '0' + temp_1;
    while (temp_2.size() < temp_1.size()) temp_2 = '0' + temp_2;

    char ostat = '0';

    // Сложение чисел побитно с конца
    for (int i = temp_1.size() - 1; i >= 0; i--) {
        char el_1 = temp_1[i];
        char el_2 = temp_2[i];

        if (el_1 == '1' && el_2 == '1' && ostat == '1') {
            res.push_back('1');
            ostat = '1';
        } else if ((el_1 == '0' && el_2 == '1' && ostat == '1') ||
                   (el_1 == '1' && el_2 == '0' && ostat == '1')) {
            res.push_back('0');
            ostat = '1';
        } else if (el_1 == '1' && el_2 == '1' && ostat == '0') {
            res.push_back('0');
            ostat = '1';
        } else if ((el_1 == '0' && el_2 == '1' && ostat == '0') ||
                   (el_1 == '1' && el_2 == '0' && ostat == '0')) {
            res.push_back('1');
            ostat = '0';
        } else if (el_1 == '0' && el_2 == '0' && ostat == '1') {
            res.push_back('1');
            ostat = '0';
        } else if (el_1 == '0' && el_2 == '0' && ostat == '0') {
            res.push_back('0');
            ostat = '0';
        }
    }

    if (ostat == '1' && num_1[0] == '0' && num_2[0] == '0') {
        res.push_back('1');
    }

    std::reverse(res.begin(), res.end());
    return res;
}


void osnova() {
    std::string number,number_2; 
    std::cout << "Введите целое число (положительное или отрицательное): ";
    std::cin >> number; 
    std::cout << "Введите целое число (положительное или отрицательное): ";
    std::cin >> number_2;
    std::string res = pram(number);
    std::string res_1 = toObratCode(number);
    std::string res_2 = toObratCode(number_2);
    std::cout << "\nДвоичное представление числа " << number << " в прямом коде равно " << res << std::endl;
    std::cout << "Двоич. представление числа " << number << " в обратном коде равно " << res_1 << std::endl;
    std::cout << "Двоичное представление второго числа в обратном коде:" << res_2<< std::endl;
    std::cout << "Двоичное представление числа " << number << " в обратном коде сумма чисел равна " << addd(res_1,res_2) << std::endl;
    std::cout << "Двоичное представление числа " << number << " в обратном коде сумма чисел равна " << obrat_pram(addd(res_1,res_2)) << std::endl;
}

int main() {
    char otvet;
    std::cout << "\nНайдите сумму двоичных чисел, заданных в естественной форме.Сложение выполните в обратном коде. Ответ выразите в прямом коде.\n\nВыполнил задание №2: Ширко Владимир.\nВариант-№4(19 в списке)\n\n";

    do {
        osnova();
        std::cout << "\nЕсли хотите продолжить, то введите 'y' или 'Y', иначе введите любой другой символ: ";
        std::cin >> otvet;
        std::cin.ignore();
    } while (otvet == 'y' || otvet == 'Y');

    std::cout << "Программа завершена.\n";

    return 0;
}