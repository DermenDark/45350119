#include <iostream>
#include <cmath>


int main() {
    double x,y,a,b,z,k,c,d,t;

    std::cout << "Введите значение x: ";
    std::cin >> x;
    std::cout << "Введите значение y: ";
    std::cin >> y;
    std::cout << "Введите значение z: ";
    std::cin >> z;
    
    std::cout << "Введите значение d: ";
    std::cin >> d;
    std::cout << "Введите значение c: ";
    std::cin >> c;
    std::cout << "Введите значение k: ";
    std::cin >> k;
    
    a= (x*y);
    b= sqrt(z);
    
    t= (cos(x*(180/3.141592))+ (a*a)/(k-c*d)-b);
    
    std::cout << "Получено значение t: "<<t;

    return 0;
}