#include <begin.h>

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

void filtr_opr(){
    std::string find_bus;
    bool problem=false;
    std::function<bool(const bus_route&)> prisnak;

    do{ if(problem){std::cout << "\nНет такого свойства. ";}
        poisk();
        std::cout<<"Введите по какому свойству будете искать необходимый автобус?";
        std::getline(std::cin, find_bus);

        if (find_bus.empty() || find_bus.length() > 1) {
            problem = true;
            continue;
        }


        std::string input; 
        switch (find_bus[0]) {
            case '1':
                std::cout << "Свойство: номер автобуса.\n";
                std::cout << "Введите номер автобуса для поиска: ";
                std::getline(std::cin, input);
                prisnak = [input](const bus_route& route) {
                    return route.nomer == input; 
                };
                break;
            case '2':
                std::cout << "Свойство: Тип автобуса.\n";
                std::cout << "Введите тип автобуса для поиска: ";
                std::getline(std::cin, input);
                prisnak = [input](const bus_route& route) {
                    return route.typ_bus == input;
                };
                break;
            case '3':
                std::cout << "Свойство: Пункт назначения.\n";
                std::cout << "Введите пункт назначения для поиска: ";
                std::getline(std::cin, input);
                prisnak = [input](const bus_route& route) {
                    return route.punkt_drive == input;
                };
                break;
            case '4':
                std::cout << "Свойство: Время отправления.\n";
                std::cout << "Введите время отправления для поиска: ";
                std::getline(std::cin, input);
                prisnak = [input](const bus_route& route) {
                    return route.time_start == input;
                };
                break;
            case '5':
                std::cout << "Свойство: Время прибытия.\n";
                std::cout << "Введите время прибытия для поиска: ";
                std::getline(std::cin, input);
                prisnak = [input](const bus_route& route) {
                    return route.time_end == input;
                };
                break;
            case '0':
                std::cout << "Выход из программы.\n";
                return; // Выход из функции
            default:
                problem = true;
                continue;
        }
    }while (problem);

    vec_bus find =readd(fl);
    vec_bus find_buss = filtr_eks(find, prisnak);
    writen(find_buss);
}