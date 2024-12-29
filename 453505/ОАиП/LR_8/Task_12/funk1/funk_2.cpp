#include <begin.h>

// Функция для сортировки выбором по убыванию
void selection_sort(vec_bus routes, size_t count)
{
    for (size_t i = 0; i < count - 1; ++i)
    {
        size_t max_index = i;
        for (size_t j = i + 1; j < count; ++j)
        {
            // Сравниваем время окончания рейса
            if (strcmp(routes[j].time_end, routes[max_index].time_end) > 0)
            {
                max_index = j; // Находим индекс максимального элемента
            }
        }
        // Меняем местами текущий элемент с максимальным
        if (max_index != i)
        {
            bus_route temp = routes[i];
            routes[i] = routes[max_index];
            routes[max_index] = temp;
        }
    }
}

// Фильтр, который перебирает массив
vec_bus filtr_prisnak(const vec_bus &rout, size_t count, const std::string &hour, size_t &new_count)
{
    vec_bus filtr_vec = (vec_bus)malloc(count * sizeof(bus_route)); // Выделяем память для фильтрованного массива
    if (filtr_vec == NULL)
    {
        std::cerr << "Ошибка выделения памяти\n";
        return filtr_vec; // Завершаем программу в случае ошибки
    }
    new_count = 0;
    for (size_t i = 0; i < count; ++i)
    {
        if (strcmp(rout[i].time_end, hour.c_str()) <= 0)
        {
            filtr_vec[new_count++] = rout[i];
        }
    }

    // Изменяем размер фильтрованного массива
    filtr_vec = (vec_bus)realloc(filtr_vec, new_count * sizeof(bus_route));
    if (filtr_vec == NULL)
    {
        std::cerr << "no_data";
        return filtr_vec; // Завершаем программу в случае ошибки
    }

    // Сортируем отфильтрованные данные по убыванию
    selection_sort(filtr_vec, new_count);

    return filtr_vec;
}

// Фильтрует данные по времени
void filtr_time()
{
    std::string hour;
    std::cout << "Введите время (чч:мм): ";
    std::cin >> hour;

    size_t count;
    vec_bus all_data = readd(fl, count); // Укажите путь к вашему файлу
    size_t new_count;
    vec_bus filtered_data;

    if (all_data != NULL)
    {
        filtered_data = filtr_prisnak(all_data, count, hour, new_count);
    }

    if (all_data != NULL && filtered_data != NULL)
    {
        if (new_count > 0)
        {
            std::cout << "Фильтрованные данные по времени:\n";
            writen(filtered_data, new_count);
        }
        else
        {
            std::cout << "Нет данных, соответствующих заданному времени.\n";
        }

        free_dynamic_array(all_data);
        free_dynamic_array(filtered_data);
    }
}