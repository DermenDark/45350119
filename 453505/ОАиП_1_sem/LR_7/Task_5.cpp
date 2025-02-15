#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <unordered_set>
#include <algorithm>
#include <bitset>
#include <map>

std::vector<std::pair<int, std::string>> rab() {
    std::vector<std::pair<int, std::string>> Apocalypse = {
        {1, "Война"},
        {2, "Голод"},
        {3, "Чума"},
        {4, "Смерть"},
        {5, "Вы"}
    };
    return Apocalypse;
}
//визуализация бочек(для теста)
std::string pokas(std::string &num){
    for(int i=0; i<num.length(); i++) {
        std::cout<<num[i]<<' ';
        if ((i + 1) % 40 == 0) {
            std::cout << " <- сорок бочек\n";
        }
    }
    return num;
}
std::vector<int> pokas(std::vector<int> &num){
    std::cout<<'\n';
    for(int i=0; i<num.size(); i++) {
        std::cout<<num[i]<<' ';
        if ((i + 1) % 40 == 0) {
            std::cout << " <- сорок бочек\n";
        }
    }
    return num;
}
//выводим график питья(для теста) 
void print(
    const std::vector<std::pair<int, std::vector<int>>>& grafik, 
    const std::vector<std::pair<int, std::string>>& spisok) 
    
    {
    for (const auto& item : grafik) {

        std::cout << "Бочка №" << item.first << " пьёт: ";
        for (const int slaveIndex : item.second) {

            std::cout << spisok[slaveIndex].second << " "; 
        }
    }
}
//рапределяем рабов на групы день первый
std::vector<std::pair<int, std::vector<int>>> rasd_rab_day1(std::vector<int> & num){

    std::string res;
    std::vector<std::pair<int, std::vector<int>>> grafik;

    int index =0;
    for(int i=1; i<81; i++) {

        grafik.push_back({num[i],{index}});
        if(i%16==0){++index;}
    }

    index =0;
    for(int i=81; i<161; i++) {

        grafik.push_back({num[i],{index,(index+1)%5}});
        if(i%8==0){++index;}
        if(i%40==0){index=0;}
    }

    index =0;
    for(int i=161; i<201; i++) {

        grafik.push_back({num[i],{index,(index+1)%5,(index+2)%5}});
        if(i%4==0){++index;}
        if(i%20==0){index=0;}
    }

    index =0;
    for(int i=201; i<209; i++) {

        grafik.push_back({num[i],{index,(index+1)%5,(index+2)%5,(index+3)%5}});
        if(i%2==0){++index;}
    }

    return grafik;
}
//вывод умерших и получение списка умерших
std::vector<int> dead_rab(
    std::vector<std::pair<int, std::vector<int>>> & grafik,
    std::vector<std::pair<int, std::string>> & spisok_rab,
    int num_bochki)
    
    {    
    std::string res;
    const std::vector<int>& slaves = grafik[num_bochki-1].second;
    std::vector<int> dead_slaves;
    
    res += "\nУмершие рабы:";
    for (int slaveIndex : slaves) {
        if (slaveIndex >= 0 && slaveIndex < spisok_rab.size()) {

            dead_slaves.push_back(slaveIndex);
            res += "\n\t";
            if(spisok_rab[slaveIndex].first==2){res += "Умер " + spisok_rab[slaveIndex].second + " ";}
            else if(spisok_rab[slaveIndex].first==5){res += "Умерли " + spisok_rab[slaveIndex].second + "!!! "+"\nВы не были близким другом Патриция:(";}
            else{res += "Умерла " + spisok_rab[slaveIndex].second + " ";}
        }
    }
    std::cout<<res;
    return dead_slaves;
}
//убираем мертвых рабов из графика питья и убираем неотравленные бочки из списка(bochki)
std::vector<int> new_day_1(
    std::vector<std::pair<int, std::vector<int>>> &grafik,
    std::vector<int> &bochki,
    std::vector<int> &dead_rab)
{
    std::unordered_set<int> dead_set(dead_rab.begin(), dead_rab.end());
    std::vector<int> updated_bochki; 

    for (int bochka : bochki) {
        bool shouldKeep = true;  // Флаг, который определяет, оставлять ли бочку

        // Ищем рабов, пьющих эту бочку
        for (const auto &pair : grafik) {
            if (pair.first == bochka + 1) { 

                for (int dead_slave : dead_set) {

                    if (std::find(pair.second.begin(), pair.second.end(), dead_slave) == pair.second.end()) {
                        shouldKeep = false; 
                        break;
                    }
                }
                break;  
            }
        }

        if (shouldKeep) {
            updated_bochki.push_back(bochka); 
        }
    }

    updated_bochki.erase(std::remove_if(updated_bochki.begin(), updated_bochki.end(),
        [](int bochka) { return bochka >= 208; }), updated_bochki.end());

    std::vector<int> final_bochki;
    for (int bochka : updated_bochki) {
        bool shouldRemove = false; 

        for (const auto &pair : grafik) {
            if (pair.first == bochka + 1) {  
                for (int slave : pair.second) {
                    if (dead_set.count(slave) == 0) {  
                        shouldRemove = true;  
                        break;
                    }
                }
                break; 
            }
        }

        if (!shouldRemove) {
            final_bochki.push_back(bochka);  // Если ни один раб не выжил, оставляем бочку
        }
    }

    return final_bochki;  
}
int fin(int totalbochka, int totalsl, int poisoned_bochka,std::vector<std::pair<int, std::string>> & spisok_rab,int n) {
    std::vector<std::vector<int>> drinkingSchedule(totalsl);
    for (int barrel = 0; barrel < totalbochka; ++barrel) {
        std::bitset<5> binaryCode(barrel);
        for (int slave = 0; slave < totalsl; ++slave) {
            if (binaryCode[slave]) {
                drinkingSchedule[slave].push_back(barrel);
            }
        }
    }

    std::bitset<5> binaryCode(poisoned_bochka);
    std::vector<int> deadSlaves;
    for (int slave = 0; slave < totalsl; ++slave) {
        if (binaryCode[slave]) {
            deadSlaves.push_back(slave);
        }
    }
    std::cout << "Новый график питья:\n";
    for (int slave = 0; slave < totalsl; ++slave) {
        std::cout << "Раб " << slave + 1 << " пьет из бочек: "; 
        for (int barrel : drinkingSchedule[slave]) {
            std::cout << barrel+n << " "; 
        }
        std::cout << "\n";
    }
    std::cout << "Умерли: \n";
    for (int slave : deadSlaves) {
        if(spisok_rab[slave].first==2){std::cout << "Умер " + spisok_rab[slave].second + " ";}
            else if(spisok_rab[slave].first==5){std::cout << "Умерли " + spisok_rab[slave].second + "!!! "+"\nВы не были близким другом Патриция:(";}
            else{std::cout << "Умерла " + spisok_rab[slave].second + " ";}
    }
    std::cout << "\n";

    int detectedPoisonedBarrel = 0;
    for (int slave : deadSlaves) {
        detectedPoisonedBarrel |= (1 << slave);
    }
    
    return detectedPoisonedBarrel;
}
int findDivisionCount(int a, int b) {
    int n = 0;
    int prom = a;

    while (prom >= b) {
        prom = prom - b;
        ++n;
    }

    if (n == 0 && a >= b) {
        return 1;
    }

    return n;
}

void osnova() {
    int num_bochki=0;
    std::vector<int>bochki_2(240, 0);
    for (int i = 0; i < 240; ++i) {
        bochki_2[i] = i; 
    }

    std::vector<std::pair<int, std::string>> rab_spis=rab();

    bool vvod =false;
    while (!vvod) {
        std::cout<<"\nВведите номер отравленной бочки:";
        std::cin>>num_bochki;

        if (num_bochki<1 || num_bochki>240) {std::cout<<"Некорректный ввод";}
        else{vvod =true;}
    }

    std::cout << "Вы выбрали бочку номер: " << num_bochki <<'\n';
    std::vector<std::pair<int, std::vector<int>>> grafik = rasd_rab_day1(bochki_2);
    print(grafik, rab_spis);


    std::cout << "\n\nДень первый:";
    std::vector<int> dead=dead_rab(grafik,rab_spis,num_bochki);
    std::vector<int> ism_bochki;

    if (dead.empty()) {
        std::cout << "\nНет умерших рабов, осталось 32 бочки.";
        std::cout << "\nДень второй:";
        int c = fin(32,5,num_bochki-209,rab_spis,209);
        std::cout << "\nОтравленная бочка:"<<c+209;
    } else {
        ism_bochki=new_day_1(grafik,bochki_2,dead);
        std::cout << "\nНомера оставшихся бочек:";
        pokas(ism_bochki);
        std::cout<<"\nOставшееся количество бочек под подозрением:"<<ism_bochki.size();
        std::cout << "\nДень второй:";

        int c=0;
        switch (5-dead.size()) {
        case 1:
            c = fin(2,1,num_bochki%2,rab_spis,findDivisionCount(ism_bochki[0],2)*2)+findDivisionCount(ism_bochki[0],2)*2;
            return;
        case 2:
            c = fin(4,2,num_bochki%4,rab_spis,findDivisionCount(ism_bochki[0],4)*4)+findDivisionCount(ism_bochki[0],4)*4;
            break;
        case 3:
            c = fin(8,3,num_bochki%8,rab_spis,findDivisionCount(ism_bochki[0],8)*8)+findDivisionCount(ism_bochki[0],8)*8;
            break;
        case 4:
            c = fin(16,4,num_bochki%16,rab_spis,findDivisionCount(ism_bochki[0],16)*16)+findDivisionCount(ism_bochki[0],16)*16;
            break;
    }
        std::cout<<"\nOтравленна бочка №"<<c;
    }

}

int main() {
    char otvet;
    std::cout << "\nПодойдите к заданию творчески и найдите способ определения отравленной бочки с ядом.\n\nВыполнил задание №1: Ширко Владимир.\nВариант-№4(19 в списке)\n\n";

    do {
        osnova(); 
        std::cout << "\nЕсли хотите продолжить, то введите 'y' или 'Y', иначе введите любой другой символ: ";
        std::cin >> otvet;
        std::cin.ignore();
    } while (otvet == 'y' || otvet == 'Y');

    std::cout << "Программа завершена.\n";

    return 0;
}