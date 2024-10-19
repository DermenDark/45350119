#include <iostream>


double my_sqrt(double x) {
    if (x < 0) return -1;
    double guess = x / 2.0;
    for (int i = 0; i < 10; ++i) {
        guess = (guess + x / guess) / 2.0;
    }
    return guess;
}

double my_cubic_root(double x) {
    if (x < 0)
        return -my_cubic_root(-x);
    
    double guess = x / 3.0;
    for (int i = 0; i < 10; ++i) {
        guess = (2 * guess + x / (guess * guess)) / 3.0;
    }
    return guess;
}

int main() {
    double p, q;
    
    std::cout << "Введите коэффициенты p и q для уравнения x^3 + px + q = 0: ";
    std::cin >> p >> q;
    
    double delta = (q / 2) * (q / 2) + (p / 3) * (p / 3) * (p / 3);
    std::cout << "Дискриминант = " << delta << std::endl;
    
    if (delta > 0) {
        double u = my_cubic_root(-q / 2 + my_sqrt(delta));
        double v = my_cubic_root(-q / 2 - my_sqrt(delta));
        double x1 = u + v;
        std::cout << "Один корень: x = " << x1 << std::endl;
    } 
    else if (delta == 0) {
        double u = my_cubic_root(-q / 2);
        double x1 = 2 * u;
        std::cout << "Два корня (один повторяется): x1 = " << x1 << std::endl;
    } 
    else {
        std::cout << "Все корни комплексные числа." << std::endl;
    }
    
    return 0;
}
