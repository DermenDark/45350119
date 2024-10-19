#include <iostream>
double sqrt(double number) {
    double x = number;
    double y = 1.0;
    double e = 0.0000001; // точность

    while (x - y > e) {
        x = (x + y) / 2;
        y = number / x;
    }
    return x;
}

int main()
{   int a,b,c;
    double x_1=0,x_2=0,x_3=0,x_4=0;
    
    std::cout << "Введите коэффициенты a,b и c для уравнения ax^4 + bx^3 + cx^2 + bx + a = 0: ";
    std::cin >> a>>b>>c;
    
    double d = (b*b-4*a*(c - 2*a));
    std::cout << "Дискриминант = " << d << std::endl;

    if(d>0){
        
        double t_1=(-b+sqrt(d))/(2*a);
        double t_2=(-b-sqrt(d))/(2*a);

        int a=1,c=1;
        double d_1 = (t_1*t_1-4*a*c);
        double d_2 = (t_2*t_2-4*a*c);
        
        if(d_1>0){ 
            
            x_1 = (t_1+sqrt(d_1))/(2*a);
            x_2 = (t_1-sqrt(d_1))/(2*a);
            std::cout<<"\nx1= "<< x_1<<"\n x2= "<<x_2;
        }
        else if(d_1=0){
            x_1 = (t_1)/2*a;
            std::cout<<"\n x1= "<<x_1;
        }
        else{
            std::cout<< "\nнет корней от t_1";
        }
        
        if(d_2>0){
            
            x_3 =(t_2+sqrt(d_2))/(2*a);
            x_4 =(t_2-sqrt(d_2))/(2*a);
            std::cout<<" \nx3= "<<x_3<<" \nx4= "<<x_4;
        }
        else if(d_1=0){
            x_1 = (t_1)/2*a;
            std::cout<<" \nx3= "<<x_1;
        }
        else{
            std::cout<< "\nнет корней от t_2";
        }
    }
    else if(d=0){
        double t_1=(-b)/2*a;
        
        if(t_1>0){ int a=1,c=1; 
            double d_2 = (t_1*t_1-4*a*(c-2*a));
            
            x_1 = (t_1+sqrt(d_2))/(2*a);
            x_2 = (t_1-sqrt(d_2))/(2*a);
            std::cout<<"x= "<< x_1<<" x= "<<x_2;
        }
        else{std::cout<< "\nнет корней";}
    }
    else{
        std::cout<< "\nнет корней";
    }
        
    return 0;
}
