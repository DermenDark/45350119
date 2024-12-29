#include <begin.h>

// Функция для обновления записи в файле
void update_record(const bus_route &updated_route, size_t index, const std::string &filename)
{
    std::fstream file(filename, std::ios::in | std::ios::out);
    if (!file)
    {
        std::cerr << "Ошибка при открытии файла для записи!" << std::endl;
        return;
    }

    size_t record_size = sizeof(bus_route);
    std::streampos pos = index * record_size;

    file.seekp(pos);

    // Записываем обновленные данные
    file.write(reinterpret_cast<const char *>(&updated_route), record_size);
    file.close();
}

// Функция для получения данных о маршруте от пользователя
bus_route get_route_from_user(const bus_route &current_route)
{
    bool problem = false;
    bus_route route = current_route; // Сохраняем текущие значения

    std::cout << "Вы можете изменить только одно свойство от исходного маршрута.\n";

    do
    {
        std::cout << " __________________\n";
        std::cout << "| Текущие значения:\n";
        std::cout << "|------------------\n";
        std::cout << "| 1. Номер автобуса: " << route.nomer.double_nomer << "\n";
        std::cout << "| 2. Тип автобуса: " << route.typ_bus << "\n";
        std::cout << "| 3. Пункт назначения: " << route.punkt_drive << "\n";
        std::cout << "| 4. Время отправления: " << route.time_start << "\n";
        std::cout << "| 5. Время прибытия: " << route.time_end << "\n";
        std::cout << "|___________________\n";
        // poisk();
        std::cout << "Введите номер свойства, которое хотите изменить (0 для выхода): ";

        int choice;
        std::cin >> choice;
        std::cin.ignore();
        bool probl = true;
        switch (choice)
        {
        case 1:
            do
            {
                std::cout << "Выберите тип номера автобуса (1 - float, 2 - double): ";
                int type_choice;
                std::cin >> type_choice;
                std::cin.ignore();

                if (type_choice == 1)
                {
                    float temp_float;
                    std::cout << "Введите номер автобуса (float): ";
                    std::cin >> temp_float;
                    route.nomer.double_nomer = static_cast<double>(temp_float);
                    probl = false;
                }
                else if (type_choice == 2)
                {
                    std::cout << "Введите номер автобуса (double): ";
                    std::cin >> route.nomer.double_nomer;
                    probl = false;
                }
                else
                {
                    probl = true;
                }
                std::cin.ignore();
            } while (probl);
            break;
        case 2:
            std::cout << "Введите новый тип автобуса: ";
            std::cin.getline(route.typ_bus, sizeof(route.typ_bus));
            break;
        case 3:
            std::cout << "Введите новый пункт назначения: ";
            std::cin.getline(route.punkt_drive, sizeof(route.punkt_drive));
            break;
        case 4:
            std::cout << "Введите новое время отправления: ";
            std::cin.getline(route.time_start, sizeof(route.time_start));
            break;
        case 5:
            std::cout << "Введите новое время прибытия: ";
            std::cin.getline(route.time_end, sizeof(route.time_end));
            break;
        case 0:
            std::cout << "Выход из функции.\n";
            return route;
        default:
            std::cout << "Некорректный выбор. Попробуйте снова.\n";
            problem = false;
            continue;
        }

        std::cout << "Свойство изменено. Хотите изменить что-то еще? (1 - да, 0 - нет): ";
        int continue_choice;
        std::cin >> continue_choice;
        std::cin.ignore();

        if (continue_choice != 0)
        {
            problem = true;
        }
        else
        {
            problem = false;
        }

    } while (problem);
    return route;
}

// поиск индекса
int find_route_index(const vec_bus &routes, size_t count, const std::function<bool(const bus_route &)> &predicate)
{
    for (size_t i = 0; i < count; ++i)
    {
        if (predicate(routes[i]))
        {
            std::cout << "Найден маршрут на индексе: " << i << std::endl;
            return i;
        }
    }
    std::cout << "Маршрут не найден." << std::endl;
    return -1;
}

// Функция для обновления записи в файле
void update_file()
{
    std::string find_bus;
    bool problem = false;
    std::function<bool(const bus_route &)> prisnak;

    do
    {
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

    int index = -1;
    if (routes != NULL)
    {
        index = find_route_index(routes, count, prisnak);
    } // Передаем count как третий аргумент
    else
    {
        return;
    }

    if (index == -1)
    {
        std::cout << "Рейс не найден.\n";
        free_dynamic_array(routes);
        return;
    }

    bus_route new_route;
    if (routes != NULL)
    {
        new_route = get_route_from_user(routes[index]);
    }

    if (!new_route.punkt_drive)
    {
        update_record(new_route, index, fl);
    } // Укажите путь к вашему файлу

    // Обновляем массив маршрутов и записываем его обратно в файл
    routes = readd(fl, count);
    if (routes != NULL)
    {
        writen(routes, count); // Передаем количество записей
        free_dynamic_array(routes);
    }
}