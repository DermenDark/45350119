#include <begin.h>

// Фильтр, который перебирает массив
vec_bus filtr_prisnak(const vec_bus& rout, size_t count, const std::string& hour, size_t& new_count) {
    vec_bus filtr_vec = (vec_bus)malloc(count * sizeof(bus_route)); // Выделяем память для фильтрованного массива
    new_count = 0;

    for (size_t i = 0; i < count; ++i) {
        // Сравниваем время окончания рейса с заданным временем
        if (rout[i].time_end <= hour) {
            filtr_vec[new_count++] = rout[i]; // Добавляем в фильтрованный массив
        }
    }

    // Изменяем размер фильтрованного массива
    filtr_vec = (vec_bus)realloc(filtr_vec, new_count * sizeof(bus_route));
    return filtr_vec; 
}

// Фильтрует данные по времени
void filtr_time() {
    std::string hour;
    std::cout << "Введите время (чч:мм): ";
    std::cin >> hour;

    size_t count;
    vec_bus all_data = readd(fl, count); // Укажите путь к вашему файлу
    size_t new_count;
    vec_bus filtered_data = filtr_prisnak(all_data, count, hour, new_count);

    if (new_count > 0) {
        std::cout << "Фильтрованные данные по времени:\n";
        writen(filtered_data, new_count);
    } else {
        std::cout << "Нет данных, соответствующих заданному времени.\n";
    }

    free_dynamic_array(all_data);
    free_dynamic_array(filtered_data);
}