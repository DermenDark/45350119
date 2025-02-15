#include <begin.h>
#include <fstream>

// Вывод информации о рейсах в терминал
void writen(vec_bus str, size_t count)
{
    int i = 1;
    for (size_t j = 0; j < count; ++j)
    {
        // Не показываем пользователю удалённые строки
        if (std::string(str[j].punkt_drive) == "*delite*")
        {
            continue;
        }

        std::cout << "\n"
                  << i << ": Номер автобуса: " << str[j].nomer.double_nomer << "\t\tТип автобуса: " << str[j].typ_bus << "\t\t\t\nПункт назначения: " << str[j].punkt_drive << "\t\tВремя отправления: " << str[j].time_start << "\t\tВремя прибытия: " << str[j].time_end << "\n";
        ++i;
    }
}

// чтение данных из файла
vec_bus readd(const std::string &filename, size_t &count)
{
    std::ifstream fin(filename, std::ios::binary);
    vec_bus routes = nullptr;
    count = 0;

    // Сначала определяем количество записей
    fin.seekg(0, std::ios::end);
    size_t file_size = fin.tellg();
    count = file_size / sizeof(bus_route); // Предполагаем, что файл содержит только bus_route
    fin.seekg(0, std::ios::beg);

    // Выделяем память для массива bus_route
    routes = (vec_bus)malloc(count * sizeof(bus_route));
    if (routes == NULL)
    {
        std::cerr << "нет данных";
        return routes;
    }

    // Читаем данные в массив
    for (size_t i = 0; i < count; ++i)
    {
        fin.read(reinterpret_cast<char *>(&routes[i].nomer.double_nomer), sizeof(double)); // Чтение фиксированного размера
        fin.read(routes[i].typ_bus, sizeof(routes[i].typ_bus));
        fin.read(routes[i].punkt_drive, sizeof(routes[i].punkt_drive));
        fin.read(routes[i].time_start, sizeof(routes[i].time_start));
        fin.read(routes[i].time_end, sizeof(routes[i].time_end));
    }

    fin.close();
    return routes;
}
void free_dynamic_array(vec_bus routes)
{
    free(routes);
}

// выводит все данные файлов
void demonstriten_all()
{
    size_t count;
    vec_bus all_data = readd(fl, count);

    if (all_data != NULL)
    {
        std::cout << "Все хранящиеся данные в файле:";
        writen(all_data, count);
        free_dynamic_array(all_data);
    }
}