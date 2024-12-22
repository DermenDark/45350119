#include <begin.h>

//вывод информации о рейсах
void writen(vec_bus & str) {
    // std::cout << "\n\nХранящиеся данные:\n";
    for ( auto& inner : str) {
        std::cout << "\nНомер автобуса: " << inner.nomer <<
        "\tТип автобуса: " << inner.typ_bus <<
        "\t\tПункт назначения: " <<inner.punkt_drive <<
        "\t\tВремя отправления:"<<inner.time_start<<
        "\tВремя прибытия:"<<inner.time_end;
        }
}

// чтение файла
vec_bus readd(const std::string& filename) {
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


//выводит все данные файлов
void demonstriten_all(){
    vec_bus all_data = readd(fl);
    std::cout<<"Все хранящиеся данные в файле:";
    writen(all_data);
}