#include <iostream>
#include <cmath>
#include <locale.h>
#include "../Static/bibl.h"

void rrr() {
    long double m = 0, D = 0;
    int n = 0;
    std::cout << "������� ������ �������:";
    std::cin >> n;

    m = prozessing(n);
    D = computeDispersion(n, m);

    std::cout << " �������������� ��������:" << m << '\n' << "���������:" << D;
}

int main() {
    setlocale(LC_ALL, "Russian");

    char otvet;
    std::cout << "��������� ��������� ��� ���������� ��������������� �������� m � ��������� D.\n\n�������� ������� ����� 1:����� ��������.\n�������-�4(19 � ������)\n";

    do {
        rrr();

        std::cout << "\n������ ������ ��� ���� ������ �������? \n(y-��/n-���): ";
        std::cin >> otvet;
        std::cin.ignore();

    } while (otvet == 'y' || otvet == 'Y');

    std::cout << "��������� ���������.\n";

    return 0;
}
