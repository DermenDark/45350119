#include <begin.h>

size_t get_record_size(const bus_route& route) {
    return sizeof(size_t) * 5 + route.nomer.size() + route.typ_bus.size() + 
           route.punkt_drive.size() + route.time_start.size() + route.time_end.size();
}

void write_record(const std::string& filename, const bus_route& route, size_t index) {
    std::ofstream out(filename, std::ios::binary | std::ios::in | std::ios::out | std::ios::app);
    if (!out) {
        std::cerr << "Ошибка при открытии файла для записи!" << std::endl;
        return;
    }


    size_t length;

    length = route.nomer.size();
    out.write(reinterpret_cast<const char*>(&length), sizeof(length));
    out.write(route.nomer.c_str(), length);

    length = route.typ_bus.size();
    out.write(reinterpret_cast<const char*>(&length), sizeof(length));
    out.write(route.typ_bus.c_str(), length);

    length = route.punkt_drive.size();
    out.write(reinterpret_cast<const char*>(&length), sizeof(length));
    out.write(route.punkt_drive.c_str(), length);

    length = route.time_start.size();
    out.write(reinterpret_cast<const char*>(&length), sizeof(length));
    out.write(route.time_start.c_str(), length);

    length = route.time_end.size();
    out.write(reinterpret_cast<const char*>(&length), sizeof(length));
    out.write(route.time_end.c_str(), length);

    if (!out) {
        std::cerr << "Ошибка при записи данных в файл!" << std::endl;
    }

    out.close();
}

// Функция для получения данных о маршруте от пользователя
bus_route get_route_from_user() {
    bus_route route;

    std::cout << "Введите номер рейса: ";
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

// Функция для обновления записи в файле
void update_file() {
    size_t index;

    std::cout << "Введите индекс маршрута для обновления (начиная с 0): ";
    std::cin >> index;
    std::cin.ignore();

    // Читаем все записи из файла
    vec_bus routes = readd(fl);

    // Проверяем, существует ли запись с данным индексом
    if (index >= routes.size()) {
        std::cerr << "Ошибка: номер вне диапазона!" << std::endl;
        return;
    }

    // Получаем новые данные от пользователя
    bus_route new_route = get_route_from_user();

    // Обнов ляем запись
    routes[index] = new_route;

    // Записываем только измененную запись
    write_record(fl, new_route, index);
}