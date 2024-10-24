#include <iostream>

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
    
    int binary[b];
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
    double viks;
    double pi = 3.141592653589793238462643383279502884197169399;
        if(x<0){x*=-1;}

    while (x>100)
        {   
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
    double x_2,e=6.28318530716,resul;
    kor = sokr(kor);
    x_2= (kor / e);


    long long int x_3 = (kor / e);

    double ress = (x_2-x_3)*e;
    double res=0,prom;

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
    double pi = 3.141592653589793238462643383279502884197169399;
    double e = 2 * pi; 
    kor = sokr(kor);
    double x_2 = kor / e;
    long long int x_3 = static_cast<long long int>(x_2); 

    double ress = (x_2 - x_3) * e; 

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

double lnn(double x) {
    if (x <= 0) return 0; // логарифм не определен для x <= 0
    double result = 0;
    double term = (x - 1) / (x + 1);
    double term_squared = term * term;
    for (int n = 1; n < 1000; n += 2) {
        result += (1.0 / n) * pooow(term, n);
    }
    return 2 * result;
}

int main() {
    double x;
    std::cout << "Введите значение x (x > 0): ";
    std::cin >> x;

    double a = sinn(x);
    std::cout << " sin(x)="<<a;
    double b = coss(x);
    std::cout << "\n cos(x)="<<b;
    double c = lnn(x);
    std::cout <<" \n ln(x)="<<c;

    double min = a;
    if (b < min) min = b;
    if (c < min) min = c;

    std::cout << "\nМинимальное значение: " << min << std::endl;
    return 0;
}
