#include <iostream>
#include <cmath>


int main() {
    double x,y,a,b,z,c,d,k;

    std::cout << "Введите значение x: ";
    std::cin >> x;
    std::cout << "Введите значение z: ";
    std::cin >> z;
    std::cout << "Введите значение k: ";
    std::cin >> k;
    
    std::cout << "Введите значение c: ";
    std::cin >> c;
    std::cout << "Введите значение d: ";
    std::cin >> d;



    
    a= (log(x)-k);
    b= sqrt(z);
    
    y= (d*d + (c*c)/(0,75*a)+b);
    
    std::cout << "Получено значение y: "<<y;

    return 0;
}