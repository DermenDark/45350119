#include <iostream>
#include <vector>
#include <algorithm>

#define ld long double

ld glav_proz(std::vector<ld>& X) {
    int a = 0, B = 0, proisv = 1;
    std::vector<ld> Y(B);

    for (int i = 0; i < X.size(); ++i) {
            if (X[i] == 0) {
                Y.push_back(i);
                ++a;
            }
    }

    std::reverse(X.begin(), X.end());

    std::cout << '\n'<<"������������ ����������� ������:";
    for (int i = 0; i < X.size(); ++i) {
        std::cout << "X[" << i << "]" << X[i] << ' ';
    }


    std::cout << '\n'<<"������� ������� ��������:";
    for (int i = 0; i < Y.size(); ++i) {
        std::cout << "X[" << Y[i] << "]=" << 0 << ' ';
    }
    return a;
}
void glavn() {
    std::cout << "��������� ���������.\n";

    int N = 0;
    std::cout << "������� ������ �������: ";
    std::cin >> N;

    std::vector<ld> X(N);
    std::cout << "������� �������� �������:\n";

    for (int i = 0; i < N; ++i) {
        std::cout << "������� ������� X[" << i << "]: ";
        std::cin >> X[i];
        if (std::cin.fail()) {
            std::cout << "\n������� �������� ������� � ������� X[" << i << "]\n";
            return;
        }
    }

    long double M = glav_proz(X);
    std::cout << "\n����������� �����: " << M << std::endl;
}
int main() {
    setlocale(LC_ALL, "Russian");
    char otvet;
    std::cout << "������� ��������� ������������ ������ ������������ �����. \n����������, ����������� �� ����� ��� �������� � ������� ���������.���� ����������� ����� ��������,\n �� ���������� �� ������� � ����� ����������.\n\n�������� ������� ����� 4:����� ��������.\n";

    do {
        glavn();

        std::cout << "\n������ ������ ��� ���� ������ �������? \n(y-��/n-���): ";
        std::cin >> otvet;
        std::cin.ignore();

    } while (otvet == 'y' || otvet == 'Y');
    std::cout << "��������� ���������.\n";
    return 0;
}