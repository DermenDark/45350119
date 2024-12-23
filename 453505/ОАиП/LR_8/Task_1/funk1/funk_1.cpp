#include <begin.h>

//вывод информации о рейсах
void writen(vec_bus & str) {
    // std::cout << "\n\nХранящиеся данные:\n";
    for ( auto& inner : str) {
        std::cout << "\nНомер автобуса: " << inner.nomer <<
        "\t\tТип автобуса: " << inner.typ_bus <<
        "\t\tПункт назначения: " <<inner.punkt_drive <<
        "\t\tВремя отправления:"<<inner.time_start<<
        "\t\tВремя прибытия:"<<inner.time_end;
        }
}


// чтение файла(текст)
vec_bus readd_1(const std::string& filename) {
    std::ifstream fin(filename); // Открываем файл 
    vec_bus routes;

    if (!fin) {
        std::cerr << "Ошибка при открытии файла для чтения!";
        return routes;}


    std::string line;
    while (std::getline(fin, line)) {
        bus_route route;
        size_t pos = 0;


        pos = line.find(',');
        route.nomer = line.substr(0, pos);
        line.erase(0, pos + 1);

        pos = line.find(',');
        route.typ_bus = line.substr(0, pos);
        line.erase(0, pos + 1);

        pos = line.find(',');
        route.punkt_drive = line.substr(0, pos);
        line.erase(0, pos + 1);

        pos = line.find(',');
        route.time_start = line.substr(0, pos);
        line.erase(0, pos + 1);

        route.time_end = line; 


        routes.push_back(route); // Добавляем в вектор
        }

    fin.close();
    return routes;
}


vec_bus readd(std::string& filename) {
    std::ifstream fin(filename, std::ios::binary);
    vec_bus routes;

    if (!fin) {
        std::cerr << "Ошибка при открытии файла для чтения!" << std::endl;
        return routes;
    }


    while (true) {
        bus_route route;

        // Читаем длину строки для номера рейса
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

//выводит все данные файлов
void demonstriten_all(){
    vec_bus all_data = readd(fl);
    // std::cout<<"Все хранящиеся данные в файле:";
    writen(all_data);
}