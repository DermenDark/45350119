#include <iostream>

double pooow(double osnov,int step){
    double res=1;
    for(int n=0;n<step; n++){
        res *= osnov;
        
    }
    return res;
}

int main() {
    double y,a,b,c;
    int N;

    std::cout << "Введите значение a: ";
    std::cin >> a;
    std::cout << "Введите значение b: ";
    std::cin >> b;
    std::cout << "Введите значение c: ";
    std::cin >> c;
    
    std::cout << "Введите значение N: ";
    std::cin >> N;

    switch ( N ) {
    case 2:
      y=(b*c-a*a);
      break;
    case 3:
      y= (a-b*c);
      break;
    case 7:
      y= (a*a +c);
      break;
    case 56:
      y= b*c;
      break;
    default:
      y= pooow(a+b,3);
      break;
    }
    
    std::cout << "\nПолучено значение y: "<<y;

    return 0;
}