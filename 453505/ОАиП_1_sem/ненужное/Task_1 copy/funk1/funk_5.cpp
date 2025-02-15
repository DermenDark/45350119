#include <begin.h>

//изменение строчки в файле
void update_record(const bus_route& updated_route, size_t index) {
    std::fstream file(fl, std::ios::in | std::ios::out | std::ios::binary);
    if (!file) {
        std::cerr << "Ошибка при открытии файла для записи!" << std::endl;
        return;
    }

    size_t record_size = sizeof(bus_route);
    std::streampos pos = index * record_size;

    file.seekp(pos);

    bus_route updated_route_copy;

    // Используем strncpy для заполнения полей структуры
    strncpy(updated_route_copy.nomer, updated_route.nomer, sizeof(updated_route_copy.nomer) - 1);
    updated_route_copy.nomer[sizeof(updated_route_copy.nomer) - 1] = '\0'; 

    strncpy(updated_route_copy.typ_bus, updated_route.typ_bus, sizeof(updated_route_copy.typ_bus) - 1);
    updated_route_copy.typ_bus[sizeof(updated_route_copy.typ_bus) - 1] = '\0'; 

    strncpy(updated_route_copy.punkt_drive, updated_route.punkt_drive, sizeof(updated_route_copy.punkt_drive) - 1);
    updated_route_copy.punkt_drive[sizeof(updated_route_copy.punkt_drive) - 1] = '\0';

    strncpy(updated_route_copy.time_start, updated_route.time_start, sizeof(updated_route_copy.time_start) - 1);
    updated_route_copy.time_start[sizeof(updated_route_copy.time_start) - 1] = '\0'; 

    strncpy(updated_route_copy.time_end, updated_route.time_end, sizeof(updated_route_copy.time_end) - 1);
    updated_route_copy.time_end[sizeof(updated_route_copy.time_end) - 1] = '\0';


    file.write(reinterpret_cast<const char*>(&updated_route_copy), record_size);
    file.close();
}


// Функция для получения данных о маршруте от пользователя
bus_route get_route_from_user(const bus_route& current_route) {
    bool problem=false;
    bus_route route = current_route; // Сохраняем текущие значения

    std::cout << "Вы можете изменить только одно свойство от исходного маршрута.\n";

    do{
        std::cout << " __________________\n";
        std::cout << "| Текущие значения:\n";
        std::cout << "|------------------\n";
        std::cout << "| 1. Номер автобуса: " << route.nomer << "\n";
        std::cout << "| 2. Тип автобуса: " << route.typ_bus << "\n";
        std::cout << "| 3. Пункт назначения: " << route.punkt_drive << "\n";
        std::cout << "| 4. Время отправления: " << route.time_start << "\n";
        std::cout << "| 5. Время прибытия: " << route.time_end << "\n";
        std::cout << "|___________________\n";
        // poisk();
        std::cout << "Введите номер свойства, которое хотите изменить (0 для выхода): ";

        int choice;
        std::cin >> choice;
        std::cin.ignore();

        switch (choice) {
            case 1:
                std::cout << "Введите новый номер автобуса: ";
                std::cin.getline(route.nomer, sizeof(route.nomer));
                break;
            case 2:
                std::cout << "Введите новый тип автобуса: ";
                std::cin.getline(route.typ_bus, sizeof(route.typ_bus));
                break;
            case 3:
                std::cout << "Введите новый пункт назначения: ";
                std::cin.getline(route.punkt_drive, sizeof(route.punkt_drive));
                break;
            case 4:
                std::cout << "Введите новое время отправления: ";
                std::cin.getline(route.time_start, sizeof(route.time_start));
                break;
            case 5:
                std::cout << "Введите новое время прибытия: ";
                std::cin.getline(route.time_end, sizeof(route.time_end));
                break;
            case 0:
                std::cout << "Выход из функции.\n";
                return route; // Возвращаем изменённую структуру
            default:
                std::cout << "Некорректный выбор. Попробуйте снова.\n";
                problem=false;
                continue; // Продолжаем цикл
        }

        // После изменения свойства, можно спросить, хочет ли пользователь изменить что-то еще
        std::cout << "Свойство изменено. Хотите изменить что-то еще? (1 - да, 0 - нет): ";
        int continue_choice;
        std::cin >> continue_choice;
        std::cin.ignore(); 

        if (continue_choice != 0) {
            problem=true;
        }
        else{problem=false;}

    }while (problem);
    

    return route; // Возвращаем изменённую структуру
}

int find_route_index(const vec_bus& routes, const std::function<bool(const bus_route&)>& predicate) {
    for (size_t i = 0; i < routes.size(); ++i) {
        if (predicate(routes[i])) {
            return i;
        }
    }
    return -1;
}

// // Функция для обновления записи в файле
void update_file() {
    std::string find_bus;
    bool problem = false;
    std::function<bool(const bus_route&)> prisnak;

    do {
        poisk();
        if (problem) {
            std::cout << "\nНет такого свойства!!!\n";
        }
        std::cout << "Введите по какому свойству будете искать необходимый автобус? (1-5 для свойств, 0 для выхода): ";
        std::getline(std::cin, find_bus);

        if (find_bus.empty() || find_bus.length() > 1) {
            problem = true;
            continue;
        }

        std::string input; // Переменная для хранения ввода пользователя

        switch (find_bus[0]) {
            case '1':
                std::cout << "Введите номер автобуса для поиска: ";
                std::getline(std::cin, input);
                prisnak = [input](const bus_route& route) {
                    return route.nomer == input;
                };
                problem = false;
                break;
            case '2':
                std::cout << "Введите тип автобуса для поиска: ";
                std::getline(std::cin, input);
                prisnak = [input](const bus_route& route) {
                    return route.typ_bus == input;
                };
                problem = false;
                break;
            case '3':
                std::cout << "Введите пункт назначения для поиска: ";
                std::getline(std::cin, input);
                prisnak = [input](const bus_route& route) {
                    return route.punkt_drive == input;
                };
                problem = false;
                break;
            case '4':
                std::cout << "Введите время отправления для поиска: ";
                std::getline(std::cin, input);
                prisnak = [input](const bus_route& route) {
                    return route.time_start == input;
                };
                problem = false;
                break;
            case '5':
                std::cout << "Введите время прибытия для поиска: ";
                std::getline(std::cin, input);
                prisnak = [input](const bus_route& route) {
                    return route.time_end == input;
                };
                problem = false;
                break;
            case '0':
                std::cout << "Выход из программы.\n";
                return;
            default:
                problem = true;
                continue;
        }
    } while (problem);

    vec_bus routes = readd(fl); 
    int index = find_route_index(routes, prisnak);

    if (index == -1) {
        std::cout << "Рейс не найден.\n";
        return;
    }

    bus_route new_route = get_route_from_user(routes[index]); 
    
    update_record(new_route, index);

    routes = readd(fl);
    writen(routes);
}

// // Функция для обновления записи в файле
// void update_file() {
//     size_t index;
//     vec_bus routes = readd(fl);
//     writen(routes);

//     filtr_opr();
    
//     std::cout << "\n\tВведите индекс маршрута для обновления : ";
//     std::cin >> index;
//     std::cin.ignore();


//     if ((index-1) >= routes.size()) {
//         std::cerr << "\nОшибка: номер вне диапазона!";
//         return;
//     }

//     bus_route new_route = get_route_from_user();
    
//     update_record(new_route, index-1);

//     routes = readd(fl);
//     writen(routes);
// }