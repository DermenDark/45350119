#include <iostream>


std::string new_day(std::string& arr,std::string&arr_2){

}
void osnova() {
    int num_bochka=0;
    std::string bochki(240, '0');
    for(int i=0; i<bochki.length(); i++) {
        std::cout<<bochki[0];
        if(i%40==0){std::cout<<"сорок бочек";}
        }

    bool vvod =false;
    while (!vvod) {
    std::cout<<"Введите номер отравленной бочки)";
    std::cin>>num_bochka;

    if (num_bochka<0 || num_bochka>240) {
        std::cout<<"Некорректный ввод";

    }else{vvod =true;}
    }

}

int main() {
    char otvet;
    std::cout << "\nПодойдите к заданию творчески и найдите способ определения отравленной бочки с ядом.\n\nВыполнил задание №1: Ширко Владимир.\nВариант-№4(19 в списке)\n\n";

    do {
        osnova(); 
        std::cout << "\nЕсли хотите продолжить, то введите 'y' или 'Y', иначе введите любой другой символ: ";
        std::cin >> otvet;
        std::cin.ignore();
    } while (otvet == 'y' || otvet == 'Y');

    std::cout << "Программа завершена.\n";

    return 0;
}