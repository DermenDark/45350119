#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <functional>
#include <cstring>

struct bus_route {
    char nomer[256];
    char typ_bus[256];
    char punkt_drive[256];
    char time_start[256];
    char time_end[256];
};

// Сокращенное название структуры для записи рейсов
typedef std::vector<bus_route> vec_bus;

// Переменная, хранящая название файла
extern std::string fl;

// Объявления функций
int find_route_index(const vec_bus& routes, const std::function<bool(const bus_route&)>& predicate);
void osnova();
void menu();
void poisk();
void del();
void funk_menu();
void filtr_opr();
void demonstriten_all();
void filtr_time();
void update_file();
void update_record(const bus_route& updated_route, size_t index);
void writen(vec_bus &);
void wri(const std::string& filename, const vec_bus& bus);

vec_bus filtr_eks(const vec_bus& , std::function<bool(const bus_route&)> );
vec_bus filtr_prisnak(const vec_bus& ,const std::string & );
vec_bus readd(const std::string& filename);
vec_bus sortirovka(const vec_bus& );


void new_bus_route();
bus_route create(const char* nomer, const char* typ_bus,
                 const char* punkt_drive, const char* time_start,
                 const char* time_end);
bus_route get_route_from_user();