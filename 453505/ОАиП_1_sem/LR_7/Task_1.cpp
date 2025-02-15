#include <iostream>
#include <string>
#include <algorithm>

std::string ostat(const std::string& num) {
    std::string result;
    int ostatok = 0;
    
    for (char tek_el : num) {
        int del = ostatok * 10 + (tek_el - '0');
        result.push_back((del / 2) + '0');
        ostatok = del % 2;
    }

    while (result.size() > 1 && result[0] == '0') {
        result.erase(result.begin());
    }

    return result.empty() ? "0" : result;
}

int find_el(const std::string& num) {
    return (num.back() - '0') % 2;
}

std::string fing_gl(const std::string& num) {
    std::string binary; 
    std::string temp = num; 
    int rem=0;
    
    if (temp[0] == '-') {
        temp = temp.substr(1); 
    }
    
    while (temp != "0") { 
        rem = find_el(temp);
        binary.push_back(rem + '0'); 

        temp = ostat(temp);
    }

    std::reverse(binary.begin(), binary.end());
    
    if (num[0] == '-') {
        binary.insert(binary.begin(),'1'); 
    }
    else{
        binary.insert(binary.begin(),'0');
    }
    return binary;
}

void osnova() {
        std::string number; 
    std::cout << "Введите целое число (положительное или отрицательное): ";
    std::cin >> number; 

    std::string res = fing_gl(number);
    
    std::cout << "Двоичное представление числа " << number << " в прямом коде равно " << res << std::endl;
}

int main() {
    char otvet;
    std::cout << "\nИз естественной формы в прямой код.\n\nВыполнил задание №1: Ширко Владимир.\nВариант-№4(19 в списке)\n\n";

    do {
        osnova();
        std::cout << "\nЕсли хотите продолжить, то введите 'y' или 'Y', иначе введите любой другой символ: ";
        std::cin >> otvet;
        std::cin.ignore();
    } while (otvet == 'y' || otvet == 'Y');

    std::cout << "Программа завершена.\n";

    return 0;
}