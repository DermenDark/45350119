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
    std::cout << "��� ��������� ����������� ������� X �� N ��������� \n����� ���������� ��������� �������, \n��� ������� ����������� ������� sin(Xi/2)< 0.\n\n�������� ������� ����� 2:����� ��������.\n�������-�4(19 � ������)\n";

    do {
        sapusk();

        std::cout << "\n������ ������ ��� ���� ������ �������? \n(y-��/n-���): ";
        std::cin >> otvet;
        std::cin.ignore();

    } while (otvet == 'y' || otvet == 'Y');
    std::cout << "��������� ���������.\n";
    FreeLibrary(load);
    return 0;
}
