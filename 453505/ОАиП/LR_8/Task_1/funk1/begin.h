#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <functional>
#include <limits>

// Основная структура
struct bus_route {
    std::string nomer;
    std::string typ_bus;
    std::string punkt_drive;
    std::string time_start;
    std::string time_end;
};
union Floats {
    float f; 
    double d; 
};

// Сокращенное название структуры для записи рейсов
typedef std::vector<bus_route> vec_bus;

// Переменная, хранящая название файла
extern std::string fl;
extern size_t max__size;
extern  const size_t MAX_SIZE;


// Объявления функций
void osnova();
void menu();
void poisk();
void funk_menu();
void filtr_opr();
void demonstriten_all();
void filtr_time();
void update_file();
void writen(vec_bus &);
void wri(const std::string &, const vec_bus&);


vec_bus filtr_eks(const vec_bus& , std::function<bool(const bus_route&)> );
vec_bus filtr_prisnak(const vec_bus& ,const std::string & );
vec_bus readd(std::string & );
vec_bus sortirovka(const vec_bus& );


void new_bus_route();
bus_route create(const std::string &, const std::string &, const std::string &, const std::string &, const std::string &);