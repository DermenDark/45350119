#include <iostream>

int main() {
    int x=0;
    int result=0;
    int massiv[4]={8,32,69,23};
    
    std::cout << "x: ";
    std::cin >> x;
    
    for(int i = 0 ; i < 4; i++ ){
        int poow = 1;
        for(int step = 0; step<i; step++){
            poow *= x;
            }
        
        result = (result + massiv[i]*poow);
    }
    
    int y1 = 23*x*x*x + 69*x*x + 32*x + 8;//проверка
    
    std::cout << "Res: "<< result <<"\nRes:"<< y1;
    return 0;
}