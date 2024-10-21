#include <iostream>

double sqrt(double number) {
    double x = number;
    double y = 1.0;
    double e = 0.000001; // точность

    while (x - y > e) {
        x = (x + y) / 2;
        y = number / x;
    }
    return x;
}
double exp(double x) {
    double term = 1.0; 
    double sum = term;
    int n = 1;

    while (n < 10) {
        term *= x / n;
        sum += term;
        n++;
    }
    return sum;
}
double factorial(int n) {
    double res = 1;
    for (int i = 1; i <= n; i++) {
        res *= i;
    }
    return res;
}

double pooow(double osnov,int step){
    double res=1;
    for(int n=0;n<step; n++){
        res *= osnov;
        
    }
    return res;
}

double sinn(double kor){
    double x_2,e=6.28318530716,resul;

    x_2= (kor / e);

    long long int x_3 = (kor / e);

    double ress = (x_2-x_3)*e;
    double res=0,prom;

    for(int n=1; n<15;n++){
        prom= pooow(ress,(2*n-1))/factorial(2*n-1);
        if (n % 2 != 1) {
            prom= -prom;
        }
        res += prom;
    }

    return res;
}
double coss(double kor){
    double e = 2 * 3.141595; 
    double x_2 = kor / e;
    long long int x_3 = static_cast<long long int>(x_2); 

    double ress = (x_2 - x_3) * e; 

    double res = 0.0;


    for (int n = 0; n < 15; n++) {
        double term = pooow(ress, 2 * n) / factorial(2 * n);
        if (n % 2 == 1) {
            term = -term; 
        }
        res += term;
    }

    return res;
}

double f(double x) {
    return exp(x) + sinn(coss(x));
}

int main() {
    double start, end;

    // Ввод данных от пользователя
    std::cout << "Введите начальную точку интервала: ";
    std::cin >> start;
    std::cout << "Введите конечную точку интервала: ";
    std::cin >> end;

    // Вычисление шага
    double step = (end - start) / 100;


    double minValue = 1e10; 
    double root = start;

    for (double x = start; x <= end; x += step) {
        double value = f(x);
        if (std::abs(value) < std::abs(minValue)) {
            minValue = value;
            root = x;
        }
    }

    std::cout << "Приближенный корень уравнения: x = " << root << " с f(x) = " << f(root) << std::endl;

    return 0;
}
