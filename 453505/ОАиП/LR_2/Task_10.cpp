#include <iostream>

int main() {
    double x1,y1,x2,y2,r1,r2;
    
    std::cout << "Введите значение x1: ";
    std::cin >> x1;
    std::cout << "Введите значение y1: ";
    std::cin >> y1;
    std::cout << "Введите значение r1: ";
    std::cin >> r1;

    std::cout << "Введите значение x2: ";
    std::cin >> x2;
    std::cout << "Введите значение y2: ";
    std::cin >> y2;
    std::cout << "Введите значение r2: ";
    std::cin >> r2;

    if((r2*r2)>((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1))){
        if((r1*r1)>((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1))){
            std::cout << "Да, но справедливо обратное для двух фигур ";
        }
        else{std::cout << "Да ";}
    }
    else if((r1*r1)>((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1))){
        std::cout << "Да";
    }
    else if( ((r1+r2)*(r1+r2))>( (x2-x1)*(x2-x1)+(y2-y1)*(y2-y1)) ){
        std::cout << "Фигуры пересекаются ";
    }
    else{
        std::cout << "Ни одно уловие не выполнено ";
    }
    
    return 0;
}