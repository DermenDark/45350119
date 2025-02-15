#include <begin.h>

// Функция для удаления записи из текстового файла
void delete_record(size_t index, const std::string &filename)
{
    size_t count;
    vec_bus routes = readd(filename, count);

    if (index < count)
    {
        vec_bus new_routes;
        new_routes.reserve(count - 1);

        for (size_t i = 0; i < count; ++i)
        {
            if (i != index)
            {
                new_routes.push_back(routes[i]);
            }
        }

        std::ofstream out(filename);
        if (!out)
        {
            std::cerr << "Ошибка при открытии файла для записи!" << std::endl;
            return;
        }

        for (const auto &route : new_routes)
        {
            if (route.is_double)
            {
                out << route.nomer.double_nomer;
            }
            else
            {
                out << route.nomer.float_nomer;
            }
            out << ","
                << route.typ_bus << ","
                << route.punkt_drive << ","
                << route.time_start << ","
                << route.time_end << "\n";
        }

        out.close();
    }
    else
    {
        std::cout << "Индекс вне диапазона." << std::endl;
    }
}

// Функция для удаления маршрута
void del()
{
    std::string find_bus;
    bool problem = false;
    std::function<bool(const bus_route &)> prisnak;

    do
    {
        poisk(); // poisk() выводит доступные свойства для поиска
        std::cout << "Введите по какому свойству будете искать необходимый автобус? (1-5 для свойств, 0 для выхода): ";
        std::getline(std::cin, find_bus);

        if (find_bus.empty() || find_bus.length() > 1)
        {
            problem = true;
            continue;
        }

        std::string input; // Переменная для хранения ввода пользователя

        switch (find_bus[0])
        {
        case '1':
            std::cout << "Введите количество свободных билетов для поиска: ";
            std::getline(std::cin, input);

            // Преобразуем строку в double
            double search_number;
            try
            {
                search_number = std::stod(input); // Преобразуем строку в double
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

            prisnak = [search_number](const bus_route &route)
            {
                return route.nomer.double_nomer == search_number; // Сравниваем с double
            };
            problem = false;
            break;
        case '2':
            std::cout << "Введите дату выезда для поиска: ";
            std::getline(std::cin, input);
            prisnak = [input](const bus_route &route)
            {
                return route.typ_bus == input;
            };
            problem = false;
            break;
        case '3':
            std::cout << "Введите пункт назначения для поиска: ";
            std::getline(std::cin, input);
            prisnak = [input](const bus_route &route)
            {
                return route.punkt_drive == input;
            };
            problem = false;
            break;
        case '4':
            std::cout << "Введите время отправления для поиска: ";
            std::getline(std::cin, input);
            prisnak = [input](const bus_route &route)
            {
                return route.time_start == input;
            };
            problem = false;
            break;
        case '5':
            std::cout << "Введите время прибытия для поиска: ";
            std::getline(std::cin, input);
            prisnak = [input](const bus_route &route)
            {
                return route.time_end == input;
            };
            problem = false;
            break;
        case '0':
            std::cout << "Выход из программы.\n";
            return;
        default:
            problem = true;
            continue;
        }
    } while (problem);

    size_t count;
    vec_bus routes = readd(fl, count); // Укажите путь к вашему файлу

    int index = -1;
    if (!routes.empty())
    {
        index = find_route_index(routes, count, prisnak); // Передаем count как третий аргумент
    }
    else
    {
        return;
    }

    if (index == -1)
    {
        std::cout << "Рейс не найден.\n";
        return;
    }

    delete_record(index, fl); // Укажите путь к вашему файлу

    // Обновляем массив маршрутов и записываем его обратно в файл
    routes = readd(fl, count);
    if (!routes.empty())
    {
        writen(routes); // Передаем количество записей
    }
}