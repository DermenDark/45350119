#include <begin.h>

void writen(vec_bus & str) {
    std::cout << "\n\nВведенные значения:\n";
    for ( auto& inner : str) {
        std::cout << "\nНомер автобуса: " << inner.nomer <<
        "\tТип автобуса: " << inner.typ_bus <<
        "\tПункт назначения: " <<inner.punkt_drive <<
        "\tВремя отправления:"<<inner.time_start<<
        "\tВремя прибытия:"<<inner.time_end;
        }
}
// запись в файл
void wri( std::string& filename,  vec_bus & bus) {
    std::ofstream in(filename, std::ios::binary); // Открываем файл для записи
    if (!in) {
        std::cerr << "Ошибка при открытии файла для записи!\n";
        return;
    }

    for ( auto& route : bus) {
        in << route.nomer << "," << route.typ_bus << "," 
             << route.punkt_drive << "," << route.time_start << "," 
             << route.time_end <<"\n"; 
    }

    in.close(); // Закрываем файл
}

// чтение файла
vec_bus rea( std::string& filename) {
    std::ifstream fin(filename); // Открываем файл для чтения
    vec_bus routes;
    if (!fin) {
        std::cerr << "Ошибка при открытии файла для чтения!";
        return routes;
    }


    std::string line;
    while (std::getline(fin, line)) {

        bus_route route;

        size_t pos = 0;

        pos = line.find(',');
        route.nomer = line.substr(0, pos);
        line.erase(0, pos + 1);

        pos = line.find(',');
        route.typ_bus = line.substr(0, pos);
        line.erase(0, pos + 1);

        pos = line.find(',');
        route.punkt_drive = line.substr(0, pos);
        line.erase(0, pos + 1);

        pos = line.find(',');
        route.time_start = line.substr(0, pos);
        line.erase(0, pos + 1);

        route.time_end = line; 

        routes.push_back(route); // Добавляем в вектор

    }
    fin.close();
    return routes;
}


//сoздаём структуры
bus_route create( std::string& nomer,  std::string& typ_bus,
                  std::string& punkt_drive,  std::string& time_start,
                  std::string& time_end) {
    return {nomer, typ_bus, punkt_drive, time_start, time_end};
}


vec_bus new_bus_route(){
    std::string MAX_SIZE;
    vec_bus spisok;
    std::string fl="file.dat";

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
        try {
            n = std::stoi(MAX_SIZE); 
        if (n > 0) {
            problem = false;}
        else{   
            problem = true;
            continue;
        }
        } catch (...) {
            std::cout << "Ошибка: введите положительное целое число.\n";
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


            if(i<n-1){
                std::cout << "\nВы хотите продолжить ввод?\nЕсли хотите продолжить, то введите 'y' или 'Y'. ";
                std::cin>>vopros;
                if(vopros != 'y' && vopros != 'Y'){break;}
                }
                
    }}while (problem);

    wri(fl,spisok);
    vec_bus read = rea(fl);
    writen(read);

    return spisok;
}