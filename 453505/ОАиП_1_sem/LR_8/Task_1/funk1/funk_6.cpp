#include <begin.h>
#include <fstream>

bus_route create_deleted_route() {
    bus_route new_route;

    // Устанавливаем номер автобуса как NaN для обозначения отсутствия значения
    new_route.nomer.double_nomer = std::numeric_limits<double>::quiet_NaN();

    strncpy(new_route.typ_bus, "*delite*", sizeof(new_route.typ_bus) - 1);
    new_route.typ_bus[sizeof(new_route.typ_bus) - 1] = '\0'; 

    strncpy(new_route.punkt_drive, "*delite*", sizeof(new_route.punkt_drive) - 1);
    new_route.punkt_drive[sizeof(new_route.punkt_drive) - 1] = '\0'; 

    strncpy(new_route.time_start, "*delite*", sizeof(new_route.time_start) - 1);
    new_route.time_start[sizeof(new_route.time_start) - 1] = '\0'; 

    strncpy(new_route.time_end, "*delite*", sizeof(new_route.time_end) - 1);
    new_route.time_end[sizeof(new_route.time_end) - 1] = '\0'; 

    return new_route;
}
void del() {
    std::string find_bus;
    bool problem = false;
    std::function<bool(const bus_route&)> prisnak;

    do {
        poisk(); // Предполагается, что poisk() выводит доступные свойства для поиска
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
                
                // Преобразуем строку в double
                double search_number;
                try {
                    search_number = std::stod(input); // Преобразуем строку в double
                } catch (const std::invalid_argument&) {
                    std::cout << "Некорректный ввод. Пожалуйста, введите число." << std::endl;
                    problem = true;
                    continue;
                } catch (const std::out_of_range&) {
                    std::cout << "Число вне допустимого диапазона." << std::endl;
                    problem = true;
                    continue;
                }

                prisnak = [search_number](const bus_route& route) {
                    return route.nomer.double_nomer == search_number; // Сравниваем с double
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

    size_t count;
    vec_bus routes = readd(fl, count); // Укажите путь к вашему файлу


    int index=-1;
    if (routes != NULL) {
        index = find_route_index(routes, count, prisnak);} // Передаем count как третий аргумент
    else{return;}

    if (index == -1) {
        std::cout << "Рейс не найден.\n";
        free_dynamic_array(routes);
        return;
    }


    bus_route new_route;
    new_route = create_deleted_route();
    update_record(new_route, index, fl); // Укажите путь к вашему файлу

    // Обновляем массив маршрутов и записываем его обратно в файл
    routes = readd(fl, count);
    if (routes != NULL) {
        writen(routes, count); // Передаем количество записей
        free_dynamic_array(routes); }
}