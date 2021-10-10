#include <iostream>
#include <cmath>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include "C:/SPB_Data/test_MH/JPO/zad4.h"
using namespace std;




int main(){
    srand(time(NULL));
    int x;
    cout  << "podaj wielkos tablicy" << endl;
    cin >> x;

    double tablica[x];
    //cout << sizeof(tablica) << sizeof(double) << endl;
    for (int i =0; i<x ; i++){
        tablica[i] = (((rand()%101)*0.01)-0.5)*2;
        cout << tablica[i] << endl;
    }

    double srednia,odchylenie;
    FUNKCJA(tablica , x , &srednia , &odchylenie);
    cout << "srednia wynosi = "<<srednia << "  odchylenie wynosi = " << odchylenie << endl;

    
    exit(0);
}