#include <iostream>
#include <cmath>
#include <iomanip>
#include <cstdlib>
#include <ctime>
//#include "C:/SPB_Data/test_MH/JPO/lib4.cpp"
using namespace std;

void  FUNKCJA (double* x , int wielkosc, double *  srednia , double * odchylenie){

double sre=0,odh=0;

for (int i=0; i<wielkosc ;i++ ){
    sre = sre + *(x+i);
}
sre = sre / wielkosc;

for(int i=0; i<wielkosc ;i++ ){
    odh = odh + pow(*(x+i) - sre,2);
}
odh = sqrt(odh/wielkosc);

*srednia = sre;
*odchylenie = odh; 

return;
}



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