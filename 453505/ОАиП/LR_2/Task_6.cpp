#include <iostream>
#include <cmath>


int main() {
    double x,y,a,b,c,d,k;

    std::cout << "Введите значение x: ";
    std::cin >> x;

    std::cout << "Введите значение k: ";
    std::cin >> k;
    std::cout << "Введите значение c: ";
    std::cin >> c;
    
    std::cout << "Введите значение d: ";
    std::cin >> d;

    
    a= log10(x);
    b= (x+ exp(d));
    
    y= ((a+b)- (c*c)/k);
    
    std::cout << "Получено значение y: "<<y;

    return 0;
}
