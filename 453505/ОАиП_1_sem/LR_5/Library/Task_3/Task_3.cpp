#include <iostream>
#include <vector>
#include <algorithm>

#define li long int

li glav_diog(const std::vector< std::vector<li>>& X) {
    int B=0,proisv=1;
    bool found = false;
    std::vector<li> Y(B);

    for (int i = 0; i < X.size(); ++i) {
        for (int j = 0; j < X[i].size(); ++j) {
            if (i==j && X[i][j] % 2 == 0) {
                Y.push_back(X[i][j]);
                found = false;
            }
        }
    }
   
    if (!found) {
        std::cout << "�� ������� ��������� ��� ������ ���������.\n";
        return 0;
    }

    std::reverse(Y.begin(), Y.end());
    if (proisv == 1) { return 0; }
    for (int i = 0; i < Y.size(); ++i) {
        proisv *= Y[i];
        std::cout<<"Y[" <<i<<"]" << Y[i]<<'\n';
    }
    return proisv;
}

void osnova() {
    int N = 0, k = 0;
    bool validInput = false;


    while (!validInput) {
        std::cout << "\n������� ������� ������� (N x K): ";
        std::cin >> N >> k;

        if (N <= 0 || k <= 0) {
            std::cout << "\n������� �������� �������. ������� ������ ���� ������ ����.\n";
        }
        else if (std::cin.fail()) {
            std::cout << "\n������� �������� �������.";
        }
        else {
            validInput = true; 
        }
    }

    std::vector< std::vector<li>> X(N, std::vector<li>(k));
    std::cout << "������� �������� �������\n(���� ����� ������ �������, �� ����� �����):\n";

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            std::cout << "������� ������� X[" << i << "][" << j << "]: ";
            std::cin >> X[i][j];
            if (std::cin.fail()) {
                std::cout << "\n������� �������� ������� � ������� X[" << i << "][" << j << "]\n";
                return;
            }
        }
    }

    long double M = glav_diog(X);
    std::cout << "������������ ��������� ���������: " << M << std::endl;
}
int main() {

    setlocale(LC_ALL, "Russian");

    char otvet;
    std::cout << "������� ������������ ������ �� ���������, ������������� �� ������� ��������� ������� � ������� ������ ��������.\n��������� ������������ ��������� ������������� �������.\n\n�������� �������:����� ��������.\n�������-�4(19 � ������)\n";

    do {
        osnova();
        std::cout << "\n������ ������ ��� ���� ������ �����? \n(y-��/n-���): ";
        std::cin >> otvet;
        std::cin.ignore();
    } while (otvet == 'y' || otvet == 'Y');

    std::cout << "��������� ���������.\n";

    return 0;
}