#include <begin.h>

void del(){
    size_t index;
    vec_bus routes = readd(fl);
    writen(routes);\

    std::cout << "\n\tВведите индекс маршрута для обновления : ";
    std::cin >> index;
    std::cin.ignore();
    
    if ((index-1) >= routes.size()) {
        std::cerr << "\nОшибка: номер вне диапазона!";
        return;
    }

    bus_route new_route = {"", "", "", "", ""};
    update_record(new_route, index-1);

    routes = readd(fl);
    writen(routes);
}