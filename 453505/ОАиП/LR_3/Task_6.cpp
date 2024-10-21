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
    std::cout << "\nRes1: "<< x_2;

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
    double e=6.28318530716;
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

double exp_taylor(double x) {
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
double lnn(double x) {
    if (x <= 0) {
        std::cerr << "Ошибка: значение должно быть больше 0" << std::endl;
        return 0; 
    }

    double estimate = x; 
    double epsilon = 1e-10; 

    while (true) {
        double next_estimate = estimate - (exp_taylor(estimate) - x) / exp_taylor(estimate);
        estimate = next_estimate;
    }
    return estimate;
}

int main() {
    double x;
    std::cout << "Введите значение x (x > 0): ";
    std::cin >> x;

    double a = sinn(x);
    std::cout << a;
    double b = coss(x);
    std::cout << b;
    double c = lnn(x);
    std::cout << c;

    // Находим минимальное значение
    double min_value = a;
    if (b < min_value) min_value = b;
    if (c < min_value) min_value = c;

    std::cout << "Минимальное значение: " << min_value << std::endl;
    return 0;
}
