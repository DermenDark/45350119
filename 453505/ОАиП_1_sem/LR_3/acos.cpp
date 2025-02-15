#include <iostream>
#include <cmath>

double sqrt(double number) {
    double x = number;
    double y = 1.0;
    double e = 0.000001; // точность

    while (x - y > e) {
        x = (x + y) / 2;
        y = number / x;
    }
    return x;
}
double factorial(int n) {
    double res = 1;
    for (int i = 1; i <= n; i++) {
        res *= i;
    }
    return res;
}
double pooow(double osnov,int step){
    double res=1;
    for(int n=0;n<step; n++){
        res *= osnov;
        
    }
    return res;
}

double Binary(double num) {
    unsigned long long bits = *(reinterpret_cast<unsigned long long*>(&num));
    int b;
    double decimal = 0;
    
    b=((bits >> 52) & 0x7FF)-1023;
    
    std::cout << "Двоичное представление: ";
    for (int i = 63; i >= 0; --i) {
        std::cout << ((bits >> i) & 1);
    }
    std::cout << "\n";

    std::cout << "Знак: " << ((bits >> 63) & 1) << "\n";
    std::cout << "Экспонента: ";
    for (int i = 62; i >= 52; --i) {
        std::cout << ((bits >> i) & 1);
    }

    std::cout << "\nМантисса: ";
    for (int i = 51; i >= 0; --i) {
        std::cout << ((bits >> i) & 1);
    }
    std::cout << "\n";
    
    int binary[b];
    int nomer_bit=1;
    for (int i = 51; i >= 52-b; --i) {
        
        binary[nomer_bit]= ((bits >> i) & 1);
        ++nomer_bit;
    }
    
    int nomer_bitt=0;
    binary[0]=1;
    std::cout <<'\n';
    for (int i = 52; i >= 52-b; --i) {

        ++nomer_bitt;
    }
    
    double base = 1; 
    for (int i = b-3; i >=0; --i) {
        if (binary[i] == 1) {
            decimal += base;
            std::cout <<'\n'<<base;
        }
        base = base*2; 
    }
    std::cout <<'\n'<<decimal;
    std::cout <<'\n'<<b;
    return decimal;
}

double sokr(double x){
    double viks;
    double pi = 3.141592653589793238462643383279502884197169399;
        if(x<0){
        x*=-1;
    }

    while (x>2*pi)
        {   
            double increment = Binary(x)*2*pi; 
            std::cout << "Increment: " << increment << std::endl;

            while (x>0) {
                x -= increment;
                if(x<0){
                    x=viks;
                    break;
                }
                viks = x;
                std::cout << "Измененное значение x: " << viks << std::endl;
            }
    }
    return x;
}
double fart(double step){
        double res = 1;
    for (int i = 1   ; i <= step; i=i+2) {
        res *= (i>0)?i:1;
    }
    return res;
}
double sinn(double kor){
    double ress = sokr(kor);

    double res=0;
    double prom=0;

    for(int n=1; n<15;n++){
        prom= pooow(ress,(2*n-1))/factorial(2*n-1);
        if (n % 2 != 1) {
            prom= -prom;
        }
        res += prom;
    }

    return res;
}
double coss(double kor){
    double ress = sokr(kor);

    double res = 0.0;

    for (int n = 0; n < 55; n++) {
        double term = pooow(ress, 2 * n) / factorial(2 * n);
        if (n % 2 == 1) {
            term = -term; 
        }
        res += term;
    }

    return res;
}
double asinn(double kor){

    double res=0;
    double prom=0;

    for(int n=1; n<8;n++){
        prom= ((fart(n)/fart(n+1))*pooow(kor,(2*n-1))/(2*n-1));
        res += prom;
    }

    return res;
}
double acoss(double kor){

    double res=0;
    double pi=3.1415/2;
    res = pi-asinn(kor);

    return res;
}
int main() {
    double x = 0;

    std::cout << "Введите x: ";
    std::cin >> x;

    double prov = x;

    double result_1 = sinn(x);
    double resssssssss=sin(prov);


    std::cout << "\nRes= " << result_1  << std::endl;
    std::cout << "\nRes= " << resssssssss  << std::endl;
    return 0;
}