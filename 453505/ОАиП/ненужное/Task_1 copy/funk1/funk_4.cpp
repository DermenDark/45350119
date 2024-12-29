#include <begin.h>

//для текста
void wri_11( std::string& filename,  vec_bus & bus) {
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

// запись в файл
void wri(const std::string& filename, const vec_bus& bus) {
    std::ofstream out(filename, std::ios::app | std::ios::binary); 

    if (!out) {
        std::cerr << "Ошибка при открытии файла для записи!\n";
        return;
    }

    for (const auto& route : bus) {
        char nomer[256], typ_bus[256], punkt_drive[256], time_start[256], time_end[256];

        strncpy(nomer, strlen(route.nomer) > 0 ? route.nomer : "no_data", sizeof(nomer) - 1);
        strncpy(typ_bus, strlen(route.typ_bus) > 0 ? route.typ_bus : "no_data", sizeof(typ_bus) - 1);
        strncpy(punkt_drive, strlen(route.punkt_drive) > 0 ? route.punkt_drive : "no_data", sizeof(punkt_drive) - 1);
        strncpy(time_start, strlen(route.time_start) > 0 ? route.time_start : "no_data", sizeof(time_start) - 1);
        strncpy(time_end, strlen(route.time_end) > 0 ? route.time_end : "no_data", sizeof(time_end) - 1);

        // Обеспечиваем, что строки заканчиваются нулевым символом
        nomer[sizeof(nomer) - 1] = '\0';
        typ_bus[sizeof(typ_bus) - 1] = '\0';
        punkt_drive[sizeof(punkt_drive) - 1] = '\0';
        time_start[sizeof(time_start) - 1] = '\0';
        time_end[sizeof(time_end) - 1] = '\0';

        // Записываем данные в фиксированные массивы
        out.write(nomer, sizeof(nomer));
        out.write(typ_bus, sizeof(typ_bus));
        out.write(punkt_drive, sizeof(punkt_drive));
        out.write(time_start, sizeof(time_start));
        out.write(time_end, sizeof(time_end));
    }

    out.close(); 
    std::cout << "\nФайл '" << filename << "' успешно записан." << std::endl;
}

//сoздаём структуры
bus_route create(const char* nomer, const char* typ_bus,
                 const char* punkt_drive, const char* time_start,
                 const char* time_end) {
    bus_route route;

    strncpy(route.nomer, nomer, sizeof(route.nomer) - 1);
    route.nomer[sizeof(route.nomer) - 1] = '\0'; // Обеспечиваем нуль-терминатор

    strncpy(route.typ_bus, typ_bus, sizeof(route.typ_bus) - 1);
    route.typ_bus[sizeof(route.typ_bus) - 1] = '\0'; // Обеспечиваем нуль-терминатор

    strncpy(route.punkt_drive, punkt_drive, sizeof(route.punkt_drive) - 1);
    route.punkt_drive[sizeof(route.punkt_drive) - 1] = '\0'; // Обеспечиваем нуль-терминатор

    strncpy(route.time_start, time_start, sizeof(route.time_start) - 1);
    route.time_start[sizeof(route.time_start) - 1] = '\0'; // Обеспечиваем нуль-терминатор

    strncpy(route.time_end, time_end, sizeof(route.time_end) - 1);
    route.time_end[sizeof(route.time_end) - 1] = '\0'; // Обеспечиваем нуль-терминатор

    return route;}

//добавление новых рейсов в справочник
void new_bus_route() {
    std::string MAX_SIZE;
    vec_bus spisok;

    bool problem = false;
    int n = 0;

    do {
        if (problem) {
            std::cout << "\nВозникла ошибка с входными данными.\n";
        }
        std::cout << "Введите количество рейсов, которые хотите добавить: ";
        std::getline(std::cin, MAX_SIZE);

        if (MAX_SIZE.empty()) {
            problem = true;
            continue;
        }

        try {
            n = std::stoi(MAX_SIZE);
            if (n > 0) {
                problem = false;
            } else {
                problem = true;
                continue;
            }
        } catch (...) {
            std::cout << "Ошибка: введите положительное целое число.\n";
            problem = true;
            continue;
        }

        for (int i = 0; i < n; ++i) {
            char vopros;
            char nomer_[256];
            char typ_bus_[256];
            char punkt_drive_[256];
            char time_start_[256];
            char time_end_[256];

            std::cout << "\nВведите данные для рейса " << (i + 1) << ":\n";
            std::cout << "Номер автобуса: ";
            std::cin.getline(nomer_, sizeof(nomer_));

            std::cout << "Тип автобуса: ";
            std::cin.getline(typ_bus_, sizeof(typ_bus_));

            std::cout << "Пункт отправления: ";
            std::cin.getline(punkt_drive_, sizeof(punkt_drive_));

            std::cout << "Время отправления: ";
            std::cin.getline(time_start_, sizeof(time_start_));

            std::cout << "Время прибытия: ";
            std::cin.getline(time_end_, sizeof(time_end_));

            spisok.push_back(create(nomer_, typ_bus_, punkt_drive_, time_start_, time_end_));

            if (i < n - 1) {
                std::cout << "\nВы хотите продолжить ввод? Если хотите продолжить, то введите 'y' или 'Y': ";
                std::cin >> vopros;
                std::cin.ignore();
                if (vopros != 'y' && vopros != 'Y') {
                    break;
                }
            }
        }
    } while (problem);

    wri(fl, spisok);
    vec_bus read = readd(fl);
    writen(read);
}