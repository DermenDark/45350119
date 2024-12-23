#include <begin.h>

size_t get_record_size(const bus_route& route) {

    return sizeof(size_t) * 5 + route.nomer.size() + route.typ_bus.size() + 

           route.punkt_drive.size() + route.time_start.size() + route.time_end.size();

}

vec_bus readdii( int max_index,bus_route new_route) {
    std::ifstream fin(fl, std::ios::binary);
    vec_bus routes;

    if (!fin) {
        std::cerr << "Ошибка при открытии файла для чтения!" << std::endl;
        return routes;
    }

    size_t current_index = 0; // Индекс текущей записи

    while (current_index < max_index) {
        bus_route route;
        size_t length;

        // Читаем длину номера рейса
        if (!fin.read(reinterpret_cast<char*>(&length), sizeof(length))) break;
        route.nomer.resize(length);
        fin.read(&route.nomer[0], length);

        // Читаем длину типа автобуса
        if (!fin.read(reinterpret_cast<char*>(&length), sizeof(length))) break;
        route.typ_bus.resize(length);
        fin.read(&route.typ_bus[0], length);

        // Читаем длину пункта назначения
        if (!fin.read(reinterpret_cast<char*>(&length), sizeof(length))) break;
        route.punkt_drive.resize(length);
        fin.read(&route.punkt_drive[0], length);

        // Читаем длину времени отправления
        if (!fin.read(reinterpret_cast<char*>(&length), sizeof(length))) break;
        route.time_start.resize(length);
        fin.read(&route.time_start[0], length);

        // Читаем длину времени прибытия
        if (!fin.read(reinterpret_cast<char*>(&length), sizeof(length))) break;
        route.time_end.resize(length);
        fin.read(&route.time_end[0], length);

        routes.push_back(route);
        current_index++; // Увеличиваем индекс текущей записи
    }

    fin.close();


    return routes;
}

vec_bus read_routes(const std::string& filename) {

    std::ifstream fin(filename, std::ios::binary);

    vec_bus routes;


    if (!fin) {

        std::cerr << "Ошибка при открытии файла для чтения!" << std::endl;

        return routes;

    }


    while (true) {

        bus_route route;

        size_t length;


        // Читаем длину номера рейса

        if (!fin.read(reinterpret_cast<char*>(&length), sizeof(length))) break;

        route.nomer.resize(length);

        fin.read(&route.nomer[0], length);


        // Читаем длину типа автобуса

        if (!fin.read(reinterpret_cast<char*>(&length), sizeof(length))) break;

        route.typ_bus.resize(length);

        fin.read(&route.typ_bus[0], length);


        // Читаем длину пункта назначения

        if (!fin.read(reinterpret_cast<char*>(&length), sizeof(length))) break;

        route.punkt_drive.resize(length);

        fin.read(&route.punkt_drive[0], length);


        // Читаем длину времени отправления

        if (!fin.read(reinterpret_cast<char*>(&length), sizeof(length))) break;

        route.time_start.resize(length);

        fin.read(&route.time_start[0], length);


        // Читаем длину времени прибытия

        if (!fin.read(reinterpret_cast<char*>(&length), sizeof(length))) break;

        route.time_end.resize(length);

        fin.read(&route.time_end[0], length);


        routes.push_back(route);

    }


    fin.close();

    return routes;

}


void update_record(const bus_route& updated_route, size_t index) {
    // Считываем все маршруты в вектор
    vec_bus routes = read_routes(fl);

    // Проверяем, что индекс в пределах допустимого диапазона
    if (index >= routes.size()) {
        std::cerr << "Индекс вне диапазона!" << std::endl;
        return;
    }


    // Обновляем нужный маршрут
    routes[index] = updated_route;
    // Открываем файл для записи
    std::ofstream fout(fl, std::ios::binary);
    if (!fout) {
        std::cerr << "Ошибка при открытии файла для записи!" << std::endl;
        return;
    }
    // Записываем обновленные маршруты обратно в файл
    for (const auto& route : routes) {
        size_t length;

        length = route.nomer.size();
        fout.write(reinterpret_cast<const char*>(&length), sizeof(length));
        fout.write(route.nomer.data(), length);

        length = route.typ_bus.size();
        fout.write(reinterpret_cast<const char*>(&length), sizeof(length));
        fout.write(route.typ_bus.data(), length);

        length = route.punkt_drive.size();
        fout.write(reinterpret_cast<const char*>(&length), sizeof(length));
        fout.write(route.punkt_drive.data(), length);

        length = route.time_start.size();
        fout.write(reinterpret_cast<const char*>(&length), sizeof(length));
        fout.write(route.time_start.data(), length);

        length = route.time_end.size();
        fout.write(reinterpret_cast<const char*>(&length), sizeof(length));
        fout.write(route.time_end.data(), length);
    }
    fout.close();
}

void write_record(const std::string& filename, const bus_route& new_route, size_t index) {
    // Сначала читаем все существующие записи
    vec_bus routes = readd(fl);

    // Проверяем, что индекс в пределах допустимого диапазона
    if (index > routes.size()) { // Позволяем вставку в конец
        std::cerr << "Индекс вне диапазона!" << std::endl;
        return;
    }

    // Вставляем новую запись в вектор
    routes.insert(routes.begin() + index, new_route);

    // Открываем файл для записи
    std::ofstream out(filename, std::ios::binary);
    if (!out) {
        std::cerr << "Ошибка при открытии файла для записи!" << std::endl;
        return;
    }

    // Записываем все записи обратно в файл
    for (const auto& route : routes) {
        size_t length;

        length = route.nomer.size();
        out.write(reinterpret_cast<const char*>(&length), sizeof(length));
        out.write(route.nomer.data(), length);

        length = route.typ_bus.size();
        out.write(reinterpret_cast<const char*>(&length), sizeof(length));
        out.write(route.typ_bus.data(), length);

        length = route.punkt_drive.size();
        out.write(reinterpret_cast<const char*>(&length), sizeof(length));
        out.write(route.punkt_drive.data(), length);

        length = route.time_start.size();
        out.write(reinterpret_cast<const char*>(&length), sizeof(length));
        out.write(route.time_start.data(), length);

        length = route.time_end.size();
        out.write(reinterpret_cast<const char*>(&length), sizeof(length));
        out.write(route.time_end.data(), length);
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

    // Проверяем, существует ли запись с данным индексом
    // if (index >= routes.size()) {
    //     std::cerr << "Ошибка: номер вне диапазона!" << std::endl;
    //     return;
    // }

    // Получаем новые данные от пользователя
    bus_route new_route = get_route_from_user();
    update_record(new_route,index);

    vec_bus routes = readd(fl);
    writen(routes);
}