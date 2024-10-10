#include <iostream>
#include <cmath>

int main() {
    double x,y,z,a,b,fx,pi=3.141592;
    int swit;

    std::cout << "Введите значение z: ";
    std::cin >> z;
    std::cout << "Введите значение a: ";
    std::cin >> a;
    std::cout << "Введите значение b: ";
    std::cin >> b;

    std::cout << "Выберете нужную вам функцию\n1. f(x)=2x\n2. f(x)=x^3\n3. f(x)=x/3\n Введите ваш выбор(1,2,3):";
    std::cin >> swit;
    
    z<1 ? x=z:x=sqrt(pow(z,3));
    
    switch(swit){
        case 1:
            fx= (2*x);
        break;
        case 2:
            fx= pow(x,3);
        break ;
        case 3:
            fx= (x/3);
        break;
        default:
            std::cout << "операция выбрана неверно ";
        return 0;
    }

     y= ( -pi*fx + a*pow( cos(pow(x,3)) ,2) + b*pow( sin(pow(x,2)) ,3 ) );
    
    std::cout << "\nполучено y: "<<y;
    
    return 0;
}