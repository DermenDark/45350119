#include <begin.h>

// Функция для обновления записи в текстовом файле
#include <begin.h>

// Функция для обновления записи в текстовом файле
void update_record(const bus_route& updated_route, size_t index, const std::string& filename) {
    size_t count;
    vec_bus routes = readd(filename, count); // Read all routes

    if (routes.empty()) { // Check if routes is empty
        std::cerr << "Не удалось прочитать маршруты из файла." << std::endl;
        return;
    }

    if (index < count) { // Check if index is within bounds
        routes[index] = updated_route; // Update the record
    } else {
        std::cerr << "Индекс вне диапазона." << std::endl;
        return;
    }

    // Write all routes back to the file
    std::ofstream out(filename);
    if (!out) {
        std::cerr << "Ошибка при открытии файла для записи!" << std::endl;
        return;
    }

    for (size_t i = 0; i < count; ++i) {
        // Write bus number based on type
        if (routes[i].is_double) {
            out << routes[i].nomer.double_nomer; // Write as double
        } else {
            out << routes[i].nomer.float_nomer; // Write as float
        }
        out << "," // Separator
            << routes[i].typ_bus << ","
            << routes[i].punkt_drive << ","
            << routes[i].time_start << ","
            << routes[i].time_end << "\n"; // New line
    }

    out.close();
}

// Функция для получения данных о маршруте от пользователя
bus_route get_route_from_user(const bus_route &current_route) {
    bus_route route = current_route; // Save current values

    std::cout << "Вы можете изменить только одно свойство от исходного маршрута.\n";

    bool problem = false;
    do {
        std::cout << " __________________\n";
        std::cout << "| Текущие значения:\n";
        std::cout << "|------------------\n";
        std::cout << "| 1. Номер автобуса: " << (route.is_double ? route.nomer.double_nomer : route.nomer.float_nomer) << "\n";
        std::cout << "| 2. Тип автобуса: " << route.typ_bus << "\n";
        std::cout << "| 3. Пункт назначения: " << route.punkt_drive << "\n";
        std::cout << "| 4. Время отправления: " << route.time_start << "\n";
        std::cout << "| 5. Время прибытия: " << route.time_end << "\n";
        std::cout << "|___________________\n";
        
        std::cout << "Введите номер свойства, которое хотите изменить (0 для выхода): ";

        int choice;
        std::cin >> choice;
        std::cin.ignore(); // Clear the newline character from the input buffer

        switch (choice) {
            case 1: {
                std::cout << "Выберите тип номера автобуса (1 - float, 2 - double): ";
                int type_choice;
                std::cin >> type_choice;
                std::cin.ignore(); // Clear the newline character from the input buffer

                if (type_choice == 1) {
                    float temp_float;
                    std::cout << "Введите номер автобуса (float): ";
                    std::cin >> temp_float;
                    route.nomer.float_nomer = temp_float;
                    route.is_double = false;          
                } else if (type_choice == 2) {
                    double temp;
                    std::cout << "Введите номер автобуса (double): ";
                    std::cin >> temp;
                    route.nomer.double_nomer = temp; 
                    route.is_double = true; 
                } else {
                    std::cout << "Некорректный выбор. Попробуйте еще раз.\n";
                    problem = true;
                    continue;
                }
                break;
            }
            case 2:
                std::cout << "Введите новый тип автобуса: ";
                std::cin.getline(route.typ_bus, sizeof(route.typ_bus)); // Use std::cin.getline for char array
                break;
            case 3:
                std::cout << "Введите новый пункт назначения: ";
                std::cin.getline(route.punkt_drive, sizeof(route.punkt_drive)); // Use std::cin.getline for char array
                break;
            case 4:
                std::cout << "Введите новое время отправления: ";
                std::cin.getline(route.time_start, sizeof(route.time_start)); // Use std::cin.getline for char array
                break;
            case 5:
                std::cout << "Введите новое время прибытия: ";
                std::cin.getline(route.time_end, sizeof(route.time_end)); // Use std::cin.getline for char array
                break;
            case 0:
                std::cout << "Выход из изменения маршрута.\n";
                return route; // Return the modified route
            default:
                std::cout << "Некорректный выбор. Пожалуйста, выберите номер от 0 до 5.\n";
                problem = true;
                continue;
        }
        problem = false; // Reset problem flag if a valid choice was made
    } while (problem);

    return route; // Return the modified route
}

// Поиск индекса
int find_route_index(const vec_bus& routes, size_t count, const std::function<bool(const bus_route&)>& predicate) {
    for (size_t i = 0; i < count; ++i) {
        if (predicate(routes[i])) {
            std::cout << "Найден маршрут на индексе: " << i << std::endl;
            return i;
        }
    }
    std::cout << "Маршрут не найден." << std::endl;
    return -1;
}

// Функция для обновления записи в файле
void update_file() {
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
    vec_bus routes = readd("file.txt", count); // Укажите путь к вашему файлу

    int index = -1;
    if (!routes.empty()) {
        index = find_route_index(routes, count, prisnak); // Передаем count как третий аргумент
    } else {
        return;
    }

    if (index == -1) {
        std::cout << "Рейс не найден.\n";
        return;
    }

    bus_route new_route;
    if (!routes.empty()) {
        new_route = get_route_from_user(routes[index]);
    }

    update_record(new_route, index, "file.txt"); // Укажите путь к вашему файлу

    // Обновляем массив маршрутов и записываем его обратно в файл
    routes = readd("file.txt", count);
    if (!routes.empty()) {
        writen(routes, count); // Передаем количество записей
    }
}