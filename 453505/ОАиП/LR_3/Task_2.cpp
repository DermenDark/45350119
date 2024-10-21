#include <iostream>

double pooow(double osnov,int step){
    double res=1;
    for(int n=0;n<step; n++){
        res *= osnov;
    }
    return res;
}

int main()
{   int n=1;
    float d_sum,E = 0.01,res;
    
    do{
        d_sum =(1/pooow(2,n)+1/pooow(3,n));
        res+=d_sum;
        n++;
        std::cout<<"\nd:"<<d_sum<<"|| "<<n;
    }while (d_sum>=E);
    
    std::cout<<"\nd:"<<res;
    return 0;
}
