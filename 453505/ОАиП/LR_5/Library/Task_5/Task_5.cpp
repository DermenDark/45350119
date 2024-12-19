#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>

#define li long int

li glav_diog(const std::vector< std::vector<li>>& X) {
    int a = 0, B = 0, proisv = 0;
    std::vector<li> Y(B);

    for (int i = 0; i < X.size(); ++i) {
        for (int j = 0; j < X[i].size(); ++j) {
            if (X[i][j] % 2 == 1 && (j) % 2 == 1) {
                Y.push_back(X[i][j]);
                ++a;
            }
        }
    }

    for (int i = 0; i < Y.size(); ++i) {
        proisv += Y[i];
    }
    return (proisv / a);
}
void glavn() {
    std::vector< std::vector<li>> X;
    std::string input;

    std::cout << "������� �������� ������� \n(���� ���- ���� ������� �������, ��������� ���� ����� ������ �������):\n";

    while (true) {
        std::getline(std::cin, input);

        if (input.empty()) {
            break;
        }

        std::stringstream ss(input);
        std::vector<li> row;
        li num;

        while (ss >> num) {
            row.push_back(num);
        }

        if (!row.empty()) {
            X.push_back(row);
        }
    }
    for (int i = 0; i < X.size(); ++i) {
        for (int j = 0; i < X[i].size(); ++j) {
            std::cout << "X[" << i << "][" << j << "]" << X[i][j] << '\n';
        }
    }
    long double M = glav_diog(X);
    std::cout << "res: " << M << std::endl;
}
int main() {

    setlocale(LC_ALL, "Russian");
    char otvet;
    std::cout << "��� ��������� ������������ ������ ����� �����. �������� ��������� ������� ������� ������ � ����������.\n������� ������������ ������ �� ���������, ������������� � ������ �������� ������� ������� � ��������������� ��������.\n��������� ������� �������������� ���������������������� �������.��\n\n�������� ������� ����� 4:����� ��������.\n";

    do {
        glavn();

        std::cout << "\n������ ������ ��� ���� ������?? \n(y-��/n-���): ";
        std::cin >> otvet;
        std::cin.ignore();

    } while (otvet == 'y' || otvet == 'Y');
    std::cout << "��������� ���������.\n";

    return 0;
}