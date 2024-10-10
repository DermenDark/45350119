#include <iostream>
#include <cmath>


int main() {
    double x,y,s,a,b,d;

    std::cout << "Введите значение x: ";
    std::cin >> x;
    std::cout << "Введите значение y: ";
    std::cin >> y;
    std::cout << "Введите значение d: ";
    std::cin >> d;
    
    b= (x+d);
    a= ((d*x)/b);
    s= ( (a*a + b*cos(x*(180/3.141592)) )/( pow(d,3) + (a + d - b) ) );
    
    std::cout << "Получено значение s: "<<s;

    return 0;
}

