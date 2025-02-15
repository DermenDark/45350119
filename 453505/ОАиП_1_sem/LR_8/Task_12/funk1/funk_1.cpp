#include <begin.h>

vec_bus readd(const std::string &filename, size_t &count)
{
    vec_bus routes;
    std::ifstream in(filename);
    if (!in)
    {
        std::cerr << "Ошибка при открытии файла!" << std::endl;
        return routes;
    }

    std::string line;
    while (std::getline(in, line))
    {
        bus_route route;
        std::istringstream ss(line);
        std::string bus_number;

        std::getline(ss, bus_number, ',');
        if (bus_number.find('.') != std::string::npos)
        {
            route.nomer.double_nomer = std::stod(bus_number);
            route.is_double = true;
        }
        else
        {
            route.nomer.float_nomer = std::stof(bus_number);
            route.is_double = false;
        }

        std::string temp;
        std::getline(ss, temp, ',');
        strncpy(route.typ_bus, temp.c_str(), sizeof(route.typ_bus) - 1);
        route.typ_bus[sizeof(route.typ_bus) - 1] = '\0';

        std::getline(ss, temp, ',');
        strncpy(route.punkt_drive, temp.c_str(), sizeof(route.punkt_drive) - 1);
        route.punkt_drive[sizeof(route.punkt_drive) - 1] = '\0';

        std::getline(ss, temp, ',');
        strncpy(route.time_start, temp.c_str(), sizeof(route.time_start) - 1);
        route.time_start[sizeof(route.time_start) - 1] = '\0';

        std::getline(ss, temp, ',');
        strncpy(route.time_end, temp.c_str(), sizeof(route.time_end) - 1);
        route.time_end[sizeof(route.time_end) - 1] = '\0';

        routes.push_back(route);
    }

    count = routes.size();
    in.close();
    return routes;
}

// выводит все данные файлов
void demonstriten_all()
{
    size_t count;
    vec_bus all_data = readd(fl, count);

    if (!all_data.empty())
    {
        std::cout << "Все хранящиеся данные в файле:";
        writen(all_data);
    }
}