#include <begin.h>

union BusNumber {
    double double_nomer;
    float float_nomer;
};
struct bus_route {
    BusNumber nomer;
    char typ_bus[256];
    char punkt_drive[256];
    char time_start[256];
    char time_end[256];
};