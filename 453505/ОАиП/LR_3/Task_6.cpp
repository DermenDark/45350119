#include <iostream>
#include <cmath>

// bool prov(int m){

//     if(m<=0){
//         std::cout << "Ошибка. Для ln(x) || x должен быть >0\n" ;
//         return false;
//     }

//     return true;
// }

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
    
    b=(((bits >> 52) & 0x7FF)-1023);
    if (b < 0) return 0;

    int binary[1000];
    int nomer_bit=1;

    for (int i = 51; i >= 52-b; --i) {
        
        binary[nomer_bit]= ((bits >> i) & 1);
        ++nomer_bit;
    }
    
    int nomer_bitt=0;
    binary[0]=1;

    for (int i = 52; i >= 52-b; --i) {

        ++nomer_bitt;
    }
    
    double base = 1; 
    for (int i = b-3; i >=0; --i) {

        if (binary[i] == 1) {
            decimal += base;
        }
        base = base*2; 

    }

    return decimal;
}

double sokr(double x){
    double viks = x;
    double pi = 3.141592653589793238462643383279502884197169399;
    if(x<0){x*=-1;}

    while (x>2*pi){   
        double increment = Binary(x)*2*pi; 

        while (x>0) {
            x -= increment;

            if(x<0){
                x=viks;
                break;
            }

            viks = x;
        }
    }
    return x;
}
double sinn(double kor){

    double ress = sokr(kor);
    double res=0.0,prom=0;

    for(int n=1; n<50;n++){

        prom = pooow(ress,(2*n-1))/factorial(2*n-1);

        if (n % 2 == 0) {
            prom= -prom;
        }

        res += prom;
    }

    return res;
}
double coss(double kor){

    double ress = sokr(kor);
    double res = 0.0, term=0;

    for (int n = 0; n < 50; n++) {

        term = pooow(ress, 2 * n)/factorial(2 * n);

        if (n % 2 == 1) {
            term = -term; 
        }

        res += term;
    }

    return res;
}

double lnn(double x) {
    if (x <= 0) return 0;

    if (x == 1) return 0;

    double result = 0.0;
    double term;
    

    if (x > 1) {

        while (x > 2.0) {
            x /= 2.0;
            result += 0.69314718056;
        }

        double y = (x - 1) / x;
        for (int n = 1; n < 1000; n += 2) {
            term = pooow(y, n) / n;
            result += term;
        }
        return result;
    } else { 
        double y = x - 1; 
        int d=0;
        d = Binary(x);

        for (int n = 1; n < 1000; n += 2) {
            term = pooow(y, n) / n;
            result += term; 
        }
        return -result;
    }
}

int main() {
    double x;
    // bool m =true;
    std::cout << "Введите значение x (x > 0): ";
    std::cin >> x;
    // m=prov(x);
    
    // if (m!=false){
        double a = sinn(x);
        double b = coss(x);
        double c = lnn(x);

        double d =sin(x);
        double e =cos(x);
        double f =log(x);



        std::cout << " sin(x)="<<a;
        std::cout << "\n cos(x)="<<b;
        std::cout <<" \n ln(x)="<<c;

        std::cout << "\n\n из <cmath>\n  sin(x)="<<d;
        std::cout << "\n  cos(x)="<<e;
        std::cout <<" \n  ln(x)="<<f;

        double min = a;
        if (b < min) min = b;
        if (c < min) min = c;

        std::cout << "\nМинимальное значение: " << min << std::endl;
    // }
    // else{return 0;}
    return 0;
}