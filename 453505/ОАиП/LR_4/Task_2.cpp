 #include <iostream>

void massiv() {

    int n, m;  
    bool proverka = true;

    std::cout << "\nВведите размер матрицы чисел (mxn, разделяйте числа пробелами): ";
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
        for (int j = 0; j < n; ++j) {
            arr_2[j][m - 1 - i] = arr[i][j];  
        }
    }

    std::cout << "Массив: ";
    for (int i = 0; i < n; ++i) {
        std::cout <<"\n";
        for (int j = 0; j < m; ++j){
        std::cout <<arr_2[i][j] << " ";
        }
    }

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