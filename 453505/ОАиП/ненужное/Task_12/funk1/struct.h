#include <begin.h>

union poesd_ticet
{
    double double_nomer;
    float float_nomer;
};
struct poesd
{
    std::string data;
    std::string punkt_drive;
    std::string time;
    std::string time_end;
    poesd_ticet nomer;
};