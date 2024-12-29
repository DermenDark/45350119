#include <begin.h>

// Нахождение определённого рейса
vec_bus filtr_eks(const vec_bus &rout, size_t count, std::function<bool(const bus_route &)> predicate, size_t &new_count)
{
    vec_bus filtr_vec = (vec_bus)malloc(count * sizeof(bus_route)); // Выделяем память для фильтрованного массива
    new_count = 0;

    for (size_t i = 0; i < count; ++i)
    {
        // Используем переданное условие для фильтрации
        if (predicate(rout[i]))
        {
            filtr_vec[new_count++] = rout[i]; // Добавляем в фильтрованный массив
        }
    }

    // Изменяем размер фильтрованного массива
    filtr_vec = (vec_bus)realloc(filtr_vec, new_count * sizeof(bus_route));
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
        poisk(); // Предполагается, что poisk() выводит доступные свойства для поиска
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
            std::cout << "Введите номер автобуса для поиска: ";
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
            std::cout << "Введите тип автобуса для поиска: ";
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
    vec_bus found_routes;

    size_t new_count;
    if (routes != NULL)
    {
        found_routes = filtr_eks(routes, count, prisnak, new_count);
    }

    if (found_routes != NULL && routes != NULL)
    {
        if (new_count == 0)
        {
            std::cout << "Рейс не найден.\n";
        }
        else
        {
            writen(found_routes, new_count); // Выводим найденные рейсы
        }
        free_dynamic_array(routes);
        free_dynamic_array(found_routes);
    }
}