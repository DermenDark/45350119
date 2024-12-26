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
    std::ofstream out(filename, std::ios::app | std::ios::binary); // Открываем файл для записи в бинарном режиме

    if (!out) {
        std::cerr << "Ошибка при открытии файла для записи!\n";
        return;
    }


    for (const auto& route : bus) {
        // Записываем данные в фиксированные массивы
        out.write(route.nomer, sizeof(route.nomer));
        out.write(route.typ_bus, sizeof(route.typ_bus));
        out.write(route.punkt_drive, sizeof(route.punkt_drive));
        out.write(route.time_start, sizeof(route.time_start));
        out.write(route.time_end, sizeof(route.time_end));

    }
    out.close(); // Закрываем файл
    std::cout << "\nФайл '" << filename << "' успешно записан." << std::endl;
}

//сoздаём структуры
bus_route create(const char* nomer, const char* typ_bus,
                 const char* punkt_drive, const char* time_start,
                 const char* time_end) {
    bus_route route;

    // Копируем строки в фиксированные массивы
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