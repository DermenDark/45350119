#include <iostream>
#include <cmath>


int main() {
    double x,y,a,b,c,d,p,h,k;

    std::cout << "Введите значение x: ";
    std::cin >> x;
    
    std::cout << "Введите значение p: ";
    std::cin >> p;
    std::cout << "Введите значение h: ";
    std::cin >> h;
    
    std::cout << "Введите значение k: ";
    std::cin >> k;
    std::cout << "Введите значение c: ";
    std::cin >> c;
    
    std::cout << "Введите значение d: ";
    std::cin >> d;

    
    a= x-p;
    b= log(h);
    
    y= (0,78*b + pow(a,3)/(k*c*d));
    
    std::cout << "Получено значение y: "<<y;

    return 0;
}