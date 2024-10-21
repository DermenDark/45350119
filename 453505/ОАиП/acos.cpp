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
double fart(double step){
        double res = 1;
    for (int i = 1   ; i <= step; i=i+2) {
        res *= (i>0)?i:1;
    }
    return res;
}
double asinn(double kor){

    double res=0,prom;

    for(int n=1; n<8;n++){
        prom= ((fart(n)/fart(n+1))*pooow(kor,(2*n-1))/(2*n-1));
        res += prom;
    }

    return res;
}
double acoss(double kor){

    double res=0,pi=3.1415/2;
    res = pi-asinn(kor);

    return res;
}

int main() {
    double x=0,res;
    int massiv[4]={8,32,69,23};
    double result_1 = acoss(0.7);
    double y =acos(0.7);

    std::cout << "\nRes_1= "<< result_1<<"\nres="<<y;
    return 0;
}