#include <iostream>
#include <cmath>


int main() {
    double x,y,a,b,c,d,k,p;

    std::cout << "Введите значение x: ";
    std::cin >> x;
    std::cout << "Введите значение c: ";
    std::cin >> c;
    std::cout << "Введите значение d: ";
    std::cin >> d;
    std::cout << "Введите значение k: ";
    std::cin >> k;
    std::cout << "Введите значение p: ";
    std::cin >> p;
    
    b= exp(k);
    a= (x+sin(p*(180/3.141592)));
    
    y= (1 + (k*k)/( 2*a*b) - b + d*c);
    
    std::cout << "Получено значение y: "<<y;

    return 0;
}