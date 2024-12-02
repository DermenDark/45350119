#include <sstream>  
#include <vector>
#include <iostream>

void massiv() {
    long double n, m;  
    bool proverka = true;
    std::cout << "\nВведите размер матрицы чисел (mxn, разделяйте числа пробелами): ";
    std::cin>>m>>n;
    std::cout << "\nВведите матрицу чисел (разделяйте числа пробелами): ";
    long double count = m*n;



    long double* vec = (long double*)malloc(count * sizeof(long double));
    if (vec == nullptr) {
        std::cout << "Ошибка выделения памяти\n";
        return;
    }


    for (size_t i = 0; i < count - 1; ++i) {
        if (vec[i] < vec[i + 1]) {  
            proverka = false;
            break;
        }
    }
    
    if (proverka) {
        std::cout << "Массив отсортирован!!!\n";
    } else {
        std::cout << "Массив не отсортирован.\n";
    }

    std::cout << "Массив: ";
    for (size_t i = 0; i < count; ++i) {
        std::cout << vec[i] << " ";
    }
    free(vec); 
    std::cout << std::endl;
}

int main() {
    char otvet;
    std::cout << "Определить произведение положительных элементов, расположенных ниже главной диагонали матрицы.\nВыполнил задание:Ширко Владимир.\nВариант-№4(19 в списке)\n";
    do {
        massiv();
        std::cout << "\nХотите ввести еще одну матрицу? (y-да/n-нет): ";
        std::cin >> otvet;
        std::cin.ignore();
    } while (otvet == 'y' || otvet == 'Y');
    
    std::cout << "Программа завершена.\n";
    
    return 0;
}