#include <begin.h>

void modifyRoute(vec_bus& routes) {

    std::string nomer;

    std::cout << "Введите номер рейса для изменения: ";

    std::getline(std::cin, nomer);


    auto it = std::find_if(routes.begin(), routes.end(), [&nomer](const bus_route& route) {

        return route.nomer == nomer;

    });


    if (it != routes.end()) {

        std::cout << "Введите новые детали рейса (тип автобуса, пункт назначения, время отправления, время прибытия):\n";

        std::getline(std::cin, it->typ_bus);

        std::getline(std::cin, it->punkt_drive);

        std::getline(std::cin, it->time_start);

        std::getline(std::cin, it->time_end);

        std::cout << "Детали рейса изменены.\n";

    } else {

        std::cout << "Рейс с номером " << nomer << " не найден.\n";

    }

}


// Функция для добавления нового рейса

void addRoute(vec_bus& routes) {

    bus_route newRoute;

    std::cout << "Введите номер рейса: ";

    std::getline(std::cin, newRoute.nomer);

    std::cout << "Введите тип автобуса: ";

    std::getline(std::cin, newRoute.typ_bus);

    std::cout << "Введите пункт назначения: ";

    std::getline(std::cin, newRoute .punkt_drive);

    std::cout << "Введите время отправления: ";

    std::getline(std::cin, newRoute.time_start);

    std::cout << "Введите время прибытия: ";

    std::getline(std::cin, newRoute.time_end);


    routes.push_back(newRoute);

    std::cout << "Новый рейс добавлен.\n";

}


// Функция для удаления рейса

void deleteRoute(vec_bus& routes) {

    std::string nomer;

    std::cout << "Введите номер рейса для удаления: ";

    std::getline(std::cin, nomer);


    auto it = std::remove_if(routes.begin(), routes.end(), [&nomer](const bus_route& route) {

        return route.nomer == nomer;

    });


    if (it != routes.end()) {

        routes.erase(it, routes.end());

        std::cout << "Рейс с номером " << nomer << " удален.\n";

    } else {

        std::cout << "Рейс с номером " << nomer << " не найден.\n";

    }

}