#include <iostream>
#include <cmath>

float sqrt(float number) {
    float x = number;
    float y = 1.0;
    float e = 0.000001; // точность

    while (x - y > e) {
        x = (x + y) / 2;
        y = number / x;
    }
    return x;
}

float factorial(int n) {
    float res = 1;
    for (int i = 1; i <= n; i++) {
        res *= i;
    }
    return res;
}

float pooow(float osnov,int step){
    float res=1;
    for(int n=0;n<step; n++){
        res *= osnov;
        
    }
    return res;
}
float fart(float step){
        float res = 1;
    for (int i = 1   ; i <= step; i=i+2) {
        res *= (i>0)?i:1;
    }
    return res;
}
float sinn(float kor){
    float x_2,e=6.28318530716,resul;

    x_2= (kor / e);
    std::cout << "\nRes1: "<< x_2;

    long long int x_3 = (kor / e);

    float ress = (x_2-x_3)*e;
    float res=0,prom;

    for(int n=1; n<15;n++){
        prom= pooow(ress,(2*n-1))/factorial(2*n-1);
        if (n % 2 != 1) {
            prom= -prom;
        }
        std::cout << "\nRes: "<< n<<"-("<<prom;
        res += prom;
    }

    return res;
}
float coss(float kor){
    float e = 2 * M_PI; 
    float x_2 = kor / e;
    long long int x_3 = static_cast<long long int>(x_2); 

    float ress = (x_2 - x_3) * e; 

    float res = 0.0;

    for (int n = 0; n < 20; n++) {
        float term = pow(ress, 2 * n) / factorial(2 * n);
        if (n % 2 == 1) {
            term = -term; 
        }
        res += term;
    }

    return res;
}
float asinn(float kor){

    float res=0,prom;

    for(int n=1; n<8;n++){
        prom= ((fart(n)/fart(n+1))*pooow(kor,(2*n-1))/(2*n-1));
        res += prom;
    }

    return res;
}
float acoss(float kor){

    float res=0,pi=3.1415/2;
    res = pi-asinn(kor);

    return res;
}
int main() {
    double x = 0, res, rrr,r;
    double pi = 3.1415956532384626;
    std::cout << "Введите x: ";
    std::cin >> x;
    rrr = x;
    while (x>60)
    {   
        double increment = (x / pooow(10,2)) * 2 * pi; 
        std::cout << "Increment: " << increment << std::endl;
        
        while (x > 100) {
            r = x;
            x -= increment;
            std::cout << "Измененное значение x: " << r << std::endl;

        }
        while (x < 0) {
            r = x;
            x += (increment/10);
            std::cout << "Измененное значение x: " << r << std::endl;
        }
    }
    std::cout << "Измененное значение x: " << x << std::endl;
    
    double result_1 = coss(r);
    double y = cos(rrr);  // Используйте стандартную функцию cos для сравнения

    std::cout << "\nRes_1= " << result_1 << "\nres=" << y << std::endl;
    return 0;
}