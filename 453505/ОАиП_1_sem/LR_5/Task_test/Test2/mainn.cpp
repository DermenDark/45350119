#include <iostream>
#include <Windows.h>
using namespace std;


int main() {
    float n = 0, perm = 0;

    HINSTANCE load;
    load = LoadLibrary(L"Dinamic.dll");

    typedef float(__stdcall* kvadratt)(float);
    kvadratt Kvadrattt;

    Kvadrattt = (kvadratt)GetProcAddress(load, "kvadratt");

    cin >> n >> perm;
    n = Kvadrattt(perm);
    cout << perm << '\n' << n;

    FreeLibrary(load);

    return 0;
}