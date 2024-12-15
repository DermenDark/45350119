#include <iostream>

int main()
{   int i=1;
    int a;
    int b;
    float N=0;
    while(i<=2){
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
