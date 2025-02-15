#include <begin.h>
// Нахождение определённого рейса
vec_bus filtr_eks(const vec_bus &rout, size_t count, std::function<bool(const bus_route &)> predicate, size_t &new_count)
{
    vec_bus filtr_vec(count); 
    new_count = 0;
    for (size_t i = 0; i < count; ++i)
    {
        if (predicate(rout[i]))
        {
            filtr_vec[new_count++] = rout[i];
        }
    }
    filtr_vec.resize(new_count);
    return filtr_vec;
}
void filtr_opr()
{
    std::string find_bus;
    bool problem = false;
    std::function<bool(const bus_route &)> prisnak;

    do
    {
        if (problem)
        {
            std::cout << "\nНет такого свойства. ";
        }
        poisk(); // poisk() выводит доступные свойства для поиска
        std::cout << "Введите по какому свойству будете искать необходимый поезд? (1-5 для свойств, 0 для выхода): ";
        std::getline(std::cin, find_bus);

        if (find_bus.empty() || find_bus.length() > 1)
        {
            problem = true;
            continue;
        }

        std::string input;

        switch (find_bus[0])
        {
        case '1': // Поиск по номеру автобуса
            std::cout << "Введите число свободных билетов на поезд для поиска: ";
            std::getline(std::cin, input);
            try
            {
                double search_number = std::stod(input); // Преобразуем строку в double
                prisnak = [search_number](const bus_route &route)
                {
                    return route.nomer.double_nomer == search_number || route.nomer.float_nomer == search_number; // Сравниваем с double и float
                };
            }
            catch (const std::invalid_argument &)
            {
                std::cout << "Некорректный ввод. Пожалуйста, введите число." << std::endl;
                problem = true;
                continue;
            }
            catch (const std::out_of_range &)
            {
                std::cout << "Число вне допустимого диапазона." << std::endl;
                problem = true;
                continue;
            }
            break;
        case '2': // Поиск по типу автобуса
            std::cout << "Введите дату выезда поезда для поиска: ";
            std::getline(std::cin, input);
            prisnak = [input](const bus_route &route)
            {
                return std::string(route.typ_bus) == input;
            };
            break;
        case '3': // Поиск по пункту назначения
            std::cout << "Введите пункт назначения для поиска: ";
            std::getline(std::cin, input);
            prisnak = [input](const bus_route &route)
            {
                return std::string(route.punkt_drive) == input;
            };
            break;
        case '4': // Поиск по времени отправления
            std::cout << "Введите время отправления для поиска: ";
            std::getline(std::cin, input);
            prisnak = [input](const bus_route &route)
            {
                return std::string(route.time_start) == input;
            };
            break;
        case '5': // Поиск по времени прибытия
            std::cout << "Введите время прибытия для поиска: ";
            std::getline(std::cin, input);
            prisnak = [input](const bus_route &route)
            {
                return std::string(route.time_end) == input;
            };
            break;
        case '0': // Выход из программы
            std::cout << "Выход из программы.\n";
            return;
        default: // Некорректный ввод
            problem = true;
            continue;
        }
        problem = false; 
    } while (problem);

    size_t count;
    vec_bus routes = readd(fl, count); 
    vec_bus found_routes;

    size_t new_count;
    if (!routes.empty())
    {
        found_routes = filtr_eks(routes, count, prisnak, new_count);
    }

    if (!found_routes.empty() && !routes.empty())
    {
        if (new_count == 0)
        {
            std::cout << "Рейс не найден.\n";
        }
        else
        {
            writen(found_routes); // Выводим найденные рейсы
        }
    }
}