#include <begin.h>

vec_bus filtr_opr_1(int n, vec_bus &routes, size_t &sizam)
{
    std::function<bool(const bus_route &)> prisnak;
    std::string input;

    // Set up the predicate based on the user's choice
    switch (n)
    {
    case 1:
        std::cout << "\nВведите нужную вам дату выезда: ";
        std::getline(std::cin, input);
        prisnak = [input](const bus_route &route)
        {
            return route.typ_bus == input;
        };
        break;

    case 2:
        std::cout << "\nВведите нужный вам пункт назначения: ";
        std::getline(std::cin, input);
        prisnak = [input](const bus_route &route)
        {
            return route.punkt_drive == input;
        };
        break;

    default:
        std::cout << "Некорректный выбор!!!" << std::endl;
        return {};
    }

    vec_bus found_routes;
    size_t new_count;
    if (!routes.empty())
    {
        found_routes = filtr_eks(routes, sizam, prisnak, new_count);
    }

    if (new_count == 0)
    {
        std::cout << "Рейс не найден.\n";
    }
    else
    {
        std::cout << "\nНайденные рейсы:\n";
        writen(found_routes);
    }
    return found_routes;
}

void writen(vec_bus &routes)
{
    if (routes.empty())
    {
        std::cout << "Нет доступных маршрутов для отображения.\n";
        return;
    }

    std::cout << "Список маршрутов:";
    for (auto &route : routes)
    {
        std::cout << "\nДата выезда: " << route.typ_bus
                  << ", \t\tПункт назначения: " << route.punkt_drive
                  << ", \nВремя отправления: " << route.time_start
                  << ", \t\tВремя прибытия: " << route.time_end
                  << ", \t\tЧисло свободных билетов: "
                  << (route.is_double ? route.nomer.double_nomer : route.nomer.float_nomer)
                  << "\n";
    }
}

vec_bus filter_routes_by_tickets(int user_input, vec_bus &routes)
{
    vec_bus filtered_routes;

    for (const auto &route : routes)
    {
        if (route.is_double)
        {
            if (route.nomer.double_nomer < static_cast<double>(user_input))
            {
                filtered_routes.push_back(route);
            }
        }
        else
        {
            if (route.nomer.float_nomer < static_cast<float>(user_input))
            {
                filtered_routes.push_back(route);
            }
        }
    }

    return filtered_routes;
}

void selection_sort(vec_bus &routes)
{
    size_t count = routes.size();
    for (size_t i = 0; i < count - 1; ++i)
    {
        size_t max_index = i;
        for (size_t j = i + 1; j < count; ++j)
        {
            if (routes[j].time_start > routes[max_index].time_start)
            {
                max_index = j;
            }
        }
        if (max_index != i)
        {
            std::swap(routes[i], routes[max_index]);
        }
    }
}

vec_bus filtr_prisnak(const vec_bus &rout, const std::string &hour)
{
    vec_bus filtr_vec;
    for (const auto &route : rout)
    {
        if (route.time_end <= hour)
        {
            filtr_vec.push_back(route);
        }
    }
    return filtr_vec;
}

vec_bus filtr_time(const vec_bus &all_data)
{
    std::string hour;
    std::cout << "Введите время отправления (чч:мм): ";
    std::cin >> hour;

    vec_bus filtered_data = filtr_prisnak(all_data, hour);

    if (!filtered_data.empty())
    {
        std::cout << "Фильтрованные данные по времени:\n";
        writen(filtered_data);
    }
    else
    {
        std::cout << "Нет данных, соответствующих заданному времени.\n";
    }

    return filtered_data;
}

void pay()
{
    size_t count;
    vec_bus routes = readd(fl, count);


    vec_bus filtered_by_date = filtr_opr_1(1, routes, count);
    if (filtered_by_date.empty())
    {
        std::cout << "Рейсы с вашими пожеланиями не найдены.\n";
        return;
    }

 
    vec_bus filtered_by_destination = filtr_opr_1(2, filtered_by_date, count);
    if (filtered_by_destination.empty())
    {
        std::cout << "Рейсы с вашими пожеланиями не найдены.\n";
        return; 
    }

    
    int ticket_count = 0;
    std::cout << "Введите нужное количество билетов: ";
    std::cin >> ticket_count;


    vec_bus filtered_by_tickets = filter_routes_by_tickets(ticket_count, filtered_by_destination);
    writen(filtered_by_tickets);


    vec_bus final_filtered_routes = filtr_time(filtered_by_tickets);
}