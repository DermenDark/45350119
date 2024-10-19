#include <iostream>

double sqrt(double number) {
    double x = number;
    double y = 1.0;
    double e = 0.00001; // точность

    while (x - y > e) {
        x = (x + y) / 2;
        y = number / x;
    }
    return x;
}

int main()
{   int a,b,c,x;
    double x_1=0,x_2=0,x_3=0,x_4=0;
    
    std::cin >> a>>b>>c;
    // std::cout<< a<< b<< c;
    
    double d =(b*b-4*a*c);
    
    if(d>0){
        
        double t_1=(-b+sqrt(d))/2*a;
        double t_2=(-b-sqrt(d))/2*a;
        if(t_1>0){ 
            x_1 = sqrt(t_1);
            x_2 = -sqrt(t_1);
            std::cout<<"\nx= "<< x_1<<" \nx= "<<x_2;
        }
        else if(t_1=0){
            x_1=sqrt(t_1);
            std::cout<< " \nx= "<<x_1;
        }
        else{
            std::cout<< "\nнет корней t_1";
        }
        
        if(t_2>0){ 
            x_3 = sqrt(t_2); 
            x_4 = -sqrt(t_2);
            std::cout<<" \nx= "<<x_3<<" \nx= "<<x_4;
        }
        else if(t_2=0){
            x_3=sqrt(t_2);
            std::cout<< " x= "<<x_3;
        }
        else{
            std::cout<< "\nнет корней t_2";
        }
    }
    else if(d==0){
        double t_1=(-b)/2*a;
        
        if(t_1>0){ 
            x_1 = sqrt(t_1);
            x_2 = -sqrt(t_1);
            std::cout<<"\nx= "<< x_1<<" \nx= "<<x_2;
        }
        else if(t_1=0){
            x_1=sqrt(t_1);
            std::cout<< " x= "<<x_1;
        }
        else{std::cout<< "\nнет корней";}
    }
    else{
        std::cout<< "\nнет корней";
    }
        
    return 0;
}
