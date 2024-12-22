#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <fstream>

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
void wri(const std::string &,const vec_bus&);

vec_bus rea(const std::string &);
vec_bus new_bus_route();

  
bus_route create(
std::string & ,
std::string & ,
std::string & ,
std::string & ,
std::string & );