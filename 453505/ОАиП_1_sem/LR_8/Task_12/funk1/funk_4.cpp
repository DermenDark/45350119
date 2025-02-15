#include <begin.h>

// Функция для записи массива маршрутов в файл
void wri(const std::string &filename, const vec_bus routes, size_t count)
{
    std::ofstream out(filename);
    if (!out)
    {
        std::cerr << "Ошибка при открытии файла для записи!" << std::endl;
        return;
    }

    for (size_t i = 0; i < count; ++i)
    {

        if (routes[i].is_double)
        {
            out << routes[i].nomer.double_nomer;
        }
        else
        {
            out << routes[i].nomer.float_nomer;
        }
        out << ","
            << routes[i].typ_bus << ","
            << routes[i].punkt_drive << ","
            << routes[i].time_start << ","
            << routes[i].time_end << "\n";
    }

    out.close();
}

// добавление новых рейсов в справочник
void new_bus_route()
{
    std::string input_size;
    int n = 0;

    while (true)
    {
        std::cout << "Введите количество рейсов, которые хотите добавить: ";
        std::getline(std::cin, input_size);

        if (input_size.empty())
        {
            std::cout << "Вы ничего не ввели.\n";
            continue;
        }

        try
        {
            n = std::stoi(input_size);
            if (n <= 0)
            {
                std::cout << "Нужно ввести положительное целое число.\n";
                continue;
            }
            break;
        }
        catch (...)
        {
            std::cout << "Ошибка: введите положительное целое число.\n";
        }
    }

    bus_route *spisok = (bus_route *)malloc(n * sizeof(bus_route));
    if (spisok == NULL)
    {
        std::cerr << "Ошибка выделения памяти\n";
        exit(1);
    }

    for (int i = 0; i < n; ++i)
    {
        char vopros;
        std::cout << "\nВведите данные для рейса " << (i + 1) << ":\n";
        bool probl = true;

        do
        {
            std::cout << "Выберите тип числа свободных билетов (1 - float, 2 - double): ";
            int type_choice;
            std::cin >> type_choice;
            std::cin.ignore();

            if (type_choice == 1)
            {
                float temp_float;
                std::cout << "Введите число свободных билетов (float): ";
                std::cin >> temp_float;
                spisok[i].nomer.float_nomer = temp_float;
                spisok[i].is_double = false;
                probl = false;
            }
            else if (type_choice == 2)
            {
                std::cout << "Введите число свободных билетов (double): ";
                double temp;
                std::cin >> temp;
                spisok[i].nomer.double_nomer = temp;
                spisok[i].is_double = true;
                probl = false;
            }
            else
            {
                probl = true;
                continue;
            }
            std::cin.ignore();
        } while (probl);

        std::cout << "Дата выезда: ";
        std::cin.getline(spisok[i].typ_bus, sizeof(spisok[i].typ_bus));

        std::cout << "Пункт назначения: ";
        std::cin.getline(spisok[i].punkt_drive, sizeof(spisok[i].punkt_drive));

        std::cout << "Время отправления: ";
        std::cin.getline(spisok[i].time_start, sizeof(spisok[i].time_start));

        std::cout << "Время прибытия: ";
        std::cin.getline(spisok[i].time_end, sizeof(spisok[i].time_end));
    }

    std::ofstream out(fl, std::ios::app);
    if (!out)
    {
        std::cerr << "Ошибка при открытии файла для записи!" << std::endl;
        free(spisok);
        return;
    }

    for (int i = 0; i < n; ++i)
    {
        if (spisok[i].is_double)
        {
            out << spisok[i].nomer.double_nomer;
        }
        else
        {
            out << spisok[i].nomer.float_nomer;
        }
        out << ","
            << spisok[i].typ_bus << ","
            << spisok[i].punkt_drive << ","
            << spisok[i].time_start << ","
            << spisok[i].time_end << "\n";
    }

    out.close();
}