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

vec_bus read() {
    std::ifstream fin(fl, std::ios::binary);
    vec_bus routes;

    if (!fin) {
        std::cerr << "Ошибка при открытии файла для чтения!" << std::endl;
        return routes;
    }

    while (true) {
        bus_route route;
        
        // Читаем запись
        if (!fin.read(reinterpret_cast<char*>(&route), sizeof(route))) break;

        // Отсекаем нули
        route.nomer[MAX_SIZE - 1] = '\0'; // Убедимся, что строка завершается нулем
        route.typ_bus[MAX_SIZE - 1] = '\0';
        route.punkt_drive[MAX_SIZE - 1] = '\0';
        route.time_start[MAX_SIZE - 1] = '\0';
        route.time_end[MAX_SIZE - 1] = '\0';

        // Добавляем в вектор, отсекая нули
        routes.push_back(route);
    }

    fin.close();
    return routes;
}

void writ(const vec_bus& bus) {
    std::ofstream out(fl, std::ios::binary | std::ios::app); // Открываем файл для записи в бинарном режиме

    if (!out) {
        std::cerr << "Ошибка при открытии файла для записи!\n";
        return;
    }

    for (const auto& route : bus) {
        // Записываем запись
        out.write(reinterpret_cast<const char*>(&route), sizeof(route));
    }

    out.close(); // Закрываем файл
    std::cout << "\nФайл '" << filename << "' успешно записан." << std::endl;
}


//выводит все данные файлов
void demonstriten_all(){
    vec_bus all_data = readd(fl);
    // std::cout<<"Все хранящиеся данные в файле:";
    writen(all_data);
}