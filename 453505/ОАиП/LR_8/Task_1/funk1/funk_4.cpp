#include <begin.h>

// запись в файл
void wri( std::string& filename,  vec_bus & bus) {
    std::ofstream in(filename, std::ios::app | std::ios::binary); // Открываем файл для дозаписи в бинарном режиме
    
    if (!in) {
        std::cerr << "Ошибка при открытии файла для записи!\n";
        return;}


    for ( auto& route : bus) {
        in << route.nomer << "," << route.typ_bus << "," 
             << route.punkt_drive << "," << route.time_start << "," 
             << route.time_end <<"\n";}


    in.close(); // Закрываем файл
    std::cout << "\nФайл '" << filename << "' успешно записан." << std::endl;
}


//сoздаём структуры
bus_route create( std::string& nomer,  std::string& typ_bus,
                  std::string& punkt_drive,  std::string& time_start,
                  std::string& time_end) {
    return {nomer, typ_bus, punkt_drive, time_start, time_end};
}

//добавление новых рейсов в справочник
void new_bus_route(){
    std::string MAX_SIZE;
    vec_bus spisok;

    bool problem=false;
    int n=0;


    do{ 
        if(problem){std::cout << "\nВозникла ошибка с входными данными.\n";}
        std::cout<<"Введите количество рейсов, которые хотите добавить.";
        std::getline(std::cin, MAX_SIZE);


        if (MAX_SIZE.empty()) {
            problem = true;
            continue;
        }

        try {n = std::stoi(MAX_SIZE); 
        if (n > 0) {problem = false;}
        else{problem = true;
            continue;}
        } 
        catch (...) {std::cout << "Ошибка: введите положительное целое число.\n";
            problem = true;
            continue;}
    

        for (int i = 0; i < n; ++i) {
            char vopros;
            std::string nomer_;
            std::string typ_bus_;
            std::string punkt_drive_;
            std::string time_start_;
            std::string time_end_;


            std::cout << "\nВведите данные для рейса " << (i + 1) << ":\n";
            std::cout << "Номер автобуса: ";
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


            if(i<n-1){
                std::cout << "\nВы хотите продолжить ввод?\nЕсли хотите продолжить, то введите 'y' или 'Y'. ";
                std::cin>>vopros;
                std::cin.ignore();
                if(vopros != 'y' && vopros != 'Y'){break;}
                }
                
    }}while (problem);

    wri(fl,spisok);
    vec_bus read = readd(fl);
    writen(read);
}