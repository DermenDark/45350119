#include <iostream>
#include <cmath>


int main() {
    double x,b,c,d,k,p,n,q;

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
    std::cout << "Введите значение n: ";
    std::cin >> n;
    
    b= cos(x*(180/3.141592));
    c= (p-n);
    
    q= ((b*b)/(k*d) + b*pow(c,3));
    
    std::cout << "Получено значение q: "<<q;

    return 0;
}