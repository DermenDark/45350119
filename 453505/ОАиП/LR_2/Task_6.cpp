#include <iostream>
#include <cmath>


int main() {
    double x,y,a,b,z,c,d,k,p;

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
    std::cout << "Введите значение p: ";
    std::cin >> p;


    
    a= (sin(x*(180/3.141592)-z));
    b= fabs(p-x);
    
    y= ((a+b)*(a+b)- k/(c*d));
    
    std::cout << "Получено значение y: "<<y;

    return 0;
}
