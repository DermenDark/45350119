#include <sstream>  
#include <vector>
#include <iostream>

void massiv() {
    std::vector<long double> vec;  
    std::string input;             
    bool no_num = true;
    bool proverka = true;
    
    std::cout << "\nВведите массив чисел (разделяйте числа пробелами): ";
    std::getline(std::cin, input);  

    std::stringstream ss(input);  
    long double num;
    

    while (ss >> num) {
        vec.push_back(num);
    }

    if (ss.fail() && !ss.eof()) {
        std::cout << "Ошибка.Были введены элементы, не являющиеся числами.\n";
        return;
    }


    for (size_t i = 0; i < vec.size() - 1; ++i) {
        if (vec[i] < vec[i + 1]) {  
            proverka = false;
            break;
        }
    }
    
    if (proverka) {
        std::cout << "Массив отсортирован.\n";
    } else {
        std::cout << "Массив не отсортирован.\n";
    }

    std::cout << "Массив: ";
    for (size_t i = 0; i < vec.size(); ++i) {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    char otvet;
    std::cout << "Определить, упорядочены ли элементы массива по убыванию.\nВыполнил задание:Ширко Владимир.\nВариант-№4(19 в списке)\n";
    do {
        massiv();
        std::cout << "\nХотите ввести еще один массив чисел? (y-да/n-нет): ";
        std::cin >> otvet;
        std::cin.ignore();
    } while (otvet == 'y' || otvet == 'Y');
    
    std::cout << "Программа завершена.\n";
    
    return 0;
}