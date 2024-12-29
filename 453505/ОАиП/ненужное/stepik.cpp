м#include <iostream>
#include <string>
#include <functional>
#include <map>
#include <vector>

// Предполагается, что bus_route и vec_bus определены где-то в вашем коде
struct bus_route {
    std::string nomer;
    std::string typ_bus;
    std::string punkt_drive;
    std::string time_start;
    std::string time_end;
};

using vec_bus = std::vector<bus_route>;

void poisk() {
    // Ваша реализация функции poisk
}

vec_bus readd(const char* filename) {
    // Ваша реализация функции readd
    return vec_bus(); // Заглушка
}

void writen(const vec_bus& routes) {
    // Ваша реализация функции writen
}

vec_bus filtr_eks(const vec_bus& routes, const std::function<bool(const bus_route&)>& predicate) {
    vec_bus result;
    for (const auto& route : routes) {
        if (predicate(route)) {
            result.push_back(route);
        }
    }
    return result;
}

bus_route get_route_from_user() {
    bus_route route;
    std::cout << "Введите номер автобуса: ";
    std::getline(std::cin, route.nomer);
    std::cout << "Введите тип автобуса: ";
    std::getline(std::cin, route.typ_bus);
    std::cout << "Введите пункт назначения: ";
    std::getline(std::cin, route.punkt_drive);
    std::cout << "Введите время отправления: ";
    std::getline(std::cin, route.time_start);
    std::cout << "Введите время прибытия: ";
    std::getline(std::cin, route.time_end);
    return route;
}

void update_record(const bus_route& updated_route, size_t index) {
    // Ваша реализация функции update_record
}

void searchAndUpdate() {
    std::string find_bus;
    bool problem = false;
    std::function<bool(const bus_route&)> prisnak;

    do {
        if (problem) {
            std::cout << "\nНет такого свойства. ";
        }
        poisk();
        std::cout << "Введите по какому свойству будете искать необходимый автобус? (1-5 для свойств, 0 для выхода): ";
        std::getline(std::cin, find_bus);

        if (find_bus.empty() || find_bus.length() > 1) {
            problem = true;
            continue;
        }

        switch (find_bus[0]) {
            case '1':
                prisnak = [](const bus_route& route) {
                    std::string input;
                    std::cout << "Введите номер автобуса для поиска: ";
                    std::getline(std::cin, input);
                    return route.nomer == input;
                };
                problem = false;
                break;
            case '2':
                prisnak = [](const bus_route& route) {
                    std::string input;
                    std::cout << "Введите тип автобуса для поиска: ";
                    std::getline(std::cin, input);
                    return route.typ_bus == input;
                };
                problem = false;
                break;
            case '3':
                prisnak = [](const bus_route& route) {
                    std::string input;
                    std::cout << "Введите пункт назначения для поиска: ";
                    std::getline(std::cin, input);
                    return route.punkt_drive == input;
                };
                problem = false;
                break;
            case '4':
                prisnak = [](const bus_route& route) {
                    std::string input;
                    std::cout << "Введите время отправления для поиска: ";
                    std::getline(std::cin, input);
                    return route.time_start == input;
                };
                problem = false;
                break;
            case '5':
                prisnak = [](const bus_route& route) {
                    std::string input;
                    std::cout << "Введите время прибытия для поиска: ";
                    std::getline(std::cin, input);
                    return route.time_end == input;
                };
                problem = false;
                break;
            case '0':
                std::cout << "Выход из программы.\n";
                return; // Выход из функции
            default:
                problem = true;
                continue;
        }
    } while (problem);

    vec_bus find = readd(fl);
    vec_bus found_routes = filtr_eks(find, prisnak);

    if (found_routes.empty()) {
        std::cout << "Рейсы не найдены.\n";
        return;
    }

    std::cout << "Найденные рейсы:\n";
    writen(found_routes);

    size_t index;
    std::cout << "\nВведите индекс маршрута для обновления: ";
    std::cin >> index;
    std::cin.ignore();

    if ((index - 1) >= found_routes.size()) {
        std::cerr << "\nОшибка: номер вне диапазона!";
        return;
    }

    bus_route new_route = get_route_from_user();
    update_record(new_route, index - 1);

    // Обновляем и выводим обновленный список маршрутов
    find = readd(fl);
    writen(find);
}

void update_file() {
    searchAndUpdate();
}