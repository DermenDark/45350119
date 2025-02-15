#include <iostream>

int prov(int m){
    if(m>30){
        std::cout << "переполнение/переполнение/переполнение" ;
        return m =false;
    }
    return m;
}

int main() {
    int res = 0; 
    int m;
    std::cout << "Введите количество членов ряда: ";
    std::cin >> m;
    m=prov(m);

    if (m!=false){
        for (int n = 1; n <= m; ++n) {
            int power_of_two = 1; 

            for (int i = 1; i < n; ++i) {
                power_of_two *= 2; 
            }

            int sign = (n - 1) % 2 == 0 ? 1 : -1; 
            int b_n = n; 

            int a_n = power_of_two * sign * b_n; 
            std::cout << "a_" << n << " = " << a_n << std::endl;

            res += a_n; 
        }
        std::cout << "res: " << res << std::endl; 
    }
    else{
        return 0;
    }

    return 0;
}

