#include "funk1/begin.h"

std::string fl = "file.bin"; 

struct bus_route* create_dynamic_array(size_t size) {
    // Выделяем память для динамического массива
    struct bus_route* array = (struct bus_route*)malloc(size * sizeof(struct bus_route));
    if (array == NULL) {
        fprintf(stderr, "Ошибка выделения памяти\n");
        exit(1); // Завершаем программу в случае ошибки
    }
    // Инициализируем массив (по желанию)
    for (size_t i = 0; i < size; ++i) {
        memset(array[i].nomer, 0, sizeof(array[i].nomer));
        memset(array[i].typ_bus, 0, sizeof(array[i].typ_bus));
        memset(array[i].punkt_drive, 0, sizeof(array[i].punkt_drive));
        memset(array[i].time_start, 0, sizeof(array[i].time_start));
        memset(array[i].time_end, 0, sizeof(array[i].time_end));
    }
    return array;
}

int main() {
    
    char otvet; 
    std::cout << "\nCправочная автовокзала и расписание движения автобусов.\n\nВыполнил задание №1:  Ширко Владимир.";

    do {
        menu();
        funk_menu();
        std::cout << "\n\nЕсли хотите продолжить, то введите 'y' или 'Y', иначе введите любой другой символ: ";
        std::cin >> otvet;
        std::cin.ignore();
    } while (otvet == 'y' || otvet == 'Y');
    std::cout << "Программа завершена.\n";

    return 0;
}