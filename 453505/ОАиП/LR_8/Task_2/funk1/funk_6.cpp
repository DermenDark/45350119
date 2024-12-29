#include <begin.h>

void del() {
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

    bus_route new_route = {"*delite*", "*delite*", "*delite*", "*delite*", "*delite*"}; 
    update_record(new_route, index);

    routes = readd(fl);
    writen(routes);
}