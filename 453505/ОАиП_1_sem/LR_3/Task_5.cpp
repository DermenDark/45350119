#include <iostream>

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

double exp(double x) {
    double term = 1.0; 
    double sum = term;
    int n = 1;

    while (n < 10) {
        term *= x / n;
        sum += term;
        n++;
    }
    return sum;
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
    double x_2, e=6.28318530716;

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

int main() {
    double start, end;

    std::cout << "Введите начальную точку интервала: ";
    std::cin >> start;
    std::cout << "Введите конечную точку интервала: ";
    std::cin >> end;

    double step = (end - start) / 100;


    double minValue = 1e10; 
    double root = start;

    for (double x = start; x <= end; x += step) {
        double value = exp(x) + sinn(coss(x));
        if (std::abs(value) < std::abs(minValue)) {
            minValue = value;
            root = x;
        }
    }

    std::cout << "Приближенный корень уравнения: x = " << root << " с f(x) = " << exp(root) + sinn(coss(root)) << std::endl;

    return 0;
}
