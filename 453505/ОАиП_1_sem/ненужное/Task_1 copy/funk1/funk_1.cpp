#include <begin.h>

//вывод информации о рейсах в терминал
void writen(vec_bus & str) {
    int i=1;
    for ( auto& inner : str) {
        //не показываем пользователю удалённые строки
            if (std::string(inner.punkt_drive) == "*delite*") {
                continue;
            }


        std::cout <<"\n"<<i<< ": Номер автобуса: " << inner.nomer <<
        "\t\tТип автобуса: " << inner.typ_bus <<
        "\t\t\tПункт назначения: " <<inner.punkt_drive <<
        "\t\tВремя отправления:"<<inner.time_start<<
        "\t\tВремя прибытия:"<<inner.time_end;
        ++i;
        }
}

//чтение данных из файла
vec_bus readd(const std::string& filename) {
    std::ifstream fin(filename, std::ios::binary);
    vec_bus routes;

    if (!fin) {
        std::cerr << "\nОшибка при открытии файла для чтения!" << std::endl;
        return routes;
    }

    while (true) {
        bus_route route;

        // Читаем данные в фиксированные массивы
        if (!fin.read(route.nomer, sizeof(route.nomer))) break;
        if (!fin.read(route.typ_bus, sizeof(route.typ_bus))) break;
        if (!fin.read(route.punkt_drive, sizeof(route.punkt_drive))) break;
        if (!fin.read(route.time_start, sizeof(route.time_start))) break;
        if (!fin.read(route.time_end, sizeof(route.time_end))) break;


        // Добавляем рейс в вектор
        routes.push_back(route);
    }

    fin.close();
    return routes;
}


//выводит все данные файлов
void demonstriten_all(){
    vec_bus all_data = readd(fl);
    if(!all_data.empty())std::cout<<"Все хранящиеся данные в файле:";
    writen(all_data);
}