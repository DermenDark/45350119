#include <begin.h>

// Функция для сортировки выбором по убыванию
void selection_sort(vec_bus routes, size_t count) {
    for (size_t i = 0; i < count - 1; ++i) {
        size_t max_index = i;
        for (size_t j = i + 1; j < count; ++j) {
            if (routes[j].time_end > routes[max_index].time_end) { // Use > operator for std::string
                max_index = j;
            }
        }
        if (max_index != i) {
            bus_route temp = routes[i];
            routes[i] = routes[max_index];
            routes[max_index] = temp;
        }
    }
}

// Фильтр, который перебирает массив
vec_bus filtr_prisnak(const vec_bus &rout, size_t count, const std::string &hour, size_t &new_count) {
    vec_bus filtr_vec(count); // Use vec_bus instead of malloc
    new_count = 0;
    for (size_t i = 0; i < count; ++i) {
        if (rout[i].time_end <= hour) { // Use <= operator for std::string
            filtr_vec[new_count++] = rout[i];
        }
    }
    filtr_vec.resize(new_count); // Resize to new_count
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

    if (!all_data.empty())
    {
        filtered_data = filtr_prisnak(all_data, count, hour, new_count);
    }

    if (!all_data.empty() && !filtered_data.empty())
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

    }
}