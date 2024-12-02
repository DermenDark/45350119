#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

double max_Row(const std::vector<long double>& row) {

    return *std::max_element(row.begin(), row.end());

}

void maxEl(std::vector<std::vector<long double>>& matrix) {

    std::sort(matrix.begin(), matrix.end(), [](const std::vector<long double>& a, const std::vector<long double>& b) {
        return max_Row(a) > max_Row(b);
    });

}

void matrik() {
    long long int n, m;            

    std::cout << "Введите количество строк (N): ";
    std::cin >> n;
    std::cout << "Введите количество столбцов (M): ";
    std::cin >> m;

    std::vector<std::vector<long double>> arr(n, std::vector<long double>(m));

    std::cout << "\nВведите матрицу чисел (разделяйте числа пробелами): ";
 
    for (int i = 0; i < n; ++i) {for (int j= 0; j< m; ++j){std::cin>>arr[i][j];}}

    for (int k = 0; k < n; ++k) {
        for (int f = 0; f < m; ++f){
        if (std::isnan(arr[k][f])) {
            std::cout << "\nНеверно введённа матрица.\n[" <<k <<"] и ["<<f<<"]-номер вводимого элемента, с которым возникли трудности.";
            return;

        }}
    }

    maxEl(arr);

    std::cout << "упорядоченная матрица: ";
    for (int k = 0; k < n; ++k) {
        std::cout<< "\n";
        for (int f = 0; f < m; ++f) {std::cout << arr[k][f] << " ";}
    }
    return;
    }

int main() {
    char otvet;
    std::cout << "Необходимо упорядочить строки матрицы по возрастанию наибольших элементов в её строках.\nВыполнил задание №3:Ширко Владимир.\nВариант-№4(19 в списке)\n";
    do {
        matrik();
        std::cout << "\nХотите ввести еще один массив чисел? (y-да/n-нет): ";
        std::cin >> otvet;
        std::cin.ignore();
    } while (otvet == 'y' || otvet == 'Y');
    
    std::cout << "Программа завершена.\n";
    
    return 0;
}