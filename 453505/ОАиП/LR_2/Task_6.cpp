#include <iostream>
#include <cmath>


int main() {
    double x,y,a,d,n,m,k;

    std::cout << "Введите значение x: ";
    std::cin >> x;
    std::cout << "Введите значение n: ";
    std::cin >> n;
    
    std::cout << "Введите значение m: ";
    std::cin >> m;
    std::cout << "Введите значение k: ";
    std::cin >> k;
    
    a= fabs(n+m);
    d= tan(x*(180/3.141592));
    
    y= (1,29+ k/a - d*d);
    
    std::cout << "Получено значение y: "<<y;

    return 0;
}