#include <iostream>

int main() {
    float x=34, y=32;
    bool b = false;
    
    x>y?b= true:b=false;
    
    if( b ){
        std::cout << "x > y ";}
    else{
        std::cout << "x < y ";}
    
    std::cout << "\nзначение x: "<<x<< "\nзначение y: "<<y;
    
    return 0;
}
