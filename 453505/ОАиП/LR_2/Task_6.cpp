#include <iostream>
#include <cmath>


int main() {
    double x,y,a,c,s,k,d;

    std::cout << "Введите значение x: ";
    std::cin >> x;
    std::cout << "Введите значение y: ";
    std::cin >> y;
    
    std::cout << "Введите значение c: ";
    std::cin >> c;
    std::cout << "Введите значение k: ";
    std::cin >> k;
    
    a= x+y;
    d= fabs(c-a);
    
    s= (10,1+ a/c - d/(k*k));
    
    std::cout << "Получено значение s: "<<s;

    return 0;
}