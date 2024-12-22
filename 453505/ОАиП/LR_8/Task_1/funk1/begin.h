#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <fstream>

// std::string fl="file.dat";
struct bus_route{
    std::string nomer;
    std::string typ_bus;
    std::string punkt_drive;
    std::string time_start;
    std::string time_end;
};
typedef std::vector<bus_route> vec_bus;

void osnova();
void menu();
void funk_menu();
void writen(vec_bus &);
vec_bus new_bus_route();
bus_route create(
std::string & ,
std::string & ,
std::string & ,
std::string & ,
std::string & );