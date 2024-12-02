#include <iostream>
#include <cmath>

void massiv() {

    long long int n, m;  
    long double proisved=1;

    std::cout << "\nВведите размер матрицы чисел (nxm, разделяйте числа пробелами): ";
    std::cin>>m>>n;
    std::cout << "\nВведите матрицу чисел (разделяйте числа пробелами): ";

    long double count = m*n;
    long double arr[m][n],arr_2[n][m];

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j){
        std::cin>>arr[i][j];
        }
    }
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j){
        if (std::isnan(arr[i][j])) {
            std::cout << "\nНеверно введённа матрица.\n[" <<i <<"] и ["<<j<<"]-номер вводимого элемента, с которым возникли трудности.";
            return;

        }}}

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (arr[i][j] > 0) {
            proisved*=arr[i][j];
            }}}

    std::cout << "Матрица: ";
    for (int i = 0; i < n; ++i) {
        std::cout <<"\n";
        for (int j = 0; j < m; ++j){
        std::cout <<arr[i][j] << " ";
        }
    }

    std::cout << "\nРезультат произведения:"<<proisved<<'\n';
}

int main() {
    char otvet;
    std::cout << "Определить произведение положительных элементов, расположенных ниже главной диагонали матрицы.\nВыполнил задание №2:Ширко Владимир.\nВариант-№4(19 в списке)\n";
    do {
        massiv();
        std::cout << "Хотите ввести еще одну матрицу? (y-да/n-нет): ";
        std::cin >> otvet;
        std::cin.ignore();
    } while (otvet == 'y' || otvet == 'Y');
    
    std::cout << "Программа завершена.\n";
    
    return 0;
}