#include <begin.h>

// Вывод информации о рейсах в терминал
void writen(vec_poesd str) {
    int i = 1;
    for (auto& el: str) {
        // Не показываем пользователю удалённые строки
        std::cout << "\n" << i << ": Номер автобуса: " << str.data <<
            "\t\t\t\nПункт назначения: " << str.punkt_drive <<
            "\t\tВремя отправления: " << str.time <<
            "\t\tТип автобуса: " << str.time_end <<
            "\t\tВремя прибытия: " << str.nomer<<"\n";
        ++i;
    }
}

//чтение данных из файла
vec_poesd readd(const std::string& filename) {
    std::ifstream fin(filename);
    vec_poesd ticket;
     if (!fin) {
        std::cerr << "Ошибка при открытии файла для чтения!" << std::endl;
        return tickets;
    }

    std::string line;
    while (std::getline(fin, line)) {
        std::istringstream ss(line);
        poesd ticket;
        std::string nomer_str;

        // Чтение данных, через запятую
        std::getline(ss, ticket.data, ',');
        std::getline(ss, ticket.punkt_drive, ',');
        std::getline(ss, ticket.time, ',');
        std::getline(ss, ticket.time_end, ',');
        std::getline(ss, nomer_str, ','); 


        // Преобразуем 
        ticket.nomer.double_nomer = std::stod(nomer_str);
        tickets.push_back(ticket);
    }
    fin.close();
    return tickets;
}

//выводит все данные файлов
void demonstriten_all(){
    vec_poesd all_data = readd(fl);
    if (count > 0) {std::cout << "Все хранящиеся данные в файле:";}
    writen(all_data);
}