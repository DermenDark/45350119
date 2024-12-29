#include <begin.h>

//для текста
// void wri_11( std::string& filename,  vec_bus & bus) {
//     std::ofstream in(filename, std::ios::app | std::ios::binary); // Открываем файл для дозаписи в бинарном режиме
    
//     if (!in) {
//         std::cerr << "Ошибка при открытии файла для записи!\n";
//         return;}


//     for ( auto& route : bus) {
//         in << route.nomer << "," << route.typ_bus << "," 
//              << route.punkt_drive << "," << route.time_start << "," 
//              << route.time_end <<"\n";}


//     in.close(); // Закрываем файл
//     std::cout << "\nФайл '" << filename << "' успешно записан." << std::endl;
// }


// Функция для записи массива маршрутов в файл
void wri(const std::string& filename, const vec_bus bus, size_t count) {
    std::ofstream out(filename, std::ios::app | std::ios::binary);
    if (!out) {
        std::cerr << "Ошибка при открытии файла для записи!\n";
        return;
    }

    for (size_t i = 0; i < count; ++i) {
        char typ_bus[256], punkt_drive[256], time_start[256], time_end[256];

       
        strncpy(typ_bus, strlen(bus[i].typ_bus) > 0 ? bus[i].typ_bus : "no_data", sizeof(typ_bus) - 1);
        strncpy(punkt_drive, strlen(bus[i].punkt_drive) > 0 ? bus[i].punkt_drive : "no_data", sizeof(punkt_drive) - 1);
        strncpy(time_start, strlen(bus[i].time_start) > 0 ? bus[i].time_start : "no_data", sizeof(time_start) - 1);
        strncpy(time_end, strlen(bus[i].time_end) > 0 ? bus[i].time_end : "no_data", sizeof(time_end) - 1);


        // Обеспечиваем, что строки заканчиваются нулевым символом

        typ_bus[sizeof(typ_bus) - 1] = '\0';
        punkt_drive[sizeof(punkt_drive) - 1] = '\0';
        time_start[sizeof(time_start) - 1] = '\0';
        time_end[sizeof(time_end) - 1] = '\0';

        // Записываем данные в файл
        if (bus[i].nomer.double_nomer == 0.0) { 
            double no_data_value = std::numeric_limits<double>::quiet_NaN(); // Используем NaN для обозначения отсутствия значения
            out.write(reinterpret_cast<const char*>(&no_data_value), sizeof(double));
        } else {
            out.write(reinterpret_cast<const char*>(&bus[i].nomer.double_nomer), sizeof(double));
        }
        out.write(typ_bus, sizeof(typ_bus));
        out.write(punkt_drive, sizeof(punkt_drive));
        out.write(time_start, sizeof(time_start));
        out.write(time_end, sizeof(time_end));
    }

    out.close();
}

//добавление новых рейсов в справочник
void new_bus_route() {
    std::string input_size;
    int n = 0;

    while (true) {
        std::cout << "Введите количество рейсов, которые хотите добавить: ";
        std::getline(std::cin, input_size);

        if (input_size.empty()) {
            std::cout << "Вы ничего не ввели.\n";
            continue;
        }

        try {
            n = std::stoi(input_size);
            if (n <= 0) {
                std::cout << "Нужно ввести положительное целое число.\n";
                continue;
            }
            break;
        } catch (...) {
            std::cout << "Ошибка: введите положительное целое число.\n";
        }
    }

    // Массив для хранения указателей на рейсы
    bus_route** spisok = (bus_route**)malloc(n * sizeof(bus_route*));
    if (spisok == NULL) {
        std::cerr << "Ошибка выделения памяти\n";
        exit(1); 
    }

    for (int i = 0; i < n; ++i) {
        char vopros;
        // Выделяем память для каждого рейса
        spisok[i] = (bus_route*)malloc(sizeof(bus_route));
        if (spisok[i] == NULL) {
            std::cerr << "Ошибка выделения памяти для рейса " << (i + 1) << "\n";
            exit(1); 
        }

        std::cout << "\nВведите данные для рейса " << (i + 1) << ":\n";
        bool probl=true;

        do{
            std::cout << "Выберите тип номера автобуса (1 - float, 2 - double): ";
            int type_choice;
            std::cin >> type_choice;        
            std::cin.ignore();

            if (type_choice == 1) {
                float temp_float;
                std::cout << "Введите номер автобуса (float): ";
                std::cin >> temp_float;
                spisok[i]->nomer.double_nomer = static_cast<double>(temp_float);
                probl=false;
            } else if(type_choice == 2){
                std::cout << "Введите номер автобуса (double): ";
                std::cin >> spisok[i]->nomer.double_nomer;
                probl=false;
            } else {
                probl=true;
            }
            std::cin.ignore();
        }while (probl);
        
        
        std::cout << "Тип автобуса: ";
        std::cin.getline(spisok[i]->typ_bus, sizeof(spisok[i]->typ_bus));

        std::cout << "Пункт назначения: ";
        std::cin.getline(spisok[i]->punkt_drive, sizeof(spisok[i]->punkt_drive));

        std::cout << "Время отправления: ";
        std::cin.getline(spisok[i]->time_start, sizeof(spisok[i]->time_start));

        std::cout << "Время прибытия: ";
        std::cin.getline(spisok[i]->time_end, sizeof(spisok[i]->time_end));
        if (i < n - 1) {
            std::cout << "\nВы хотите продолжить ввод? Если хотите продолжить, то введите 'y' или 'Y': ";
            std::cin >> vopros;
            std::cin.ignore();
            if (vopros != 'y' && vopros != 'Y') {
                n=i+1;
                break;
                }
            }
    }


    for (int i = 0; i < n; ++i) {
        wri(fl, spisok[i], 1); 
        free(spisok[i]);
    }
    free(spisok);
}