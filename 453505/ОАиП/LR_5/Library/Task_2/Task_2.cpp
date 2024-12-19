#include <iostream>
#include <Windows.h>

int main() {
    setlocale(LC_ALL, "Russian");

    HINSTANCE load;
    load = LoadLibrary(L"Dinamic.dll");


    typedef void(__stdcall* glavn)();
    glavn sapusk;

    sapusk = (glavn)GetProcAddress(load, "glavn");

    char otvet;
    std::cout << "Для заданного одномерного массива X из N элементов \nнайти количество элементов массива, \nдля которых выполняется условие sin(Xi/2)< 0.\n\nВыполнил задание номер 2:Ширко Владимир.\nВариант-№4(19 в списке)\n";

    do {
        sapusk();

        std::cout << "\nХотите ввести еще один размер массива? \n(y-да/n-нет): ";
        std::cin >> otvet;
        std::cin.ignore();

    } while (otvet == 'y' || otvet == 'Y');
    std::cout << "Программа завершена.\n";
    FreeLibrary(load);
    return 0;
}
