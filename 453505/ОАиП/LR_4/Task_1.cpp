#include <iostream>

int main()
{   int i=1,a,b;
    float N;
    while(i<=30){
        if(i % 2==1){
            a = i;
            b = i*i;
        }
        else{
            a = i/2;
            b = i*i*i;
        }
        N +=(a-b)*(a-b);
        i++;
    }
    std::cout<<"|| "<<N<<"|| ";
    return 0;
}
