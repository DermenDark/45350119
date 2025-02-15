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
double factorial(int n) {
    double res = 1;
    for (int i = 1; i <= n; i++) {
        res *= i;
    }
    return res;
}
double poow(double osnov,int step){
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

    double res=0, prom;

    for(int n=1; n<8;n++){
        prom= ((fart(n)/fart(n+1))*poow(kor,(2*n-1))/(2*n-1));
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
    float x1,y1,x2,y2,x3,y3,a,b,c,p,P,r,R,S0,S1,S2,S3,sr,cr,sR,cR,pi=3.141592;
    float h1,h2,h3,m1,m2,m3,bis1,bis2,bis3, ugl1,ugl2,ugl3;

    std::cout << "Введите значение x1: ";
    std::cin >> x1;
    std::cout << "Введите значение y1: ";
    std::cin >> y1;

    std::cout << "Введите значение x2: ";
    std::cin >> x2;
    std::cout << "Введите значение y2: ";
    std::cin >> y2;
    
    std::cout << "Введите значение x3: ";
    std::cin >> x3;
    std::cout << "Введите значение y3: ";
    std::cin >> y3;
    
    
    a= sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
    std::cout << "сторона a: "<<a;
    b= sqrt((x3-x2)*(x3-x2)+(y3-y2)*(y3-y2));
    std::cout << "сторона b: "<<b;
    c= sqrt((x1-x3)*(x1-x3)+(y1-y3)*(y1-y3));
    std::cout << "сторона c: "<<c;
    
    p=((a+b+c)/2);
    std::cout << "\nполупериметр p: "<<p;
    
    h1 = ( 2*sqrt(p*(p-a)*(p-b)*(p-c))/a );
    std::cout << "\nвысота h1: "<<h1;
    h2 = ( 2*sqrt(p*(p-a)*(p-b)*(p-c))/b );
    std::cout << "высота h2: "<<h2;
    h3 = ( 2*sqrt(p*(p-a)*(p-b)*(p-c))/c );
    std::cout << "высота h3: "<<h3;
    
    m1 = ( sqrt(2*a*a+2*b*b-c*c)/2 );
    std::cout << "\nмедиана m1: "<<m1;
    m2 = ( sqrt(2*a*a+2*c*c-b*b)/2 );
    std::cout << "медиана m2: "<<m2;
    m3 = ( sqrt(2*c*c+2*b*b-a*a)/2 );
    std::cout << "медиана m3: "<<m3;
    
    bis1 = (sqrt( a*b*(a+b+c)*(a+b-c))/(a+b) );
    std::cout << "\nбиссектриса bis1: "<<bis1;
    bis2 = (sqrt( c*b*(a+b+c)*(c+b-a))/(c+b) );
    std::cout << "биссектриса bis2: "<<bis2;
    bis3 = ( sqrt(a*c*(a+b+c)*(a+c-b))/(a+c) );
    std::cout << "биссектриса bis3: "<<bis3;
    
    ugl1 = ( acoss( (a*a+c*c-b*b)/(2*a*c) ));
    std::cout << "\nугол №1(в радианах): "<<ugl1;
    ugl1 = ( ugl1*(180/pi) );
    std::cout << " угол №1(в градусах): "<<ugl1;
    
    ugl2 = ( acoss( (b*b+c*c-a*a)/(2*b*c) ));
    std::cout << "\nугол №2(в радианах): "<<ugl2;
    ugl2 = ( ugl2*(180/pi) );
    std::cout << " угол №2(в градусах): "<<ugl2;
    
    ugl3 = ( acoss( (a*a+b*b-c*c)/(2*a*b) ));
    std::cout << "\nугол №3(в радианах): "<<ugl3;
    ugl3 = ( ugl3*(180/pi) );
    std::cout << " угол №3(в градусах): "<<ugl3;
    
    S0=((a*h1)/2);
    std::cout << " \nплощадь треугольника: "<<S0;
    
    r= (S0/p);
    std::cout << " \nрадиус вписанной окружности: "<<r;
    sr=(pi*r*r);
    std::cout << " \nплощадь вписанной окружности: "<<sr;
    cr=(2*pi*r);
    std::cout << " \nдлина вписанной окружности: "<<cr;
    
    R= ((a*b*c)/(4*S0));
    std::cout << " \nрадиус oписанной окружности: "<<R;
    sR=(pi*R*R);
    std::cout << " \nплощадь вписанной окружности: "<<sR;
    cR=(2*pi*R);
    std::cout << " \nдлина вписанной окружности: "<<cR;
    
    P=(a+b+c);
    std::cout << " \nпериметр треугольника: "<<P;
    
    S0=((a*h1)/2);
    std::cout << " \nплощадь треугольника: "<<S0;
    S1=(sqrt(p*(p-a)*(p-b)*(p-c)));
    std::cout << " \nплощадь треугольника: "<<S1;
    S2=p*r;
    std::cout << " \nплощадь треугольника: "<<S2;
    S3=((a*b*c)/(4*R));
    std::cout << " \nплощадь треугольника: "<<S3;
    
    return 0;
}