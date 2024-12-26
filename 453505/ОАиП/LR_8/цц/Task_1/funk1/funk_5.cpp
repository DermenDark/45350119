#include <begin.h>

void update_record(const bus_route& updated_route, size_t index) {
    // Открываем файл в режиме чтения и записи
    std::fstream file(fl, std::ios::in | std::ios::out | std::ios::binary);
    if (!file) {
        std::cerr << "Ошибка при открытии файла для записи!" << std::endl;
        return;
    }
    // Размер одной записи
    size_t record_size = sizeof(bus_route);
    std::streampos pos = index * record_size;
    file.seekp(pos);
    file.write(reinterpret_cast<const char*>(&updated_route), record_size);

    // Закрываем файл
    file.close();
}

// Функция для получения данных о маршруте от пользователя
bus_route get_route_from_user() {
    bus_route route;

    std::cout << "Введите номер рейса: ";
    std::cin.getline(route.nomer, sizeof(route.nomer));

    std::cout << "Введите тип автобуса: ";
    std::cin.getline(route.typ_bus, sizeof(route.typ_bus));

    std::cout << "Введите пункт назначения: ";
    std::cin.getline(route.punkt_drive, sizeof(route.punkt_drive));

    std::cout << "Введите время отправления: ";
    std::cin.getline(route.time_start, sizeof(route.time_start));

    std::cout << "Введите время прибытия: ";
    std::cin.getline(route.time_end, sizeof(route.time_end));

    return route;
}

// Функция для обновления записи в файле
void update_file() {
    size_t index;
    vec_bus routes = readd(fl);
    writen(routes);
    std::cout << "\n\tВведите индекс маршрута для обновления : ";
    std::cin >> index;
    std::cin.ignore();


    if ((index-1) >= routes.size()) {
        std::cerr << "\nОшибка: номер вне диапазона!";
        return;
    }

    bus_route new_route = get_route_from_user();
    
    update_record(new_route, index-1);

    routes = readd(fl);
    writen(routes);
}