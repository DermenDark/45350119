#include <iostream>

int main() {
    float k, x=280, y=290, a=36, b=35, c=34;

    std::cout << "Введите значение K: ";
    std::cin >> k;

    x<y?x=0:y=0;
    
    if(a>b && a>c){ a = a - k;
    }
    else if(b>a && b>c){ b = b - k;
    }
    else{c = c - k;
    }
    std::cout << "результат X: "<<x<<"\nрезультат Y: "<<y<<"\nрезультат A: "<<a<<"\nрезультат B: "<<b<<"\nрезультат c: "<<c ;
    
    return 0;
}