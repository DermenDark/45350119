#include <iostream>

int main() {
    int x1,y1,x2,y2,res,min,kon,min_kon;
    
    std::cout << "Сколько часов было в начале занятия: ";
    std::cin >> x1;
    std::cout << "Сколько минут было в начале занятия: ";
    std::cin >> y1;
    std::cout << "Сколько часов было в конце занятия: ";
    std::cin >> x2;
    std::cout << "Сколько минут было в конце занятия: ";
    std::cin >> y2;
    
    if(x1>24 or x2>24 or y1 >60 or y2>60){
        std::cout << "неправильно заданы данные. ";
        return 0;
    }
    
    res = (x2-x1)*60;
    min = (y2-y1);
    
    res = res + min;
    
    kon = res/60;
    min_kon = res%60;

    std::cout << "\nвремя обучения: "<<kon<<":"<<min_kon;

    return 0;
}