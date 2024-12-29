#include <begin.h>

// Вывод информации о рейсах в терминал
void writen(vec_bus str, size_t count) {
    int i = 1;
    for (size_t j = 0; j < count; ++j) {
        // Не показываем пользователю удалённые строки
        if (std::string(str[j].punkt_drive) == "*delite*") {
            continue;
        }

        std::cout << "\n" << i << ": Номер автобуса: " << str[j].nomer <<
            "\t\tТип автобуса: " << str[j].typ_bus <<
            "\t\t\tПункт назначения: " << str[j].punkt_drive <<
            "\t\tВремя отправления: " << str[j].time_start <<
            "\t\tВремя прибытия: " << str[j].time_end;
        ++i;
    }
}

//чтение данных из файла
vec_bus readd(const std::string& filename, size_t& count) {
    std::ifstream fin(filename, std::ios::binary);
    vec_bus routes = nullptr;
    count = 0;

    if (!fin) {
        std::cerr << "\nОшибка при открытии файла для чтения!" << std::endl;
        return routes;
    }

    // Сначала определяем количество записей
    fin.seekg(0, std::ios::end);
    size_t file_size = fin.tellg();
    count = file_size / sizeof(bus_route); // Предполагаем, что файл содержит только bus_route
    fin.seekg(0, std::ios::beg);

    // Выделяем память для массива bus_route
    routes = (vec_bus)malloc(count * sizeof(bus_route));
    if (routes == NULL) {
        std::cerr << "Ошибка выделения памяти\n";
        exit(1); // Завершаем программу в случае ошибки
    }

    // Читаем данные в массив
    for (size_t i = 0; i < count; ++i) {
        if (!fin.read(routes[i].nomer, sizeof(routes[i].nomer))) break;
        if (!fin.read(routes[i].typ_bus, sizeof(routes[i].typ_bus))) break;
        if (!fin.read(routes[i].punkt_drive, sizeof(routes[i].punkt_drive))) break;
        if (!fin.read(routes[i].time_start, sizeof(routes[i].time_start))) break;
        if (!fin.read(routes[i].time_end, sizeof(routes[i].time_end))) break;
    }

    fin.close();
    return routes;
}

size_t get_count(const std::string& filename) {
    std::ifstream fin(filename, std::ios::binary);
    
    if (!fin) {
        std::cerr << "Ошибка при открытии файла для чтения!" << std::endl;
        return 0; 
    }

    fin.seekg(0, std::ios::end);
    size_t file_size = fin.tellg();
    fin.seekg(0, std::ios::beg);

    size_t count = file_size / sizeof(bus_route);
    fin.close(); 
    return count; 
}
size_t get_count(const std::string& filename, size_t max_count) {
    std::ifstream fin(filename, std::ios::binary);
    
    if (!fin) {
        std::cerr << "Ошибка при открытии файла для чтения!" << std::endl;
        return 0;
    }

    fin.seekg(0, std::ios::end);
    size_t file_size = fin.tellg(); 
    fin.seekg(0, std::ios::beg);

    size_t count = file_size / sizeof(bus_route);
    fin.close();
    
    return (count < max_count) ? count : max_count;
}
void free_dynamic_array(vec_bus routes) {
    free(routes); 
}

//выводит все данные файлов
void demonstriten_all(){
    size_t count;
    count = get_count(fl);
    vec_bus all_data = readd(fl,count);
    if (count > 0) std::cout << "Все хранящиеся данные в файле:";
    writen(all_data,count);
    free_dynamic_array(all_data);
}