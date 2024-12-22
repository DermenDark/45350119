#include <begin.h>

void funk_menu(){
    std::string num_funk="0";
    bool problem=false;
    vec_bus bus_sapis;
    

    do{ if(problem){std::cout << "\nНет такой функции. ";}
        std::cout << "Ведите нужную вам функцию:";
        std::getline(std::cin, num_funk);

        if (num_funk.empty() || num_funk.length() > 1) {
            problem = true;
            continue;
        }


        switch (num_funk[0]) {
            case '1':
                std::cout << "Вы выбрали функцию 1.\n";
                demonstriten_all();
                break;
            case '2':
                std::cout << "Вы выбрали функцию 2.\n";
                filtr_time();
                break;
            case '3':
                std::cout << "Вы выбрали функцию 3.\n";
                filtr_opr();
                break;
            case '4':
                std::cout << "Вы выбрали функцию 4.\n";
                new_bus_route();

                break;
            case '5':
                std::cout << "Вы выбрали функцию 5.\n";

                break;
            case '6':
                std::cout << "Вы выбрали функцию 6.\n";

                break;
            case '7':
                std::cout << "Вы выбрали функцию 7.\n";                

                break;
            case '8':
                std::cout << "Вы выбрали функцию 8.\n";
                remove(fl.c_str());
                std::cout << "Данные о рейсах успешно удалены.";
                break;
            case '0':
                std::cout << "Выход из программы.\n";
                problem = false;  
                break;
            default:
                problem = true; 
                break;
        }
    }while (problem);
}