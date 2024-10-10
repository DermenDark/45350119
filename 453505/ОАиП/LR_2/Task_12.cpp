#include <iostream>
#include <cmath>

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
    double x_2;

    x_2= (kor / 6.28318530716);
    int x_3 = (kor / 6.28318530716);
    
    double ress = (x_2-x_3)*6.28318530716;

    double res=0,prom;
    for(int n=1; n<70;n++){
        prom= pooow(ress,(2*n-1))/factorial(2*n-1);
        if (n % 2 != 1) {
            prom= -prom;
        }
        std::cout << "\nRes: "<< n<<"-("<<prom;
        res += prom;
    }

    return res;
}

int main() {
    double x=0,result_1=0,res;
    int massiv[4]={8,32,69,23};

    std::cout << "x: ";
    std::cin >> x;
  
    result_1=sinn(x);
    res = sin(x);
    std::cout << "\nRes_1= "<< result_1<<"\nres="<<res;
    return 0;
}