#include <begin.h>

void writen(vec_bus & str) {
    std::cout << "\nВведенные значения:\n";
    for (const auto& inner : str) {
        std::cout << "Номер автобуса: " << inner.nomer <<
         "Тип автобуса: " << inner.typ_bus <<
          ", Пункт назначения: " <<inner.punkt_drive <<
           "Время отправления:"<<inner.time_start<<
           "Время прибытия:"<<inner.time_end;
        }
}


//сoздаём структуры
bus_route create(
std::string & nomer,
std::string & typ_bus,
std::string & punkt_drive,
std::string & time_start ,
std::string & time_end ) {return {nomer, typ_bus, punkt_drive, time_start, time_end}; }


vec_bus new_bus_route(){
    std::string MAX_SIZE;
    vec_bus spisok;

    bool problem=false;
    int n=0;


    do{ if(problem){std::cout << "\nВозникла ошибка с входными данными.\n";}
        std::cout<<"Введите количество рейсов, которые хотите добавить.";
        std::getline(std::cin, MAX_SIZE);


        if (MAX_SIZE.empty()) {
            problem = true;
            continue;
        }
        try {
            n = std::stoi(MAX_SIZE); 
        if (n > 0) {
            problem = false;
            continue;}
        } catch (...) {std::cout << "Ошибка: введите положительное целое число.\n";}
    

    for (int i = 0; i <= n; ++i) {
        char vopros;
        std::string nomer_;
        std::string typ_bus_;
        std::string punkt_drive_;
        std::string time_start_;
        std::string time_end_;


        std::cout << "Введите данные для рейса " << (i + 1) << ":\n";
        std::cout << "Номер рейса: ";
        std::getline(std::cin, nomer_);

        std::cout << "Тип автобуса: ";
        std::getline(std::cin, typ_bus_);

        std::cout << "Пункт отправления: ";
        std::getline(std::cin, punkt_drive_);

        std::cout << "Время отправления: ";
        std::getline(std::cin, time_start_);

        std::cout << "Время прибытия: ";
        std::getline(std::cin, time_end_);

        spisok.push_back(create(nomer_, typ_bus_, punkt_drive_, time_start_, time_end_));


        std::cout << "Вы хотите продолжить ввод? ";
        std::cin>>vopros;
        if(vopros != 'y' || vopros != 'Y'){continue;}
        std::cin.ignore();

    }}while (problem);

    writen(spisok);
    return spisok;
}