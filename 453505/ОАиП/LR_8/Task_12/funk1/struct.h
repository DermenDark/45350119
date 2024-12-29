struct bus_route {
    union {
        double double_nomer;
        float float_nomer;
    } nomer;

    char typ_bus[256];      
    char punkt_drive[256];  
    char time_start[256]; 
    char time_end[256];    
    bool is_double;        
};