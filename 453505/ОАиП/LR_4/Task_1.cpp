#include <iostream>
#include <cmath>

void massiv() {
    long long int k;            
    bool proverka = true;

    std::cout << "\nВведите количество элементов в массиве: ";
    std::cin>>k;

    long double arr[k]; 
    std::cout << "\nВведите массив чисел (разделяйте числа пробелами): ";
 
    for (int i = 0; i < k; ++i) {std::cin>>arr[i];}

    for (int i = 0; i < k; ++i) {
        if (std::isnan(arr[i])) {
            std::cout << "\nНеверно введённый массив.\n" <<i <<"-номер вводимого элемента, с которым возникли трудности.";
            return;

        }
    }
    
    for (int i = 0; i < k-1; ++i) {if(arr[i]<arr[i+1]){proverka = false;}}
    
    if (proverka) {
        std::cout << "Массив отсортирован!!!\n";
    } 
    else {
        std::cout << "Массив не отсортирован.\n";
    }

    std::cout << "Массив: ";
    for (int i = 0; i < k; ++i) {std::cout << arr[i] << " ";}
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