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

double sinn(double kor){
    double x_2,e=6.28318530716,resul;

    x_2= (kor / e);
    std::cout << "\nRes1: "<< x_2;

    long long int x_3 = (kor / e);

    double ress = (x_2-x_3)*e;
    double res=0,prom;

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
double coss(double kor){
    double e = 2 * M_PI; 
    double x_2 = kor / e;
    long long int x_3 = static_cast<long long int>(x_2); 

    double ress = (x_2 - x_3) * e; 

    double res = 0.0;


    for (int n = 0; n < 15; n++) {
        double term = pow(ress, 2 * n) / factorial(2 * n);
        if (n % 2 == 1) {
            term = -term; 
        }
        res += term;
    }

    return res;
}


int main()
{   int i=1;
    float a=0,h,x,y,m=20,pi=3.1415,b=pi/2;
    for(int i=1;i<=m;i++){
        h=(b-a)/m;
        x=(a+i*h);
        y=sin(x)-cos(x);
        std::cout<<'\n'<<i<<"y:"<<y;
    }

    return 0;
}
