#include <iostream>
#include <cmath>
#include <iomanip>

int main() {
    long double vvod=1;
    std::cin>>vvod;
    long double res=0;
    
    for(int n=1;n<=vvod;++n){
        res+=2/((pow(10,n)-1)*pow(10,n));           
    }
    std::cout << std::setprecision(256) << res;
    return 0;
}