#include <begin.h>
//фильт, который перебирает массив
vec_bus filtr_prisnak(const vec_bus& rout,const std::string& hour) {
    vec_bus filtr_vec;

    for (const auto& route : rout) {
        // Сравниваем время окончания рейса с заданным временем
        if (route.time_end <= hour) {filtr_vec.push_back(route);}
    }

    return filtr_vec; 
}

// Нахождение определённого рейса
vec_bus filtr_eks(const vec_bus& rout, std::function<bool(const bus_route&)> predicate) {
    vec_bus filtr_vec;

    for (const auto& route : rout) {
        // Используем переданное условие для фильтрации
        if (predicate(route)) {
            filtr_vec.push_back(route);
        }
    }
    return filtr_vec; 
}

//сортировка по убыванию
vec_bus sortirovka(const vec_bus& rout) {
    vec_bus filtr_vec = rout; 
    size_t n = filtr_vec.size();


    for (size_t i = 0; i < n - 1; ++i) {
        // Предполагаем, что текущий элемент является максимальным
        size_t maxIndex = i;

        for (size_t j = i + 1; j < n; ++j) {if (filtr_vec[j].time_end > filtr_vec[maxIndex].time_end) {maxIndex = j;}}
        std::swap(filtr_vec[i], filtr_vec[maxIndex]);}

    return filtr_vec; 
}

//фильтрует данные по времени
void filtr_time(){
    std::string hour;
    std::string minuts;


    std::cout<<"Введите нужное вам время пребытия(через ':'):";
    std::getline(std::cin, hour, ':');
    std::getline(std::cin, minuts);


    vec_bus filtr = readd(fl);
    filtr = sortirovka(filtr);
    filtr= filtr_prisnak(filtr, hour + ":" + minuts);
    if (filtr.empty()) {
        std::cout << "Нет рейсов со временем раньше " << hour<<":"<<minuts<< "." << std::endl;

    }
    std::cout<<"Вот все подходящие вам рейсы:";
    writen(filtr);
}